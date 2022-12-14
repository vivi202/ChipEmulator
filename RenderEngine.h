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
};


#endif //CHIPEMULATOR_RENDERENGINE_H
