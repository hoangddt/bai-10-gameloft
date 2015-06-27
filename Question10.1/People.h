#pragma once
#include "Date.h"

class People
{
public:
	People();
	virtual ~People();
	virtual void displayInfo() const;
	const char* getName() const;
	void setName(const char* name);
	Date getBirthday() const;
	void setBirthday(int day, int month, int year);
	int getIDCode() const;
	void setIDCode(int id);
protected:
	char* mName;
	Date mBirthday;
	int mIDCode;
};