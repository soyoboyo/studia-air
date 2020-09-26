package com.example.jacek.pam_androiproje;

import android.arch.persistence.room.Room;
import android.location.Location;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RatingBar;
import android.widget.Toast;

import com.example.jacek.pam_androiproje.database.room.AppDatabase;
import com.example.jacek.pam_androiproje.database.room.LocationModel;

import java.util.Date;

public class AddNewLocationActivity extends AppCompatActivity {

    Button buttonAdd;
    EditText editTextName;
    EditText editTextWebsite;
    EditText editTextNote;
    EditText editTextAddress;
    RatingBar ratingBar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add);

        buttonAdd = (Button) findViewById(R.id.buttonAdd);
        editTextName = (EditText) findViewById(R.id.editTextName);
        editTextWebsite = (EditText) findViewById(R.id.editTextWWW);
        editTextNote = (EditText) findViewById(R.id.editTextNote);
        editTextAddress = (EditText) findViewById(R.id.editTextAddress);
        ratingBar = (RatingBar) findViewById(R.id.ratingBar);

        buttonAdd.setOnClickListener(new View.OnClickListener() {
            public void onClick(View view) {
                addNewLocation();
            }
        });
    }

    public void addNewLocation() {
        try {
            AppDatabase db = Room.databaseBuilder(getApplicationContext(), AppDatabase.class, "locations").allowMainThreadQueries().build();
            String name = this.editTextName.getText().toString();
            String website = this.editTextWebsite.getText().toString();
            String address = this.editTextAddress.getText().toString();
            String note = this.editTextNote.getText().toString();
            Float rating = this.ratingBar.getRating();
            GPSTracker tracker = new GPSTracker(getApplicationContext());
            if (tracker.canGetLocation()) {
                Location location = tracker.getLocation();
                LocationModel locationModel = new LocationModel(name, address, website, note, rating, new Date(), location.getLatitude(), location.getLongitude());
                db.locationDao().insert(locationModel);
                Log.i("tag", locationModel.toString());
                Toast.makeText(AddNewLocationActivity.this, "Location added.", Toast.LENGTH_LONG).show();
            } else {
                Toast.makeText(getApplicationContext(), "Couldn't get location. Try again.", Toast.LENGTH_LONG).show();
            }
            tracker.stopUsingGPS();
        } catch (Exception e) {
            Toast.makeText(AddNewLocationActivity.this, "Error adding location. Try again.", Toast.LENGTH_LONG).show();
        }
    }
}
