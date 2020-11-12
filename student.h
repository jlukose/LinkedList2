#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>

using namespace std;

//student header file for students name, id, and gpa

class Student{
 public:
  Student();
  ~Student();
  char* getFirstName();
  char* getLastName();
  int* getID();
  float* getGPA();
 private:
  char firstName[20];
  char lastName[20];
  int ID;
  float GPA;
};
#endif
