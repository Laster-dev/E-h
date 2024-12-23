#include "字符串操作.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/// <summary>
/// 拼接两个字符串并返回新的
/// </summary>
/// <param name="字符串1"></param>
/// <param name="字符串2"></param>
/// <returns></returns>
char* 字符串_拼接(char* 字符串1, char* 字符串2)
{
	char* 结果 = (char*)malloc(strlen(字符串1) + strlen(字符串2) + 1);
	strcpy(结果, 字符串1);
	strcat(结果, 字符串2);
	return 结果;
}

/// <summary>
/// 存在返回存在数量，不存在返回0
/// </summary>
/// <param name="字符串"></param>
/// <param name="子字符串"></param>
/// <returns></returns>
int 字符串_是否存在(char* 字符串, char* 子字符串)
{
	int 结果 = 0;
	char* p = 字符串;
	while (p = strstr(p, 子字符串))
	{
		结果++;
		p++;
	}
	return 结果;
}

/// <summary>
/// 替换字符串
/// </summary>
/// <param name="源字符串"></param>
/// <param name="被替换的字符串"></param>
/// <param name="替换的字符串"></param>
/// <returns></returns>
char* 字符串_替换(char* 源字符串, char* 被替换的字符串, char* 替换的字符串)
{
	char* 结果 = (char*)malloc(strlen(源字符串) + 1);
	char* p = 源字符串;
	char* q = 结果;
	while (*p)
	{
		if (strstr(p, 被替换的字符串) == p)
		{
			strcpy(q, 替换的字符串);
			p += strlen(被替换的字符串);
			q += strlen(替换的字符串);
		}
		else
		{
			*q = *p;
			q++;
			p++;
		}
	}
	*q = '\0';
	return 结果;
}

/// <summary>
/// 去除所有空格
/// </summary>
/// <param name="字符串"></param>
/// <returns></returns>
char* 字符串_去除空格(char* 字符串)
{
	char* 结果 = (char*)malloc(strlen(字符串) + 1);
	char* p = 字符串;
	char* q = 结果;
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
	return 结果;
}

/// <summary>
/// 分割字符串，返回分割后的字符串数组
/// </summary>
/// <param name="字符串"></param>
/// <param name="分隔符"></param>
/// <param name="结果数量"></param>
/// <returns></returns>
char** 字符串_分割(char* 字符串, const char* 分隔符, int* 结果数量)
{
	char* p = 字符串;
	char* q = p;
	int 数量 = 0;
	while (p = strstr(p, 分隔符))
	{
		数量++;
		p += strlen(分隔符);
	}
	数量++;
	*结果数量 = 数量;
	char** 结果 = (char**)malloc(sizeof(char*) * 数量);
	p = 字符串;
	for (int i = 0; i < 数量; i++)
	{
		q = strstr(p, 分隔符);
		if (q)
		{
			结果[i] = (char*)malloc(q - p + 1);
			strncpy(结果[i], p, q - p);
			结果[i][q - p] = '\0';
			p = q + strlen(分隔符);
		}
		else
		{
			结果[i] = (char*)malloc(strlen(p) + 1);
			strcpy(结果[i], p);
		}
	}
	return 结果;
}

char* 字符串_转大写(char* 字符串)
{
	char* 结果 = (char*)malloc(strlen(字符串) + 1);
	char* p = 字符串;
	char* q = 结果;
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
	return 结果;
}

char* 字符串_转小写(char* 字符串)
{
	char* 结果 = (char*)malloc(strlen(字符串) + 1);
	char* p = 字符串;
	char* q = 结果;
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
	return 结果;
}

char* 字符串_去除首尾空格(char* 字符串)
{
	char* 结果 = (char*)malloc(strlen(字符串) + 1);
	char* p = 字符串;
	char* q = 结果;
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
	return 结果;
}

char** 字符串_分割(char* 字符串, const char* 分隔符, int* 结果数量)
{
	char* p = 字符串;
	char* q = p;
	int 数量 = 0;
	while (p = strstr(p, 分隔符))
	{
		数量++;
		p += strlen(分隔符);
	}
	数量++;
	*结果数量 = 数量;
	char** 结果 = (char**)malloc(sizeof(char*) * 数量);
	if (结果 == NULL) {
		return NULL; // 如果内存分配失败，返回 NULL
	}
	p = 字符串;
	for (int i = 0; i < 数量; i++)
	{
		q = strstr(p, 分隔符);
		if (q)
		{
			结果[i] = (char*)malloc(q - p + 1);
			if (结果[i] == NULL) {
				// 如果内存分配失败，释放已分配的内存并返回 NULL
				for (int j = 0; j < i; j++) {
					free(结果[j]);
				}
				free(结果);
				return NULL;
			}
			strncpy(结果[i], p, q - p);
			结果[i][q - p] = '\0';
			p = q + strlen(分隔符);
		}
		else
		{
			结果[i] = (char*)malloc(strlen(p) + 1);
			if (结果[i] == NULL) {
				// 如果内存分配失败，释放已分配的内存并返回 NULL
				for (int j = 0; j < i; j++) {
					free(结果[j]);
				}
				free(结果);
				return NULL;
			}
			strcpy(结果[i], p);
		}
	}
	return 结果;
}

char* 字符串_转base64(char* 字符串)
{
	char* 结果 = (char*)malloc(strlen(字符串) * 4 / 3 + 4);
	char* p = 字符串;
	char* q = 结果;
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
	return 结果;
}

char* 字符串_从base64还原(char* 字符串)
{
	char* 结果 = (char*)malloc(strlen(字符串) * 3 / 4 + 1);
	char* p = 字符串;
	char* q = 结果;
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
	return 结果;
}

char* 字符串_取MD5(char* 字符串)
{
	char* 结果 = (char*)malloc(33);
	char* p = 字符串;
	char* q = 结果;
	while (*p)
	{
		sprintf(q, "%02x", *p);
		q += 2;
		p++;
	}
	*q = '\0';
	return 结果;
}

char* 字符串_删除指定位置的字符(char* 字符串, int 开始位置, int 结束位置)
{
	char* 结果 = (char*)malloc(strlen(字符串) - 结束位置 + 开始位置 + 1);
	char* p = 字符串;
	char* q = 结果;
	int i = 0;
	while (*p)
	{
		if (i < 开始位置 || i > 结束位置)
		{
			*q = *p;
			q++;
		}
		p++;
		i++;
	}
	*q = '\0';
	return 结果;
}

