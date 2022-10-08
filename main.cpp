#include "Window.h"
#include "DisplayTextureHandler.h"
#include "RenderEngine.h"
int main() {
    Window* window=Window::getInstance();
    RenderEngine engine;
    DisplayTextureHandler displayHandler;
    engine.addDrawable(&displayHandler);
    while (window->isRunning()){
        window->events();
        SDL_RenderClear(window->getRenderer());
        engine.drawAll();
        SDL_RenderPresent(window->getRenderer());
    }

    delete window;
    return 0;
}
