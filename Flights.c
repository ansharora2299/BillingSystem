#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Functions.h"
#define Size 20

int main()
{
	
	int ch_user,ch, ch_adm;
	char s[20],d[20];
 	start=getData("data.txt",start);
	while(1)
	{
		printf("Enter\n 1. Administrator\n 2. User\n 3. Exit\n");
		scanf("%d", &ch);
		switch(ch)
		{
		case 1:
			printf("Enter\n 1. Add new flight\n 2. Delete Flight\n 3. Display All Flights\n 4. No of Flights\n");
			scanf("%d",&ch_adm);
			switch(ch_adm)
			{
			case 1:
				addFlight();
				break;
			case 2:
				deleteFlight();
				break;
			case 3: 
				displayList(start);
				break;
			case 4: 
				printf("No of Flights are is %d\n",getSize(start));
				break;
			}
			break;

		case 2:
			printf("Enter\n 1. New Booking\n 2. Delete Booking\n 3. Display All Bookings\n");
			scanf("%d",&ch_user);
			switch(ch_user)
			{
			case 1: newBooking();
				break;

			case 2: deleteBooking();
				break;

			case 3: displayBookings();
				break;
			}
			break;

		case 3:	putData("data.txt",start);
			exit(0);
			break;
		}


	}

}





