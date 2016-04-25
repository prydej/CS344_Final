/*****************************************
Title 	:	Eagle Airlines
File	: saveFromLL.c
Date	: 12APR2016
Author 	: Julian G. Pryde
Course 	: CS344
Section : 01
Assignment : Final Project
Input 	:	pointer to linked list
Output 	: Error value
description : Saves the contents of a binary file to a linked list
*****************************************/

#include <stdio.h>
#include <time.h>
#include "action.h"

int saveFromLL(ListNodePtr startPtr){
	
	char filename[20]; //DD_MM_YYYY_Daily.bin
	time_t rawtime;
	struct tm tm;
	
	//create filename string
	time(&rawtime);
	tm = *localtime(&rawtime);
	sprintf(filename, "%d_%d_%d_Daily.bin", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	
	//open file
	//name is date + daily file
	outFile = fopen(filename, "wb");
	
	if (outFile == NULL){
		printf("Could not open file to write daily file to.");
		return 1;	
	}
	
	//loop through linked list contents
	currentPtr = startPtr;
	do (currentPtr -> nextPtr != NULL){
		//increment pointer
		currentPtr -> nextPtr = currentPtr -> nextPtr -> nextPtr; //current pointer = next pointer's next pointer
	
		//write node to file
		fwrite(currentPtr, sizeof(ListNode), 1, outFile);
	} while (currentPtr -> nextPtr != NULL); //loop until current next pointer is null
	
	//return
	return 0;
}
