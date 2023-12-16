#include <iostream>
#include <string>
#include <array>
#include "roster.h"
#include "student.h"
#include "degree.h"
using namespace std;

// PART F - DEMONSTRATION USING THE FUNCTION CALLS TO ACHIEVE REQUIRED RESULTS.

int main() {
	const string studentData[] =

	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Joao,Miranda,joao.miranda423@gmail.com,20,10,20,30,SOFTWARE"
	};

	//Part F.1 
	cout << "C867 ~ Scripting and Programming - Applications" << endl;
	cout << "Programming Language Used: C++" << endl;
	cout << "Student ID# : 010548237" << endl;
	cout << "Name: Joao Marcelo Martins Miranda" << endl;
	cout << endl;
	cout << "Displaying all students:" << endl;

	//Part F.2 - Instance of the Roster class
	class Roster * classRoster = new Roster(4);

	//Part F.3 - Adding the students to classRoster
	for (int i = 0; i < 5; i++) {
		classRoster->parse(studentData[i]);
	};

	//Part F.4 - Conversion of pseudo code
	classRoster->printAll();
	cout << endl;

	classRoster->printInvalidEmails();
	cout << "(Check for missing '@', '.' or spaces)" << endl;
	cout << endl;

	for (int i = 0; i < 5; i++) {
		classRoster->printAverageDaysInCourse(classRoster->getStudentID(i));
	}
	cout << endl;

	classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << endl;

	classRoster->remove("A3");
	cout << endl;

	classRoster->printAll();
	cout << endl;

	cout << "Removing Student ID: A3, Again." << endl;
	classRoster->remove("A3");
	cout << endl;

	cout << "DONE." << endl;

	delete classRoster;
	return 0;
}
	
