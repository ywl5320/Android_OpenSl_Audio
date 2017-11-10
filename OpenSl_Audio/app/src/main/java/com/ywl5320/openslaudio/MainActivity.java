package com.ywl5320.openslaudio;

import android.content.res.AssetManager;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("openslaudioywl5320");
    }

    AssetManager assetManager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        assetManager = getAssets();


    }

    public native void playAudioByOpenSL_assets(AssetManager assetManager, String filename);

    public native void playAudioByOpenSL_uri(String uri);

    public native void playAudioByOpenSL_pcm(String pamPath);


    public void play_assets(View view) {
        playAudioByOpenSL_assets(assetManager, "mydream.m4a");
    }


    public void play_uri(View view) {
        playAudioByOpenSL_uri("http://mpge.5nd.com/2015/2015-11-26/69708/1.mp3");
    }

    public void play_pcm(View view) {

        String path = Environment.getExternalStorageDirectory().getAbsolutePath() + "/mydream.pcm";
        Log.d("ywl5320", path);
        playAudioByOpenSL_pcm(path);
    }
}
