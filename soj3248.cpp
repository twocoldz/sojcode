#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct node
{
    int l,r;
    int v;
}tree[100005*4];

void BuildTree(int k,int l,int r)
{
    tree[k].l=l;
    tree[k].r=r;
    tree[k].v=(r-l+1);
    if(l==r)
    {
        return ;
    }
    int mid=(l+r)>>1;
    BuildTree(k*2,l,mid);
    BuildTree(k*2+1,mid+1,r);
}

int Insert(int k,int v)
{
    tree[k].v--;
    if(tree[k].l==tree[k].r)
    {
        return tree[k].l;
    }
    if(tree[k*2].v<v)
    {
        return Insert(2*k+1,v-tree[k*2].v);
    }
    else
    {
        return Insert(2*k,v);
    }
}

int Query(int k,int v)
{
    if(v==tree[k].r)
    {
        return tree[k].v;
    }
    else if(v<=tree[k*2].r)
    {
        return Query(2*k,v);
    }
    else
    {
        return tree[k*2].v+Query(2*k+1,v);
    }
}
int out[100005];

int main()
{
    int t;
    scanf("%d",&t);
    int cases=1;
    while(t--)
    {
        int n,K;
        scanf("%d",&K);
        BuildTree(1,1,K);
        int index=1;
        out[1]=1;
        Insert(1,1);
        for(int i=2;i<=K;i++)
        {
            int left=Query(1,index);
            int next=(i+left)%(K-i+1);
            if(next==0)
                next=K-i+1;
            index=Insert(1,next);
            out[index]=i;
        }
        printf("Case #%d: ",cases++);
        int temp;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&temp);
            i==n?printf("%d\n",out[temp]):printf("%d ",out[temp]);
        }
    }
    return 0;
}
