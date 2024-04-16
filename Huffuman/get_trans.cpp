#include "get_trans.h"
using namespace std;
void get_trans(map<char,int>&mp,map<char,string>&trans,map<string,char>&reverse)
{
    multimap<int, TreeNode> info;
    map<char, int>::iterator po = mp.begin();
    while (po != mp.end())
    {
        char m;
        pair<int, TreeNode> p;
        p.first = (*po).second;
        m = (*po).first;
        p.second.set_A(m);
        info.insert(p);
        ++po;
    }
    TreeNode t;
    while (1)
    {
        TreeNode p;
        pair<int, TreeNode>a = (*info.begin());//当前应该连起来的两个节点
        pair<int, TreeNode>b = *(++(info.begin()));
        TreeNode* c = new TreeNode;
        *c = a.second;
        TreeNode* d = new TreeNode;
        *d = b.second;
        LinkChild(p, *c, *d);
        map<int, TreeNode>::iterator z = ++info.begin();
        info.erase(info.begin(), ++z);
        info.insert(make_pair(a.first + b.first, p));
        t = (*info.begin()).second;
        if (info.size() == 1)
            break;
    }
    Print(&t, trans,reverse);
    Realease(t.leftchild);
    Realease(t.rightchild);
}