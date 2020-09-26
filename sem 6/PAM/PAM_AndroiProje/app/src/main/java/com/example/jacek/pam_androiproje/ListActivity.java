package com.example.jacek.pam_androiproje;

import android.arch.persistence.room.Room;
import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;

import com.example.jacek.pam_androiproje.database.LocationModelAdapter;
import com.example.jacek.pam_androiproje.database.LocationsFactory;
import com.example.jacek.pam_androiproje.database.room.AppDatabase;
import com.example.jacek.pam_androiproje.database.room.LocationModel;
import com.google.gson.Gson;

import java.text.ParseException;
import java.util.ArrayList;
import java.util.List;

public class ListActivity extends AppCompatActivity {

    ListView listView;
    LocationModelAdapter locationAdapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_list);
        listView = (ListView) findViewById(R.id.listView);
        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> arg0, View arg1, int position, long arg3) {
                LocationModel loc = (LocationModel) listView.getItemAtPosition(position);
                Intent intent = new Intent(ListActivity.this, EditActivity.class);
                Gson gson = new Gson();
                String locationToEdit = gson.toJson(loc);
                intent.putExtra("locationToEdit", locationToEdit);
                startActivity(intent);
            }
        });
    }

    @Override
    public void onResume() {
        super.onResume();
        AppDatabase db = Room.databaseBuilder(getApplicationContext(), AppDatabase.class, "locations").allowMainThreadQueries().build();

        List<LocationModel> list = db.locationDao().getAll();
        if (list.isEmpty()) {
            LocationsFactory factory = new LocationsFactory();
            try {
                list = factory.getLocations();
            } catch (ParseException e) {
                e.printStackTrace();
            }
        }
        ArrayList<LocationModel> locations = new ArrayList<>(list);

        locationAdapter = new LocationModelAdapter(this, locations);
        listView.setAdapter(locationAdapter);
    }
}
