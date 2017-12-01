#include<stdio.h>
#include<stdlib.h>
#define Size 20

struct node
{
char src[Size],dest[Size];
char time[5];
int fare;
struct node* link;
};

typedef struct node* sn;
sn start=NULL,temp=NULL;

int nc=0;

void addNode(sn nn)
{
nn->link=NULL;
if(start==NULL)
{
start=nn;
nc++;
}
else
{
temp=start;
while(temp->link!=0)
temp=temp->link;
temp->link=nn;
nc++;
}
return;
}

void displayList()
{
int i;
temp=start;
for(i=1;temp!=NULL;i++)
{
printf("%d> %s TO %s\nAT : %s\nFARE = %d",i,temp->src,temp->dest,temp->time,temp->fare);
temp=temp->link;
}
//sn searchList(char s[], char d[]);
}

void addFlight()
{
sn nn = (sn) malloc(sizeof(sn));
printf("Enter Source\n");
scanf("%s",nn->src);

printf("Enter Destination\n");
scanf("%s",nn->dest);

printf("Enter Time in 24hr format (example-21:50)\n");
scanf("%s",nn->time);

printf("Enter base fare\n");
scanf("%d",&nn->fare);

addNode(nn);
}

/*void searchFlight()
{

char s[Size],d[Size];

printf("Enter Source\n");
scanf("%s",s);

printf("Enter Destination\n");
scanf("%s",d);

temp = searchList(s,d);

if(temp==NULL)
printf("No Flight Found\n");

else
printf("%s TO %s\nAT : %s\nFARE = %d",temp->src,temp->dest,temp->time,temp->fare);

}
*/

void deleteFlight()
{
int n;

displayList();

if(start!=NULL)
{
printf("Enter nth flight to delete\n");
scanf("%d",&n);
delete_nth_node(n);
return;
}
}

void delete_nth_node(int n)
{
temp=start;
if(start->link==NULL&&n==1)
{
start=NULL;
free(temp);
}
else if(start->link!=NULL&&n==1)
{
start=start->link;
free(temp);
}
else if(start->link!=NULL&&n>1)
{
sn temp2=NULL;
if(n!=nc)
{
for(int i=1;i<n-1;i++)
temp=temp->link;
temp2=temp->link;
temp->link=temp2->link;
free(temp2);
}
else
{
while(temp->link!=NULL)
{
temp2=temp;
temp=temp->link;
}
temp2->link=NULL;
free(temp);
}
}
nc--;
}

int main()
{
	
	int choice_user,choice, ch;
	while(1)
	{
		printf("Enter\n 1. Administrator\n 2. User\n 3. Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
		case 1:
			printf("Enter\n 1. Add new flight\n 2. Delete Flight\n");
			scanf("%d",&ch);
			scanf("%*c");
			switch(ch)
			{
			case 1:
				addFlight();
				break;
			case 2:
				deleteFlight();
				break;
			}
			break;
		case 2:

			displayList();
			/*printf("Enter\n 1. New Booking\n 2. Display Booking\n 3. Delete Booking\n");
			scanf("%d",&choice_user);
			switch(choice_user)
			{
			case 1:
				newBooking();
				break;
			case 2:
				findBooking();
				break;
			case 3:
				deleteBooking();
				break;
			}*/
			break;

		case 3:
			exit(0);
			break;
		}


	}

}

