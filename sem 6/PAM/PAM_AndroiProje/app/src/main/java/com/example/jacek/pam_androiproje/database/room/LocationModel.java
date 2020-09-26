package com.example.jacek.pam_androiproje.database.room;

import android.arch.persistence.room.ColumnInfo;
import android.arch.persistence.room.Entity;
import android.arch.persistence.room.PrimaryKey;
import android.arch.persistence.room.TypeConverters;

import java.text.SimpleDateFormat;
import java.util.Date;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Entity
@Getter
@Setter
@NoArgsConstructor
@AllArgsConstructor
@TypeConverters({DateConverter.class})
public class LocationModel {
    @PrimaryKey
    private Integer id;

    @ColumnInfo(name = "name")
    private String name;

    @ColumnInfo(name = "address")
    private String address;

    @ColumnInfo(name = "website")
    private String website;

    @ColumnInfo(name = "note")
    private String note;

    @ColumnInfo(name = "rating")
    private Float rating;

    @ColumnInfo(name = "visited")
    @TypeConverters({DateConverter.class})
    private Date visited;

    @ColumnInfo(name = "latitude")
    private Double latitude;

    @ColumnInfo(name = "longitude")
    private Double longitude;

    public LocationModel(String name, String address, String website, String note, Float rating, Date visited,  Double latitude, Double longitude) {
        this.name = name;
        this.address = address;
        this.website = website;
        this.visited = visited;
        this.note = note;
        this.rating = rating;
        this.latitude = latitude;
        this.longitude = longitude;
    }

    public String getVisitedString(){
        return new SimpleDateFormat("dd.MM.yyyy HH:mm").format(visited);
    }

    @Override
    public String toString() {
        return "LocationModel{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", address='" + address + '\'' +
                ", website='" + website + '\'' +
                ", visited=" + visited +
                ", note='" + note + '\'' +
                ", rating=" + rating +
                ", latitude=" + latitude +
                ", longitude=" + longitude +
                '}' + "\n";
    }
}
