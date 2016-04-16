/*****************************************
Title :	Eagle Airlines
File	: action.h
Date	: 12APR2016
Author : Julian G. Pryde
Course : CS344
Section : 01
Assignment : Final Project
*****************************************/

//Linked list node declaration
typedef struct listNodes {
	int time;
	int employee;
	char[2] location;
	char[50] description;
	ListNode *nextPtr;
} ListNode;

//Function Declarations
ListNodePtr readDaily(char[256] filename, ListNodePtr startPtr);
ListNodePtr readGroup(char[256] filename, ListNodePtr startPtr);
int displayMenu();
char* getString(int size);

//Declare ListNodePtr
typedef struct ListNode *ListNodePtr;

//Declare Daily file linked list
ListNodePtr startPtr;
