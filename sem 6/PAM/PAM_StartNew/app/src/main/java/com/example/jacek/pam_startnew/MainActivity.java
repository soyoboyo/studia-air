package com.example.jacek.pam_startnew;

import android.Manifest;
import android.app.Activity;
import android.content.ContentUris;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.provider.Contacts;
import android.support.v4.app.ActivityCompat;
import android.support.v7.app.AppCompatActivity;
import android.telephony.SmsManager;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import java.util.Locale;

public class MainActivity extends AppCompatActivity {

    Button btnContacts;
    Button btnSMS;
    Button btnMaps;
    Button btnNewActivity;

    EditText editTextContactID;
    EditText editTextSMSPhone;
    EditText editTextSMSMessage;
    EditText editTextCoordNS;
    EditText editTextCoordWE;
    EditText editTextNewActivity;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.SEND_SMS}, 1);

        btnContacts = (Button) findViewById(R.id.buttonContacts);
        btnSMS = (Button) findViewById(R.id.buttonSms);
        btnMaps = (Button) findViewById(R.id.buttonMaps);
        btnNewActivity = (Button) findViewById(R.id.buttonNewActivity);

        editTextContactID = (EditText) findViewById(R.id.editTextContactID);
        editTextSMSPhone = (EditText) findViewById(R.id.editTextSMSPhone);
        editTextSMSMessage = (EditText) findViewById(R.id.editTextSMSMessage);
        editTextCoordNS = (EditText) findViewById(R.id.editTextCoordNS);
        editTextCoordWE = (EditText) findViewById(R.id.editTextCoordWE);
        editTextNewActivity = (EditText) findViewById(R.id.editTextNewActivity);

        btnContacts.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Uri contactUri = ContentUris.withAppendedId(Contacts.People.CONTENT_URI, Integer.parseInt(editTextContactID.getText().toString()));
                Intent intent = new Intent(Intent.ACTION_VIEW, contactUri);
                startActivity(intent);
            }
        });

        btnSMS.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                sendSMS(editTextSMSPhone.getText().toString(), editTextSMSMessage.getText().toString());
            }
        });

        btnMaps.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String uri = String.format(Locale.ENGLISH, "geo:%f,%f", Float.parseFloat(editTextCoordNS.getText().toString()), Float.parseFloat(editTextCoordWE.getText().toString()));
                Intent intent = new Intent(Intent.ACTION_VIEW, Uri.parse(uri));
                startActivity(intent);
            }
        });

        btnNewActivity.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intentA1A2 = new Intent(MainActivity.this, NewActivity.class);
                Bundle myBundle = new Bundle();
                myBundle.putString("someText", editTextNewActivity.getText().toString());
                intentA1A2.putExtras(myBundle);
                startActivityForResult(intentA1A2, 101);
            }
        });
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if ((requestCode == 101) && (resultCode == Activity.RESULT_OK)) {
            Bundle myBundle = data.getExtras();
        }
    }

    private void sendSMS(String phoneNumber, String message) {
        SmsManager sms = SmsManager.getDefault();
        sms.sendTextMessage(phoneNumber, null, message, null, null);
        Toast.makeText(getApplicationContext(), "SMS sent.", Toast.LENGTH_LONG).show();
    }
}
