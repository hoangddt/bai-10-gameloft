#pragma once
#include "People.h"
#include "Staff.h"

// Data type enum Subject {MATHS, PHYS, ENGLISH}
#include "Subject.h"


class Teacher: public Staff
{
public:
	Teacher(const char *name);
	// Teacher(Teacher *otherTeacher);
	Teacher(const Teacher &otherTeacher);
	~Teacher();
	void displayInfo() const;
	int getClass() const;
	void setClass(int cla);
	Subject getSubject() const;
	void setSubject(Subject subject);
	Subject getSecondSubject() const;
	void setSecondSubject(Subject subject);

	static int count;
private:
	int mClass;
	Subject mSubject;
	Subject mSecondSubject;
};