#include "Window.h"
#include "RenderEngine.h"
#include "ChipInterpreterHandler.h"
int main() {
    uint32_t lastPoll=0;
    uint32_t currentTime;
    uint32_t pollPeriod=16;
    Window* window=Window::getInstance();
    RenderEngine engine;
    Rom rom("Rom/chip8-test-suite.ch8");
    ChipInterpreterHandler chipInterpreterHandler(900);
    chipInterpreterHandler.loadRom(rom);
    engine.addDrawable(&chipInterpreterHandler);
    while (window->isRunning()){
        currentTime=SDL_GetTicks();
        if(currentTime - lastPoll > pollPeriod) {//poll at 60Hz to avoid too much cpu usage.
            SDL_Event e;
            while (SDL_PollEvent(&e) != 0) {
                window->events(e);
                chipInterpreterHandler.handleEvents(e);
            }
            lastPoll=currentTime;
        }
        chipInterpreterHandler.handleExecution();
        engine.render();
    }
    delete window;
    return 0;
}
