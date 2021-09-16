#include <stdio.h>
#include <windows.h>

DWORD pid[20];
char name[20][30];
int count;
int isRunning(DWORD pid) {
    HANDLE process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    DWORD status = WaitForSingleObject(process, 1);
    if (status == WAIT_OBJECT_0) return 0;
    else if (status == WAIT_TIMEOUT) {
        count--;
        return 1;
    }

}
// ok done
void print_processes() {
    printf("______________TASK MANAGER____________\n\n\n");
    printf("%10s       | %10s\n", "PID", "PROCESS");
    printf("--------------------------------------\n");
    for (int i = 0; i < 20; i++)
    {

        if (pid[i] > 0 && isRunning(pid[i]) == 1)
        {
            printf("%10lu       |    %-10s\n", pid[i], name[i]);
        }
    }
    printf("\n\n%d processes are running\n", count);
}