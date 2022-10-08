#include "Window.h"
#include "RenderEngine.h"
#include "ChipInterpreterHandler.h"
int main() {
    Window* window=Window::getInstance();
    RenderEngine engine;
    ChipInterpreterHandler chipInterpreterHandler(500);
    engine.addDrawable(&chipInterpreterHandler);
    while (window->isRunning()){
        SDL_Event e;
        while (SDL_PollEvent(&e) !=0){
            window->events(e);
            chipInterpreterHandler.handleEvents(e);
        }
        chipInterpreterHandler.handleExecution();
        engine.render();
    }

    delete window;
    return 0;
}
