#include <cstdlib>
#include "��������ת��.h"

char* ���ı�(int ����)
{
	char* ��� = (char*)malloc(12);
	sprintf(���, "%d", ����);
	return ���;
}

int ������(char* �ı�)
{
	return atoi(�ı�);
}
