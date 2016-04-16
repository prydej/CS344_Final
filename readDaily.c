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

ListNodePtr readDaily(char* filename[], ListNodePtr startPtr){
	
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
		
		//Read a record from the file
		fseek(daily, 0, SEEK_SET;//set file pointer back to beginning
		tempNodePtr = malloc(sizeof(ListNode)); //allocate memory for a new node
		if (tempNodePtr == NULL){
			
			printf("Could not allocate memory for new record from daily file.");
			return NULL;
		}//end if
		
		fread(&tempNodePtr, sizeof(ListNode), 1, daily);
	
	return startPtr
}//end readDaily
