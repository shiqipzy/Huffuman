#define _CRT_SECURE_NO_WARNINGS
#include"encode.h"
#include"get_trans.h"
#include<map>
#include"file_edit.h"
using namespace std;
int main()
{
	char p[100];
	string c;
	c=Read("test.txt", p,c);
	map<char, int> mp;
    map<char, string>trans;
	map<string, char>reverse;
	for (int i = 0; i < c.length(); i++)
	{
	auto t=mp.find(c[i]);
	if (t == mp.end())
	{
		mp.insert(make_pair(c[i], 1));
	}
	else
	{
		mp[c[i]]++;
	}
	}
	string b;
	get_trans(mp, trans,reverse);
    for (int i = 0; i < c.length(); i++)
    {
		b += trans[c[i]];
    }
	Write("test_code.txt", b);
	string code;
	code=Read("test_code.txt", p, code);
	string r;
	for (int i = 0; i < code.length(); i++)
	{
		for (int j = i; j < code.length(); j++)
		{
			auto p = reverse.find(code.substr(i,j-i));
			if (p != reverse.end())
			{
				r += (*p).second;
				i = j - 1;
				break;
			}
		}
	}
	Write("test_tran.txt", r);
}