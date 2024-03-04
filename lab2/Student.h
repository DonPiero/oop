#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H

#include <string>

class Student {
public:
    std::string name;
    float mathGrade;
    float englishGrade;
    float historyGrade;
    void setName(const std::string &newName);
    std::string getName();
    void setMathGrade(float grade);
    float getMathGrade();
    void setEnglishGrade(float grade);
    float getEnglishGrade();
    void setHistoryGrade(float grade);
    float getHistoryGrade();
    float calculateAverageGrade();
};

#endif //UNTITLED_STUDENT_H
