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

if(start==NULL)
{
printf("Empty\n");
return;
}

int i;
temp=start;
for(i=1;temp!=NULL;i++)
{
printf("%d> %s TO %s\nAT : %s\nFARE = %d\n",i,temp->src,temp->dest,temp->time,temp->fare);
temp=temp->link;
}

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


void delete_nth_node(int n);

void deleteFlight()
{
int n;

displayList();

if(start!=NULL)
{
printf("\nEnter nth flight to delete\n");
printf("Enter 0 to exit\n");
scanf("%d",&n);

if(n!=0)
delete_nth_node(n);

return;
}
}


void delete_nth_node(int n)
{
if(n<1 || n>nc)
{
printf("Invalid Value of n\n");
deleteFlight();
}
if(start==NULL)
{
printf("Empty\n");
return;
}

temp=start;

if(start->link==NULL)
{
start=NULL;
free(temp);
nc--;
return;
}
else
{

if(n==1)
{
start=start->link;
free(temp);
nc--;
return;
}

sn curr = start;

if(n==nc)
{

while(curr->link->link!=NULL)
curr=curr->link;

temp=curr->link;
curr->link=NULL;
free(temp);
nc--;
return;
}

int i;
for(i=1;i<n;i++)
{
curr=curr->link;
}
temp=curr->link;
curr->link=temp->link;
free(temp);
nc--;
return;
}
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

		case 3:	putData();
			exit(0);
			break;
		}


	}

}





