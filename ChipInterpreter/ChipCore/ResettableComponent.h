//
// Created by vincenzo on 28/09/22.
//

#ifndef CHIPEMULATOR_RESETTABLECOMPONENT_H
#define CHIPEMULATOR_RESETTABLECOMPONENT_H
class ResettableComponent{
public:
    virtual ~ResettableComponent()=default;

    virtual void reset()=0;
};
#endif //CHIPEMULATOR_RESETTABLECOMPONENT_H
