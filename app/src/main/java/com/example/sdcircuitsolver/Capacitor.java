package com.example.sdcircuitsolver;

public class Capacitor { /* worth writing interface for component? */
    String name;
    String positiveNode;
    String negativeNode;
    double val;

    //Constructor for component type
    public Capacitor(String name, String positiveNode, String negativeNode, double val)
    {
        this.name = name;
        this.positiveNode = positiveNode;
        this.negativeNode = negativeNode;
        this.val = val;
    }
}
