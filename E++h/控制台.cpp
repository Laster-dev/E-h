#include "����̨.h"
#include <windows.h>
#include <stdio.h>
#include <conio.h>

����̨::����̨()
{
}

����̨::~����̨()
{
}



void ����̨::����()
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


void ����̨::���(char* str)
{
	printf(str);
}

void ����̨::���(char* str, int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	printf(str);
	SetConsoleTextAttribute(hConsole, 7);
}

void ����̨::�����(char* str)
{
	printf(str);
	printf("\n");
}

void ����̨::�����(char* str, int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	printf(str);
	printf("\n");
	SetConsoleTextAttribute(hConsole, 7);
}

void ����̨::����������ɫ(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void ����̨::���ñ�����ɫ(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}


int ����̨::��ȡ��������()
{
	// ʹ�� _kbhit �� _getch ���������Ͷ�ȡ��������
	if (_kbhit()) {
		return _getch();
	}
	return 0; // ���û�а��������£����� 0
}

char* ����̨::��ȡ�������밴ť�ı�()
{
	// ʹ�� _kbhit �� _getch ���������Ͷ�ȡ��������
	if (_kbhit()) {
		char* str = (char*)malloc(2);
		str[0] = _getch();
		str[1] = '\0';
		return str;
	}
	return ""; // ���û�а��������£����ؿ��ַ���
}

char* ����̨::��ȡ�����ı���()
{
    size_t ���� = 128;
    size_t ���� = 0;
    char* buffer = (char*)malloc(����);
    if (buffer == NULL) {
        return NULL;
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (���� + 1 >= ����) {
            ���� *= 2;
            char* �»����� = (char*)realloc(buffer, ����);
            if (�»����� == NULL) {
                free(buffer);
                return NULL;
            }
            buffer = �»�����;
        }
        buffer[����++] = (char)c;
    }
    buffer[����] = '\0';

    return buffer;
}
