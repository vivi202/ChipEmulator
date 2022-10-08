//
// Created by vincenzo on 08/10/22.
//

#ifndef CHIPEMULATOR_DRAWABLE_H
#define CHIPEMULATOR_DRAWABLE_H


class Drawable {
public:
    virtual ~Drawable()=default;

    virtual void draw()=0;
};


#endif //CHIPEMULATOR_DRAWABLE_H
