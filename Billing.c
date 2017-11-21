//simple project to store frequent passenger information and airlines billing system! (dynamic Pricing) 
#include<stdio.h>
 #include<stdlib.h>
//linked list for storing passenger info
struct node
{
	//int info;
	int frequentFlyID;
	char name[40];
	char from[10],to[10];
	struct node *link;
};
typedef struct node *Nodeptr;
Nodeptr new;
new->link=NULL;
//correct till here (TESTED)

Nodeptr getnode()
{
	return ((Nodeptr) malloc(sizeof(Nodeptr)));
}
//gonna check this (Linked List Implementations 
void insertData(Nodeptr p)
{		
	int c;
	//CHECK
	while(new->link!=NULL)
	{
		Nodeptr temp;
		new->link=temp;
	}
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
/* if a person check the price of the flight from a particular destination to xyz more than 2 times, the price 
increases by some values*/
/*TODO:
	1. flights available list make 
	2. check whether to use files or compile time values for list of places and price
	3. 

