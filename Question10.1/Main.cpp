#include <cstdio>

#include "People.h"
#include "Staff.h"
#include "Student.h"
#include "Teacher.h"
#include "Node.h"
#include "functionality.h"

int main(int argc, char const *argv[])
{
	// Create 5 staff, 5 teacher, and 5 student
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

	// Create a list and add to list
	Node *list = NULL;
	
	// Add 5 staff to list
	for (int i = 0; i < numberOfInstance; ++i)
	{
		Node::add(list, staffs[i]);
	}

	// Add 5 teacher to list
	for (int i = 0; i < numberOfInstance; ++i)
	{
		Node::add(list, teachers[i]);
	}

	// Add 5 student to list
	for (int i = 0; i < numberOfInstance; ++i)
	{
		Node::add(list, students[i]);
	}


	
	return 0;
}