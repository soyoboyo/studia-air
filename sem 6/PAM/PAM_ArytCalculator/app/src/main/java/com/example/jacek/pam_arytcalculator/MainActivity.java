package com.example.jacek.pam_arytcalculator;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import org.w3c.dom.Text;

import java.util.ArrayList;
import java.util.Formatter;
import java.util.List;


public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    private TextView input;
    private TextView output;
    private List<Button> buttons;
    private Double arg1 = 0.0;
    private Double arg2 = 0.0;
    private String operation = new String("");
    private TextView history;


    @Override

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        input = (TextView) findViewById(R.id.input);
        output = (TextView) findViewById(R.id.output);
        history = (TextView) findViewById(R.id.history);
        findButtons();
        for (Button btn : buttons) {
            btn.setOnClickListener(this);
        }
        operation = "";

    }

    public void findButtons() {
        buttons = new ArrayList<Button>();
        buttons.add((Button) findViewById(R.id.button0));
        buttons.add((Button) findViewById(R.id.button1));
        buttons.add((Button) findViewById(R.id.button2));
        buttons.add((Button) findViewById(R.id.button3));
        buttons.add((Button) findViewById(R.id.button4));
        buttons.add((Button) findViewById(R.id.button5));
        buttons.add((Button) findViewById(R.id.button6));
        buttons.add((Button) findViewById(R.id.button7));
        buttons.add((Button) findViewById(R.id.button8));
        buttons.add((Button) findViewById(R.id.button9));
        buttons.add((Button) findViewById(R.id.buttonC));
        buttons.add((Button) findViewById(R.id.buttonDiv));
        buttons.add((Button) findViewById(R.id.buttonMul));
        buttons.add((Button) findViewById(R.id.buttonMinus));
        buttons.add((Button) findViewById(R.id.buttonPlus));
        buttons.add((Button) findViewById(R.id.buttonEquals));
    }

    public void setArgValue(Double digit) {
        if (arg1 == 0.0 && arg2 == 0.0) {
            input.setText(String.format("%.0f", digit));
            output.setText("");
        }
        if (operation.equals("")) {
            arg1 *= 10.0;
            arg1 += digit;
            Log.i("TAG", "arg1 " + digit.toString());
        } else {
            arg2 *= 10.0;
            arg2 += digit;
            Log.i("TAG", "arg2 " + digit.toString());
        }
    }

    public void calculate() {
        Double result = 0.0;
            switch (operation) {
                case "+":
                    result = arg1 + arg2;
                    break;
                case "-":
                    result = arg1 - arg2;
                    break;
                case "x":
                    result = arg1 * arg2;
                    break;
                case "/":
                    result = arg1 / arg2;
                    break;
                default:
                    output.setText(R.string.no_operation);
                    break;

            }
        if (!result.toString().equals("Infinity")) {
            System.out.println("wynik " + result.toString());
            String r = Double.toString(result);
            output.setText(r);
            history.append(input.getText().toString() + output.getText().toString() + "\n");
        } else {
            output.setText("Nie można dzielić przez 0!");
        }


        operation = "";
        arg1 = 0.0;
        arg2 = 0.0;
        result = 0.0;
    }

    @Override
    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.button0:
                input.append("0");
                setArgValue(0.0);
                break;
            case R.id.button1:
                input.append("1");
                setArgValue(1.0);
                break;
            case R.id.button2:
                input.append("2");
                setArgValue(2.0);
                break;
            case R.id.button3:
                input.append("3");
                setArgValue(3.0);
                break;
            case R.id.button4:
                input.append("4");
                setArgValue(4.0);
                break;
            case R.id.button5:
                input.append("5");
                setArgValue(5.0);
                break;
            case R.id.button6:
                input.append("6");
                setArgValue(6.0);
                break;
            case R.id.button7:
                input.append("7");
                setArgValue(7.0);
                break;
            case R.id.button8:
                input.append("8");
                setArgValue(8.0);
                break;
            case R.id.button9:
                input.append("9");
                setArgValue(9.0);
                break;
            case R.id.buttonC:
                input.setText("");
                output.setText("");
                arg1 = 0.0;
                arg2 = 0.0;
                operation = "";
                break;
            case R.id.buttonDiv:
                input.append(" / ");
                operation = "/";
                break;
            case R.id.buttonMul:
                input.append(" x ");
                operation = "x";
                break;
            case R.id.buttonMinus:
                input.append(" - ");
                operation = "-";
                break;
            case R.id.buttonPlus:
                input.append(" + ");
                operation = "+";
                break;
            case R.id.buttonEquals:
                input.append(" = ");
                calculate();
                break;

        }
    }
}