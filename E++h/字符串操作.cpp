#include "�ַ�������.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/// <summary>
/// ƴ�������ַ����������µ�
/// </summary>
/// <param name="�ַ���1"></param>
/// <param name="�ַ���2"></param>
/// <returns></returns>
char* �ַ���_ƴ��(char* �ַ���1, char* �ַ���2)
{
	char* ��� = (char*)malloc(strlen(�ַ���1) + strlen(�ַ���2) + 1);
	strcpy(���, �ַ���1);
	strcat(���, �ַ���2);
	return ���;
}

/// <summary>
/// ���ڷ��ش��������������ڷ���0
/// </summary>
/// <param name="�ַ���"></param>
/// <param name="���ַ���"></param>
/// <returns></returns>
int �ַ���_�Ƿ����(char* �ַ���, char* ���ַ���)
{
	int ��� = 0;
	char* p = �ַ���;
	while (p = strstr(p, ���ַ���))
	{
		���++;
		p++;
	}
	return ���;
}

/// <summary>
/// �滻�ַ���
/// </summary>
/// <param name="Դ�ַ���"></param>
/// <param name="���滻���ַ���"></param>
/// <param name="�滻���ַ���"></param>
/// <returns></returns>
char* �ַ���_�滻(char* Դ�ַ���, char* ���滻���ַ���, char* �滻���ַ���)
{
	char* ��� = (char*)malloc(strlen(Դ�ַ���) + 1);
	char* p = Դ�ַ���;
	char* q = ���;
	while (*p)
	{
		if (strstr(p, ���滻���ַ���) == p)
		{
			strcpy(q, �滻���ַ���);
			p += strlen(���滻���ַ���);
			q += strlen(�滻���ַ���);
		}
		else
		{
			*q = *p;
			q++;
			p++;
		}
	}
	*q = '\0';
	return ���;
}

/// <summary>
/// ȥ�����пո�
/// </summary>
/// <param name="�ַ���"></param>
/// <returns></returns>
char* �ַ���_ȥ���ո�(char* �ַ���)
{
	char* ��� = (char*)malloc(strlen(�ַ���) + 1);
	char* p = �ַ���;
	char* q = ���;
	while (*p)
	{
		if (*p != ' ')
		{
			*q = *p;
			q++;
		}
		p++;
	}
	*q = '\0';
	return ���;
}

/// <summary>
/// �ָ��ַ��������طָ����ַ�������
/// </summary>
/// <param name="�ַ���"></param>
/// <param name="�ָ���"></param>
/// <param name="�������"></param>
/// <returns></returns>
char** �ַ���_�ָ�(char* �ַ���, const char* �ָ���, int* �������)
{
	char* p = �ַ���;
	char* q = p;
	int ���� = 0;
	while (p = strstr(p, �ָ���))
	{
		����++;
		p += strlen(�ָ���);
	}
	����++;
	*������� = ����;
	char** ��� = (char**)malloc(sizeof(char*) * ����);
	p = �ַ���;
	for (int i = 0; i < ����; i++)
	{
		q = strstr(p, �ָ���);
		if (q)
		{
			���[i] = (char*)malloc(q - p + 1);
			strncpy(���[i], p, q - p);
			���[i][q - p] = '\0';
			p = q + strlen(�ָ���);
		}
		else
		{
			���[i] = (char*)malloc(strlen(p) + 1);
			strcpy(���[i], p);
		}
	}
	return ���;
}

char* �ַ���_ת��д(char* �ַ���)
{
	char* ��� = (char*)malloc(strlen(�ַ���) + 1);
	char* p = �ַ���;
	char* q = ���;
	while (*p)
	{
		if (*p >= 'a' && *p <= 'z')
		{
			*q = *p - 32;
		}
		else
		{
			*q = *p;
		}
		q++;
		p++;
	}
	*q = '\0';
	return ���;
}

char* �ַ���_תСд(char* �ַ���)
{
	char* ��� = (char*)malloc(strlen(�ַ���) + 1);
	char* p = �ַ���;
	char* q = ���;
	while (*p)
	{
		if (*p >= 'A' && *p <= 'Z')
		{
			*q = *p + 32;
		}
		else
		{
			*q = *p;
		}
		q++;
		p++;
	}
	*q = '\0';
	return ���;
}

char* �ַ���_ȥ����β�ո�(char* �ַ���)
{
	char* ��� = (char*)malloc(strlen(�ַ���) + 1);
	char* p = �ַ���;
	char* q = ���;
	while (*p == ' ')
	{
		p++;
	}
	while (*p)
	{
		*q = *p;
		q++;
		p++;
	}
	q--;
	while (*q == ' ')
	{
		q--;
	}
	q++;
	*q = '\0';
	return ���;
}

char** �ַ���_�ָ�(char* �ַ���, const char* �ָ���, int* �������)
{
	char* p = �ַ���;
	char* q = p;
	int ���� = 0;
	while (p = strstr(p, �ָ���))
	{
		����++;
		p += strlen(�ָ���);
	}
	����++;
	*������� = ����;
	char** ��� = (char**)malloc(sizeof(char*) * ����);
	if (��� == NULL) {
		return NULL; // ����ڴ����ʧ�ܣ����� NULL
	}
	p = �ַ���;
	for (int i = 0; i < ����; i++)
	{
		q = strstr(p, �ָ���);
		if (q)
		{
			���[i] = (char*)malloc(q - p + 1);
			if (���[i] == NULL) {
				// ����ڴ����ʧ�ܣ��ͷ��ѷ�����ڴ沢���� NULL
				for (int j = 0; j < i; j++) {
					free(���[j]);
				}
				free(���);
				return NULL;
			}
			strncpy(���[i], p, q - p);
			���[i][q - p] = '\0';
			p = q + strlen(�ָ���);
		}
		else
		{
			���[i] = (char*)malloc(strlen(p) + 1);
			if (���[i] == NULL) {
				// ����ڴ����ʧ�ܣ��ͷ��ѷ�����ڴ沢���� NULL
				for (int j = 0; j < i; j++) {
					free(���[j]);
				}
				free(���);
				return NULL;
			}
			strcpy(���[i], p);
		}
	}
	return ���;
}

char* �ַ���_תbase64(char* �ַ���)
{
	char* ��� = (char*)malloc(strlen(�ַ���) * 4 / 3 + 4);
	char* p = �ַ���;
	char* q = ���;
	while (*p)
	{
		unsigned char a = *p;
		unsigned char b = 0;
		unsigned char c = 0;
		if (*(p + 1))
		{
			b = *(p + 1);
		}
		if (*(p + 2))
		{
			c = *(p + 2);
		}
		unsigned char d = a >> 2;
		unsigned char e = ((a & 0x03) << 4) | (b >> 4);
		unsigned char f = ((b & 0x0f) << 2) | (c >> 6);
		unsigned char g = c & 0x3f;
		*q = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[d];
		q++;
		*q = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[e];
		q++;
		*q = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[f];
		q++;
		*q = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[g];
		q++;
		p += 3;
	}
	*q = '\0';
	return ���;
}

char* �ַ���_��base64��ԭ(char* �ַ���)
{
	char* ��� = (char*)malloc(strlen(�ַ���) * 3 / 4 + 1);
	char* p = �ַ���;
	char* q = ���;
	while (*p)
	{
		unsigned char a = strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/", *p) - "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
		unsigned char b = strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/", *(p + 1)) - "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
		unsigned char c = strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/", *(p + 2)) - "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
		unsigned char d = strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/", *(p + 3)) - "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
		unsigned char e = (a << 2) | (b >> 4);
		unsigned char f = ((b & 0x0f) << 4) | (c >> 2);
		unsigned char g = ((c & 0x03) << 6) | d;
		*q = e;
		q++;
		if (*(p + 2) == '=')
		{
			break;
		}
		*q = f;
		q++;
		if (*(p + 3) == '=')
		{
			break;
		}
		*q = g;
		q++;
		p += 4;
	}
	*q = '\0';
	return ���;
}

char* �ַ���_ȡMD5(char* �ַ���)
{
	char* ��� = (char*)malloc(33);
	char* p = �ַ���;
	char* q = ���;
	while (*p)
	{
		sprintf(q, "%02x", *p);
		q += 2;
		p++;
	}
	*q = '\0';
	return ���;
}

char* �ַ���_ɾ��ָ��λ�õ��ַ�(char* �ַ���, int ��ʼλ��, int ����λ��)
{
	char* ��� = (char*)malloc(strlen(�ַ���) - ����λ�� + ��ʼλ�� + 1);
	char* p = �ַ���;
	char* q = ���;
	int i = 0;
	while (*p)
	{
		if (i < ��ʼλ�� || i > ����λ��)
		{
			*q = *p;
			q++;
		}
		p++;
		i++;
	}
	*q = '\0';
	return ���;
}

