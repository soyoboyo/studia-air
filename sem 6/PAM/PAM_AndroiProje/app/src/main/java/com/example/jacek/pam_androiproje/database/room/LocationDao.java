package com.example.jacek.pam_androiproje.database.room;

import android.arch.persistence.room.Dao;
import android.arch.persistence.room.Delete;
import android.arch.persistence.room.Insert;
import android.arch.persistence.room.Query;
import android.arch.persistence.room.Update;

import java.util.List;

@Dao
public interface LocationDao {
    @Query("SELECT * FROM LocationModel")
    List<LocationModel> getAll();

    @Insert
    public void insert(LocationModel locationModel);

    @Update
    public void update(LocationModel locationModel);

    @Delete
    public void delete(LocationModel locationModel);
}
