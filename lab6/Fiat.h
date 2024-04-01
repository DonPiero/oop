#ifndef UNTITLED_FIAT_H
#define UNTITLED_FIAT_H

#include "Car.h"

class Fiat : public Car {
public:
    const char* getName() const override;
    double getFuelCapacity() const override;
    double getFuelConsumption() const override;
    double getAverageSpeed(Weather condition) const override;
};

#endif //UNTITLED_FIAT_H
