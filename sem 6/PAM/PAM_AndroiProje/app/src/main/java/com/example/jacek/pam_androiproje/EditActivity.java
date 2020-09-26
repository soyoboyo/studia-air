package com.example.jacek.pam_androiproje;

import android.app.AlertDialog;
import android.arch.persistence.room.Room;
import android.content.DialogInterface;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.RatingBar;
import android.widget.TextView;
import android.widget.Toast;

import com.example.jacek.pam_androiproje.database.room.AppDatabase;
import com.example.jacek.pam_androiproje.database.room.LocationModel;
import com.google.gson.Gson;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class EditActivity extends AppCompatActivity {

    TextView textViewTitle;
    FloatingActionButton btnUpdate;
    FloatingActionButton btnDelete;
    AppDatabase db;
    LocationModel locationModel;

    EditText editTextName;
    EditText editTextAddress;
    EditText editTextWebsite;
    EditText editTextNote;
    RatingBar ratingBar;
    EditText editTextVisited;
    EditText editTextLatitude;
    EditText editTextLongitude;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_edit);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        db = Room.databaseBuilder(getApplicationContext(), AppDatabase.class, "locations").allowMainThreadQueries().build();

        editTextName = (EditText) findViewById(R.id.editTextName);
        editTextWebsite = (EditText) findViewById(R.id.editTextWebsite);
        editTextNote = (EditText) findViewById(R.id.editTextNote);
        editTextAddress = (EditText) findViewById(R.id.editTextAddress);
        ratingBar = (RatingBar) findViewById(R.id.ratingBar);
        editTextVisited = (EditText) findViewById(R.id.editTextVisited);
        editTextLatitude = (EditText) findViewById(R.id.editTextLatitude);
        editTextLongitude = (EditText) findViewById(R.id.editTextLongitude);

        btnUpdate = (FloatingActionButton) findViewById(R.id.btnUpdate);
        btnDelete = (FloatingActionButton) findViewById(R.id.btnDelete);
        btnUpdate.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                try {
                    updateLocation();
                } catch (ParseException e) {
                    e.printStackTrace();
                    Log.e("edit", "Error updating activity.");
                }
            }
        });
        btnDelete.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                try {
                    popDialog();
                } catch (Exception e) {
                    Log.e("edit", "Error deleting activity");
                }
            }
        });
        getSupportActionBar().setDisplayHomeAsUpEnabled(true);
    }

    @Override
    public void onResume() {
        super.onResume();

        Gson gson = new Gson();
        locationModel = gson.fromJson(getIntent().getStringExtra("locationToEdit"), LocationModel.class);
        Log.i("on resume", locationModel.toString());

        ((TextView) findViewById(R.id.textViewTitle)).setText("Editing: " + locationModel.getName());
        editTextName.setText(locationModel.getName());
        editTextAddress.setText(locationModel.getAddress());
        editTextWebsite.setText(locationModel.getWebsite());
        editTextNote.setText(locationModel.getNote());
        ratingBar.setRating(locationModel.getRating());
        editTextVisited.setText(locationModel.getVisitedString());
        editTextLatitude.setText(locationModel.getLatitude().toString());
        editTextLongitude.setText(locationModel.getLongitude().toString());
    }

    void updateLocation() throws ParseException {
        String name = editTextName.getText().toString();
        String website = editTextWebsite.getText().toString();
        String note = editTextNote.getText().toString();
        String address = editTextAddress.getText().toString();
        Float rating = ratingBar.getRating();
        DateFormat format = new SimpleDateFormat("dd.MM.yyyy HH:mm");
        Date visited = format.parse(editTextVisited.getText().toString());
        Double latitude = Double.parseDouble(editTextLatitude.getText().toString());
        Double longitude = Double.parseDouble(editTextLongitude.getText().toString());
        try {
            LocationModel updatedLocation = new LocationModel(locationModel.getId(), name, address, website, note, rating, visited, latitude, longitude);
            db.locationDao().update(updatedLocation);
            Toast.makeText(EditActivity.this, "Location updated.", Toast.LENGTH_LONG).show();
            Log.i("tag", "Location updated.");
            finish();
        } catch (Exception e) {
            Toast.makeText(EditActivity.this, "Error editing location.", Toast.LENGTH_LONG).show();
        }
    }

    void deleteLocation() {
        try {
            db.locationDao().delete(locationModel);
            Toast.makeText(EditActivity.this, "Location deleted.", Toast.LENGTH_LONG).show();
            Log.i("tag", "location deleted");
            finish();
        } catch (Exception e) {
            Toast.makeText(EditActivity.this, "Error deleting location.", Toast.LENGTH_LONG).show();
        }
    }

    void popDialog() {
        AlertDialog.Builder builder = new AlertDialog.Builder(EditActivity.this);
        builder.setTitle("Deleting location");
        builder.setMessage("Are you sure you want to delete this location?");
        builder.setPositiveButton("Yes", new DialogInterface.OnClickListener() {
            public void onClick(DialogInterface dialog, int id) {
                deleteLocation();
            }
        });
        builder.setNegativeButton("No", new DialogInterface.OnClickListener() {
            public void onClick(DialogInterface dialog, int id) {
                dialog.dismiss();
            }
        });
        AlertDialog alert = builder.create();
        alert.show();
    }
}
