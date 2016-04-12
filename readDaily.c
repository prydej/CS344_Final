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

ListNodePtr readDaily(char* filename[], ListNodePtr startPtr){
	
	FILE * daily;
	
	//open daily file
	daily = fopen(filename, "rb");
	
	//if daily file exists, fill linked list with daily file info
	if (daily != NULL){
		//loop through all info in daily file and add each item to linked list
	}
	
	//return ppointer to linked list
}
