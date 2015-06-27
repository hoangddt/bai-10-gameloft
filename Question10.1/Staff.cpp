#pragma once
#include <cstdio>
#include "Staff.h"

Staff::Staff():People()
{
}

Staff::~Staff()
{
}

void Staff::displayInfo() const
{
	People::displayInfo();
	printf("DepartmentID: %d - JoinedDay: %d/%d/%d - Level: %d\n",
		getDepartmentID,
		getJoinedDay,
		mJoinedDay.day,
		mJoinedDay.month,
		mJoinedDay.year,
		mLevel);
}

int Staff::getDepartmentID() const
{
	return mDepartmentID;
}

void Staff::setDepartmentID(int depID)
{
	mDepartmentID = depID;
}

Date Staff::getJoinedDay() const
{
	return mJoinedDay;
}

void Staff::setJoinedDay(int day, int month, int year)
{
	Date validDate = verifyDate(day, month, year);
	mJoinedDay = validDate;
}

int Staff::getLevel() const
{
	return mLevel;
}

void Staff::setLevel(int level)
{
	mLevel = level;
}