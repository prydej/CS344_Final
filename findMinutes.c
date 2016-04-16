/*****************************************
Title :	Eagle Airlines
File	: FindMinutes.c
Date	: 15APR2016
Author : Julian G. Pryde
Course : CS344
Section : 01
Assignment : Final Project
Input :	time in HHMM
Output : time in MMMM since midnight
*****************************************/

#include "action.h"

int findMinutes(int hhmm){
	char[4] time;
	char[2] stringHours, stringMinutes;
	int hours, minutes, minsInHours, minsOfDay;
	
	//turn hhmm to string
	sprintf(&time, "%d", hhmm);
	
	//convert first two digits back to int
	stringHours = strcat(time[0], time[1]);
	hours = atoi(stringHours);
	
	//multiply hours to minutes
	minsInHours = hours * 60;
	
	//add second two digits from string to hours
	stringMinutes = strcat(time[2], time[3]);
	minutes = atoi(stringMinutes);
	minsOfDay = minsInHours + minutes;
	
	//return
	return minsOfDay;
}
