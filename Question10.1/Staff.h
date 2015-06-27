#pragma once
#include "People.h"

class Staff: public People
{
public:
	Staff();
	~Staff();
	void displayInfo() const;
	int getDepartmentID() const;
	void setDepartmentID(int depID);
	Date getJoinedDay() const;
	void setJoinedDay(int day, int month, int year);
	int getLevel() const;
	void setLevel(int level);
private:
	int mDepartmentID;
	Date mJoinedDay;
	int mLevel;
};