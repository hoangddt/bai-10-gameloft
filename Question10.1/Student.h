#pragma once
#include "People.h"

class Student: public People
{
public:
	Student();
	~Student();
	void displayInfo() const;
	int getGrade() const;
	void setGrade(int grade);
	int getNumberOfProject() const;
	void setNumberOfProject(int n);
	const float* getSoreOfEachProject() const;
	void setSoreOfEachProject(int position, float score);
	float getAverageScore() const;
protected:
	int mGrade;
	int mNumberOfProject;
	float* mScores;
	float avegareScore();
};