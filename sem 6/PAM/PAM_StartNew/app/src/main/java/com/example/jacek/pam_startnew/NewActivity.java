package com.example.jacek.pam_startnew;

import android.app.Activity;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class NewActivity extends AppCompatActivity {

    TextView dataRecieved;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_new);

        dataRecieved = (TextView) findViewById(R.id.textView);
        Intent myLoclaIntent = getIntent();
        Bundle myBundle = myLoclaIntent.getExtras();
        dataRecieved.setText(myBundle.getString("someText"));

        setResult(Activity.RESULT_OK, myLoclaIntent);


    }
}
