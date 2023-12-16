#pragma once
#include <iostream>
#include <string>
#include <array>
#include "degree.h"
#include "student.h"
using namespace std;

//PART E - CREATION OF THE ROSTER CLASS

class Roster {

public:

	void parse(string studentData);
	Roster(int studentNum);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	string getStudentID(int);
	int ind = 0;
	const static int studentNum = 5;
	//Part E.1 - Array of Pointers
	Student* classRosterArray[studentNum] = { nullptr, nullptr, nullptr, nullptr, nullptr };
	~Roster();
};