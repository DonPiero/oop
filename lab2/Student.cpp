#include "Student.h"
#include <string>

void Student::setName(const std::string& newName) {
        this->name = newName;
}
std::string Student::getName() {
        return this->name;
}

void Student::setMathGrade(float grade) {
        this->mathGrade = grade;
}

float Student::getMathGrade() {
        return this->mathGrade;
}

void Student::setEnglishGrade(float grade) {
        this->englishGrade = grade;
}

float Student::getEnglishGrade() {
        return this->englishGrade;
}

void Student::setHistoryGrade(float grade) {
        this->historyGrade = grade;
}

float Student::getHistoryGrade() {
        return this->historyGrade;
}
float Student::calculateAverageGrade() {
    return (this->mathGrade + this->englishGrade + this->historyGrade) / 3;
}

