#include <iostream>
#include <string>
#include <array>
#include "student.h"
#include "degree.h"
using namespace std;

//PART D - CREATION OF THE STUDENT CLASS

Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->daysInCourse[0] = 0;
	this->daysInCourse[1] = 0;
	this->daysInCourse[2] = 0;
	this->degreeProgram;
}
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysInCourse[0] = daysInCourse[0];
	this->daysInCourse[1] = daysInCourse[1];
	this->daysInCourse[2] = daysInCourse[2];
	this->degreeProgram = degreeProgram;
}

//Part 2.e - print functions-----------------------------------------------------
void Student::printID(){
	cout << studentID;
	return;
}

void Student::printFirstName() {
	cout << firstName << endl;
	return;
}

void Student::printLastName() {
	cout << lastName << endl;
	return;
}
void Student::printEmailAddress() {
	cout << emailAddress << endl;
	return;
}

void Student::printAge() {
	cout << age << endl;
	return;
}

void Student::printDaysToComp() {
	cout << daysInCourse[0] << " " << daysInCourse[1] << " " << daysInCourse[2] << endl;
	return;
}

void Student::printDegreeProgram() {
	string strDegree;
	if (degreeProgram == DegreeProgram::SECURITY) {
		strDegree = "SECURITY";
	}
	else if (degreeProgram == DegreeProgram::NETWORK) {
		strDegree = "NETWORK";
	}
	else if (degreeProgram == DegreeProgram::SOFTWARE) {
		strDegree = "SOFTWARE";
	}
	cout << strDegree << endl;
	return;
}

void Student::print() {
	string strDegree;
	if (degreeProgram == DegreeProgram::SECURITY) {
		strDegree = "SECURITY";
	}
	else if (degreeProgram == DegreeProgram::NETWORK) {
		strDegree = "NETWORK";
	}
	else if (degreeProgram == DegreeProgram::SOFTWARE) {
		strDegree = "SOFTWARE";
	}
	else {
		strDegree = "NOT VALID / NOT AVAILABLE";
	}
	cout << studentID << '\t' << getFirstName() << "\t" << getLastName() << "\t" << getAge()
		<< "\t{" << getDaysInCourse()[0] << "," << getDaysInCourse()[1] << "," << getDaysInCourse()[2] << "}\t" << strDegree << endl;
	return;
}

//Part 2.a - getters (accessors)-----------------------------------------------------
string Student::getStudentID() {
	return studentID;
};
string Student::getFirstName() {
	return firstName;
};
string Student::getLastName() {
	return lastName;
};
string Student::getEmailAddress() {
	return emailAddress;
};
int Student::getAge() {
	return age;
};
int* Student::getDaysInCourse() {
	return daysInCourse;
};
DegreeProgram Student::getDegreeProgram() {
	return degreeProgram;
};

//Part 2.b setters (mutators)-----------------------------------------------------
void Student::setStudentID(string studentID) {
	this->studentID = studentID;
};
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(string lastName) {
	this->lastName =  lastName;
}; 
void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
};
void Student::setAge(int age) {
	this->age = age;
};
void Student::setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
	for (int i = 0; i < 3; i++)
		this->daysInCourse[0] = daysInCourse1;
		this->daysInCourse[1] = daysInCourse2;
		this->daysInCourse[2] = daysInCourse3;
};
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

//destructor
Student::~Student() {};