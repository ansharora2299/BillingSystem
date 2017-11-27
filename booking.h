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
