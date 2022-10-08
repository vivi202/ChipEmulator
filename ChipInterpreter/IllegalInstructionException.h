//
// Created by vincenzo on 08/10/22.
//

#ifndef CHIPEMULATOR_ILLEGALINSTRUCTIONEXCEPTION_H
#define CHIPEMULATOR_ILLEGALINSTRUCTIONEXCEPTION_H
#include <exception>
#include <string>
class IllegalInstructionException : public std::exception{
public:
    explicit IllegalInstructionException(uint16_t machineCode):machineCode(machineCode),std::exception(){
    };

    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Illegal instruction";
    }

    uint16_t machineCode;
};


#endif //CHIPEMULATOR_ILLEGALINSTRUCTIONEXCEPTION_H
