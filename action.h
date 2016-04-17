/*****************************************
Title :	Eagle Airlines
File	: action.h
Date	: 12APR2016
Author : Julian G. Pryde
Course : CS344
Section : 01
Assignment : Final Project
description : header file for the Eagle Airlines project
*****************************************/

//Linked list node declaration
struct listNodes {
	int time;
	int employee;
	char location[2];
	char description[50];
	struct listNodes* nextPtr;
};

//Declare ListNodePtr
typedef struct listNodes ListNode;
typedef ListNode *ListNodePtr;

//Function Declarations
int readtoLL(char filename[256], ListNodePtr startPtr);
int displayMenu();
char* getString(int size);

//Declare Daily file linked list
ListNodePtr startPtr;

