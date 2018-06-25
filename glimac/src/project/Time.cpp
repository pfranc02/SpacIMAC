#include "project/Time.hpp"

//getters
int Time::getSpeed() const {
    return speed;
}

float Time::getValue() const {
    return value;
}


//setters
void Time::setSpeed(int speed) {
    Time::speed = speed;
}

void Time::setValue(float value) {
    Time::value = value;
}

Time::Time() {
    speed = 1;
    value = 0;
}



