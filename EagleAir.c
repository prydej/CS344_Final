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
	
	//open daily file and read information to linked list (call readDaily())
	readDaily(argv[1], startPtr);
	
	while (restart != no){
		
		//if group file exists, read in group file to C struct and add as node to linked list
		readGroup(argv[2], startPtr);
	
		//ask user about displaying records
	
		//ask user for start/end date and time and employee #
	
		//display according records
	
		//loop the bitch
	}
}
