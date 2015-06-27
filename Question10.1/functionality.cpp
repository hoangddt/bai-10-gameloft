#include "functionality.h"

Date verifyDate(int day, int month, int year)
{
	int validDate;
	if (month > 0 && month < 13)
	{
		validDate.month = month;
	}
	else
	{
		// set to 1 default
		validDate.month = 1;
	}

	int maxDay = 0;
	switch (validDate.month)
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
		validDate.day = day;
	}

	// make sure year contain 4 digits
	if (year / 1000 > 0)
	{
		validDate.year = year;
	}

	return validDate;
}