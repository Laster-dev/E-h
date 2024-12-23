#include "控制台.h"
#include <windows.h>
#include <stdio.h>
#include <conio.h>

控制台::控制台()
{
}

控制台::~控制台()
{
}



void 控制台::清屏()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) return;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;

    DWORD cellCount = csbi.dwSize.X * csbi.dwSize.Y;
    DWORD count;
    COORD homeCoords = { 0, 0 };

    FillConsoleOutputCharacter(hConsole, (TCHAR)' ', cellCount, homeCoords, &count);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cellCount, homeCoords, &count);
    SetConsoleCursorPosition(hConsole, homeCoords);
}


void 控制台::输出(char* str)
{
	printf(str);
}

void 控制台::输出(char* str, int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	printf(str);
	SetConsoleTextAttribute(hConsole, 7);
}

void 控制台::输出行(char* str)
{
	printf(str);
	printf("\n");
}

void 控制台::输出行(char* str, int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	printf(str);
	printf("\n");
	SetConsoleTextAttribute(hConsole, 7);
}

void 控制台::设置字体颜色(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void 控制台::设置背景颜色(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}


int 控制台::读取键盘输入()
{
	// 使用 _kbhit 和 _getch 函数来检测和读取键盘输入
	if (_kbhit()) {
		return _getch();
	}
	return 0; // 如果没有按键被按下，返回 0
}

char* 控制台::读取键盘输入按钮文本()
{
	// 使用 _kbhit 和 _getch 函数来检测和读取键盘输入
	if (_kbhit()) {
		char* str = (char*)malloc(2);
		str[0] = _getch();
		str[1] = '\0';
		return str;
	}
	return ""; // 如果没有按键被按下，返回空字符串
}

char* 控制台::读取输入文本行()
{
    size_t 容量 = 128;
    size_t 长度 = 0;
    char* buffer = (char*)malloc(容量);
    if (buffer == NULL) {
        return NULL;
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (长度 + 1 >= 容量) {
            容量 *= 2;
            char* 新缓冲区 = (char*)realloc(buffer, 容量);
            if (新缓冲区 == NULL) {
                free(buffer);
                return NULL;
            }
            buffer = 新缓冲区;
        }
        buffer[长度++] = (char)c;
    }
    buffer[长度] = '\0';

    return buffer;
}
