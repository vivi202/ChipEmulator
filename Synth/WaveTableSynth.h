//
// Created by vincenzo on 23/10/22.
//

#ifndef CHIPEMULATOR_WAVETABLESYNTH_H
#define CHIPEMULATOR_WAVETABLESYNTH_H

#include <vector>
#include <cmath>
class WaveTableSynth {
public:
    virtual ~WaveTableSynth()=default;
    explicit WaveTableSynth(int samplingFreq,float wantedFreq = 220.0f):samplingFreq(samplingFreq),
    wantedFreq(wantedFreq){};
    virtual void renderAudioSample(float &l,float &r){
        //set l & r samples
        l+=amplitude * table[(int)phi];
        r+=amplitude * table[(int)phi];
        //update phi
        phi=std::fmod((phi + deltaPhi),(float)table.size());
    };
    virtual void generateTable(int nSamples)=0;

    void setSamplingFreq(int newSamplingFreq){
        samplingFreq=newSamplingFreq;
    }

    virtual void setWantedFreq(float newWantedFreq){
        wantedFreq=newWantedFreq;
        deltaPhi=(float)table.size()* wantedFreq / static_cast<float>(samplingFreq);
    }
    void setAmplitude(float newAmplitude){
        amplitude=newAmplitude;
    }

protected:
    std::vector<float>table;
    float phi=0.0;//readIndex
    float deltaPhi=0.0;
    float amplitude=1.0;
    int samplingFreq;
    float wantedFreq;
};


#endif //CHIPEMULATOR_WAVETABLESYNTH_H
