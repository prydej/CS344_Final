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
Credit to : Stack Overflow user Tony (http://stackoverflow.com/users/1211744/tony)
			in question "C: how to break apart a multi digit number into separate variables?"
			(http://stackoverflow.com/questions/9302681/c-how-to-break-apart-a-multi-digit-number-into-separate-variables#_=_)
			asked by mugetsu (http://stackoverflow.com/users/949275/mugetsu)
*****************************************/

#include "action.h"
#include <stdio.h>


int findMinutes(int hhmm){
	
	int divisor = 100;
	int hours, minutes, minsOfDay;
	
	//take mod of divisor to find minutes
	minutes = hhmm % divisor;
	
	//divide hhmm by 100 to find hours
	hours = hhmm/100;
	
	//add minutes to hours
	minsOfDay = hours + minutes;
	
	//return
	return minsOfDay;
}
