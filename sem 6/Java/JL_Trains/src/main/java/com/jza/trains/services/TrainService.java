package com.jza.trains.services;

import com.jza.trains.algorithm.City;
import com.jza.trains.algorithm.Connection;
import com.jza.trains.algorithm.Dijkstra;
import com.jza.trains.dao.TrainRepo;
import com.jza.trains.models.ResultRoutes;
import com.jza.trains.models.Train;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.mongodb.core.MongoTemplate;
import org.springframework.stereotype.Service;

import java.util.*;

@Service
public class TrainService {

	@Autowired
	MongoTemplate mongoTemplate;

	@Autowired
	TrainRepo trainRepo;

	@Autowired
	CmdService cmdService;

	public ResultRoutes findRoute(String start, String end) {

		List<Train> trains = trainRepo.findAllByOrderByStart();
		List<String> cityNames = this.getCities();
		Collections.sort(cityNames);
		ResultRoutes resultRoutes = new ResultRoutes();


		Map<String, City> cityMap = new HashMap<>();

		for (String cityName : cityNames) {
			cityMap.put(cityName, new City(cityName));
		}
		System.out.println("trains count: " + trains.size());
		for (int i = 0, j = 0; i < trains.size(); i++) {
			Train train = trains.get(i);
			String cityName = cityNames.get(j);
			if (train.getStart().equals(cityName)) {
				cityMap.get(cityName).connections.add(new Connection(cityMap.get(train.getEnd()), train.getDistance()));
				System.out.println("from: " + cityName + " to: " + cityMap.get(train.getEnd()).getName());
			} else {
				j++;
				i--;
			}
		}
		Dijkstra.computePaths(cityMap.get(start));
		System.out.println("Distance to " + cityMap.get(end).getName() + ": " + cityMap.get(end).minDistance);
		List<City> path = Dijkstra.getShortestPathTo(cityMap.get(end));
		List<String> route = new ArrayList<>();
		for (City c : path) {
			System.out.println(c.getName());
			route.add(c.getName());
		}
		System.out.println("==================================");
		resultRoutes.getRoutes().add(route);
		resultRoutes.setDistance(cityMap.get(end).minDistance);
		return resultRoutes;

	}

	public Boolean addTrain(Train train) {

		String start = train.getStart();
		String end = train.getEnd();
		String id = start + end;
		train.setId(id);
		Train existing = this.findTrain(train.getStart(), train.getEnd());
		if (existing != null) {
			return false;
		} else if (start.equals(end)) {
			return false;
		} else {
			trainRepo.save(train);
			cmdService.exportData();
			return true;
		}
	}


	public List<String> getCities() {

		try {
			Iterable<String> startCities = mongoTemplate.getCollection("trains").distinct("start", String.class);
			Iterable<String> endCities = mongoTemplate.getCollection("trains").distinct("end", String.class);
			List<String> startCitiesList = new ArrayList<>(makeCollection(startCities));
			List<String> endCitiesList = new ArrayList<>(makeCollection(endCities));
			Set<String> distinctCities = new HashSet<>();
			distinctCities.addAll(startCitiesList);
			distinctCities.addAll(endCitiesList);
			List<String> distinctCitiesList = new ArrayList<>(distinctCities);
			Collections.sort(distinctCitiesList);
			return distinctCitiesList;

//			Iterable<String> list = mongoTemplate.getCollection("trains").distinct("start", String.class);
//			List<String> citiesDistinct = new ArrayList<>(makeCollection(list));
//			Collections.sort(citiesDistinct);
//			return citiesDistinct;
		} catch (Exception e) {
			System.out.println("Error finding cities: " + e.getMessage());
			return null;
		}

	}

	public List<Train> findAllTrains() {
		List<Train> trains = trainRepo.findAllByOrderByStart();
		return trains;
	}

	public Train findTrain(String startCity, String endCity) {
		Train train;
		try {
			train = trainRepo.findByStartAndEnd(startCity, endCity);
			return train;
		} catch (Exception e) {
			System.out.println("Error finding train: " + e.getMessage());
			return null;
		}

	}


	public static <E> Collection<E> makeCollection(Iterable<E> iter) {
		Collection<E> list = new ArrayList<E>();
		for (E item : iter) {
			list.add(item);
		}
		return list;
	}

}

