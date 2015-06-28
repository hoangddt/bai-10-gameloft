#include "functionality.h"
#include <cstring>
Date verifyDate(int day, int month, int year)
{
	Date validDate;
	// make sure year contain 4 digits
	if (year / 1000 > 0)
	{
		validDate.year = year;
	}

	if (month > 0 && month < 13)
	{
		validDate.month = month;
	}
	else
	{
		// set to 1 default
		validDate.month = 1;
	}

	int maxDay = 0;
	switch (validDate.month)
	{
		case 2:
			if (validDate.year % 4 == 0)
			{
				maxDay = 29;
			}
			else maxDay = 28;
			break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			maxDay = 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			maxDay = 30;
			break;

		default:
			maxDay = 0;
	}

	if (day > 0 && day <= maxDay)
	{
		validDate.day = day;
	}



	return validDate;
}

// Check Subject in enum and assign to result parameter in string
void retrieveSubjectInString(char *result, Subject sub)
{
	switch (sub)
	{
		case MATHS:
			strcpy(result, "MATHS");
			break;
		case PHYS:
			strcpy(result, "PHYS");
			break;
		case ENGLISH:
			strcpy(result, "ENGLISH");
			break;
		default: strcpy(result, "UNKNOW");
	}
}

// Add array of instance is created by People
// to node (linked-list)
// elements is array of pointer
void addInstanceToNode(	Node* &node, 
						People* elements[5],
						int numberOfInstance)
{
	for (int i = 0; i < numberOfInstance; ++i)
	{
		Node::add(node, elements[i]);
	}
}


// Add to student score for each project
// eg: initScoreForStudent(student, 3, 7.5, 1.5, 5.6)
void initScoreForStudent(	Student *student,
							int numberOfProj,
							... )
{
	student->setNumberOfProject(numberOfProj);
	
	va_list vl;
	va_start(vl, numberOfProj);

	for (int i = 0; i < numberOfProj; ++i)
	{
		double score = va_arg(vl, double);
		// printf("%d - Got score: %.1f\n", i, score);
		student->setSoreOfEachProject(i, score);
	}

	va_end(vl);

}

// print student have score > score
// in a node from startFrom position
void printHighScoreStudent(Node* node, int startFrom, float score)
{
	Node* pivot = node;
	int count = 0;
	while (pivot != NULL)
	{
		if (count >= startFrom)
		{
			Student *stu = (Student*) pivot->data;
			float averageScore = stu->getAverageScore();
			// printf("Average Score: %.1f\n", averageScore);
			if ( averageScore > score)
			{
				stu->displayInfo();
				printf("=====***=====\n\n");
			}
		}
		pivot = pivot->next;
		count++;
	}
}