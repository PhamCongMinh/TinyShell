
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void help() {
	char s[100];
	printf("\nList function:\n\t+ run_background\n\t+ run_foreground\n\t+ local_time\n\t+ list_task\n\t+ kill_process\n\t+ list_directory\n\t+ stop_resume_use_debug");
	printf("\nWrite the name of function that you want to know how to use it :\n");
	printf("help>");
	gets(s);
	fflush(stdin);

	if (!strcmp(s, "run_background")) {
		printf("\nContains the function run_bg (): used to create the process of executing the .exe file, the input value is the path to the exe file.");
		printf("\nContains function signal_ctrl_c (): close the process with the key combination ctr + c");
	}

	if (!strcmp(s, "run_foreground")) {
		printf("\nContains the function run_fg (): Also used to create an exe file run process but will automatically close the process 10 seconds after running");
		printf("\nContains signal_terminate (): Used to close process");
	}

	if (!strcmp(s, "local_time")) {
		printf("\nContains function local_time() : Print current time in local time zone");
	}

	if (!strcmp(s, "list_task")) {
		printf("\nContains function print_process() : Print out information of running processes. ");
	}

	if (!strcmp(s, "kill_process")) {
		printf("\nContains function kill() : Closes the specified process");
		printf("\nContains killAllProcess() function: Closes all existing processes.");
	}

	if (!strcmp(s, "list_directory")) {
		printf("6");
	}

	if (!strcmp(s, "stop_resume_use_debug")) {
		printf("\nContains suspend () function: Suspends the specified process, incorporates the debug feature");
		printf("\nContains resume () function: Reopens the suspension process.");
	}
}

