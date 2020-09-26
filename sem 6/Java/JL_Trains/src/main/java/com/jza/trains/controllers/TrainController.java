package com.jza.trains.controllers;

import com.jza.trains.dao.TrainRepo;
import com.jza.trains.models.ResultRoutes;
import com.jza.trains.models.Train;
import com.jza.trains.services.TrainService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
public class TrainController {

	@Autowired
	TrainRepo trainRepo;

	@Autowired
	TrainService trainService;

	@PostMapping(value = "/addTrain")
	public ResponseEntity saveTrain(@RequestBody Train train) {
		Boolean saved = trainService.addTrain(train);
		if (saved) {
			return new ResponseEntity<>("Train saved to database", HttpStatus.OK);
		} else {
			return new ResponseEntity<>("Train already exist", HttpStatus.CONFLICT);
		}
	}

	@GetMapping(value = "/findRoute/{startCity}/{endCity}")
	public ResultRoutes findRoute(@PathVariable("startCity") String startCity, @PathVariable("endCity") String endCity) {
		ResultRoutes resultRoutes = trainService.findRoute(startCity, endCity);
		if (resultRoutes.getRoutes().get(0).size() == 1){
			return null;
		} else {
			return resultRoutes;
		}

	}


	@GetMapping(value = "/allTrains")
	public List<Train> getTrains() {
		return trainService.findAllTrains();
	}

	@GetMapping(value = "/findTrain/{startCity}/{endCity}")
	public Train findTrain(@PathVariable("startCity") String startCity, @PathVariable("endCity") String endCity) {
		return trainService.findTrain(startCity, endCity);
	}

	@GetMapping(value = "/allCitiesDistinct")
	public List<String> getAllCitiesDistinct() {
		return trainService.getCities();
	}

}
