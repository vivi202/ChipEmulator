#include "Window.h"
int main() {
    Window* window=Window::getInstance();
    while (window->isRunning()){
        window->events();
    }

    delete window;
    return 0;
}
