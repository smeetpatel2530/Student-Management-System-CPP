#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include "Class.h"
#include <fstream>

// --- Function Prototypes ---

// Initialize a class list
void init(Class&);

// Create a new student node from user input
stud* CreateStudent();

// Add a student to the class list
void addStudent(Class&, stud*);

// Display all students in the class
void display(const Class&);

// Save the list of students to a text file
void SaveFile(const Class&);

// Load students from a text file
void LoadFile(Class&);

// Search for a student by their ID
stud* FindStudentByID(const Class&, const std::string&);

// Delete a student by their ID
void deleteStudent(Class&, const std::string&);

#endif
