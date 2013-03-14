#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define LL(x) (x<<1)
#define RR(x) (x<<1|1)

using namespace std;

const int maxn=100005;

struct node
{
    int l,r;
    int v;
}tree[maxn*4];

void BuildTree(int k,int l,int r)
{
    tree[k].l=l;
    tree[k].r=r;
    tree[k].v=0;
    if(l==r)
    {
        return;
    }
    int mid=(l+r)>>1;
    BuildTree(LL(k),l,mid);
    BuildTree(RR(k),mid+1,r);
}

void Insert(int k,int pos,int v)
{
    if(tree[k].l==tree[k].r)
    {
        tree[k].v=max(tree[k].v,v);
        return ;
    }
    int mid=(tree[k].l+tree[k].r)>>1;
    if(pos<=mid)
    {
        Insert(LL(k),pos,v);
    }
    else
    {
        Insert(RR(k),pos,v);
    }
    tree[k].v=max(tree[LL(k)].v,tree[RR(k)].v);
}

int Query(int k,int l,int r)
{
    if(tree[k].l==l&&tree[k].r==r)
    {
        return tree[k].v;
    }
    int mid=(tree[k].l+tree[k].r)>>1;
    if(r<=mid)
    {
        return Query(LL(k),l,r);
    }
    else if(l>mid)
    {
        return Query(RR(k),l,r);
    }
    else
    {
        return max(Query(LL(k),l,mid),Query(RR(k),mid+1,r));
    }
}

int a[maxn];
int b[maxn];

int main()
{
    int n,d;
    while(scanf("%d%d",&n,&d)==2&&n)
    {
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        sort(b,b+n);
        int len=unique(b,b+n)-b;
        BuildTree(1,0,len);
        int ans=0;
        for(i=0;i<n;i++)
        {
            int l=lower_bound(b,b+len,a[i]-d)-b;
            int r=upper_bound(b,b+len,a[i]+d)-b-1;
            int x=Query(1,l,r);
            ans=max(ans,x+1);
            int pos=lower_bound(b,b+len,a[i])-b;
            Insert(1,pos,x+1);
        }
        printf("%d\n",ans);
    }
    return 0;
}
