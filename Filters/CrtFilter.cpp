//
// Created by vincenzo on 27/10/22.
//

#include "CrtFilter.h"
void CrtFilter::draw() {
    generateScanLines();
    SDL_RenderCopy(Window::getInstance()->getRenderer(),texture, nullptr, nullptr);
}

CrtFilter::CrtFilter() {
    texture= SDL_CreateTexture(Window::getInstance()->getRenderer(),SDL_PIXELFORMAT_ARGB8888,
                               SDL_TEXTUREACCESS_TARGET,
                               Window::getInstance()->getWidth(),Window::getInstance()->getHeight());
    SDL_SetTextureBlendMode(texture,SDL_BLENDMODE_BLEND);
    generateScanLines();
}

CrtFilter::~CrtFilter() {
    SDL_DestroyTexture(texture);
}

void CrtFilter::generateScanLines() {
    Window* window=Window::getInstance();
    int width=window->getHeight();
    int height=window->getHeight();

    SDL_DestroyTexture(texture);
    texture=SDL_CreateTexture(Window::getInstance()->getRenderer(),SDL_PIXELFORMAT_ARGB8888,
                      SDL_TEXTUREACCESS_TARGET,
                      width,height);
    SDL_SetTextureBlendMode(texture,SDL_BLENDMODE_BLEND);

    SDL_Renderer *renderer=window->getRenderer();
    SDL_SetRenderTarget(renderer,texture);
    SDL_SetRenderDrawColor(renderer,0,0,0,0);
    SDL_RenderClear(renderer);
    if(crossingLineEnabled){
        int max;
        if(crossingLineDirection)
            max=width;
        else
            max=height;
        frameCounter+=2;
        if(frameCounter >= 60){
            crossingLineCounter=(crossingLineCounter + scanLinesDensity) % max;
            frameCounter=0;
        }
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, scanLineOpacity);
    if(horizontalScanLinesEnabled){
        for (int y = 0; y < height; y+= scanLinesDensity) {
            if(crossingLineCounter == y && !crossingLineDirection)
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, crossingScanLineOpacity);
            SDL_RenderDrawLine(renderer,0,y,width,y);
        }
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, scanLineOpacity);
    if(verticalScanLinesEnabled) {
        for (int x = 0; x < width; x += scanLinesDensity) {
            if(crossingLineCounter == x && crossingLineDirection)
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, crossingScanLineOpacity);
            SDL_RenderDrawLine(renderer, x, 0, x, height);
        }
    }
    SDL_SetRenderTarget(renderer, nullptr);
}

void CrtFilter::setScanLineOpacity(int newScanLineOpacity) {
    CrtFilter::scanLineOpacity = newScanLineOpacity;
}

void CrtFilter::setCrossingScanLineOpacity(int newCrossingScanLineOpacity) {
    CrtFilter::crossingScanLineOpacity = newCrossingScanLineOpacity;
}

void CrtFilter::setScanLinesDensity(int newScanLinesDensity) {
    CrtFilter::scanLinesDensity = newScanLinesDensity;
    crossingLineCounter=0;
}


void CrtFilter::setHorizontalScanLinesEnabled(bool newHorizontalScanLinesEnabled) {
    CrtFilter::horizontalScanLinesEnabled = newHorizontalScanLinesEnabled;
}

void CrtFilter::setVerticalScanLinesEnabled(bool newVerticalScanLinesEnabled) {
    CrtFilter::verticalScanLinesEnabled = newVerticalScanLinesEnabled;
}

void CrtFilter::setCrossingLineEnabled(bool newCrossingLineEnabled) {
    CrtFilter::crossingLineEnabled = newCrossingLineEnabled;
    crossingLineCounter=0;
}

void CrtFilter::setCrossingLineDirection(bool newCrossingLineDirection) {
    CrtFilter::crossingLineDirection = newCrossingLineDirection;
    crossingLineCounter=0;
}
