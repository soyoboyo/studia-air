package com.jza.trains.models;

import lombok.*;
import org.springframework.data.annotation.Id;
import org.springframework.data.mongodb.core.mapping.Document;

@Getter
@Setter
@NoArgsConstructor
@AllArgsConstructor
@Document(collection = "trains")
public class Train {
	@Id
	private String id;
	private String start;
	private String end;
	private Integer distance;

	public Train(String start, String end, Integer distance) {
		this.start = start;
		this.end = end;
		this.distance = distance;
	}



}
