#include <iostream>
#include <windows.h>
#include <psapi.h>

int main() {
    // 获取当前活动窗口的句柄
    HWND hwnd = GetForegroundWindow();
    if (hwnd == NULL) {
        std::cerr << "无法获取当前活动窗口的句柄。" << std::endl;
        return 1;
    }

    // 获取进程ID和线程ID
    DWORD processId;
    DWORD threadId = GetWindowThreadProcessId(hwnd, &processId);

    // 打开进程以获取进程名
    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processId);
    if (hProcess == NULL) {
        std::cerr << "无法打开进程。" << std::endl;
        return 1;
    }

    // 分配内存以存储进程名
    const int maxChars = 1024;
    char processName[maxChars];
    if (GetModuleFileNameEx(hProcess, NULL, processName, maxChars) == 0) {
        std::cerr << "无法获取进程名。" << std::endl;
        CloseHandle(hProcess);
        return 1;
    }

    // 输出进程名
    std::cout << "" << processName << std::endl;

    // 关闭句柄
    CloseHandle(hProcess);

    return 0;
}