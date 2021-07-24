//
// Created by slahuddin.ch on 6/29/2021.
//

#include "../include/OboeRecorderWrapper.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
OboeRecorderWrapper::OboeRecorderWrapper() : sessionID(0){}

////////////////////////////////////////////////////////////////////////////////////////////////////
OboeRecorderWrapper::OboeRecorderWrapper(int16_t ID) : sessionID(ID){}

////////////////////////////////////////////////////////////////////////////////////////////////////
void OboeRecorderWrapper::openStream() {
    recordingBuilder.setDirection(oboe::Direction::Input);
    recordingBuilder.setAudioApi(oboe::AudioApi::AAudio);
    recordingBuilder.setSampleRate(SAMPLING_RATE);
    recordingBuilder.setChannelCount(oboe::ChannelCount::Mono);
    recordingBuilder.setFormat(oboe::AudioFormat::I16);
    recordingBuilder.setFramesPerDataCallback(FRAMES_PER_CALLBACK);
    recordingBuilder.setInputPreset(oboe::InputPreset::VoiceCommunication);
    recordingBuilder.setContentType(oboe::ContentType::Speech);
    recordingBuilder.setUsage(oboe::Usage::VoiceCommunication);
    recordingBuilder.setCallback(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void OboeRecorderWrapper::setSession(int16_t sessionId) {
    recordingBuilder.setSessionId(static_cast<oboe::SessionId>(sessionId));
    oboe::Result recordStreamResult = recordingBuilder.openStream(&recordStream);

    if (recordStreamResult != oboe::Result::OK) {
        LOGE("Error opening stream: %s", convertToText(recordStreamResult));
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void OboeRecorderWrapper::startStream()
{
    start = true;
    oboe::Result startStream = recordStream->requestStart();
    if (startStream != oboe::Result::OK) {
        LOGE("Unable TO START STREAM %s", convertToText(startStream));
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
void OboeRecorderWrapper::stopStream()
{
    start = false;
    oboe::Result startStream = recordStream->requestStop();
    if (startStream != oboe::Result::OK) {
        LOGE("Unable TO START STREAM %s", convertToText(startStream));
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////
void OboeRecorderWrapper::setSessionID(int16_t ID)
{
    sessionID = ID;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
int16_t OboeRecorderWrapper::getSessionID()
{
    return sessionID;
}

static long int x = 0;

oboe::DataCallbackResult
OboeRecorderWrapper::onAudioReady(oboe::AudioStream *oboeStream, void *audioData, int32_t numFrames)
{

//    LOGE("TIME----> FRAME NUMBER %s \n", std::to_string(++x).c_str() );

    oboe::DataCallbackResult callbackResult = oboe::DataCallbackResult::Continue;

    auto result = static_cast<int16_t *>(audioData);


    for (int i = 0; i < numFrames; i++) {
            ringBuffer.insert(result[i]);
        }

    return callbackResult;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////