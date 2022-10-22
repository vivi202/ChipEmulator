//
// Created by vincenzo on 08/10/22.
//

#ifndef CHIPEMULATOR_RENDERENGINE_H
#define CHIPEMULATOR_RENDERENGINE_H

#include "Drawable.h"
#include "Window.h"
#include <list>
class RenderEngine {
public:
    void addDrawable(Drawable* d);
    void removeDrawable(Drawable*d);
    void render();
private:
    void drawAll();
    std::list<Drawable*> drawableList;
    uint32_t lastRender=0;
    uint32_t currentTime=0;
    const int RenderPeriod=16;
};


#endif //CHIPEMULATOR_RENDERENGINE_H
