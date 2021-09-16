#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include "list_directory.h"
#include "run_background.h"
#include "run_foreground.h"
#include "kill_process.h"
#include "local_time.h"
#include "list_task.h"
#include "stop_resume_use_debug.h"
#include "help.h"

DWORD pid[20];
char name[20][30];
int count = 0;

//== them lenh clear xóa màn hình vào menu ==
void menu()
{
    printf("\n\n");
    printf("\tMenu of funtions in TinyShell:\n");
    printf("\t[*] menu    : contain all funtions\n");
    printf("\t[*] dir     : list all files in this directory with absolutely path\n");
    printf("\t[*] r_fg    : run program in forgeground with absolutely path\n");
    printf("\t[*] r_bg    : run program in background with absolutely path\n");
    printf("\t[*] list    : list all processes with id which are running\n");
    printf("\t[*] kill_all: kill all processes with id which are running\n");
    printf("\t[*] kill    : kill a process with id which is running\n");
    printf("\t[*] suspend : stop a process which is running.\n");
    printf("\t[*] resume  : resume a stopping process which be stopped\n");
    printf("\t[*] time    : print local time and date\n");
    printf("\t[*] help    : description of all functions\n");
    printf("\t[*] r_bat   : run file .bat\n");
    printf("\t[*] clear   : clear the console\n");
    printf("\t[*] exit    : exit shell\n");
    printf("\n\n");
}

int main()
{
    char user_input[100];
    char cmd[2][100];
    char space = ' ';
    char* index_space;
    printf("                        WELCOME TO TINY SHELL\n");
    printf("======================================================================\n");
   

    while (1)
    {
        printf("\nTinyShell> ");

        scanf("%[^\n]%*c", user_input);
        fflush(stdin);

        // tách lệnh từ input của người dùng
        index_space = strchr(user_input, space);
        if (index_space != NULL)
        {
            // tách tham số phía sau input
            strcpy(cmd[1], index_space + 1);
            // copy toàn bộ input
            strcpy(cmd[0], user_input);
            // tách lệnh phía trước input
            cmd[0][strlen(user_input) - strlen(cmd[1]) - 1] = '\0';
        }
        // gán input vào cmd
        else strcpy(cmd[0], user_input);

        // thuc hien cau lenh 
        if (strcmp(cmd[0], "dir") == 0)
            printListDir(cmd[1]);
        else if (strcmp(cmd[0], "menu") == 0)
            menu();
        else if (strcmp(cmd[0], "r_fg") == 0)
            run_fg(cmd[1]);
        else if (strcmp(cmd[0], "r_bg") == 0)
            run_bg(cmd[1]);
        else if (strcmp(cmd[0], "list") == 0)
            print_processes();
        else if (strcmp(cmd[0], "kill_all") == 0)
            killAllProcesses();
        else if (strcmp(cmd[0], "kill") == 0)
            kill(cmd[1]);
        else if (strcmp(cmd[0], "r_bat") == 0)
            system(cmd[1]);
        else if (strcmp(cmd[0], "suspend") == 0)
            suspend(cmd[1]);
        else if (strcmp(cmd[0], "resume") == 0)
            resume(cmd[1]);
        else if (strcmp(cmd[0], "time") == 0)
            local_time();
        else if (strcmp(cmd[0], "help") == 0) {
            help();
        }
        else if (strcmp(cmd[0], "clear") == 0)
            system("cls");
        else if (strcmp(cmd[0], "exit") == 0)
            exit(0);
        else
            printf("Command not found!\n");
    }
    getchar();
    return 0;
}