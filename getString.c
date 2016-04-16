/*****************************************
Title :	Eagle Airlines
File	: getString.c
Date	: 12APR2016
Author : Julian G. Pryde
Course : CS344
Section : 01
Assignment : Final Project
Input :	size of string
Output : string from stdin
Method : printf function 
*****************************************/

#include "action.h"

char* getString(int size){
	
	int elephant;
	char[size];

	//clear std input buffer of newline character
	while (getchar() != '\n'){
	}

	elephant = -1;
	do {
		elephant++;
		string[elephant] = getchar();
	} while (string[elephant] != '\n');
	string[elephant] = '\0';
	
	return string;
}/home/julian/Documents/ERAU/CS344/Project

