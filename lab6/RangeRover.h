#ifndef UNTITLED_RANGEROVER_H
#define UNTITLED_RANGEROVER_H

#include "Car.h"

class RangeRover : public Car {
public:
    const char* getName() const override;
    double getFuelCapacity() const override;
    double getFuelConsumption() const override;
    double getAverageSpeed(Weather condition) const override;
};

#endif //UNTITLED_RANGEROVER_H
