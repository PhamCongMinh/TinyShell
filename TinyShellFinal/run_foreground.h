#include <stdio.h> 
#include <windows.h>
#include <signal.h>
#include <tchar.h>

void signal_terminate(DWORD id) {
    HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, id);
    TerminateProcess(hProcess, 1);
    CloseHandle(hProcess);
    return;
}
//== ok done ==
int run_fg(char* filename)
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);

    //== chuyển từ char* sang _T
    wchar_t* _Tfilename = (wchar_t*)malloc((strlen(filename) + 1) * sizeof(wchar_t)); //memory allocation
    mbstowcs(_Tfilename, filename, strlen(filename) + 1);

    if (!CreateProcess(_Tfilename, NULL, NULL, NULL, FALSE, 
        CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
    {
        printf("Error!!! Can't open this process\n");
        return 1;
    }
    //== hàm hỗ trợ ctrl + c để tắt tiến trình (chỉ hỗ trợ console app)
    signal(SIGINT, signal_terminate);
    //== tạo fg process nhờ funtion này ==
    WaitForSingleObject(pi.hProcess, 10000);
    TerminateProcess(pi.hProcess, 1);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    printf("Terminated process with id = %lu\n", pi.dwProcessId);
    return 0;
}
