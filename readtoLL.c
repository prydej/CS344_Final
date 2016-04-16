/*****************************************
Title :	Eagle Airlines
File	: readDaily.c
Date	: 12APR2016
Author : Julian G. Pryde
Course : CS344
Section : 01
Assignment : Final Project
Input :	Daily filename
Output : Linked list with all information in daily file
Method : printf function 
*****************************************/

#include "action.h"

ListNodePtr readFile(char* filename[], ListNodePtr startPtr){
	
	int bat, numRecords;
	ListNodePtr currentPtr;
	ListNode tempNodePtr;
	
	
	//open file for reading
	FILE* daily = fopen(filename, "rb");
	
	//if file exists, add contents to linked listNodes
	if (daily == NULL){
		printf("Unable to read daily file!\n");
		return NULL;
	} else if {
		//find number of records in file
		fseek(daily, 0, SEEK_END); //set pointer at end of filename
		numRecords = ftell(daily)/sizeof(ListNode); //divide pointer's positionin file by size of record
		
		//add all records in file to linked list
		currentPtr = startPtr //set currentPointer to startPointer
		
		for (bat = 0; bat < numRecords, bat++){//for all records in file
			//Read a record from the file
			fseek(daily, 0, SEEK_SET);//set file pointer back to beginning
			
			tempNodePtr = malloc(sizeof(ListNode)); //allocate memory for a new node
			if (tempNodePtr == NULL){
				printf("Could not allocate memory for new record from daily file.");
				return NULL;
			}//end if
			
			fread(&tempNodePtr, sizeof(ListNode), 1, daily);
			
			//add records to linked list in order of time 
			if (startPtr == NULL){
				//if start pointer is null, point start pointer to temp index
				startPtr = tempNodePtr;
			} else {
				
				dailyMinsSinceMidnight = findMinutes(currentPointer -> time); //Find time of current record in minutes since midnight

				hasBeenPlaced = 0;
				while (currentPtr->nextPtr->nextPtr != NULL && hasBeenPlaced != 1){ //loop through all items in linked list
		
					nodeMinsSinceMidnight = findMinutes(//find time of current node in minutes since midnight
			
					//if time is after date of current node and before time of next node
					if (tempNodePtr->time > currentPtr->time){ //nodes are in ascending order of time, so place after 1st earlier time
				
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
				//TODO add condition to put node from file at end of linked list 
					
				}
			}
			
			//place node from file in chronological order
		
		} //end for
	}//end if
	
	return startPtr
}//end readDaily
