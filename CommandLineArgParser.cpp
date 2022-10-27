//
// Created by vincenzo on 27/10/22.
//

#include "CommandLineArgParser.h"
#include <string>
#include <iostream>
#include <filesystem>
void CommandLineArgParser::parse() {
    const std::vector<std::string_view> args(argvPointer+1,argvPointer+argumentLength);
    if(args.size() < 2){
        std::cerr<<"Missing required parameters!";
        printUsage();
        exit(1);
    }
    for (auto& arg : args){
        if(arg == "--rom" ){
            romPath= nextArgument(arg);
            if(std::filesystem::exists(romPath))
                isRom= true;
            else
                isRom= false;
        }
        if(arg == "--freq" ){
            frequency= std::stoi(nextArgument(arg));
        }
    }
    if(!isRom){
        std::cerr<<"\n"<<"Path to rom is either missing or invalid!";
        printUsage();
        exit(1);
    }
}

const std::string &CommandLineArgParser::getRomPath() const {
    return romPath;
}

int CommandLineArgParser::getFrequency() const {
    return frequency;
}

std::string CommandLineArgParser::nextArgument(const std::string_view &stringView) {
    auto res=(*(&stringView+1)).data();
    return res;
}

void CommandLineArgParser::printUsage() {
    std::cerr<<"\n"<<"Usage: ChipInterpreter --rom PathToYourRom [--freq InterpreterFrequency]";
}

