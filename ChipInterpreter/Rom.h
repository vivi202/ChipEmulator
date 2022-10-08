//
// Created by vincenzo on 08/10/22.
//

#ifndef CHIPEMULATOR_ROM_H
#define CHIPEMULATOR_ROM_H

#include <string>
#include <utility>
class Rom {
public:
    explicit Rom(std::string path):path(std::move(path)){};
    const std::string &getPath() const {
        return path;
    }
private:
    std::string path;
};


#endif //CHIPEMULATOR_ROM_H
