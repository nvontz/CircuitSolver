package com.example.sdcircuitsolver;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;


public class MainActivity extends AppCompatActivity {

    EditText e1;
    Resistor r;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        e1 = (EditText) findViewById(R.id.editText);
        r = new Resistor("R1", "in", "gnd", 10.0 );
        //String s = r.printResistorString(r);
    }

    public void send(View view)
    {
        // Gosh this sucks but it is what it is
        String file = "*Netlist solution\nV1 in gnd 10; 10Volt source\nR1 in in2 5; 5 Ohm Resistor\nR2 in2 gnd 20; 20 Ohm Resistor\n\n.op ; DC analysis";
        System.out.println(file.length());
        MessageSender messageSender = new MessageSender();
        messageSender.execute(file);
    }
}