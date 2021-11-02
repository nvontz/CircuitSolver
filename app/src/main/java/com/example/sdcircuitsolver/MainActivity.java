package com.example.sdcircuitsolver;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


    }

    public void onButtonClick(View view)
    {
        TextView txtWelcomeMsg = findViewById(R.id.welcomeMsg);
        txtWelcomeMsg.setText("Will setup TCP connection and send message");
    }
}