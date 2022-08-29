package com.example.supervisorandroid_v2;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.text.method.ScrollingMovementMethod;
import android.view.View;
import android.widget.CheckBox;
import android.widget.SeekBar;
import android.widget.TextView;


public class MainActivity extends AppCompatActivity {
    public long  controPtr = 0; //pointer to top C++ class object

     // Used to load the C++ library on application startup.
    static {
        System.loadLibrary("native-lib");
        System.loadLibrary("ControlSupervisor");
        System.loadLibrary("DataCommunication");
        System.loadLibrary("DataCommunicationAndroid");
        System.loadLibrary("List");
        System.loadLibrary("Node");
        System.loadLibrary("ProcessingDataList");
    }
    //resposible to define the system on startup
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        tv.setMovementMethod(new ScrollingMovementMethod());

        controPtr = createControl(); //here a create a top C++ class object to be manipulate
                                     //the pointer controPtr allow to keep the object live during APP execution
    }
    //function that link with button CONNECT on Android Display
    public void btnConnect(View v) {
        TextView tv = findViewById(R.id.sample_text);  //used to print the string returned from C++ Supervisor functionality
        tv.setMovementMethod(new ScrollingMovementMethod());  //used to add scroll functionality to Text Area
        tv.setText(connect(controPtr)); //call connect function wrapper that to will uses C++ plus method readData() from ControllerSupervisor Class,
                                        // and print the returned string in TextView

    }
    //function that link with button HOURS ON on Android Display
    public void btnHoursOn(View v) {
        SeekBar startDatseekBar;
        SeekBar endDatseekBar;
        SeekBar monthNumberSeekBar;
        CheckBox monthCheck;

        startDatseekBar = (SeekBar)findViewById(R.id.startDate);  //to link SeekBar Star Date from display to manipulate
        endDatseekBar = (SeekBar)findViewById(R.id.endDate);  //to link SeekBar End Date from display to manipulate
        monthCheck = (CheckBox)findViewById(R.id.monthCheck); //to link CheckBox Month from display to manipulate
        monthNumberSeekBar = (SeekBar)findViewById((R.id.monthNumber)); //to link SeekBar Month Number from display to manipulate

        int start = startDatseekBar.getProgress(); //get SeekBar Star Date value manipulate on display
        int end = endDatseekBar.getProgress(); //get SeekBar End Date value manipulate on display
        int monthN = monthNumberSeekBar.getProgress(); //get SeekBar Month Number value manipulate on display
        boolean ckMonth = monthCheck.isChecked(); //get CheckBox state (TRUE OR FALSE) value manipulate on display


        TextView tv = findViewById(R.id.sample_text);  //used to print the string returned from C++ Supervisor functionality
        tv.setMovementMethod(new ScrollingMovementMethod()); //used to add scroll functionality to Text Area
        tv.setText(countHour(controPtr, start, end, ckMonth, monthN)); //call countHour function wrapper that to will uses C++ plus method readData() from ControllerSupervisor Class,
                                                                        // and print the returned string in TextView


    }
    //function that link with button LIST BY DATE on Android Display
    public void btnListDate(View v) {
        SeekBar startDatseekBar;
        SeekBar endDatseekBar;
        SeekBar monthNumberSeekBar;
        CheckBox monthCheck;

        startDatseekBar = (SeekBar)findViewById(R.id.startDate); //to link SeekBar Star Date from display to manipulate
        endDatseekBar = (SeekBar)findViewById(R.id.endDate); //to link SeekBar End Date from display to manipulate
        monthCheck = (CheckBox)findViewById(R.id.monthCheck); //to link CheckBox Month from display to manipulate
        monthNumberSeekBar = (SeekBar)findViewById((R.id.monthNumber)); //to link SeekBar Month Number from display to manipulate

        int start = startDatseekBar.getProgress(); //get SeekBar Star Date value manipulate on display
        int end = endDatseekBar.getProgress();   //get SeekBar End Date value manipulate on display
        int monthN = monthNumberSeekBar.getProgress(); //get SeekBar Month Number value manipulate on display
        boolean ckMonth = monthCheck.isChecked(); //get CheckBox state (TRUE OR FALSE) value manipulate on display


        TextView tv = findViewById(R.id.sample_text); //used to print the string returned from C++ Supervisor functionality
        tv.setMovementMethod(new ScrollingMovementMethod()); //used to add scroll functionality to Text Area
        tv.setText(listDate(controPtr, start, end, ckMonth, monthN)); //call listDate function wrapper that to will uses C++ plus method readData() from ControllerSupervisor Class,
                                                                     // and print the returned string in TextView


    }
    //function that link with button DISPLAY ALL on Android Display
    public void btnDisplayAll(View v) {
        TextView tv = findViewById(R.id.sample_text); //used to print the string returned from C++ Supervisor functionality
        tv.setMovementMethod(new ScrollingMovementMethod()); //used to add scroll functionality to Text Area
        tv.setText(displayAll(controPtr));  //call displayAll function wrapper that to will uses C++ plus method readData() from ControllerSupervisor Class,
                                           // and print the returned string in TextView
    }
    //function that link with button EMULATE on Android Display
    public void btnEmulate(View v) {
        emulateComm(controPtr);  //call emulateComm function wrapper that to will uses C++ plus method readData() from ControllerSupervisor Class,
                                 // and print the returned string in TextView
                                 //The objective of this function is create a false list to be possible test the APP

        //TextView tv = findViewById(R.id.sample_text);
        //tv.setText(displayAll(controPtr));
    }



    /**
     * A native method that is implemented by the native library (wrapper),
     * which is packaged with this application.
     */
    public native String connect(long numberptr);
    public native String displayAll(long numberptr);
    public native String countHour(long numberptr, int start, int end, boolean month, int monthNumber);
    public native String listDate(long numberptr, int start, int end, boolean month, int monthNumber);
    public native String emulateComm(long numberptr);
    public native long createControl();
}