package com.jza.trains.dao;


import com.jza.trains.models.Train;
import org.springframework.data.mongodb.repository.MongoRepository;
import org.springframework.data.repository.query.Param;
import org.springframework.data.rest.core.annotation.RepositoryRestResource;

import java.util.List;

@RepositoryRestResource(collectionResourceRel = "trains", path = "trains")
public interface TrainRepo extends MongoRepository<Train, String> {
	Train findByStartAndEnd(@Param("start") String start, @Param("end") String end);
	List<Train> findAllByOrderByStart();
}
