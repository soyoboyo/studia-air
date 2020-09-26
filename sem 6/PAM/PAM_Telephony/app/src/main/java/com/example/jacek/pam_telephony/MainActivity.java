package com.example.jacek.pam_telephony;

import android.Manifest;
import android.annotation.TargetApi;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.IntentFilter;
import android.content.pm.PackageManager;
import android.location.LocationManager;
import android.os.Build;
import android.os.Bundle;
import android.provider.Telephony;
import android.support.v4.app.ActivityCompat;
import android.support.v7.app.AppCompatActivity;
import android.telephony.SmsManager;
import android.telephony.TelephonyManager;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import org.w3c.dom.Text;

import java.util.List;

public class MainActivity extends AppCompatActivity {

    Button btnSMS;
    Button btnInfo;
    EditText editTextSMS;
    TextView textViewInfo;
    private static final int PERMISSION_REQUEST_CODE = 1;

    private SmsBroadcastReceiver smsBroadcastReceiver;
    @TargetApi(Build.VERSION_CODES.O)
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        btnSMS = (Button) findViewById(R.id.buttonSMS);
        btnInfo = (Button) findViewById(R.id.buttonInfo);
        editTextSMS = (EditText) findViewById(R.id.editTextSMS);
        textViewInfo = (TextView) findViewById(R.id.textViewInfo);
        final TelephonyManager telMgr = (TelephonyManager) this.getSystemService(Context.TELEPHONY_SERVICE);
        final LocationManager locationManager = (LocationManager) this.getSystemService(Context.LOCATION_SERVICE);

        if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.M) {
            Log.d("permission", "permission denied to SEND_SMS - requesting it");
            String[] permissions = {Manifest.permission.SEND_SMS, Manifest.permission.READ_PHONE_STATE, Manifest.permission.READ_SMS, Manifest.permission.ACCESS_FINE_LOCATION};
            ActivityCompat.requestPermissions(this, permissions, PERMISSION_REQUEST_CODE);
        }

        btnSMS.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String number = "1354329875";
                sendSMS(number, editTextSMS.getText().toString());
            }
        });

        btnInfo.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (ActivityCompat.checkSelfPermission(MainActivity.this, Manifest.permission.READ_PHONE_STATE) == PackageManager.PERMISSION_GRANTED) {
                    String imei = telMgr.getImei();
                    Integer phoneType = telMgr.getPhoneType();
                    Integer simState = telMgr.getSimState();
                    Integer callState = telMgr.getCallState();
                    Integer networkType = telMgr.getNetworkType();
                    String subscriberID = telMgr.getSubscriberId();
                    Integer dataActivity = telMgr.getDataActivity();
                    Integer dataState = telMgr.getDataState();
                    String softwareVersion = telMgr.getDeviceSoftwareVersion();
                    textViewInfo.setText(
                            "PHONE TYPE: " + getPhoneTypeString(phoneType) + "\n" +
                            "IMEI: " + imei + "\n" +
                            "SIM STATE: " + getSimStateString(simState) + "\n" +
                            "CALL STATE " + getCallStateString(callState) + "\n" +
                            "NETWORK TYPE: " + getNetworkTypeString(networkType) + "\n" +
                            "SUBSCRIBER ID: " + subscriberID + "\n" +
                            "DATA ACTIVITY: " + getDataActivityString(dataActivity) + "\n" +
                    "DATA STATE: " + getDataStateString(dataState) + "\n" +
                    "SOFTWARE VERSION: "+ softwareVersion + "\n");
                    return;
                }
            }
        });
    }
    private void createSMSLis() {
        smsBroadcastReceiver = new SmsBroadcastReceiver("123456789", ":AutoSMS:");
        registerReceiver(smsBroadcastReceiver, new IntentFilter(Telephony.Sms.Intents.SMS_RECEIVED_ACTION));
        smsBroadcastReceiver.setListener(new SmsBroadcastReceiver.Listener(){
            @Override
            public void onTextReceived(String text){
                Log.i("sms reciever", "text");
            }
        });
    }
    private void sendSMS(String phoneNumber, String message) {
        SmsManager sms = SmsManager.getDefault();
        sms.sendTextMessage(phoneNumber, null, message, null, null);
        Toast.makeText(getApplicationContext(), "SMS sent.", Toast.LENGTH_LONG).show();
    }

    private String getCallStateString(Integer callState) {
        switch (callState) {
            case TelephonyManager.CALL_STATE_IDLE:
                return "IDLE";
            case TelephonyManager.CALL_STATE_OFFHOOK:
                return "OFF HOOK";
            case TelephonyManager.CALL_STATE_RINGING:
                return "RINGING";
            default:
                return callState.toString();
        }
    }

    private String getPhoneTypeString(Integer phoneType) {
        switch (phoneType) {
            case TelephonyManager.PHONE_TYPE_NONE:
                return "none";
            case TelephonyManager.PHONE_TYPE_GSM:
                return "GSM";
            case TelephonyManager.PHONE_TYPE_CDMA:
                return "CDMA";
            case TelephonyManager.PHONE_TYPE_SIP:
                return "SIP";
            default:
                return phoneType.toString();
        }
    }

    private String getNetworkTypeString(Integer networkType) {
        switch (networkType) {
            case TelephonyManager.NETWORK_TYPE_LTE:
                return "LTE";
            default:
                return networkType.toString();
        }
    }

    private String getSimStateString(Integer simState) {
        switch (simState) {
            case TelephonyManager.SIM_STATE_UNKNOWN:
                return "UNKNOWN";
            case TelephonyManager.SIM_STATE_ABSENT:
                return "ABSENT";
            case TelephonyManager.SIM_STATE_PIN_REQUIRED:
                return "PIN REQUIRED";
            case TelephonyManager.SIM_STATE_PUK_REQUIRED:
                return "PUK REQUIRED";
            case TelephonyManager.SIM_STATE_NETWORK_LOCKED:
                return "NETWORK LOCKED";
            case TelephonyManager.SIM_STATE_READY:
                return "READY";
            case TelephonyManager.SIM_STATE_NOT_READY:
                return "NOT READY";
            case TelephonyManager.SIM_STATE_PERM_DISABLED:
                return "PERM DISABLED";
            case TelephonyManager.SIM_STATE_CARD_IO_ERROR:
                return "IO ERROR";
            case TelephonyManager.SIM_STATE_CARD_RESTRICTED:
                return "RESTRICTED";
            default:
                return simState.toString();
        }
    }

    private String getDataActivityString(Integer dataActivity) {
        switch (dataActivity) {
            case TelephonyManager.DATA_ACTIVITY_NONE:
                return "NONE";
            case TelephonyManager.DATA_ACTIVITY_IN:
                return "IN";
            case TelephonyManager.DATA_ACTIVITY_OUT:
                return "OUT";
            case TelephonyManager.DATA_ACTIVITY_INOUT:
                return "IN-OUT";
            case TelephonyManager.DATA_ACTIVITY_DORMANT:
                return "DORMANT";
            default:
                return dataActivity.toString();
        }
    }

    private String getDataStateString(Integer dataState) {
        switch (dataState) {
            case TelephonyManager.DATA_DISCONNECTED:
                return "DISCONNECTED";
            case TelephonyManager.DATA_CONNECTING:
                return "CONNECTIONG";
            case TelephonyManager.DATA_CONNECTED:
                return "CONNECTED";
            case TelephonyManager.DATA_SUSPENDED:
                return "SUSPENDED";
            default:
                return dataState.toString();
        }
    }
}
