
// #include guards
#ifndef STUDENT_H
#define STUDENT_H

#include <cstring>
using namespace std;

class Student 
{
	public:
		Student(); //constructor
		~Student(); //destructor
		void setFirstName(char* f); //set Student's first name
		char* getFirstName(); //get Student's first name
		void setLastName(char* l); //set Student's last name
		char* getLastName(); //get Student's last name
		void setID(int i); //set Student ID
		int getID(); //get Student ID
		void setGPA(float g); //set Student GPA
		float getGPA(); //get Student GPA
	private: 
		char* first_name;
		char* last_name;
		int id;
		float gpa;
};


#endif
