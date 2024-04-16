#define _CRT_SECURE_NO_WARNINGS
#include "file_edit.h"
using namespace std;
string Read(const char* p, char* result,string c)
{
	string b;
	FILE* f = fopen(p, "r");
	if (f == NULL)
	{
		printf("∂¡»° ß∞‹\n");
	}
	while (fgets(result,100,f)!=NULL)
	{
		b += result;
	}
	return b;
	fclose(f);
}

void Write(const char* p, string c)
{
	FILE* fp = fopen(p, "w");
	if (fp == NULL)
	{
		printf("–¥»Î ß∞‹\n");
	}
	fputs(c.c_str(), fp);
	fclose(fp);
}
