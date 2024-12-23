#pragma once
static class 控制台
{
public:
	控制台();
	~控制台();
	static void 清屏();
	static void 输出(char* str);
	static void 输出(char* str, int color);
	static void 输出行(char* str);
	static void 输出行(char* str, int color);
	static void 设置字体颜色(int color);
	static void 设置背景颜色(int color);
	static int 读取键盘输入();
	static char* 读取键盘输入按钮文本();
	static char* 读取输入文本行();

};

