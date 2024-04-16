#include "encode.h"
using namespace std;
void ADD_bm(TreeNode* b, string p)
{
    if (b == NULL)
        return;
    if (b->leftchild)
    {
        b->leftchild->bm.insert(0, p);
        ADD_bm(b->leftchild, p);
    }
    if (b->rightchild)
    {
        b->rightchild->bm.insert(0, p);
        ADD_bm(b->rightchild, p);
    }
}
void LinkChild(TreeNode& a, TreeNode& b, TreeNode& c)
{
    a.leftchild = &b;
    b.father = &a;
    b.bm.insert(0, "0");
    ADD_bm(&b, "0");
    a.rightchild = &c;
    c.father = &a;
    c.bm.insert(0, "1");
    ADD_bm(&c, "1");

}
void    Print(TreeNode* p,map<char,string>&trans,map<string,char>&reverse)
{
    if (p == NULL)
        return;
    if ((p->leftchild == NULL) && p->rightchild == NULL)
    {
        trans.insert(make_pair(p->A, p->bm));
        reverse.insert(make_pair(p->bm, p->A));
    }
    Print(p->leftchild,trans,reverse);
    Print(p->rightchild,trans,reverse);
}
void    Realease(TreeNode* p)
{
    if (p == NULL)
        return;
    Realease(p->leftchild);
    Realease(p->rightchild);
    delete p;
}
