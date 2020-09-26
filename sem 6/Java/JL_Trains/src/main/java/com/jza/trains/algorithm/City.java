package com.jza.trains.algorithm;

import com.jza.trains.models.Train;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

import java.util.ArrayList;
import java.util.List;

@NoArgsConstructor
@AllArgsConstructor
@Getter
@Setter
public class City implements Comparable<City> {
	public String name;
	public List<Connection> connections = new ArrayList<>();
	public Integer minDistance = Integer.MAX_VALUE;
	public City previous;


	public City(String argName) {
		name = argName;
	}

	@Override
	public int compareTo(City o) {
		return Integer.compare(minDistance, o.minDistance);
	}
}
