#include <iostream>
#include "字符串操作.h"
#include "数据类型转换.h"
#include "控制台.h"
#include <windows.h>

int main()
{
	char* a = 字符串_转base64("C:\\Windows\\System32\\kernel.appcore.dll");

	控制台::输出行(a,RGB(110,0,50));

	char* b = 字符串_从base64还原(a);
	控制台::输出(b, RGB(110, 0, 50));

}
