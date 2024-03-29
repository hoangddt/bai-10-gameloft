#pragma once
#include "Date.h"
#include "Subject.h"
#include "Student.h"
#include "People.h"
#include "Staff.h"
#include "Teacher.h"
#include "Node.h"
#include "Student.h"
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
// Return validDate that is verified
Date verifyDate(int day, int month, int year);

// Input enum - Output string
// ex input MATHS (enum) output "MATHS" string
void retrieveSubjectInString(char *result, Subject sub);

// Add array of instance is created by People
// to node (linked-list)
// elements is array of pointer
void addInstanceToNode(	Node* &node, 
						People* elements[5],
						int numberOfInstance);

// Add to student score for each project
// eg: initScoreForStudent(student, 3, 7.5, 1.5, 5.6)
void initScoreForStudent(	Student *student,
							int numberOfProj,
							... );

// print student have score > score
// in a node from startFrom position
void printHighScoreStudent(Node* node, int startFrom, float score);

// Create People instance and use copy constructor
void testPeopleCopyConstructor();

// CLone current list, return list is created
Node* cloneList(Node* list);

// Sort list group by type: staff first, teacher next, and student last
void sortList(Node* &list);


// Write a list of student to file
// provide list is contain linked-list of data
// PATH is the path we want to output eg: "D:\\out.txt"
void writeListStudentToFile(Node *list, const char *PATH);

// Load student data from file
// and add to list (append)
void loadStudentFromFile(Node* &list, const char *PATH);

// Try to read and printf all information to screen
// for testing purpose
void readStudentFile(const char *PATH);

// append source to des, whithout create new
void appendList(Node* &des, Node* src);