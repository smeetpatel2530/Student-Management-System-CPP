#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <string>

// Struct for Date of Birth
struct dOB {
    int day;
    int month;
    int year;
};

// Struct for Grade
struct grade {
    int Math;
    int Literature;
    int English;
};

// Struct for Total Score
struct tS {
    float totalScore;
};

// Main Student struct
struct stud {
    int No;
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string Gender;
    dOB dateOfBirth;
    std::string socialID;
    grade studentGrade;
    tS totalStudentScore;
    stud* pNext; // Pointer for the linked list
};

#endif
