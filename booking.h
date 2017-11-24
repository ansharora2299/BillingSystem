/*simple project to store frequent passenger information and airlines billing system! (dynamic Pricing) and FILE HANDLING
DS Project by Piyush Anay and Ansh
*/
#include<stdlib.h>
#include<string.h>
#include<time.h>
#ifndef BOOKING_H_
#define BOOKING_H_
typedef enum { false, true } bool;
//linked list for storing passenger info
int nTicket=-1;
///Number of bookings that the structure array can store
int capacity=1;
typedef struct
{
	///Name of the Passenger
	char passenger_name[30];
	///Departure City
	char departure_city[20];
	///Destination City
	char destination_city[20];
	///Name of the airline
	char airline[20];
	///Flight Number
	char flight_number[10];
	///Date of Journey
	char date[10];
	///Reference number of the booking
	char booking_reference[20];

	///Fare of the ticket
	int fare;
	///Status of booking - Valid or Deleted
	bool active;
	///Departure time
	struct tm dep;
	///Arrival time
	struct tm arr;


}ticket;
///Pointer to the structure array containing bookings
ticket *booking;
/// File  variable for flights.txt
FILE* fo;
/// File variable for availableFlights.txt
FILE* fi;
/**
 * \brief Increases the capacity of the structure
 *
 * Increases capacity of the structure if the array of structures is completely filled.
 *
 */
void increaseCapacity()
{
	if(nTicket==capacity-1)
		{
			capacity*=2;
			booking=(ticket*)realloc(booking, capacity*sizeof(ticket));
		}
}
/**
 *  Rewrites file containing bookings
 *
 * Rewrites the file containing the bookings
 *  after deleting a booking (active changed to false)
 */
void rewriteFile()
{
	FILE* fb;
	fb=fopen("src/bookings.dat","w+");
	int size=sizeof(ticket);
	int i=0;
	for(i=0;i<=nTicket;i++)
		fwrite(&booking[i], size, 1, fb);
	fclose(fb);
}

/**
 *  Reads file containing the bookings
 *
 * Opens bookings.dat and copies the structure variables present into  structure array
 */
void readFile()
{
	FILE *fb;
	fb =  fopen("src/bookings.dat","r");
	int size=sizeof(ticket);

	while(fread(&booking[++nTicket], size, 1, fb)==1)
		increaseCapacity();
	--nTicket;
	fclose(fb);

}

**
 * \brief Initiates booking
 *
 * Called in the beginning to open the bookings.dat file and allocate memory for a structure object
 *
 */
void startBooking()
{
	booking = (ticket*)malloc(capacity * sizeof(ticket));
	readFile();
}
/**
 * \brief Generates booking reference number
 *
 * Generates a random alphanumeric reference number associated with each booking
 * the last digit representing the number of tickets booked till now
 * @param s String to store the reference number
 * @param len Length of the required reference number
 */
void gen_reference(char *s, int len) {
	srand(time(0));
	char temp[5];
	int i=0;
    char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    s[len]='\0';
    sprintf(temp,"%d",nTicket);
    strcat(s, temp);
}
/**
 * \brief Display flights for the route
 *
 * Displays all the flights available flying from the entered departure city to the destination city
 * @param dep Name of Departure City
 * @param des Name of Destination City
 * @return True if some flights are found False if no flights are found
 */
bool displayFlight(char dep[], char des[])
{
	int seatAvail;
	char depf[20], desf[20], fn[10], dep_t[10], arr_t[10], al[20];
	int faref=0;

	fi=fopen("src/flights.txt", "r");
	fo=fopen("src/availableFlights.txt", "w");
	int i=0,flag=0;
	printf("S.No \t Departure City \t Destination City \t Airline \t\t Flight Number \t Departure Time \t Arrival Time \t Fare\n");
	while( fscanf(fi, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d\n", depf, desf, al, fn, dep_t, arr_t, &faref, &seatAvail)!=EOF)
	{
		if(strcmp(dep, depf)==0&&strcmp(des, desf)==0)
		{
			flag=1;
			printf("%d \t %-10s \t %-10s \t\t %-10s \t\t %s \t\t %s \t\t %s \t\t %d\n", ++i, depf, desf, al, fn, dep_t, arr_t, faref);
			fprintf(fo, "%d,%s,%s,%s,%s,%s,%s,%d,%d\n", i, depf, desf, al, fn, dep_t, arr_t, faref, seatAvail);
		}
	}

	fclose(fo);
	if(flag==0)
		return false;
	else
		return true;
}
/**
 * \brief Extract details of the flight selected
 *
 * Copies details of the booking to the structure variable according to the choice of the flight entered by the user
 *  choice Index represents the flight selected by the user
 */
void feedDetails(int choice)
{
	int i=0,dep_h,dep_m, arr_h, arr_m;
	char depf[20], desf[20], fn[10], al[20];
	int faref=0;
	fo=fopen("src/availableFlights.txt", "r");
	while( fscanf(fo, "%d,%[^,],%[^,],%[^,],%[^,],%d:%d,%d:%d,%d,%*d\n", &i, depf, desf, al, fn, &dep_h, &dep_m, &arr_h, &arr_m, &faref)!=EOF)
	{

		if(i==choice)
		{
			strcpy(booking[nTicket].flight_number,fn);
			strcpy(booking[nTicket].airline,al);
			booking[nTicket].fare=faref;
			booking[nTicket].dep.tm_hour=dep_h;
			booking[nTicket].dep.tm_min=dep_m;
			booking[nTicket].arr.tm_hour=arr_h;
			booking[nTicket].arr.tm_min=arr_m;

			break;
		}
	}

}
/**
 * \brief Counts the number of digits in a number
 * @param n Number whose digits need to be counted
 * @return Number of digits in the number passed as argument
 */
int count(int n)
{
	int i=0;
	while(n!=0)
	{
		n/=10;
		i++;
	}
	return i;
}
/**
 * \brief Remove trailing new line character
 *
 * Replaces the trailing new line character in the string (added by fgets()) with a null character
 */
void remove_newline(char* a)
{
	a[strlen(a)-1]='\0';
}
