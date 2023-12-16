#include <iostream>
#include <string>
#include <array>
#include "roster.h"
#include "student.h"
#include "degree.h"
using namespace std;

//PART E - CREATION OF THE ROSTER CLASS, Definition of functions/methods.

const static int studentNum = 5;
Student* classRosterArray[studentNum] = { nullptr, nullptr, nullptr, nullptr, nullptr };
//Class Constructor
Roster::Roster(int studentCount) {
	this->ind = 0;
	for (int i = 0; i < studentNum; i++) {
		if (i < studentCount) {
			this->classRosterArray[i] = new Student;
		} else {
			this->classRosterArray[i] = nullptr;
		}
	}
	return;
}

//Part E2 - Creation of Parse function and adding to 
void Roster::parse(string studentData) {
	 string studentID, firstName, lastName, emailAddress;

	if (ind < studentNum) {
		classRosterArray[ind] = new Student();

		size_t rhs = studentData.find(",");
		string studentID = studentData.substr(0, rhs);
		classRosterArray[ind]->setStudentID(studentID);

		size_t lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		string firstName = studentData.substr(lhs, rhs - lhs);
		classRosterArray[ind]->setFirstName(firstName);

		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		string lastName = studentData.substr(lhs, rhs - lhs);
		classRosterArray[ind]->setLastName(lastName);

		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		string emailAddress = studentData.substr(lhs, rhs - lhs);
		classRosterArray[ind]->setEmailAddress(emailAddress);

		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		int age = stoi(studentData.substr(lhs, rhs - lhs));
		classRosterArray[ind]->setAge(age);

		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));
		classRosterArray[ind]->setDaysInCourse(daysInCourse1,daysInCourse2,daysInCourse3);

		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		string strDegreeProgram = studentData.substr(lhs, rhs - lhs);

		DegreeProgram degree = DegreeProgram::SOFTWARE;
		if (strDegreeProgram == "SECURITY") {
			classRosterArray[ind]->setDegreeProgram(degree = DegreeProgram::SECURITY);
		}
		else if (strDegreeProgram == "NETWORK") {
			classRosterArray[ind]->setDegreeProgram(degree = DegreeProgram::NETWORK);
		}
		else if (strDegreeProgram == "SOFTWARE") {
			classRosterArray[ind]->setDegreeProgram(degree = DegreeProgram::SOFTWARE);
		}
		ind++;
	}
}

//Part 3.a - Definition of the add function.
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, 
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

		int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3};

		if (ind < studentNum) {
			classRosterArray[ind] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
			ind++;
		}
	}

//Part 3.b - Definition of the remove function.
void Roster::remove(string studentID) {
	bool studentSelected = false;
	for (int i = 0; i < studentNum; i++) {
		if (classRosterArray[i] == nullptr) {
			continue;
		}
		else if (studentID == classRosterArray[i]->getStudentID()) {
			classRosterArray[i] = nullptr;
			studentSelected = true;
			break;
		}
	}
	if (studentSelected == false) {
		cout << "The Student With ID: " << studentID << " Was Not Found." << endl;
	}
	else if (studentSelected == true) {
		cout << "The Following Student ID Was Removed: " << studentID << endl;
	}
}

//Part 3.c - Definition of the print all function.
void Roster::printAll() {
	for (int i = 0; i < studentNum; i++) {
		if (classRosterArray[i] == nullptr) {
			continue;
		}
		else (classRosterArray[i]->print());
	}
	return;
}

//Part 3.d - Definition of the (print by average days in course) function.
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < studentNum; i++) {
		if (studentID == classRosterArray[i]->getStudentID()) {
			cout <<"Student ID: " << studentID << ", " << " average days in course: "
				<< ((classRosterArray[i]->getDaysInCourse()[0] +
					classRosterArray[i]->getDaysInCourse()[1] +
					classRosterArray[i]->getDaysInCourse()[2]) / 3) << endl;
		}
	}
	return;
}

//Part 3.e -  Definition of the (print invalid emails) function.
void Roster::printInvalidEmails() {
	cout << endl;
	cout << "Displaying invalid e-mail addresses:" << endl;
	cout << endl;
	for (int i = 0; i < studentNum; i++) {
		if ((classRosterArray[i]->getEmailAddress()).find('@') == -1) {
			cout << classRosterArray[i]->getEmailAddress() << " - is invalid." << endl;
		}
		else if ((classRosterArray[i]->getEmailAddress()).find(' ') != -1) {
			cout << classRosterArray[i]->getEmailAddress() << " - is invalid." << endl;
		}
		else if ((classRosterArray[i]->getEmailAddress()).find('.') == -1) {
			cout << classRosterArray[i]->getEmailAddress() << " - is invalid." << endl;
		}
	} 
	return;
}

//Part 3.f - Definition of the (print by degree program) function.
void Roster::printByDegreeProgram(DegreeProgram degree) {
	string strDegree;
	if (degree == DegreeProgram::SECURITY) {
		strDegree = "SECURITY";
	}
	else if (degree == DegreeProgram::NETWORK) {
		strDegree = "NETWORK";
	}
	else if (degree == DegreeProgram::SOFTWARE) {
		strDegree = "SOFTWARE";
	}
	else {
		strDegree = "ERROR / INVALID";
	}
	cout << "Showing students in degree program: " << strDegree << endl;
	int studentCount = 0;
	for (int i = 0; i < studentNum; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degree) {
			classRosterArray[i]->print();
			++studentCount;
		}
	}
	if (studentCount == 0) {
		cout << "ERROR / INVALID" << endl;
	}
	return;
}
string Roster::getStudentID(int ind) {
	string studentID = classRosterArray[ind]->getStudentID();
	return studentID;
};

//Part F.5 - Destructor defined.
Roster::~Roster() {
	for (int i = 0; i < this->studentNum; i++) {
		delete this->classRosterArray[i];
	}
}