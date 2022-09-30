//
// Created by vincenzo on 30/09/22.
//

#ifndef CHIPEMULATOR_WINDOW_H
#define CHIPEMULATOR_WINDOW_H
#include "SDL.h"
#include <string>

class Window {
public:
    static Window* getInstance();
    SDL_Renderer* getRenderer();
    ~Window();
    void quit();
    bool isRunning() const;
    void events();
private:
    Window();
    static Window* instance;
    bool running;
    const std::string title="ChipEmulator";
    int width=1280;
    int height=720;
    SDL_Window *sdlWindow;
    SDL_Renderer* sdlRenderer;
};


#endif //CHIPEMULATOR_WINDOW_H
