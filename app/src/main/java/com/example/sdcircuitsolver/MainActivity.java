package com.example.sdcircuitsolver;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.List;


public class MainActivity extends AppCompatActivity {

    EditText e1;
    //Resistor r;

    ArrayList<ElectricalComponent> componentList;

    public enum electricalType {
        RESISTOR,
        CAPACITOR,
        VOLTAGE_SOURCE,
        CURRENT_SOURCE
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        e1 = (EditText) findViewById(R.id.editText);
        //r = new Resistor("R1", "in", "gnd", 10.0 );
        //String s = r.printResistorString();

        componentList = new ArrayList<ElectricalComponent>();
        ElectricalComponent e1 =
                new ElectricalComponent(electricalType.RESISTOR, "R1", "in1", "in2", 1.2);
        componentList.add(e1);

        ElectricalComponent e2 =
                new ElectricalComponent(electricalType.RESISTOR, "R2", "in2", "gnd", 5.2);
        componentList.add(e2);

        ElectricalComponent e3 =
                new ElectricalComponent(electricalType.VOLTAGE_SOURCE, "Vin", "in1", "gnd", 5.0);
        componentList.add(e3);

        String netlist = WriteToNetlist(componentList);


        System.out.println("\n\n\n" + netlist + "\n\n\n");
    }

    public void send(View view)
    {
        // Gosh this sucks but it is what it is
        String file = "*Netlist solution\nV1 in gnd 10; 10Volt source\nR1 in in2 5; 5 Ohm Resistor\nR2 in2 gnd 20; 20 Ohm Resistor\n\n.op ; DC analysis";
        System.out.println(file.length());
        MessageSender messageSender = new MessageSender();
        messageSender.execute(file);
    }

    public String WriteToNetlist(ArrayList<ElectricalComponent> compList)
    {
        String s = "*Netlist Solution\n";
        String temp;
        ElectricalComponent tempEC;
        for(int i = 0; i < compList.size(); i++)
        {
            tempEC = compList.get(i);
            temp = tempEC.name + " " + tempEC.positiveNode + " " + tempEC.negativeNode + " " + tempEC.val + "\n";
            s = s.concat(temp);
        }
        return s;
    }
}