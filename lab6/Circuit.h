#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "Car.h"

class Circuit {
private:
    double length;
    Weather condition;
    Car** cars;
    double* raceTimes;
    int numCars;
    int capacity;
public:
    Circuit();
    ~Circuit();
    void SetLength(double len);
    void SetWeather(Weather cond);
    void AddCar(Car* car);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();

};

#endif // CIRCUIT_H
