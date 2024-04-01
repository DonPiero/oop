#include "BMW.h"

const char* BMW::getName() const {
    return "BMW";
}

double BMW::getFuelCapacity() const {
    return 1000.0;
}

double BMW::getFuelConsumption() const {
    return 9.0;
}

double BMW::getAverageSpeed(Weather condition) const {
    switch(condition) {
        case Weather::Rain:
            return 90.0;
        case Weather::Sunny:
            return 110.0;
        case Weather::Snow:
            return 70.0;
    }
}
