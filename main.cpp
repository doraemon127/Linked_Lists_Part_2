/*
Project Description: Student List using Linked Lists. User can add and delete students, print student list, and display average GPA of all Students in list.
Date: 4-13-2021
Name: Aammya Sapra
*/

#include <iostream>
#include <cstring>
#include <iomanip> //for setprecision()
#include "Student.h"
#include "Node.h"

using namespace std;


//function prototypes
void add_student(Node* &start, Node* prev, Node* student_node); 
void print_student_list(Node* n);
void delete_student(Node* &start, Node* prev, int i);
void average_gpa(Node* head, float total, int count);
void collect_student_info(Student* s);



//------------------------------------------------------MAIN FUNCTION----------------------------------------------------------

int main() 
{
	//print out instructions
	cout << '\n' << "To add a student type \'ADD\'." << endl;
	cout << "To print current students type \'PRINT\'." << endl;
	cout << "To delete a student type \'DELETE\'." << endl;
	cout << "To return average student GPA type \'AVERAGE\'." << endl;
	cout << "To quit type \'QUIT\'." << endl << endl;

	
	Node* head = NULL;
	bool inputting = true;
	char command[10];  //stores the command (ADD, PRINT, DELETE, AVERAGE, QUIT) inputted by the user


	while (inputting)
	{
		cin >> command;

		if (strcmp(command, "ADD") == 0) {
			Student* s = new Student(); //create new Student
			collect_student_info(s); //collect student information from user and set values
			Node* student_node = new Node(s); //create new node to store new student
			if (head == NULL) {
				head = student_node; //if list empty make head
				cout << "\nStudent added. Enter a command to continue or \'QUIT\' to exit." << endl << endl;
			} else {
				add_student(head, NULL, student_node); //insert new Student into Linked List in sorted order
			}
		} 
		else if (strcmp(command, "PRINT") == 0) {
			print_student_list(head); //call print_student_list() function 
			cout << "Enter a command to continue or \'QUIT\' to exit." << endl << endl;
		} 
		else if (strcmp(command, "DELETE") == 0) {
			if (head == NULL) { //if list is empty
				cout << "\nThe list is empty. Enter \'ADD\' to continue or \'QUIT\' to exit." << endl << endl;
			} else {
				int student_id;
				cout << "Enter Student's ID Number: "; //prompt for ID of student to be deleted
				cin >> student_id;
				delete_student(head, NULL, student_id); //delete student
			}
		}
		else if (strcmp(command, "AVERAGE") == 0) {
			average_gpa(head, 0.0, 0); //call average_gpa() function
			cout << "Enter a command to continue or \'QUIT\' to exit." << endl << endl;
		}
		else if (strcmp(command, "QUIT") == 0) {
			inputting = false;
			break;
		} else { //prompt user to re-enter command if something invalid was entered
			cout << "Please enter either \'ADD\', \'PRINT\', \'DELETE\', \'AVERAGE\', or \'QUIT\'." << endl << endl;
		}
	} //end of while loop

	return 0;
} //end of main



//--------------------------------------------------------FUNCTIONS------------------------------------------------------------


//function that asks user for student information and stores it
void collect_student_info(Student* s) {
	char f[100]; //stores first name
	char l[100]; //stores last name
	int i; //stores ID number
	float g; //stores gpa

	//prompt for new Student's first name, last name, student id, and GPA
	cout << "\nFirst Name: ";
	cin.clear();
	cin.ignore(10000,'\n');
	cin >> f;
	s->setFirstName(f);

	cout << "Last Name: ";
	cin.clear();
	cin.ignore(10000,'\n');
	cin >> l;
	s->setLastName(l);

	cout << "ID Number: ";
	cin.clear();
	cin.ignore(10000,'\n');
	cin >> i;
	s->setID(i);

	cout << "GPA: ";
	cin.clear();
	cin.ignore(10000,'\n');
	cin >> g;
	s->setGPA(g);
	//cin.get();
}



//function to insert new Node for new Student into Linked List, sorting by Student ID number (least to greatest)
//using recursion 
void add_student(Node* &start, Node* prev, Node* student_node) 
{
	bool found = false;
	Node* current = start;

	if (start != NULL) { 
		if (student_node->getStudent()->getID() <=  start->getStudent()->getID()) {
			found = true; //insertion location found
			student_node->setNext(current);
			if (prev != NULL) {
				prev->setNext(student_node);
			}
			cout << "\nStudent added. Enter a command to continue or \'QUIT\' to exit." << endl << endl;
			return;
		} else {
			if (found == false && current->getNext() != NULL) {
				prev = current;
				Node* new_start = current->getNext();
				add_student(new_start, prev, student_node);
			} else if (current->getNext() == NULL) { //append if no smaller IDs found
				current->setNext(student_node);
				student_node->setNext(NULL);
				cout << "\nStudent added. Enter a command to continue or \'QUIT\' to exit." << endl << endl;
				return;
			}
		}
	}
}




//function to print all Students currently stored
//GPA shown to 2 decimal places
//using recursion
void print_student_list(Node* n) 
{
	if (n != NULL) { //if list is not empty
		cout << "\nFirst Name: " << n->getStudent()->getFirstName() << endl;
		cout << "Last Name: " << n->getStudent()->getLastName() << endl;
		cout << "ID: " << n->getStudent()->getID() << endl;
		cout << "GPA: " << fixed << setprecision(2) << n->getStudent()->getGPA() << endl << endl;
		print_student_list(n->getNext()); //recursively call print until last Node is printed
	}
	return;
}


//function to delete Student from Linked List given Student ID
//using recursion
void delete_student(Node* &start, Node* prev, int id)
{
	Node* current = start;
	
	if (start != NULL) {
		if (start->getStudent()->getID() == id) {
            start = start->getNext();
    		return;
        }
		
		if (current->getStudent()->getID() == id) {  //match is found
			if (current->getNext() == NULL) { //if match is last node in list
				if (prev != NULL) {
					prev->setNext(NULL);
				}
				delete current;
				cout << "\nStudent with ID number " << id << " has been deleted." << endl;
				cout << "Enter a command to continue or \'QUIT\' to exit." << endl << endl;
				return;
			} else if (prev != NULL) {
				prev->setNext(current->getNext());
				//deletes the current nodt\e
				delete current;
				cout << "\nStudent with ID number " << id << " has been deleted." << endl;
				cout << "Enter a command to continue or \'QUIT\' to exit." << endl << endl;
				return;
			}
		}
		else {
			Node* next_start = current->getNext();
			delete_student(next_start, current, id);
		}
	}
}




//function that prints the average GPA of all Students
//average GPA shown to 2 decimal places
//using recursion
//total stores total GPA of students
//count stores number of students
void average_gpa(Node* head, float total, int count)
{
	if (head != NULL) { //if list is not empty
		total += head->getStudent()->getGPA();
		count++;
		head = head->getNext();
		average_gpa(head, total, count); //recursively call the function until the GPA of all students has been added to total
	} else if (head == NULL and total > 0) { //if GPA of all students has been added to total
		float avg = total / count;
		cout << "\nAverage GPA: " << fixed << setprecision(2) << avg << endl;
		return;
	} else { //if list is empty
		cout << "\nThere are currently no students in the list so an average GPA cannot be calculated." << endl;
		return;
	}

}














/*
//function to delete Student from Linked List given Student ID
//using recursion
void delete_student(Node* &start, Node* prev, int id)
{
	Node* current = start;
	bool found = false;

	if (current != NULL) {

		if (current->getStudent()->getID() == id) { //match is found
			found = true;
			if (prev == NULL) { //Node to be deleted is the head
				start = start->getNext();
				delete current;
				cout << "\nStudent with ID number " << id << " has been deleted." << endl;
				cout << "Enter a command to continue or \'QUIT\' to exit." << endl << endl;
				return;
			} else if (prev != NULL) { //Node to be deleted is not the head
				prev->setNext(current->getNext()); //fix links
				delete current;
				cout << "\nStudent with ID number " << id << " has been deleted." << endl;
				cout << "Enter a command to continue or \'QUIT\' to exit." << endl << endl;
				return;
			}
		}

		//recursively call function until match is found of end of list is reached
		if (found == false && current->getNext() != NULL) {
			Node* n = current->getNext();
			delete_student(n, current, id);
		}

		if (found == false && current->getNext() == NULL) {
			cout << "Student not found. Please check to make sure you entered the correct ID number." << endl;
			cout << "Enter a command to continue or \'QUIT\' to exit." << endl << endl;
			return;
		}

	}

	return;
}

*/




