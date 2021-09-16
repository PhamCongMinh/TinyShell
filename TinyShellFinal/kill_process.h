#include <stdio.h>
#include <windows.h>

DWORD pid[20];
int count;

void kill(char *id)
{
    DWORD dwDesiredAccess = PROCESS_TERMINATE;
    BOOL  bInheritHandle = FALSE;
    HANDLE hProcess = OpenProcess(dwDesiredAccess, bInheritHandle, atoi(id));
    if (hProcess == NULL) {
        printf("Error!!! Can't kill this process.\n");
        return FALSE;
    }

    BOOL result = TerminateProcess(hProcess, 1);
    if (result == TRUE) {
        CloseHandle(hProcess);
        count--;
        for (int i = 0; i < 20; i++) {
            if (pid[i] == atoi(id)) {
                pid[i] = 0;
            }
        }
        printf("Killed process with id = %s\n", id);
    }

    return;
}
void killAllProcesses() {
    for (int i = 0; i < 20; i++)
    {
        if (pid[i] > 0) {
            HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid[i]);
            BOOL result = TerminateProcess(hProcess, 1);
            CloseHandle(hProcess);
            if (result == TRUE) {
                count--; 
                pid[i] = 0;
            }
        }
    }
}