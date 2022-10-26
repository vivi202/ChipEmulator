//
// Created by vincenzo on 23/10/22.
//

#include "SineWaveTableSynth.h"

#include <cmath>


void SineWaveTableSynth::generateTable(int nSamples) {
    table.resize(nSamples);
    for (int i = 0; i < table.size(); i++) {
        table[i]=sinf((float)2.0 * (float)M_PI * (float)i/(float)nSamples);
    }
}


