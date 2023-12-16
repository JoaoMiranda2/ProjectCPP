#pragma once
#include <iostream>
#include <string>
#include <array>
#include "degree.h"
using namespace std;

//PART D - CREATION OF THE STUDENT CLASS

class Student {
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[3];
	DegreeProgram degreeProgram;

public:
	//Part 2.d - constructor
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	//Declaration of destructor
	~Student();
	//Part 2.a - getters (accessors)
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysInCourse();
	DegreeProgram getDegreeProgram();

	//Part 2.b - setters (mutators)
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
	void setDegreeProgram(DegreeProgram degreeProgram);

	//Part 2.e - print functions
	void print();
	void printID();
	void printFirstName();
	void printLastName();
	void printEmailAddress();
	void printAge();
	void printDaysToComp();
	void printDegreeProgram();
};
