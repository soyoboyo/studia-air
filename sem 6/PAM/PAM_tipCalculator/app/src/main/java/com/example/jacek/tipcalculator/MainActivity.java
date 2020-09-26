package com.example.jacek.tipcalculator;

import android.content.Context;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private int duration = Toast.LENGTH_SHORT;
    private Context context;
    private RadioGroup radioGroup;
    private RadioButton radioButton;
    private EditText editText;
    private TextView textView;
    private Button button;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        context = getApplicationContext();
        Button button = findViewById(R.id.button);
        radioGroup = (RadioGroup) findViewById(R.id.radioGroup);
        radioGroup.check(R.id.usd);
        editText = findViewById(R.id.editText);
        textView = findViewById(R.id.textView);
        button.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {

                Integer selectedId = radioGroup.getCheckedRadioButtonId();
                radioButton = (RadioButton) findViewById(selectedId);
//                Toast.makeText(context, selectedId.toString(), Toast.LENGTH_SHORT).show();

                String currency = radioButton.getText().toString();
                Double input = Double.parseDouble(editText.getText().toString());
                switch (currency) {
                    case "USD": {
                        input *= 3.39;
                        textView.setText(editText.getText().toString() + " USD = " + input.toString() + " PLN");
                        Log.i( "TAG", "usd");
                        break;
                    }
                    case "EUR": {
                        input *= 4.21;
                        textView.setText(editText.getText().toString() + " EUR = " + input.toString() + " PLN");
                        Log.i( "TAG", "eur");
                        break;
                    }
                }
//                Toast.makeText(context, radioButton.getText(), Toast.LENGTH_SHORT).show();
//                Log.i( "info", "przeliczono");
//                Log.d( "info", "przeliczono");
//                Log.v( "info", "przeliczono");
//                Log.e( "info", "przeliczono");
//                Log.i( "info", "przeliczono");
//
            }
        });
    }
}
