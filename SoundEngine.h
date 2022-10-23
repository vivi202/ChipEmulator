//
// Created by vincenzo on 22/10/22.
//

#ifndef CHIPEMULATOR_SOUNDENGINE_H
#define CHIPEMULATOR_SOUNDENGINE_H

#include "SDL.h"
#include "Synth/WaveTableSynth.h"
#include "Synth/SineWaveTableSynth.h"
#include <list>
class SoundEngine {
public:
    static SoundEngine* getInstance();
    static const int samplePerSecond=48000;
    void startPlaying() const;
    void stopPlaying() const;
    virtual ~SoundEngine();
    static void forwardCallback(void *userdata, Uint8 *stream, int len);
    void addSynth(WaveTableSynth* s,float wantedFreq);
    void removeSynth(WaveTableSynth* s);
private:
    SoundEngine();
    static SoundEngine* instance;
    void audioCallback(Uint8 *stream, int len);
    std::list<WaveTableSynth*>  synthesizers;
    SDL_AudioSpec want{}, have{};
    SDL_AudioDeviceID audioDevice;
    const SDL_AudioFormat audioFormat = AUDIO_S16SYS;
    const int audioChannels=2;
    const int sampleBufferSize=1024;
    const int synthTableSize=128;
};


#endif //CHIPEMULATOR_SOUNDENGINE_H
