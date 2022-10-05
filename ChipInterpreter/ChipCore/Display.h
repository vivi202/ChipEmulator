//
// Created by vincenzo on 30/09/22.
//

#ifndef CHIPEMULATOR_DISPLAY_H
#define CHIPEMULATOR_DISPLAY_H

#include "ResettableComponent.h"
class Display: public ResettableComponent{
public:
    Display(int width,int height):width(width),height(height){};

    virtual ~Display() = default;

    virtual Display* clone() const =0;

    virtual bool readPixel(int x,int y)=0;
    virtual void writePixel(int x,int y,bool value)=0;

    int getWidth() const {
        return width;
    }

    int getHeight() const {
        return height;
    }
protected:
    int width;
    int height;
};


#endif //CHIPEMULATOR_DISPLAY_H
