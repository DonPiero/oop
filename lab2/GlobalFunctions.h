#ifndef UNTITLED_GLOBALFUNCTIONS_H
#define UNTITLED_GLOBALFUNCTIONS_H

#include "Student.h"

class GlobalFunctions {
public:
    int compareByName(Student &student1, Student &student2);
    int compareByAverageGrade(Student &student1, Student &student2);

    int compareByMathGrade(Student &student1, Student &student2);

    int compareByEnglishGrade(Student &student1, Student &student2);

    int compareByHistoryGrade(Student &student1, Student &student2);
};


#endif //UNTITLED_GLOBALFUNCTIONS_H
