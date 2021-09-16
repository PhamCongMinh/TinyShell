#include <stdio.h> 
#include <windows.h> 

//== ok done
void suspend(DWORD processId)
{
    if (DebugActiveProcess(processId)) {
        printf("Process with id = %d is stopping", processId);
    }
    else
    {
        printf("Error!!! Can't stop this process");
    }
}
void resume(DWORD processId)
{
    if (DebugActiveProcessStop(processId)) {
        printf("Process with id = %d is resumed", processId);
    }
    else {
        printf("Error!!! Can't resume this process");
    }
}