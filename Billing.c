//simple project to store frequent passenger information and airlines billing system! (dynamic Pricing) 
#include<stdio.h>
 #include<stdlib.h>
//linked list for storing passenger info
struct node
{
	int info;
	int frequentFlyID;
	char name[40];
	char from[10],to[10];
	struct node *linkReference;
};
typedef struct node *Nodeptr;
//correct till here (TESTED)

//gonna check this (Linked List Implementations 
void insertData(Nodeptr p)
{
	printf("Enter the name of the passenger");
	scanf("%c",p->name);
	printf("Enter the Frequent flyer ID");
	scanf("%d",&p->frequentFlyID);
	printf("Where you are travelling from?");
	scanf("%c",p->from);
	printf("Where you are travelling to?");
	scanf("%c",p->to);
	
	

}
//will be added soon
