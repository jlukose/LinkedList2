//Linked List part 2 by Joshua Lukose 11/2020
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdio.h>
#include "student.h"
#include "node.h"

using namespace std;

Node* head = NULL;
int addStudent(Student* student, Node* currentNode);
int deleteStudent(int, Node* currentNode);
int print(Node* ptr);
float average(Node* ptr);

int main(){
  char input[10];
  while (true){
    cout << "Commands: ADD, PRINT, DELETE, AVERAGE, QUIT" << endl;
    cin.get(input, 10);
    cin.ignore(256, '\n');
    if (strcmp(input, "ADD") == 0){//Add function
      Student* student = new Student;
      cout << "Enter first name: ";
      cin.get(student->getFirstName(), 20);
      cin.ignore(256, '\n');
      cout << "Enter last name: ";
      cin.get(student->getLastName(), 20);
      cin.ignore(256, '\n');
      cout << "Enter ID: ";
      cin >> *student->getID();
      cin.ignore(256, '\n');
      cout << "Enter GPA: ";
      cin >> *student->getGPA();
      cin.ignore(256, '\n');
      addStudent(student, head);
    }
    if (strcmp(input, "PRINT") == 0){//Print function
      cout << endl;
      print(head);
    }
    if (strcmp(input, "DELETE") == 0){//Delete function
      cout << "Enter ID: ";
      int deleteID;
      cin >> deleteID;
      cin.clear();
      cin.ignore(1000, '\n');
      deleteStudent(deleteID, head);
    }
    if (strcmp(input, "AVERAGE") == 0){//Average function
      float averageGPA = average(head);
      cout << "Average GPA: " << setprecision(3) << averageGPA << endl;
    }
    if (strcmp(input, "QUIT") == 0){//Quit function
      return 0;
    }
  }
  return 0;
}

int addStudent(Student* student, Node* currentNode){
  Node *prev;
  if(head == NULL){//Create first Node in list
    head = new Node(student);
    return 0;
  }
  else if(head -> getStudent()->getID() >= student -> getID()){//If adding an ID  that preceeds the head ID
    Node* temp = NULL;
    temp = new Node(student);
    temp->setNext(head);
    head = temp;
    return 0;
  }
  else{
    prev = currentNode;
    Node* current = currentNode->getNext();
    if (current == NULL){//Adding to the end
      currentNode -> setNext(new Node(student));
      return 0;
    }
    if (current->getStudent()->getID() >= student->getID()){//Adding to middle
      Node* temp = NULL;
      temp = new Node(student);
      temp->setNext(current);
      prev->setNext(temp);
      return 0;
    }  
    if(current != NULL && current->getStudent()->getID() <= student->getID()){//Move on to trying next spot using recurstion
      addStudent(student, current);
      return 0;
    }
  }
  return 0;
}

int print(Node* ptr){
  if (ptr == NULL){
    return 0;
  }
  if (ptr->getNext() == NULL){//If last node print node then end print function
    cout << ptr->getStudent()->getFirstName() << " "
       << ptr->getStudent()->getLastName() << ", "
       << *ptr->getStudent()->getID() << ", "
       << *ptr->getStudent()->getGPA() << endl << endl;
    return 0;
  }
  if (ptr->getNext() != NULL){//If there is a next node print current node then move to next node using recurrsion
    cout << ptr->getStudent()->getFirstName() << " "
       << ptr->getStudent()->getLastName() << ", "
       << *ptr->getStudent()->getID() << ", "
       << *ptr->getStudent()->getGPA() << endl;    
    print(ptr->getNext());
    return 0;
  }
  return 0;
}

//WIP
int deleteStudent(int deleteID, Node* currentNode){//delete by id
  Student* student;
  Node* prev;
  if(head == NULL){//if list is empty
    cout << "List Empty" << endl;
    return 0;
  }
  if(*head->getStudent()->getID() == deleteID){//if deleting head
    cout << "deleting head" << endl;
    Node* temp = NULL;
    cout << "A" << endl;
    temp = head;
    cout << "B" << endl;
    head = head->getNext();
    cout << "C" << endl;
    delete temp->getStudent();
    cout << "D" << endl;
    delete temp;
    cout << "E" << endl;
    return 0;
  }
  else{//check next node
    cout << "deleting next" << endl;
    prev = currentNode;
    Node* next = currentNode->getNext();
    if (next != NULL && *next->getStudent()->getID() == deleteID){
      Node* temp = NULL;
      temp = next;
      prev->setNext(next->getNext());
      delete temp->getStudent();
      delete temp;
      return 0;
    }    
    if(next != NULL && *next->getStudent()->getID() != deleteID){//repeat on next node
      deleteStudent(deleteID, next);
      return 0;
    }
    else{
      return 0;
    }
  }
  return 0;
}

float average(Node* ptr){//uses recursion to add up gpa and number of students, returns average
  ptr = head;
  float sum = 0;
  int nstudents = 0;
  while (ptr != NULL){
    sum = sum + *ptr->getStudent()->getGPA();
    nstudents++;
    ptr = ptr->getNext();
  }
  return(sum/nstudents);
}
