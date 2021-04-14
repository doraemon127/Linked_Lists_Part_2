
#include <cstring>
#include "Student.h"


//constructor
Student::Student() 
{
	first_name = new char();
	last_name = new char();
	id = 0;
	gpa = 0.0;
}


//destructor
Student::~Student()
{
	delete first_name;
	delete last_name;
}


//setter
void Student::setFirstName(char* f)
{
	first_name = new char[strlen(f) + 1]; //add 1 to make space for null terminating character
	strcpy(first_name, f);
}


//getter
char* Student::getFirstName()
{
	return first_name;
}


//setter
void Student::setLastName(char* l)
{
	last_name = new char[strlen(l) + 1]; //add 1 to make space for null terminating character
	strcpy(last_name, l);
}


//getter 
char* Student::getLastName()
{
	return last_name;
}


//setter
void Student::setID(int i) 
{
	id = i;
}


//getter
int Student::getID()
{
	return id;
}


//setter
void Student::setGPA(float g) 
{
	gpa = g;
}


//getter
float Student::getGPA()
{
	return gpa;
}