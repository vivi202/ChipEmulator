//
// Created by vincenzo on 22/10/22.
//

#include "SoundEngine.h"
#include "iostream"
SoundEngine* SoundEngine::instance= nullptr;
SoundEngine::SoundEngine() {
    if(SDL_Init(SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0){
        SDL_Log("Unable to initialize SDL AudioSystem: %s", SDL_GetError());
        exit(1);
    }
    SDL_memset(&want,0,sizeof(want));
    want.freq=samplePerSecond;
    want.format=audioFormat;
    want.channels=audioChannels;
    want.samples=sampleBufferSize;
    want.callback= SoundEngine::forwardCallback;
    want.userdata= this;
    audioDevice = SDL_OpenAudioDevice(nullptr,0,&want,&have,
                                      SDL_AUDIO_ALLOW_FORMAT_CHANGE);
}

SoundEngine::~SoundEngine() {
    SDL_CloseAudioDevice(audioDevice);
}

void SoundEngine::startPlaying() const {
    SDL_PauseAudioDevice(audioDevice,0);//SDL start calling the callback function this result in sound.
}

void SoundEngine::stopPlaying() const {
    SDL_PauseAudioDevice(audioDevice,1);//SDL stop calling the callback function this result in silence.
}


void SoundEngine::addSynth(WaveTableSynth *s,float wantedFreq) {
    s->generateTable(synthTableSize);
    s->setWantedFreq(wantedFreq);
    synthesizers.push_front(s);
}

void SoundEngine::removeSynth(WaveTableSynth *s) {
    synthesizers.remove(s);
}

void SoundEngine::forwardCallback(void *userdata, Uint8 *stream, int len) {
    //forward audioCallback to audioCallback memberFunction
    static_cast<SoundEngine*>(userdata)->audioCallback(stream,len);
}

void SoundEngine::audioCallback(Uint8 *stream, int len) {
    auto* signedStream=reinterpret_cast<int16_t *>(stream);
    uint32_t samples = len / sizeof(int16_t);
    for (int i = 0; i < samples; i+=2) {
        float left=0;
        float right=0;
        for (auto &synth :synthesizers) {
            synth->renderAudioSample(left,right);
        }
        signedStream[i]=(int16_t)(32767.0f * left / (float)synthesizers.size());
        signedStream[i+1]=(int16_t)(32767.0f * left / (float)synthesizers.size());;
    }
}

SoundEngine *SoundEngine::getInstance() {
    if(!instance){
        instance= new SoundEngine;
    }
    return instance;
}


