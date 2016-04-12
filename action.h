/*****************************************
Title :	Eagle Airlines
File	: action.h
Date	: 12APR2016
Author : Julian G. Pryde
Course : CS344
Section : 01
Assignment : Final Project
*****************************************/


void readDaily(char[256] filename, ListNodePtr startPtr);

void readGroup(char[256] filename, ListNodePtr startPtr);

//Declare Daily file linked list
ListNodePtr startPtr;

typedef struct listNodes {
	int time;
	int date;
	int employee;
	char[2] location;
	char[50] description;
	ListNode *nextPtr;
} ListNode;
