#include "functionality.h"

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

// Create People instance and use copy constructor
void testPeopleCopyConstructor()
{
	People A("A");
	A.displayInfo();
	People B(A);
	A.displayInfo();

	People *C = new People("Hoang");
	C->displayInfo();
	People D(*C);
	D.displayInfo();
	delete C;
}

// CLone current list, return list is created
Node* cloneList(Node* list)
{
	if (list == NULL)
		return NULL;

	Node *pivot = list;
	Node *newlist = NULL;
	printf("\nExecuting cloneList....\n");
	while (pivot != NULL)
	{
		Teacher *isTeacher = dynamic_cast<Teacher*> (pivot->data);
		Staff *isStaff = dynamic_cast<Staff*> (pivot->data);
		Student *isStudent = dynamic_cast<Student*> (pivot->data);
		
		People *newElement;
		
		if (isTeacher)
		{
			// Because Teacher dirived from Staff, dynamic_cast will return true
			// for both isStaff and isTeacher if it is Teacher
			// So we disable isStaff to avoid copy by Staff constructor
			isStaff = NULL;
			// only use Teacher constructor
			Teacher *teacher = new Teacher(*(isTeacher));
			newElement = teacher;
		}
		if (isStudent)
		{
			Student *student = new Student(*(isStudent));
			newElement = student;
		}
		if (isStaff)
		{
			Staff *staff = new Staff(*(isStaff));
			newElement = staff;
		}

		Node::add(newlist, newElement);

		pivot = pivot->next;
	}

	return newlist;
}


// Sort list group by type: staff first, teacher next, and student last
void sortList(Node* &list)
{
	Node* listStaff = NULL;
	Node* listTeacher = NULL;
	Node* listStudent = NULL;

	Node *pivot = list;
	Node *newlist = NULL;

	while (pivot != NULL)
	{
		Teacher *isTeacher = dynamic_cast<Teacher*> (pivot->data);
		Staff *isStaff = dynamic_cast<Staff*> (pivot->data);
		Student *isStudent = dynamic_cast<Student*> (pivot->data);
		
		People *newElement;
		
		if (isTeacher)
		{
			// Because Teacher dirived from Staff, dynamic_cast will return true
			// for both isStaff and isTeacher if it is Teacher
			// So we disable isStaff to avoid copy by Staff constructor
			isStaff = NULL;
			// only use Teacher constructor
			Teacher *teacher = new Teacher(*(isTeacher));
			newElement = teacher;
			Node::add(listTeacher, newElement);
		}
		if (isStudent)
		{
			Student *student = new Student(*(isStudent));
			newElement = student;
			Node::add(listStudent, newElement);
		}
		if (isStaff)
		{
			Staff *staff = new Staff(*(isStaff));
			newElement = staff;
			Node::add(listStaff, newElement);
		}

		pivot = pivot->next;
	}
	appendList(newlist, listStaff);
	appendList(newlist, listTeacher);
	appendList(newlist, listStudent);

	Node::freeNode(list);
	list = newlist;
}



// Write a list to file
// provide list is contain linked-list of data
// PATH is the path we want to output eg: "D:\\out.txt"
void writeListStudentToFile(Node *list, const char *PATH)
{
	ofstream myfile(PATH);
	if (myfile.is_open())
	{
		
		Node *pivot = list;
		while (pivot != NULL)
		{
			Student *isStudent = dynamic_cast<Student*> (pivot->data);
			if (isStudent)
			{
				// performe write action
				Student *student = isStudent;
				myfile<<student->getName()<<endl;
				myfile<<student->getIDCode()<<endl;

				Date bd = student->getBirthday();
				myfile<<bd.day<<" "<<bd.month<<" "<<bd.year<<endl;
				myfile<<student->getGrade()<<endl;

				int numberOfProj = student->getNumberOfProject();
				myfile<<numberOfProj<<endl;
				
				const float* scores = student->getSoreOfEachProject();
				for (int i = 0; i < numberOfProj; ++i)
				{
					if (i == numberOfProj-1)
					{
						myfile<<scores[i];
						continue;
					}
					myfile<<scores[i]<<" ";
				}
				if (pivot->next != NULL)
				{
					myfile<<endl;
				}
				
			}

			// move forward in linked-list
			pivot = pivot->next;
		}
		myfile.close();
	}
	else
	{
		printf("Can not write to file: %s\n", PATH);
	}
}

void loadStudentFromFile(Node* &list, const char *PATH)
{
	ifstream myfile(PATH);

	if (myfile.is_open())
  	{
  		
  		while (!myfile.eof())
  		{
  			
			string strName;
  			int IDCode,
  				day,
  				month,
  				year,
  				grade,
  				numberOfProj;

  			getline(myfile, strName);
			const char *name = strName.c_str();
			
  			myfile>>IDCode;
  			myfile>>day>>month>>year;
  			myfile>>grade;
  			myfile>>numberOfProj;

  			float *scores = new float[numberOfProj];
  			for (int i = 0; i < numberOfProj; ++i)
  			{
  				myfile>>scores[i];
  			}
  			char next;
  			myfile.get(next);

  			// Create a student object with given information
  			Student *student = new Student(name);
  			
  			student->setName(name);
  			student->setIDCode(IDCode);
  			student->setBirthday(day, month, year);
  			student->setGrade(grade);
  			student->setNumberOfProject(numberOfProj);

  			for (int i = 0; i < numberOfProj; ++i)
			{
				student->setSoreOfEachProject(i, scores[i]);
			}
			Node::add(list, student);
			
  		}
    	myfile.close();
	}
	else
		printf("Can not open file to read: %s\n", PATH);
}


void readStudentFile(const char *PATH)
{
	ifstream myfile(PATH);

	if (myfile.is_open())
  	{
  		
  		while (!myfile.eof())
  		{
  			//char name[50];
			string strName;
  			int IDCode,
  				day,
  				month,
  				year,
  				grade,
  				numberOfProj;

  			getline(myfile, strName);
			const char *name = strName.c_str();
			
  			myfile>>IDCode;
  			myfile>>day>>month>>year;
  			myfile>>grade;
  			myfile>>numberOfProj;

  			float *scores = new float[numberOfProj];
  			for (int i = 0; i < numberOfProj; ++i)
  			{
  				myfile>>scores[i];
  			}
  			char next;
			myfile.get(next);
			//getline(myfile, strName);
  			
			// print to screen
			cout<<name<<endl;
			cout<<IDCode<<endl;
  			cout<<day<<" "<<month<<" "<<year<<endl;
  			cout<<grade<<endl;
  			cout<<numberOfProj<<endl;
  			for (int i = 0; i < numberOfProj; ++i)
  			{
  				cout<<scores[i]<<" ";
  			}
  			cout<<endl;
			printf("Continue reading?..\n");
			int tempToRead;
			cin>>tempToRead;
			
  		}
    	myfile.close();
	}
	else
		printf("Can not open file to read: %s\n", PATH);
}

// append source to des, whithout create new
void appendList(Node* &des, Node* src)
{


	if (des == NULL)
	{
		des = src;
		return;
	}

	// Go to last element of destincnation
	Node* pivot = des;
	Node* last;

	while (pivot != NULL)
	{
		last = pivot;
		pivot = pivot->next;
	}

	last->next = src;
}