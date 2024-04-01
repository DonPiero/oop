#ifndef CAR_H
#define CAR_H

#include "Weather.h"

class Car {
public:
    virtual const char* getName() const = 0;
    virtual double getFuelCapacity() const = 0;
    virtual double getFuelConsumption() const = 0;
    virtual double getAverageSpeed(Weather condition) const = 0;
};

#endif // CAR_H
