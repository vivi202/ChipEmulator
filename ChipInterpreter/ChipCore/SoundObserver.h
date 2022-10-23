//
// Created by vincenzo on 23/10/22.
//

#ifndef CHIPEMULATOR_SOUNDOBSERVER_H
#define CHIPEMULATOR_SOUNDOBSERVER_H


class SoundObserver {
public:
    virtual ~SoundObserver()=default;
    virtual void startSound()=0;
    virtual void stopSound()=0;
};


#endif //CHIPEMULATOR_SOUNDOBSERVER_H
