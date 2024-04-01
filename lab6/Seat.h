#ifndef UNTITLED_SEAT_H
#define UNTITLED_SEAT_H

#include "Car.h"

class Seat : public Car{
public:
    const char* getName() const override;
    double getFuelCapacity() const override;
    double getFuelConsumption() const override;
    double getAverageSpeed(Weather condition) const override;
};


#endif //UNTITLED_SEAT_H
