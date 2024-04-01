#ifndef UNTITLED_BMW_H
#define UNTITLED_BMW_H

#include "Car.h"

class BMW : public Car {
public:
    const char* getName() const override;
    double getFuelCapacity() const override;
    double getFuelConsumption() const override;
    double getAverageSpeed(Weather condition) const override;
};

#endif //UNTITLED_BMW_H
