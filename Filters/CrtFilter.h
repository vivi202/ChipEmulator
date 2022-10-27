//
// Created by vincenzo on 27/10/22.
//

#ifndef CHIPEMULATOR_CRTFILTER_H
#define CHIPEMULATOR_CRTFILTER_H
#include "../Window.h"
#include "../Drawable.h"



class CrtFilter : public Drawable{
public:
    ~CrtFilter() override;

    CrtFilter();

    void draw() override;

private:
    int scanLineOpacity = 15;
    int crossingScanLineOpacity = 45;
    int scanLinesDensity = 4;
    SDL_Texture* texture;
    void generateScanLines();
    int crossingLineCounter=0;
    bool horizontalScanLinesEnabled= true;
    bool verticalScanLinesEnabled= false;
    bool crossingLineEnabled= true;
    bool crossingLineDirection= false;
    int frameCounter=0;
public:
    void setCrossingLineEnabled(bool crossingLineEnabled);

    void setCrossingLineDirection(bool crossingLineDirection);

public:
    void setHorizontalScanLinesEnabled(bool horizontalScanLinesEnabled);

    void setVerticalScanLinesEnabled(bool verticalScanLinesEnabled);

    void setScanLineOpacity(int scanLineOpacity);

    void setCrossingScanLineOpacity(int crossingScanLineOpacity);

    void setScanLinesDensity(int scanLinesDensity);
};


#endif //CHIPEMULATOR_CRTFILTER_H
