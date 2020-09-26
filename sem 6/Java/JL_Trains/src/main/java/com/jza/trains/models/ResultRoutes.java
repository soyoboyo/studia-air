package com.jza.trains.models;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

import java.util.ArrayList;
import java.util.List;


@AllArgsConstructor
@NoArgsConstructor
@Getter
@Setter
public class ResultRoutes {
	private List<List<String>> routes = new ArrayList<>();
	private Integer distance;
}
