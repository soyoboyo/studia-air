package com.jza.trains.algorithm;

import com.jza.trains.algorithm.City;
import lombok.*;

@AllArgsConstructor
@NoArgsConstructor
@Getter
@Setter
@ToString
public class Connection {
	public City end;
	public Integer distance;

}
