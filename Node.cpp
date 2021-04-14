
#include "Node.h"


//constructor
Node::Node(Student* s) 
{
	student = s;
	next = NULL;
}


//destructor
Node::~Node() 
{
	delete &student;
	next = NULL;
}


//getter (get Student pointer)
Student* Node::getStudent()
{
	return student;
}


//setter (set next pointer to corresponding Node pointer)
void Node::setNext(Node* n)
{
	next = n;
}


//getter (get next Node pointer)
Node* Node::getNext()
{
	return next;
}
