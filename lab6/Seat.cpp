#include "Seat.h"

const char* Seat::getName() const {
    return "Seat";
}

double Seat::getFuelCapacity() const {
    return 950.0;
}

double Seat::getFuelConsumption() const {
    return 7.0;
}

double Seat::getAverageSpeed(Weather condition) const {
    switch(condition) {
        case Weather::Rain:
            return 85.0;
        case Weather::Sunny:
            return 105.0;
        case Weather::Snow:
            return 65.0;
    }
}
