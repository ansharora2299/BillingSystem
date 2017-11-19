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

Nodeptr getnode()
{
	return ((Nodeptr) malloc(sizeof(Nodeptr)));
}
//gonna check this (Linked List Implementations 
void insertData(Nodeptr p)
{		
	Nodeptr new;
	//CHECK
	printf("Enter the name of the passenger");
	scanf("%c",p->name);
	printf("Enter the Frequent flyer ID");
	scanf("%d",&p->frequentFlyID);
	printf("Where you are travelling from?");
	scanf("%c",p->from);
	printf("Where you are travelling to?");
	scanf("%c",p->to);
	
	/* or can be done like this?
	printf("Enter the name of the passenger");
	scanf("%c",name);
	printf("Enter the Frequent flyer ID");
	scanf("%d",&frequentFlyID);
	printf("Where you are travelling from?");
	scanf("%c",from);
	printf("Where you are travelling to?");
	scanf("%c",to);
	p->
	*/

}
//will be added soon
