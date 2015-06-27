#include "People.h"

People::People()
{
	mName = new char[50];
}

People::~People()
{
	delete []mName;
}

void People::displayInfo()
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
	mName = name;
}

Date People::getBirthday() const
{
	return mBirthday;
}

void People::setBirthday(int day, int month, int year)
{
	if (month < 0 && month < 13)
	{
		mBirthday.month = month;
	}
	else
	{
		// set to 1 default
		mBirthday.month = 1;
	}

	int maxDay = 0;
	switch (mBirthday.month)
	{
		case 2:
			if (year % 4 == 0)
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
		mBirthday.day = day;
	}

	// make sure year contain 4 digits
	if (year / 1000 > 0)
	{
		mBirthday.year = year;
	}
	
}

int People::getIDCode() const
{
	return mIDCode;
}
void People::setIDCode(int id)
{
	mIDCode = id;
}