#include "RangeRover.h"

const char* RangeRover::getName() const {
    return "RangeRover";
}

double RangeRover::getFuelCapacity() const {
    return 1300.0;
}

double RangeRover::getFuelConsumption() const {
    return 9.0;
}

double RangeRover::getAverageSpeed(Weather condition) const {
    switch(condition) {
        case Weather::Rain:
            return 70.0;
        case Weather::Sunny:
            return 90.0;
        case Weather::Snow:
            return 50.0;
    }
}
