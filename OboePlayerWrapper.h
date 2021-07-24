//
// Created by slahuddin.ch on 6/29/2021.
//

#ifndef OBOEPLAYERWRAPPER_H
#define OBOEPLAYERWRAPPER_H


#include "RingBuffer.h"
#include <oboe/Oboe.h>

#include "logging_macros.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////  Configs //////////////////////////////////////////////////////////////////////
#define SAMPLING_RATE 48000


class OboePlayerWrapper{

public:
    int16_t sessionId;
    oboe::AudioStreamBuilder playbackBuilder;
    oboe::AudioStream *playbackStream;

    jnk0le::Ringbuffer<int16_t, 16384> ringBuffer;

public:

    OboePlayerWrapper();
    OboePlayerWrapper(int16_t ID);

    void openStream(int speakerID);
    void openStream();

    void setSession(int sessionId);

    void startStream();
    void stopStream();
};


#endif //OBOEPLAYERWRAPPER_H
