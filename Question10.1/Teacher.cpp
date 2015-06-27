#include <cstdio>
#include "Teacher.h"


Teacher::Teacher()
:People(),
Staff()
{
}

Teacher::~Teacher()
{
}

void Teacher::displayInfo() const
{
	People::displayInfo();
	Staff::displayInfo();
	printf("Class: %d\n", getClass());
	char *subject = new char[8];

	// retrieve subject
	Subject sub = getSubject();
	retrieveSubjectInString(subject, sub);
	printf("Subject: %s\n", subject);

	// retrieve subject
	sub = getSecondSubject();
	retrieveSubjectInString(subject, sub);
	printf("Second Subject: %s\n", subject);

	delete []subject;
}
int Teacher::getClass() const
{
	return mClass;
}
void Teacher::setClass(int cla)
{
	if (cla > 0)
	{
		mClass = cla;
	}
}
Subject Teacher::getSubject() const
{
	return mSubject;
}
void Teacher::setSubject(Subject subject)
{
	mSubject = subject;
}
Subject Teacher::getSecondSubject() const
{
	return mSecondSubject;
}
void Teacher::setSecondSubject(Subject subject)
{
	mSecondSubject = subject;
}