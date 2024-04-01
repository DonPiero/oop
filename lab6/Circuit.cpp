#include "Circuit.h"
#include <iostream>

Circuit::Circuit() {
    this->length = 0;
    this->condition = Weather::Sunny;
    this->cars = nullptr;
    this->raceTimes = nullptr;
    this->numCars = 0;
    this->capacity = 0;
}

Circuit::~Circuit() {
    delete[] this->cars;
    delete[] this->raceTimes;
}

void Circuit::SetLength(double len) {
    this->length = len;
}

void Circuit::SetWeather(Weather cond) {
    this->condition = cond;
}

void Circuit::AddCar(Car* car) {
    if (this->numCars >= this->capacity) { // crestem capacitatea tabloului de masini din cursa si il updatam pt a fii pregatit pt un nou participant
        int newCapacity = this->capacity + 1;
        Car** newCars = new Car*[newCapacity];
        double* newRaceTimes = new double[newCapacity];

        for (int i = 0; i < this->numCars; i++) {
            newCars[i] = this->cars[i];
            newRaceTimes[i] = this->raceTimes[i];
        }

        delete[] this->cars;
        delete[] this->raceTimes;

        this->cars = newCars;
        this->raceTimes = newRaceTimes;
        this->capacity = newCapacity;
    }

    this->cars[this->numCars++] = car;
}

void Circuit::Race() {
    for (int i = 0; i < this->numCars; i++) {
        double fuelRequired = this->length * this->cars[i]->getFuelConsumption();
        if (fuelRequired <= this->cars[i]->getFuelCapacity()) {
            this->raceTimes[i] = this->length / this->cars[i]->getAverageSpeed(this->condition); // pt fiecare participant ii calculam timpul
        } else {
            this->raceTimes[i] = -1.0;
        }
    }
}

void Circuit::ShowFinalRanks() {
    int* indexes = new int[this->numCars];
    for (int i = 0; i < this->numCars; i++) {
        indexes[i] = i; // a cata masina din this cars este pe locul 1,2,3.... indexul = locul, valoarea = masina
    }

    // Bubble sort
    for (int i = 0; i < this->numCars - 1; i++) {
        for (int j = 0; j < this->numCars - i - 1; j++) {
            if (this->raceTimes[indexes[j]] > this->raceTimes[indexes[j + 1]]) {
                int temp = indexes[j];
                indexes[j] = indexes[j + 1];
                indexes[j + 1] = temp;
            }
        }
    }

    std::cout << "Final Ranking:" << std::endl;
    for (int i = 0; i < this->numCars; i++) {
        if(this->raceTimes[indexes[i]] >= 0)
        {
            std::cout << this->cars[indexes[i]]->getName() << ": " << this->raceTimes[indexes[i]] << " hours" << std::endl;
        }
    }

    delete[] indexes; // baieti buni
}


void Circuit::ShowWhoDidNotFinish() {
    std::cout << "Cars that did not finish:" << std::endl;
    for (int i = 0; i < this->numCars; i++) {
        if (this->raceTimes[i] < 0) {
            std::cout << this->cars[i]->getName() << std::endl;
        }
    }
}
