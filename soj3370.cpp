#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn=100005;

struct node
{
    int l,r;
    int num;
    bool lazy;
}tree[maxn*8];

void BuildTree(int k,int l,int r)
{
    tree[k].l=l;
    tree[k].r=r;
    tree[k].num=0;
    tree[k].lazy=0;
    if(l==r)
    {
        return;
    }
    int mid=(l+r)>>1;
    BuildTree(k*2,l,mid);
    BuildTree(k*2+1,mid+1,r);
}

void Updata(int k)
{
    tree[k].num=tree[k].r-tree[k].l+1-tree[k].num;
    tree[k].lazy=!tree[k].lazy;
}

void Insert(int k,int l,int r)
{
    if((tree[k].l==l&&tree[k].r==r)||(tree[k].l==tree[k].r))
    {
        Updata(k);
        return ;
    }
    if(tree[k].lazy)
    {
        Updata(k*2);
        Updata(k*2+1);
        tree[k].lazy=0;
    }
    int mid=(tree[k].l+tree[k].r)>>1;
    if(r<=mid)
    {
        Insert(k*2,l,r);
    }
    else if(l>mid)
    {
        Insert(k*2+1,l,r);
    }
    else
    {
        Insert(k*2,l,mid);
        Insert(k*2+1,mid+1,r);
    }
    tree[k].num=tree[k*2].num+tree[k*2+1].num;
}

int Query(int k,int l,int r)
{
    if((tree[k].l==l&&tree[k].r==r)||(tree[k].l==tree[k].r))
    {
        return tree[k].num;
    }
    if(tree[k].lazy)
    {
        Updata(k*2);
        Updata(k*2+1);
        tree[k].lazy=0;
    }
    int mid=(tree[k].l+tree[k].r)>>1;
    if(r<=mid)
    {
        return Query(k*2,l,r);
    }
    else if(l>mid)
    {
        return Query(k*2+1,l,r);
    }
    else
    {
        return Query(k*2,l,mid)+Query(k*2+1,mid+1,r);
    }
}

int main()
{
    int n,q;
    while(scanf("%d%d",&n,&q)==2)
    {
        BuildTree(1,1,n);
        int op,l,r;
        while(q--)
        {
            scanf("%d%d%d",&op,&l,&r);
            if(op)
            {
                printf("%d\n",Query(1,l,r));
            }
            else
            {
                Insert(1,l,r);
            }
        }
    }
    return 0;
}
