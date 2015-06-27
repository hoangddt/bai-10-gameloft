#pragma once
#include "People.h"
#include "Staff.h"

// Data type enum Subject {MATHS, PHYS, ENGLISH}
#include "Subject.h"


class Teacher: public People, public Staff
{
public:
	Teacher();
	~Teacher();
	void displayInfo() const;
	int getClass() const;
	void setClass(int cla);
	Subject getSubject() const;
	void setSubject(Subject subject);
	Subject getSecondSubject() const;
	void setSecondSubject(Subject subject);
private:
	int mClass;
	Subject mSubject;
	Subject mSecondSubject;
};