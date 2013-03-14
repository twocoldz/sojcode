#include <iostream>
#include <cstring>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct node
{
    long long v,lazy;
    int l,r;
}tree[100005*4];

long long sum;
int num[100005];

void BuildTree(int k,int l,int r)
{
    tree[k].l=l;
    tree[k].r=r;
    tree[k].lazy=0;
    if(l==r)
    {
        tree[k].v=num[l];
        return;
    }
    int mid=(l+r)>>1;
    BuildTree(k*2,l,mid);
    BuildTree(k*2+1,mid+1,r);
    tree[k].v=tree[k*2].v+tree[k*2+1].v;
}

void Insert(int k,int l,int r,int v)
{
    if(l==tree[k].l&&tree[k].r==r)
    {
        tree[k].v+=v*(r-l+1);
        tree[k].lazy+=v;
        return ;
    }
	int mid=(tree[k].l+tree[k].r)>>1;
//    if(tree[k].lazy!=0)
//    {
        tree[k*2].v+=tree[k].lazy*(mid-tree[k].l+1);
        tree[k*2].lazy+=tree[k].lazy;
        tree[k*2+1].v+=tree[k].lazy*(tree[k].r-mid);
        tree[k*2+1].lazy+=tree[k].lazy;
        tree[k].lazy=0;
//    }
    if(r<=mid)
    {
        Insert(k*2,l,r,v);
    }
    else if(l>mid)
    {
        Insert(k*2+1,l,r,v);
    }
    else
    {
        Insert(k*2,l,mid,v);
        Insert(k*2+1,mid+1,r,v);
    }
    tree[k].v=tree[k*2].v+tree[k*2+1].v;
}

void Query(int k,int l,int r)
{
    if(tree[k].l==l&&tree[k].r==r)
    {
        sum+=tree[k].v;
		return ;
    }
	int mid=(tree[k].l+tree[k].r)>>1;
//    if(tree[k].lazy!=0)
//    {
        tree[k*2].v+=tree[k].lazy*(mid-tree[k].l+1);
        tree[k*2].lazy+=tree[k].lazy;
        tree[k*2+1].v+=tree[k].lazy*(tree[k].r-mid);
        tree[k*2+1].lazy+=tree[k].lazy;
        tree[k].lazy=0;
//    }
    if(r<=mid)
    {
        Query(k*2,l,r);
    }
    else if(l>mid)
    {
        Query(k*2+1,l,r);
    }
    else
    {
        Query(k*2,l,mid);
		Query(k*2+1,mid+1,r);
    }
}

int main()
{
    int n,q;
    while(scanf("%d%d",&n,&q)==2&&(n!=0))
    {
        int i;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
        }
		BuildTree(1,1,n);
        char c[3];
        int l,r,x;
        while(q--)
        {
            scanf("%s",c);
            if(c[0]=='Q')
            {
                scanf("%d%d",&l,&r);
				sum=0;
                Query(1,l,r);
				printf("%lld\n",sum);
            }
            else
            {
                scanf("%d%d%d",&l,&r,&x);
                Insert(1,l,r,x);
            }
        }
    }
    return 0;
}
