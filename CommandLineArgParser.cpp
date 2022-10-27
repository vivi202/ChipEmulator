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
        if(arg == "--scanH"){
            horizontalScanLinesEnabled= true;
        }
        if(arg == "--scanV"){
            verticalScanLinesEnabled= true;
        }
        if(arg == "--scanX"){
            horizontalScanLinesEnabled= true;
            verticalScanLinesEnabled= true;
        }
        if(arg == "--crossDir"){
            crossingLineEnabled = true;
            std::string crossDir= nextArgument(arg);
            if(crossDir == "V"){
                crossingLineDirection= false;
            } else if (crossDir == "H"){
                crossingLineDirection= true;
            }else{
                std::cerr<<"\n"<<"invalid crossing line direction";
                printUsage();
            }
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

bool CommandLineArgParser::isHorizontalScanLinesEnabled() const {
    return horizontalScanLinesEnabled;
}

bool CommandLineArgParser::isVerticalScanLinesEnabled() const {
    return verticalScanLinesEnabled;
}

bool CommandLineArgParser::isCrossingLineEnabled() const {
    return crossingLineEnabled;
}

bool CommandLineArgParser::isCrossingLineDirection() const {
    return crossingLineDirection;
}

