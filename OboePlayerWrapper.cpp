//
// Created by slahuddin.ch on 6/29/2021.
//

#include "../include/OboePlayerWrapper.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
OboePlayerWrapper::OboePlayerWrapper() : sessionId(0) {}


////////////////////////////////////////////////////////////////////////////////////////////////////
OboePlayerWrapper::OboePlayerWrapper(int16_t ID) : sessionId(ID) {}


////////////////////////////////////////////////////////////////////////////////////////////////////
void OboePlayerWrapper::openStream(int speakerID)
{
    playbackBuilder.setDeviceId(speakerID);
    playbackBuilder.setDirection(oboe::Direction::Output);
    playbackBuilder.setAudioApi(oboe::AudioApi::AAudio);
    playbackBuilder.setSampleRate(SAMPLING_RATE);
    playbackBuilder.setChannelCount(oboe::ChannelCount::Mono);
    playbackBuilder.setFormat(oboe::AudioFormat::I16);
    playbackBuilder.setInputPreset(oboe::InputPreset::VoiceCommunication);
    playbackBuilder.setContentType(oboe::ContentType::Speech);
    playbackBuilder.setUsage(oboe::Usage::VoiceCommunication);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void OboePlayerWrapper::openStream()
{
    playbackBuilder.setDirection(oboe::Direction::Output);
    playbackBuilder.setAudioApi(oboe::AudioApi::AAudio);
    playbackBuilder.setSampleRate(SAMPLING_RATE);
    playbackBuilder.setChannelCount(oboe::ChannelCount::Mono);
    playbackBuilder.setFormat(oboe::AudioFormat::I16);
    playbackBuilder.setInputPreset(oboe::InputPreset::VoiceCommunication);
    playbackBuilder.setContentType(oboe::ContentType::Speech);
    playbackBuilder.setUsage(oboe::Usage::VoiceCommunication);
}


////////////////////////////////////////////////////////////////////////////////////////////////////
void OboePlayerWrapper::setSession(int sessionId)
{
    playbackBuilder.setSessionId(static_cast<oboe::SessionId>(sessionId));
    oboe::Result recordStreamResult = playbackBuilder.openStream(&playbackStream);

    if (recordStreamResult != oboe::Result::OK) {
        LOGE("Error opening stream: %s", convertToText(recordStreamResult));
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
void OboePlayerWrapper::startStream()
{
    oboe::Result startStream = playbackStream->requestStart();

    if (startStream != oboe::Result::OK) {
        LOGE("Unable TO START RECORD STREAM %s", convertToText(startStream));
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
void OboePlayerWrapper::stopStream()
{
    oboe::Result startStream = playbackStream->requestStop();

    if (startStream != oboe::Result::OK) {
        LOGE("Unable TO START RECORD STREAM %s", convertToText(startStream));
    }
}



////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////