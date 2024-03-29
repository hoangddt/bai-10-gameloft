#include <cstdio>
#include <vld.h>
#include "People.h"
#include "Staff.h"
#include "Student.h"
#include "Teacher.h"
#include "Node.h"
#include "functionality.h"

int main(int argc, char const *argv[])
{
	// 10.2 - Create 5 staff, 5 teacher, and 5 student
	int numberOfInstance = 5;


	Staff *staffs[] = { new Staff("Staff 1"),
						new Staff("Staff 2"),
						new Staff("Staff 3"),
						new Staff("Staff 4"),
						new Staff("Staff 5")
					};

	Teacher *teachers[] = { new Teacher("Teacher 1"),
							new Teacher("Teacher 2"),
							new Teacher("Teacher 3"),
							new Teacher("Teacher 4"),
							new Teacher("Teacher 5")
					};

	Student *students[] = { new Student("Student 1"),
							new Student("Student 2"),
							new Student("Student 3"),
							new Student("Student 4"),
							new Student("Student 5")
					};

	initScoreForStudent(students[0], 3, 7.5, 7.5, 5.6);
	initScoreForStudent(students[1], 4, 8.5, 7.5, 7.6, 5.6);
	initScoreForStudent(students[2], 3, 5.5, 1.5, 5.6);
	initScoreForStudent(students[3], 3, 7.5, 8.5, 5.6);
	initScoreForStudent(students[4], 3, 7.5, 9.5, 5.6);
	
	// Display Info
	printf("Display Info of All Student:\n");
	for (int i = 0; i < numberOfInstance; ++i)
	{
		students[i]->displayInfo();
		printf("---------***--------\n\n");
	}

	// 10.2 - Create a list and add to list
	Node *list = NULL;


	// Add 5 staff to list
	for (int i = 0; i < numberOfInstance; ++i)
	{
		Node::add(list, staffs[i]);
	}
	// Add 5 student to list
	for (int i = 0; i < numberOfInstance; ++i)
	{
		Node::add(list, students[i]);
	}
	// Add 5 teacher to list
	for (int i = 0; i < numberOfInstance; ++i)
	{
		Node::add(list, teachers[i]);
	}

	// Sort list group by type: staff first, teacher next, and student last
	// sortList(list);

	// 10.2- print student have score > 5.0
	printf("--------Print Info Of Student have score > 5.0------\n");
	int startFrom = 10;
	printHighScoreStudent(list, startFrom, 5.0);
	
	// End 10.2 -----------------
	
	// 10.3 - clone a list
	// Clone list to otherList
	printf("Calling cloneList\n");
	Node *otherList = cloneList(list);
	otherList;
	// End 10.3 -----------------

	// 10.4 - static method to remove element of node
	// this method will remove last element
	for (int i = 0; i < 13; ++i)
	{
		Node::remove(list);
	}
	// End 10.4 ------------------

	// 10.5 - Save a list of student to file
	char* PATH = "ouput.txt";
	writeListStudentToFile(otherList, PATH);

	// printf("\n\n Read from file to screen\n\n");
	// readStudentFile("ouput.txt");

	// 10.5 - Load list student from existing file
	printf("Prepare to load from file \n");
	Node* studentList = NULL;
	loadStudentFromFile(studentList, PATH);
	studentList;
	// End 10.5 - End question 10 ------------------
	
	Node::freeNode(list);
	Node::freeNode(otherList);
	Node::freeNode(studentList);
	return 0;
}