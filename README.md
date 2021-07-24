# Oboe_Wrapper_Cpp
Oboe Wrapper for c++ 

This is a simple c++ Oboe Recorder and Player Wrapper


It Records the Audio using Oboe Recorder
Stores the Audio Frames in RingBuffer


## Record Audio in C++
To record the Audio

clone the git oboe repository and place it ib your project.

Create an instance of OboeRecorderWrapper

Call the following functions

    void openStream();

    void setSession(int x);

    void startStream();
    
These functions will automatically starts the recording using OBoe.

OnAudioReady is a callback function. 

It will automatically be called from Oboe.

The Data will start comming in RingBuffer

Note: I am getting device Audio session ID from Java
If something is not working try setting session ID

## To Play the recorder Audio 

Create an Instance of OboePLayerWrapper

Call the following 

    void openStream();

    void setSession(int x);

    void startStream();
    
 the session ID should be same for player and Recorder.
 
 To start Recoding 
 
 start removing data from Recoder RingBuffer and put it for direct play
 
 The code for Directplay is
 
    int16_t arr[FRAMES_PER_CALLBACK];
    whlie (True)
    {
        //Remove data from RingBuffer and place it in arr to play
        
        if (mOboeRecoder.ingbuffer.readAvailable() >= FRAMES_PER_CALLBACK)
        {
            int16_t data = 0;
            if (mOboeRecorder.ringBuffer.remove(&data))
            {
                arr[i] = data;
            }
            else
            {
                LOGE("NOT ENOUGH DATA");
            }
        }
        
     
        mOboePLayer.playbackStream->write(arr, FRAMES_PER_CALLBACK, 1);
    
    }