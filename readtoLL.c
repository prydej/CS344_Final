/*****************************************
Title :	Eagle Airlines
File	: readFile.c
Date	: 12APR2016
Author : Julian G. Pryde
Course : CS344
Section : 01
Assignment : Final Project
Input :	filename
Output : Linked list with all information in file
Method : printf function 
*****************************************/

#include "action.h"
#include <stdio.h>
#include <stdlib.h>

int readtoLL(char* filename, ListNodePtr startPtr){
	
	/* Declare variables */
	
	int bat, numRecords, tempMinsSinceMidnight, nodeMinsSinceMidnight, hasBeenPlaced;
	ListNodePtr currentPtr;
	ListNodePtr tempNodePtr;

	/* open file for reading */
	
	FILE* inFile = fopen(filename, "rb");
	
	//if file exists, add contents to linked listNodes
	if (inFile == NULL){
		printf("Unable to read file!\n");
		return 1;
	} else {
		
		/* read files into linked list chronologically*/
		
		//find number of records in file
		fseek(inFile, 0, SEEK_END); //set pointer at end of filename
		numRecords = ftell(inFile)/sizeof(ListNode); //divide pointer's positionin file by size of record
		
		//add all records in file to linked list
		currentPtr = startPtr; //set currentPointer to startPointer
		
		for (bat = 0; bat < numRecords; bat++){//for all records in file
			
			/* Read a record from the file */
			fseek(inFile, 0, SEEK_SET);//set file pointer back to beginning
			
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
					
					//if time is after date of current node and before time of next node
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
			if (hasBeenPlaced == 0){
				//point current node (last node) nextPtr to tempNodePtr 
				currentPtr->nextPtr = tempNodePtr;

			} //end if
		} //end for
	} //end if
	return 0;
} //end readtoLL

