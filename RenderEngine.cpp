//
// Created by vincenzo on 08/10/22.
//

#include "RenderEngine.h"

void RenderEngine::addDrawable(Drawable *d) {
    drawableList.push_back(d);
}

void RenderEngine::removeDrawable(Drawable *d) {
    drawableList.remove(d);
}

void RenderEngine::drawAll() {
    for (auto & itr : drawableList) {
        itr->draw();
    }
}

void RenderEngine::render() {
        SDL_RenderClear(Window::getInstance()->getRenderer());
        drawAll();
        SDL_RenderPresent(Window::getInstance()->getRenderer());
}
