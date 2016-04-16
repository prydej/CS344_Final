/*****************************************
Title :	Eagle Airlines
File	: readGroup.c
Date	: 12APR2016
Author : Julian G. Pryde
Course : CS344
Section : 01
Assignment : Final Project
Input :	group filename
Output : Linked list of group file info w/ group file info added
Method : printf function 
*****************************************/

#include "action.h"

ListNodePtr readGroup(char* filename[], ListNodePtr startPtr){
	
	int numRecords, tiger, groupMinsSinceMidnight, nodeMinsSinceMidnight, hasBeenPlaced;
	ListNodePtr currentPtr;
	ListNode tempNodePtr;
	
	
	//open file for reading
	FILE* group = fopen(filename, "rb");
	
	//if file exists, add contents to linked listNodes
	if (group == NULL){
		printf("Unable to read group file!\n");
		return NULL;
	} else if {
		//find number of records in file
		fseek(group, 0, SEEK_END); //set pointer at end of filename
		numRecords = ftell(group)/sizeof(ListNode); //divide pointer's positionin file by size of record
		
		//add all records in file to linked list
		currentPtr = startPtr //set currentPointer to startPointer
		
		for (tiger = 0; tiger < numRecords; tiger++){ //for all group file records
		
			//Read a record from the file
			fseek(group, 0, SEEK_SET;//set file pointer back to beginning
			tempNodePtr = malloc(sizeof(ListNode)); //allocate memory for a new node
			if (tempNodePtr == NULL){
				
				printf("Could not allocate memory for new record from group file.");
				return NULL;
			}//end if
		
			fread(&tempNodePtr, sizeof(ListNode), 1, group);
		
			groupMinsSinceMidnight = findMinutes(currentPointer -> time); //Find time of current record in minutes since midnight

			hasBeenPlaced = 0;
			while (currentPtr->nextPtr != NULL && hasBeenPlaced != 1){ //loop through all items in linked list
			
				nodeMinsSinceMidnight = findMinutes(//find time of current node in minutes since midnight
				
				//if time is after date of current node and before time of next node
				if (tempNodePtr->time > currentPtr->time){ //since nodes are inascending order of time, only compare to current node time
					
					//point tempNodePtr nextPtr to next node
					tempNodePtr->nextPtr = currentPtr->nextPtr;
					
					//point current node nextPtr to tempNodePtr 
					currentPtr->currentPtr = tempNodePtr;
					
					hasBeenPlaced = 1;
					
				} else {
					//move currentPtr to next node in list
					currentPtr = currentPtr->nextPtr;
				}//end if
				
			} //end while
		} // end for
	} //end if
	
	//if file does not exist, return from function
	return 0;
} //end readGroup
