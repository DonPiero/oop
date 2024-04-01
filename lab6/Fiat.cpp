#include "Fiat.h"

const char* Fiat::getName() const {
    return "Fiat";
}

double Fiat::getFuelCapacity() const {
    return 900.0;
}

double Fiat::getFuelConsumption() const {
    return 7.5;
}

double Fiat::getAverageSpeed(Weather condition) const {
    switch(condition) {
        case Weather::Rain:
            return 75.0;
        case Weather::Sunny:
            return 95.0;
        case Weather::Snow:
            return 65.0;
    }
}
