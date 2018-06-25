#pragma once
#include <iostream>
#ifndef IMACGL_TIME_H
#define IMACGL_TIME_H


class Time {
private:
    int speed;
    float value;

public:
    //getters
    int getSpeed() const;
    float getValue() const;
    //setters
    void setSpeed(int speed);
    void setValue(float value);

    //constructor
    Time();
};


#endif //IMACGL_TIME_H
