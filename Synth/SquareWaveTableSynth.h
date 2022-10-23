//
// Created by vincenzo on 23/10/22.
//

#ifndef CHIPEMULATOR_SQUAREWAVETABLESYNTH_H
#define CHIPEMULATOR_SQUAREWAVETABLESYNTH_H
#include "WaveTableSynth.h"
#include <vector>
#include <cmath>
class SquareWaveTableSynth : public WaveTableSynth{
public:
    ~SquareWaveTableSynth() override = default;

    explicit SquareWaveTableSynth(int samplingFreq);

    void generateTable(int nSamples) override;

private:
};


#endif //CHIPEMULATOR_SQUAREWAVETABLESYNTH_H
