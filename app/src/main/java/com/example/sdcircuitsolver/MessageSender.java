package com.example.sdcircuitsolver;

import android.os.AsyncTask;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;

public class MessageSender extends AsyncTask<String, Void, Void>
{
    Socket s;
    PrintWriter pw;

    @Override
    protected Void doInBackground(String... voids)
    {
        String message = voids[0];
        System.out.println(message);
        try {
            s = new Socket("10.150.114.142", 8080);
            pw = new PrintWriter(s.getOutputStream());
            pw.write(message);
            pw.flush();
            pw.close();
            s.close();

        }catch (IOException e)
        {
            e.printStackTrace();
        }

        return null;
    }

}
