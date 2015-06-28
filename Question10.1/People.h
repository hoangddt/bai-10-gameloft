#pragma once
#include "Date.h"

class People
{
public:
	People(const char *name);
	// People(People *otherPeoplePointer);
	People(const People &otherPeople);
	virtual ~People();
	virtual void displayInfo() const;
	const char* getName() const;
	void setName(const char* name);
	Date getBirthday() const;
	void setBirthday(int day, int month, int year);
	int getIDCode() const;
	void setIDCode(int id);

	static int count;
protected:
	char* mName;
	Date mBirthday;
	int mIDCode;
};