/*****************************************
Title :	Eagle Airlines
File	: EagleAir.c
Date	: 12APR2016
Author : Julian G. Pryde
Course : CS344
Section : 01
Assignment : Final Project
Input :	Group and Daily filename, chosen record
Output : To terminal, records of work
Method : linked lists, binary/text files
*****************************************/

#include <stdio.h>
#include "action.h"

int main(argc, char *argv[]){
	
	//instantiate linked list of info from daily file
	startPtr = NULL;
	ListNodePtr* currentPointer;
	char dispRecord;
	int startTime, endTime, employeeID;
	int searchIter = 0;
	char location[2];
	
	//open daily file and read information to linked list (call readDaily())
	readtoLL(argv[1], startPtr);
		
	//if group file exists, read in group file to C struct and add as node to linked list
	readtoLL(argv[2], startPtr);
	
	while (restart != no){
		displayMenu();
	} //end while
	
	return 0;
} //end main

