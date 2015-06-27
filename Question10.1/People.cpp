#include <cstdio>
#include <cstring>
#include "People.h"
#include "functionality.h"


People::People()
{
	mName = new char[50];
}

People::~People()
{
	delete []mName;
}

void People::displayInfo() const
{
	printf("Name: %s\n", getName());
	printf("ID code: %d\n", getIDCode());
	Date bd = getBirthday();
	printf("BirthDay: %d/%d/%d\n", bd.day, bd.month, bd.year);
}

const char* People::getName() const
{
	return mName;
}

void People::setName(const char* name)
{
	strcpy(mName, name);
}

Date People::getBirthday() const
{
	return mBirthday;
}

void People::setBirthday(int day, int month, int year)
{
	Date validDay = verifyDate(day, month, year);
	mBirthday = validDay;
	
}

int People::getIDCode() const
{
	return mIDCode;
}
void People::setIDCode(int id)
{
	mIDCode = id;
}