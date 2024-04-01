#include "Volvo.h"

const char* Volvo::getName() const {
    return "Volvo";
}

double Volvo::getFuelCapacity() const {
    return 1200.0;
}

double Volvo::getFuelConsumption() const {
    return 8.5;
}

double Volvo::getAverageSpeed(Weather condition) const {
    switch(condition) {
        case Weather::Rain:
            return 80.0;
        case Weather::Sunny:
            return 100.0;
        case Weather::Snow:
            return 60.0;
    }
}
