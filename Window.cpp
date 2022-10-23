//
// Created by vincenzo on 30/09/22.
//

#include "Window.h"
#include <exception>
Window* Window::instance= nullptr;

Window::Window(){
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        exit(1);
    }
    sdlWindow = SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
                                 width,height,SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if(sdlWindow){
        sdlRenderer= SDL_CreateRenderer(sdlWindow,-1,SDL_RENDERER_ACCELERATED);
        if(sdlRenderer){
            running= true;
        }else{
            SDL_Log("Unable to create 2d rendering context: %s", SDL_GetError());
        }
    }else{
        running= false;
    }
}

Window *Window::getInstance() {
    if(instance == nullptr){
        instance=new Window();
    }
    return instance;
}

Window::~Window() {
    //Free sdl2 resources
    SDL_DestroyRenderer(sdlRenderer);
    SDL_DestroyWindow(sdlWindow);
}

SDL_Renderer *Window::getRenderer() {
    return sdlRenderer;
}

void Window::quit() {
    running = false;
}

bool Window::isRunning() const {
    return running;
}

void Window::events(SDL_Event& e) {
    switch (e.type) {
        case SDL_QUIT:
            quit();
    }

}

