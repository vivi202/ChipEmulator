//
// Created by vincenzo on 27/10/22.
//

#ifndef CHIPEMULATOR_COMMANDLINEARGPARSER_H
#define CHIPEMULATOR_COMMANDLINEARGPARSER_H

#include <vector>
#include <string_view>
#include <string>
class CommandLineArgParser {
public:
    CommandLineArgParser(int argc,char *argv[]){
        argumentLength=argc;
        argvPointer=argv;
    };
    void parse();

    const std::string &getRomPath() const;

    int getFrequency() const;

    bool isHorizontalScanLinesEnabled() const;

    bool isVerticalScanLinesEnabled() const;

    bool isCrossingLineEnabled() const;

    bool isCrossingLineDirection() const;

private:
    int argumentLength;
    char ** argvPointer;
    std::string romPath;
    bool isRom= false;
    int frequency=500;
    bool horizontalScanLinesEnabled= false;
    bool verticalScanLinesEnabled= false;
    bool crossingLineEnabled= false;
    bool crossingLineDirection= false;
    static std::string nextArgument(const std::string_view &stringView);
    void printUsage();
};


#endif //CHIPEMULATOR_COMMANDLINEARGPARSER_H
