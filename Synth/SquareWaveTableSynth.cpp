//
// Created by vincenzo on 23/10/22.
//

#include "SquareWaveTableSynth.h"


void SquareWaveTableSynth::generateTable(int nSamples) {
    table.resize(nSamples);
    //squareWave using fourier series
    for (int i = 0; i < table.size(); ++i) {
        table[i]=sinf((float)2.0 * (float)M_PI * (float)i/(float)nSamples)+
                sinf(3* (float)2.0 * (float)M_PI * (float)i/(float)nSamples)/3+
                sinf(5* (float)2.0 * (float)M_PI * (float)i/(float)nSamples)/5;
    }
}

SquareWaveTableSynth::SquareWaveTableSynth(int samplingFreq) : WaveTableSynth(samplingFreq) {}
