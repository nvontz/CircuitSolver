package com.example.sdcircuitsolver;

public class Resistor {
    String name;
    String positiveNode;
    String negativeNode;
    double val;

    public Resistor(String name, String positiveNode, String negativeNode, double val)
    {
        this.name = name;
        this.positiveNode = positiveNode;
        this.negativeNode = negativeNode;
        this.val = val;
    }

    public String printResistorString(Resistor r)
    {
        //horribly done, just testing
        return r.name + " " + r.positiveNode + " " + r.negativeNode + " " + r.val;
    }

}
