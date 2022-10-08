//
// Created by vincenzo on 08/10/22.
//

#include "ChipInterpreterHandler.h"
void ChipInterpreterHandler::draw() {
    textureHandler.draw();
}

void ChipInterpreterHandler::handleExecution() {
    interpreter.cycle();
}

void ChipInterpreterHandler::handleEvents(SDL_Event &e) {

}

void ChipInterpreterHandler::loadRom(Rom &rom) {
    auto &path=rom.getPath();
    std::ifstream romFile(path,std::ifstream::binary);
    if(romFile.is_open()){
        romFile.seekg(0,std::ifstream::end);
        long size=romFile.tellg();
        auto buff=std::unique_ptr<char>(new char[size]);
        romFile.seekg(0,std::ifstream::beg);
        romFile.read(buff.get(),size);
        interpreter.loadProgramData(reinterpret_cast<uint8_t*>(buff.get()),size);
        romFile.close();
    }
}
