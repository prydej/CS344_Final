/*****************************************
Title :	Eagle Airlines
File	: displayMenu.c
Date	: 12APR2016
Author : Julian G. Pryde
Course : CS344
Section : 01
Assignment : Final Project
Input :	user's choice of employee id, time constraints, and location
Output : Linked list of daily file info w/ group file info added
Method : printf function 
*****************************************/

#include "action.h"

int displayMenu(){
	
	char dispRecord;
	int startTime, endTime, employeeID;
	int searchIter = 0;
	char seeRecord = 1;
	char location[2];
	
		//ask user for start/end time, location, and employee #
		printf("Start time: ");
		scanf("%d", &startTime);
	
		printf("End time: ");
		scanf("%d", &endTime);
	
		printf("Location: ");
		location = getString(2);
	
		printf("Employee ID #:");
		scanf("%d", &employeeID);
	
		//display according records
		//loop through all list elements
		currentPointer = startPtr;
	
		//set current pointer to startPtr
		while (currentPointer != NULL){
		
			//change time into minutes since midnight
		
		
			//find where time falls between target times
			if (currentPointer->time >= startTime){
			
			} //end if
		
			//find where employee ID is correct
	
			//find where location is correct 
	
			//display selected records
		
			searchIter++; //increment searchIteration
		}// end while
} //end displayMenu
