#include <cstdio>
#include "Student.h"

int Student::count = 0;

Student::Student(const Student &otherStudent)
:People(otherStudent.getName())
{
	setGrade(otherStudent.getGrade());
	int numOfProject = otherStudent.getNumberOfProject();
	mScores = NULL;
	setNumberOfProject(numOfProject);
	const float *scores = otherStudent.getSoreOfEachProject();
	for (int i = 0; i < numOfProject; ++i)
	{
		setSoreOfEachProject(i, scores[i]);
	}
	

	Date birthday = otherStudent.getBirthday();
	setBirthday(birthday.day, birthday.month, birthday.year);
	count++;
}

Student::Student(const char *name)
:People(name)
{
	// init Scores with 1 (project)
	// will change this in method setNumberOfProject
	mGrade = 10;
	mScores = new float[1];
	count++;
}
Student::~Student()
{
	printf("Destroying Student: %s\n", getName());
	delete []mScores;
}
void Student::displayInfo() const
{
	People::displayInfo();

	int numProject = getNumberOfProject();
	const float* scores = getSoreOfEachProject();
	
	printf("Grade: %d, Avegage Score: %0.2f\n", getGrade(), getAverageScore());
	printf("Number of Project: %d\n", numProject);
	
	printf("Score of Each project: \n");
	for (int i = 0; i < numProject; ++i)
		{
			printf("%.1f, ", scores[i]);
		}
	printf("\n");

}
int Student::getGrade() const
{
	return mGrade;
}
void Student::setGrade(int grade)
{
	mGrade = grade;
}
int Student::getNumberOfProject() const
{
	return mNumberOfProject;
}
void Student::setNumberOfProject(int n)
{
	if (n > 0)
	{
		mNumberOfProject = n;
		// delete to reallocate
		delete []mScores;
		// allocate with new numberOfProject value
		mScores = new float[mNumberOfProject];
	}
}
const float* Student::getSoreOfEachProject() const
{
	return mScores;
}
void Student::setSoreOfEachProject(int position, float score)
{
	mScores[position] = score;
}
float Student::getAverageScore() const
{
	float avegareScore = 0,
		  sum = 0;
	int numProject = getNumberOfProject();
	for (int i = 0; i < numProject; ++i)
	{
		sum += mScores[i];
	}

	avegareScore = sum / numProject;

	return avegareScore;
}