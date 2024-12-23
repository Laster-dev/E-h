#include <cstdlib>
#include "数据类型转换.h"

char* 到文本(int 数字)
{
	char* 结果 = (char*)malloc(12);
	sprintf(结果, "%d", 数字);
	return 结果;
}

int 到整数(char* 文本)
{
	return atoi(文本);
}
