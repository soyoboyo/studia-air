package com.example.jacek.pam_androiproje.database;

import com.example.jacek.pam_androiproje.database.room.LocationModel;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class LocationsFactory {
    public List<LocationModel> getLocations() throws ParseException {

        DateFormat format = new SimpleDateFormat("dd.MM.yyyy HH:mm");
        List<LocationModel> list = new ArrayList<>();
        try {
            list.add(new LocationModel("Robotronik", "Wroclawczyka 37", "robotronik.pl", "sklep narzedziowy", 4.0f, new Date(), 51.111585, 17.054939));
            list.add(new LocationModel("Skalnik", "Ladna 4/6", "skalnik.pl", "sklep turystyczny", 4.0f, format.parse("01.06.2018 14:15"), 51.112343, 17.055582));
            list.add(new LocationModel("Kokosowa Wyspa", "Wybrzeze Stanislawa Wyspianskiego 35", "kokosowa-wyspa.pl", "szkola językowa", 3.0f, new Date(), 51.107907, 17.067872));
            list.add(new LocationModel("Wybieg dla lwów", "Wroblewskiego 1-5", "kokosowa-wyspa.pl", "zwerzątka", 5.0f, new Date(), 51.104499, 17.077222));
            list.add(new LocationModel("Ratusz Wrocławski", "Rynek 50", "muzeum.miejskie.wroclaw.pl", "ratusz miejska", 2.0f, new Date(), 51.109558, 17.032092));
            list.add(new LocationModel("Hydropolis", "Na Grobli 19-21", "hydropolis.pl", "museum nauki", 5.0f, new Date(), 51.103845, 17.057369));
            list.add(new LocationModel("Teatr Polski - Scena im. J.Grzegorzewskiego", "Gabrieli Zapolskiej 3", "teatrpolski.wroc.pl", "teatr", 3.50f, new Date(), 51.101177, 17.026148));
        } catch (ParseException e) {
            e.printStackTrace();
        }
        return list;
    }
}
