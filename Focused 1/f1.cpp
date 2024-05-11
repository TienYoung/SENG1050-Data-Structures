#include <cstdio>
#include <cstdlib>
#include <cstring>

struct FlightInfo
{
	char* destination;
	char* date;
};

void fillFlightInfo(FlightInfo* flight, const char* destination, const char* date);
void printFlightInfo(FlightInfo* flights, int size);

int main()
{
	FlightInfo flights[10] = {};

	for (int i = 0; i < 10; i++)
	{
		printf("Please input flight info #%d/10\n", i + 1);
		printf("Destination:");
		char buffer[30] = "";
		fgets(buffer, 30, stdin);
		char destination[30] = "";
		sscanf_s(buffer, "%[^\n]s", &destination, 30);


		printf("Date:");
		fgets(buffer, 30, stdin);
		char date[30] = "";
		sscanf_s(buffer, "%[^\n]s", &date, 30);

		fillFlightInfo(&flights[i], destination, date);

		printf("\n");
	}

	printf("\n");
	printFlightInfo(flights, 10);

	for (int i = 0; i < 10; i++)
	{
		free(flights[i].destination);
		free(flights[i].date);
	}

	return 0;
}


void fillFlightInfo(FlightInfo* flight, const char* destination, const char* date)
{
	flight->destination = static_cast<char*>(malloc(strlen(destination) + 1));
	strcpy_s(flight->destination, strlen(destination) + 1, destination);

	flight->date = static_cast<char*>(malloc(strlen(date) + 1));
	strcpy_s(flight->date, strlen(date) + 1, date);
}

void printFlightInfo(FlightInfo* flights, int size)
{
	printf("Flight information:\n");

	for (int i = 0; i < size; i++)
	{
		printf("%-35s%-35s\n", flights[i].destination, flights[i].date);
	}
}

