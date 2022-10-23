//
// Created by vincenzo on 23/10/22.
//

#ifndef CHIPEMULATOR_SINEWAVETABLESYNTH_H
#define CHIPEMULATOR_SINEWAVETABLESYNTH_H

#include "WaveTableSynth.h"
#include <vector>
#include <cmath>
class SineWaveTableSynth : public WaveTableSynth{
public:
    explicit SineWaveTableSynth(int samplingFreq): WaveTableSynth(samplingFreq){};
    ~SineWaveTableSynth() override = default;
    void generateTable(int nSamples) override;
};


#endif //CHIPEMULATOR_SINEWAVETABLESYNTH_H
