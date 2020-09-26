package com.jza.trains.algorithm;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;

public class Dijkstra {

	public static void computePaths(City startCity) {
		startCity.minDistance = 0;
		PriorityQueue<City> cityPriorityQueue = new PriorityQueue<>();
		cityPriorityQueue.add(startCity);

		while (!cityPriorityQueue.isEmpty()) {
			City a = cityPriorityQueue.poll();

			System.out.println(a.getName() + " " + a.connections.size());
			for (Connection c : a.connections) {
				City b = c.end;
				Integer dist = c.distance;
				Integer distThruA = a.minDistance + dist;
				if (distThruA < b.minDistance) {
					cityPriorityQueue.remove(b);
					b.minDistance = distThruA;
					b.previous = a;
					cityPriorityQueue.add(b);
				}
			}

		}
	}

	public static List<City> getShortestPathTo(City end) {
		List<City> route = new ArrayList<City>();
		for (City city = end; city != null; city = city.previous) {
			route.add(city);
		}
		Collections.reverse(route);
		return route;
	}


}
