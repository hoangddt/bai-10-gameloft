#include <cstdio>
#include "Student.h"

Student::Student()
:People()
{
	// init Scores with 1 (project)
	// will change this in method setNumberOfProject
	mScores = new float[1];
}
Student::~Student()
{
	delete []mScores;
}
void Student::displayInfo() const
{
	People::displayInfo();

	int numProject = getNumberOfProject();
	const float* scores = getSoreOfEachProject();
	
	printf("Grade: %d, Avegage Score: %0.2f\n");
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
	return *mSrores;
}
void Student::setSoreOfEachProject(int position, float score)
{
	mScores[position] = score;
}
float Student::getAverageScore() const
{
	float avegareScore = 0,
		  sum = 0;
	int numProject;
	for (int i = 0; i < numProject; ++i)
	{
		sum += mScores[i];
	}

	avegareScore = sum / numProject;

	return avegareScore;
}