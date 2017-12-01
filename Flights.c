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
sn start=NULL;
sn temp=NULL;

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
while(temp->link!=NULL)
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
printf("%d> %s TO %s\nAT : %s\nFARE = %d\n",i,temp->src,temp->dest,temp->time,temp->fare);
temp=temp->link;
}
//sn searchList(char s[], char d[]);
}

void addFlight()
{
sn nn = (sn)malloc(sizeof(struct node));
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
printf("\nEnter nth flight to delete\n");
scanf("%d",&n);
delete_nth_node(n);
return;
}
}

void delete_nth_node(int n)
{
if(n<=nc)
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
sn curr=NULL;
if(n!=nc)
{
for(int i=1;i<n-1;i++)
temp=temp->link;
curr=temp->link;
temp->link=curr->link;
free(curr);
}
else
{
while(temp->link!=NULL)
{
curr=temp;
temp=temp->link;
}
curr->link=NULL;
free(temp);
}
}
nc--;
}
else
printf("Invalid Flight No.");
}

void newBooking()
{
char s[SIZE],d[SIZE];
printf("Enter the source\n");
scanf("%s",s);
printf("Enter the Destination\n");
scanf("%s",d);
sn curptr=searchFlight(s,d);
printf("Select the Flight to be booked\n");
int i;
temp=start1;
for(i=1;temp!=NULL;i++)
{
printf("%d> %s TO %s\nAT : %s\nFARE = %d\n",i,temp->src,temp->dest,temp->time,temp->fare);
temp=temp->link;
}
int n
scanf("%d",&n);
int j;
for(j=1;j<n;j++)
temp=temp->link;
printf("Your Flight details are:\n%d> %s TO %s\nAT : %s\nFARE = %d\n",i,temp->src,temp->dest,temp->time,temp->fare);
else
printf("Invalid Flight No. Selected");
}

void putData()
{
if(start==NULL)
{
printf("Nothing to write\n");
return;
}

FILE *fp;
fp=fopen("data.txt","w");

if(fp!=NULL)
{
int i;
temp=start;
for(i=1;temp!=NULL;i++)
{
fprintf(fp,"%s\t%s\t%s\t%d\n",temp->src,temp->dest,temp->time,temp->fare);
temp=temp->link;
}
fclose(fp);
printf("\nData Written\n");
}
else
printf("Error Writing Data\n");
}

void getData()
{

FILE *fp;
fp=fopen("data.txt","r");
rewind(fp);
if(fp!=NULL)
{

temp=start;
while(!feof(fp))
{
sn nn = (sn)malloc(sizeof(struct node));
fscanf(fp,"%s\t%s\t%s\t%d\n",nn->src,nn->dest,nn->time,&nn->fare);
addNode(nn);
}
}
else
{
printf("Error retreiving data\n");
return;
}

printf("Data Read\n");
return;
}


int main()
{
	
	int choice_user,choice, ch;
	getData();
	while(choice!=3)
	{
		printf("Enter\n 1. Administrator\n 2. User\n 3. Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
		case 1:
			printf("Enter\n 1. Add new flight\n 2. Delete Flight\n 3. Exit\n");
			scanf("%d",&ch);
			//scanf("%*c");
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
			printf("Enter\n 1. New Booking\n 2. Display Booking\n 3. Delete Booking\n");
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
			}
			break;
		case 3:	putData();
			exit(0);
                        break;
		}	
 	  }
     }
}

