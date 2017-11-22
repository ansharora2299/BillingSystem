//simple project to store frequent passenger information and airlines billing system! (dynamic Pricing) and FILE HANDLING
#include<stdio.h>
 #include<stdlib.h>
//linked list for storing passenger info
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
