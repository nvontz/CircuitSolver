package com.example.sdcircuitsolver;

import java.util.ArrayList;

public class ElectricalComponent {



    public String name;
    public String positiveNode;
    public String negativeNode;
    public double val;
    public MainActivity.electricalType type;

    public ElectricalComponent(
            MainActivity.electricalType type,    /* Resistor, capacitor, voltage source, etc */
            String name,            /* Name of component, ie R1 */
            String positiveNode,    /* plus node used for nodal analysis and netlist */
            String negativeNode,    /* negative node used for nodal analysis and netlist */
            double val)             /* measurement value, Farads, Ohms, etc */
    {
        this.type = type;
        this.name = name;
        this.positiveNode = positiveNode;
        this.negativeNode = negativeNode;
        this.val = val;
    }



}
