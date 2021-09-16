#include <stdio.h>
#include <time.h>

void local_time()
{
	time_t rawtime;
	struct tm* timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	printf("Current local time and date: %s", asctime(timeinfo));
}