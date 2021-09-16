#include <stdio.h> 
#include <windows.h>
#include <tchar.h>
#include <signal.h>

DWORD pid[20];
char name[20][30];
int count;
void signal_ctrl_c() {
    // chưa sửa được lỗi ko update list processes khi tắt bằng ctrl + c
    printf("test!!!");
}
//== ok done ==
int run_bg(char* filename)
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);

    //== chuyển từ char* sang _T
    wchar_t* _Tfilename = (wchar_t*)malloc((strlen(filename) + 1) * sizeof(wchar_t)); //memory allocation
    mbstowcs(_Tfilename, filename, strlen(filename) + 1);

    if (!CreateProcess(_Tfilename, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
    {
        printf("Error!!! Can't open this process\n");
        return 1;
    }

    printf("process has id = %lu is running\n", pi.dwProcessId);
    pid[count] = pi.dwProcessId;
    strcpy(name[count], filename);
    count++;
    //== hàm hỗ trợ ctrl + c để tắt tiến trình (chỉ hỗ trợ console app)

    signal(2, signal_ctrl_c);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return 0;
}
