
// #include guards
#ifndef NODE_H
#define NODE_H

#include "Student.h"

class Node
{
    public:
        Node(Student* s); //constructor
        ~Node(); //destructor
        Student* getStudent(); //get student pointer
        void setNext(Node* n); //set the next pointer to the corresponding Node pointer n
        Node* getNext(); //get next Node pointer
    private: 
        Student* student;
        Node* next;
};

#endif