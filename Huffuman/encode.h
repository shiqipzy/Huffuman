#pragma once
#include<iostream>
#include<map>
#include<list>
#include<string>
using namespace std;
class TreeNode
{
public:
    TreeNode* rightchild;
    TreeNode* leftchild;
    TreeNode* father;
    char A;//待编码字符
    string bm;//编码结果,insert成员函数默认从头部插入字符
    TreeNode(TreeNode* a = NULL, TreeNode* b = NULL, TreeNode* c = NULL, char B = 'a', string g = "") :rightchild(a), leftchild(b), father(c), A(B), bm(g) {}
    void set_A(char p)
    {
        A = p;
    }
};
void LinkChild(TreeNode& a, TreeNode& b, TreeNode& c);
void Print(TreeNode* p,map<char,string>&trans,map<string,char>&reverse);
void ADD_bm(TreeNode* b, string p);
void Realease(TreeNode* p);

