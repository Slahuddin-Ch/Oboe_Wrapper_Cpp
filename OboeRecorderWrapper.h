//
// Created by slahuddin.ch on 6/29/2021.
//

#ifndef OBOERECORDERWRAPPER_H
#define OBOERECORDERWRAPPER_H


#include "RingBuffer.h"
#include <oboe/Oboe.h>

#include "logging_macros.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////  Configs //////////////////////////////////////////////////////////////////////

#define SAMPLING_RATE 48000
#define FRAMES_PER_CALLBACK 480

class OboeRecorderWrapper : public oboe::AudioStreamCallback{
public:
    bool start = false;

    oboe::AudioStreamBuilder recordingBuilder;
    oboe::AudioStream *recordStream;
    jnk0le::Ringbuffer<int16_t, 16384> ringBuffer;
    int16_t sessionID;
//    resampler::MultiChannelResampler *multiChannelResampler;


public:

    OboeRecorderWrapper();
    OboeRecorderWrapper(int16_t ID);

    void openStream();

    void setSession(int16_t sessionId);

    void startStream();
    void stopStream();

    //ToDO not implemented yet

    void setSessionID(int16_t ID);
    int16_t getSessionID();

    oboe::DataCallbackResult
    onAudioReady(oboe::AudioStream *oboeStream, void *audioData, int32_t numFrames) override;

    void getData();


    void close();
};


#endif //OBOERECORDERWRAPPER_H
