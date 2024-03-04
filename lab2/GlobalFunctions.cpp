#include "GlobalFunctions.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <cmath>

int GlobalFunctions::compareByName( Student& student1, Student& student2) {
    return student1.getName().compare(student2.getName());
}

int GlobalFunctions::compareByAverageGrade(Student& student1, Student& student2) {
    float avg1 = student1.calculateAverageGrade();
    float avg2 = student2.calculateAverageGrade();

    if (avg1 == avg2)
        return 0;
    else
        return (avg1 > avg2) ? 1 : -1;
}

int GlobalFunctions::compareByMathGrade(Student& student1, Student& student2) {
    if (student1.getMathGrade() == student2.getMathGrade()) return 0;
    return (student1.getMathGrade() > student2.getMathGrade()) ? 1 : -1;
}

int GlobalFunctions::compareByEnglishGrade(Student& student1, Student& student2) {
    if (student1.getEnglishGrade() == student2.getEnglishGrade()) return 0;
    return (student1.getEnglishGrade() > student2.getEnglishGrade()) ? 1 : -1;
}

int GlobalFunctions::compareByHistoryGrade(Student& student1, Student& student2) {
    if (student1.getHistoryGrade() == student2.getHistoryGrade()) return 0;
    return (student1.getHistoryGrade() > student2.getHistoryGrade()) ? 1 : -1;
}
