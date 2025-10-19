#include "function.h"
#include <iostream>
#include <string>

// Initialize a class by setting its head pointer to null
void init(Class& cl) {
    cl.pHead = nullptr;
}

// Create a new student by getting input from the user
stud* CreateStudent() {
    stud* p = new stud;
    if (p == nullptr) {
        return nullptr; // Memory allocation failed
    }

    std::cout << "Enter Student ID: ";
    std::cin >> p->studentID;
    std::cout << "Enter First Name: ";
    std::cin >> p->firstName;
    std::cout << "Enter Last Name: ";
    std::cin >> p->lastName;
    std::cout << "Enter Gender: ";
    std::cin >> p->Gender;
    std::cout << "Enter Date of Birth (dd mm yyyy): ";
    std::cin >> p->dateOfBirth.day >> p->dateOfBirth.month >> p->dateOfBirth.year;
    std::cout << "Enter Social ID: ";
    std::cin >> p->socialID;

    // For simplicity, grades and scores can be added here or defaulted
    p->studentGrade.Math = 0;
    p->studentGrade.Literature = 0;
    p->studentGrade.English = 0;
    p->totalStudentScore.totalScore = 0.0f;

    p->pNext = nullptr;
    return p;
}

// Add a student to the end of the linked list
void addStudent(Class& cl, stud* p) {
    if (cl.pHead == nullptr) {
        cl.pHead = p;
    } else {
        stud* cur = cl.pHead;
        while (cur->pNext != nullptr) {
            cur = cur->pNext;
        }
        cur->pNext = p;
    }
    std::cout << "Student added successfully!\n";
}

// Display all students in the linked list
void display(const Class& cl) {
    if (cl.pHead == nullptr) {
        std::cout << "No students in the class.\n";
        return;
    }
    stud* cur = cl.pHead;
    while (cur != nullptr) {
        std::cout << "------------------------\n";
        std::cout << "ID: " << cur->studentID << "\n";
        std::cout << "Name: " << cur->firstName << " " << cur->lastName << "\n";
        std::cout << "Gender: " << cur->Gender << "\n";
        std::cout << "------------------------\n";
        cur = cur->pNext;
    }
}

// A simple placeholder for SaveFile functionality
void SaveFile(const Class& cl) {
    std::cout << "Save file functionality not implemented yet.\n";
}

// A simple placeholder for LoadFile functionality
void LoadFile(Class& cl) {
    std::cout << "Load file functionality not implemented yet.\n";
}

// Find a student by ID
stud* FindStudentByID(const Class& cl, const std::string& id) {
     stud* cur = cl.pHead;
     while (cur != nullptr) {
         if (cur->studentID == id) {
             return cur;
         }
         cur = cur->pNext;
     }
     return nullptr; // Not found
}

// Delete a student by ID
void deleteStudent(Class& cl, const std::string& id) {
    if (cl.pHead == nullptr) {
        std::cout << "List is empty, cannot delete.\n";
        return;
    }

    stud* pDel = nullptr;

    // Case 1: Delete the head node
    if (cl.pHead->studentID == id) {
        pDel = cl.pHead;
        cl.pHead = cl.pHead->pNext;
        delete pDel;
        std::cout << "Student with ID " << id << " deleted.\n";
        return;
    }

    // Case 2: Delete a node in the middle or at the end
    stud* pPrev = cl.pHead;
    while (pPrev->pNext != nullptr && pPrev->pNext->studentID != id) {
        pPrev = pPrev->pNext;
    }

    if (pPrev->pNext != nullptr) { // Found the node to delete
        pDel = pPrev->pNext;
        pPrev->pNext = pDel->pNext;
        delete pDel;
        std::cout << "Student with ID " << id << " deleted.\n";
    } else {
        std::cout << "Student with ID " << id << " not found.\n";
    }
}
