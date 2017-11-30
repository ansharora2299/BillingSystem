
    #include <stdio.h>

    #include <stdlib.h>

    #include <string.h>

    #define Size 20

FILE *fp;
char src[Size],dest[Size];
int time,bfare;
void addFlight()
{
fp=fopen("data.txt","a");
if(fp!=NULL)
{
printf("Enter Source\n");
scanf("%s",src);
fprintf(fp,"%s ",src);

printf("Enter Destination\n");
scanf("%s",dest);
fprintf(fp,"%s ",dest);

printf("Enter Time in 24hr format (example-2150)\n");
scanf("%d",&time);
fprintf(fp,"%d ",time);

printf("Enter base fare\n");
scanf("%d",&bfare);
fprintf(fp,"%d\n",bfare);

}
else 
printf("failed to add try again");

fclose(fp);
}

void read()
{
if(fp!=NULL)
{
fp=fopen("data.txt","r");
char c;
c = fgetc(fp);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fp);
    }
}
else 
printf("failed to open");

fclose(fp);
}

int main()
{
int n;
scanf("%d",&n);
if(n==1)
addFlight();
else
read();
}
