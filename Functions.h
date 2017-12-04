//this is a custom header file, we're using this to make code compact and easy to read and modify in the .c file
#define Size 30 //size for the source and Destination of the journey

struct node //structure used for using linked list node (Creation of nodes)
{
  //all the data is defined here
  char src[Size],dest[Size];
  char time[5];
  int fare;
  struct node* link;
};

typedef struct node* sn; //typecasting is used to make our code compact
sn start=NULL;
sn start1=NULL;
sn temp=NULL;

int nc=0;

sn addNode(sn nn,sn s) //function to add flights
{
nn->link=NULL;
if(s==NULL)
{
s=nn;
}
else
{
  temp=s;
while(temp->link!=NULL)
    temp=temp->link;
  temp->link=nn;
}
return s;
}

void putData(char *file,sn s)
{
if(s==NULL)
{
  printf("Nothing to write\n");
return;
}

FILE *fp; //creating a file pointer
fp=fopen(file,"w"); //opening file in write mode to write

if(fp!=NULL) //to ammend changes in the file
{
  int i;
  temp=s;
for(i=1;temp!=NULL;i++)
{
  fprintf(fp,"%s\t%s\t%s\t%d\n",temp->src,temp->dest,temp->time,temp->fare); //the data is being stored after every tab space directly through the linkedList
  temp=temp->link;
}
  fclose(fp);//closing the file
  printf("\nData Written\n");
}
else
  printf("Error Writing Data\n");
}

sn getData(char *file,sn s)//function to retrieve data from file
{

  FILE *fp;
  fp=fopen(file,"r");//read mode
  rewind(fp);
  if(fp!=NULL)
  {

      temp=s;
      while(!feof(fp))
      {
        sn nn = (sn)malloc(sizeof(struct node));
        fscanf(fp,"%s\t%s\t%s\t%d\n",nn->src,nn->dest,nn->time,&nn->fare);//adding in linked list again for code effieciency
        s=addNode(nn,s);
      }
}
else
{
  printf("Error retreiving data\n");
  return s;
}

  printf("Data Read\n");
  return s;
}


void displayList(sn s)//function to display data directly from
{

if(s==NULL)
{
printf("Empty\n");
return;
}

int i;
temp=s;
for(i=1;temp!=NULL;i++)
{
printf("%d> %s TO %s\nAT : %s\nFARE = %d\n",i,temp->src,temp->dest,temp->time,temp->fare);
temp=temp->link;
}

}


int getSize(sn s)
{
if(s==NULL)
{
return 0;
}

int i=0;
temp=s;
while(temp!=NULL)
{
temp=temp->link;
i++;
}
return i;
}

sn delete_nth_node(int n, sn s)
{
nc=getSize(s);

if(n<1 || n>nc)
{
printf("Invalid Value of n\n");
return s;
}

if(s==NULL)
{
printf("Empty\n");
return s;
}

temp=s;

if(s->link==NULL)
{
s=NULL;
free(temp);
return s;
}
else
{

if(n==1)
{
s=s->link;
free(temp);
return s;
}

sn curr = s;

if(n==nc)
{

while(curr->link->link!=NULL)
curr=curr->link;

temp=curr->link;
curr->link=NULL;
free(temp);
return s;
}

int i;
for(i=1;i<n-1;i++)
{
curr=curr->link;
}
temp=curr->link;
curr->link=temp->link;
free(temp);
return s;
}
}

void addFlight()//Administrator function to add new flight in the database/file
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

start=addNode(nn,start);
}


void deleteFlight()
{
int n;
displayList(start);

if(start!=NULL)
{
printf("\nEnter nth flight to delete\n");
printf("Enter 0 to cancel\n");
scanf("%d",&n);

if(n!=0)
start=delete_nth_node(n,start);

return;
}
}

sn search(char *s,char *d)
{
if(start==NULL)
{
printf("Empty List\n");
return NULL;
}

sn curr =start;
start1=NULL;
while(curr!=NULL)
{
if(!strcmp(curr->src,s) && !strcmp(curr->dest,d))
{
sn nn=(sn)malloc(sizeof(struct node));

strcpy(nn->src,curr->src);
strcpy(nn->dest,curr->dest);
strcpy(nn->time,curr->time);
       nn->fare=curr->fare;
start1 = addNode(nn,start1);
}
curr=curr->link;
}

return start1;
}

void displayBookings()
{
start1=NULL;
start1=getData("booking.txt",start1);
displayList(start1);
return;
}

void newBooking()
{
char s[Size],d[Size];
int n,i;

printf("Enter source and Destination\n");
scanf("%s %s",s,d);

start1=search(s,d);
displayList(start1);

if(start1!=NULL)
{
printf("Choose Flight\n");
scanf("%d",&n);

sn curr=start1;
for(i=1;i<n;i++)
{
curr=curr->link;
}

FILE *fp;
fp=fopen("booking.txt","a");
fprintf(fp,"%s\t%s\t%s\t%d\n",curr->src,curr->dest,curr->time,curr->fare);
printf("Booking Complete\n");
fclose(fp);
}
}

void deleteBooking()
{
int n,i;
displayBookings();
if(start1!=NULL)
{
printf("Choose Booking\n");
scanf("%d",&n);

start1=delete_nth_node(n,start1);

putData("booking.txt",start1);
}
}
