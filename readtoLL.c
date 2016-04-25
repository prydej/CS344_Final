/*****************************************
Title :	Eagle Airlines
File	: readToLL.c
Date	: 12APR2016
Author : Julian G. Pryde
Course : CS344
Section : 01
Assignment : Final Project
Input :	filename, pointer to linked list, mode for group or daily file
Output : pointer linked list 
description : takes a pointer to a pointer to a linked list and a filename of a binary file and adds
records from file in chronological order to linked list using a time struct member in HHMM format
*****************************************/

#include "action.h"
#include <stdio.h>
#include <stdlib.h>

ListNodePtr readtoLL(char* filename, ListNodePtr startPtr, char mode){
	
	/* Declare variables */
	
	int bat, numRecords, tempMinsSinceMidnight, nodeMinsSinceMidnight, hasBeenPlaced;
	ListNodePtr currentPtr;
	ListNodePtr tempNodePtr;

	/* open file for reading */
	
	FILE* inFile = fopen(filename, "rb");
	
	if (inFile == NULL){
		
		if (mode == 'g'){ //if group file does not exist, return from program
			printf("The group file could not be loaded.");
			return 1;
		} else if (mode == 'd') { //if daily file does not exist, create new file
			printf("Daily file not found. Creating new one.");
			
			FILE* newFile = fopen(filename, "ab+");
			if (newFile == NULL){
				printf("Could not create a new daily file.");
				return 1;
			}
		}
	} else { //if file exists, add contents to linked listNodes
		
		/* read files into linked list chronologically*/
		
		//find number of records in file
		fseek(inFile, 0, SEEK_END); //set pointer at end of filename
		numRecords = ftell(inFile)/sizeof(ListNode); //divide pointer's position file by size of record
		
		//add all records in file to linked list
		currentPtr = startPtr; //set currentPointer to startPointer
		
		fseek(inFile, 0, SEEK_SET);//set file pointer back to beginning
		
		for (bat = 0; bat < numRecords; bat++){//for all records in file
			
			/* Read a record from the file */
			
			tempNodePtr = malloc(sizeof(ListNode)); //allocate memory for a new node
			if (tempNodePtr == NULL){
				printf("Could not allocate memory for new record from file.");
				return 1;
			}//end if
			
			fread(&tempNodePtr, sizeof(ListNode), 1, inFile);
			
			/* add record to linked list in correct place */
			if (startPtr == NULL){
				//if start pointer is null, point start pointer to temp index
				startPtr = tempNodePtr;
			} else {
				
				tempMinsSinceMidnight = findMinutes(currentPtr -> time); //Find time of current record in minutes since midnight

				hasBeenPlaced = 0;
				while (currentPtr->nextPtr != NULL && hasBeenPlaced != 1){ //loop through all items in linked list
		
					nodeMinsSinceMidnight = findMinutes(currentPtr->time); //find time of current node in minutes since midnight
					
					//if time is after date of current node
					if (tempNodePtr->time > currentPtr->time){ //nodes are in ascending order of time, so place after 1st earlier time
				
						//point tempNodePtr nextPtr to next node
						tempNodePtr->nextPtr = currentPtr->nextPtr;
				
						//point current node nextPtr to tempNodePtr 
						currentPtr->nextPtr = tempNodePtr;
				
						hasBeenPlaced = 1;
					} //end if
					//move currentPtr to next node in list
					currentPtr = currentPtr->nextPtr;
				}//end if
			} //end while
			
			if (hasBeenPlaced == 0){ //if place not found, place node at beginning of list
				//point tempNodePtr to first node in list
				tempNodePtr -> next = startPtr;
				
				//point startPtr to tempNodePtr
				startPtr = tempNodePtr;

			} //end if
		} //end for
	} //end if
	
	fclose(inFile);
	return startPtr;
} //end readtoLL

