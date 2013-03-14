#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;

struct node
{
    int l,r;
    int min,max,x;
}tree[50005*8];

int num[50005];

int Min(int x,int y)
{
    return x<y?x:y;
}

int Max(int x,int y)
{
    return x>y?x:y;
}

int Max(int x,int y,int z)
{
    return Max(Max(x,y),z);
}

void BuildTree(int k,int l,int r)
{
    tree[k].l=l;
    tree[k].r=r;
    if(l==r)
    {
        tree[k].min=tree[k].max=num[l];
        tree[k].x=-1000000001;
        return ;
    }
    int mid=(l+r)>>1;
    BuildTree(k*2,l,mid);
    BuildTree(k*2+1,mid+1,r);
    tree[k].x=Max(tree[k*2].x,tree[k*2].x,tree[k*2].max-tree[k*2+1].min);
    tree[k].max=Max(tree[k*2].max,tree[k*2+1].max);
    tree[k].min=Min(tree[k*2].min,tree[k*2+1].min);
}

int Query(int k,int l,int r,int &max,int &min)
{
    if(tree[k].l==l&&tree[k].r==r)
    {
        max=tree[k].max;
        min=tree[k].min;
        return tree[k].x;
    }
    int mid=(tree[k].l+tree[k].r)>>1;
    if(r<=mid)
    {
        return Query(k*2,l,r,max,min);
    }
    else if(l>mid)
    {
        return Query(k*2+1,l,r,max,min);
    }
    else
    {
        int t1,t2,ans,mn,mx;
        t1=Query(k*2,l,mid,max,min);
        t2=Query(k*2+1,mid+1,r,mx,mn);
        ans=Max(t1,t2,max-mn);
        max=Max(max,mx);
        min=Min(min,mn);
        return ans;
    }
}

void Change(int k,int pos,int v)
{
   // printf("%d %d %d\n",pos,tree[k].l,tree[k].r);
    if(tree[k].l==tree[k].r)
    {
        tree[k].max=tree[k].min=v;
        return ;
    }
    int mid=(tree[k].l+tree[k].r)>>1;
    if(pos<=mid)
    {
        Change(k*2,pos,v);
    }
    else
    {
        Change(k*2+1,pos,v);
    }
    tree[k].max=Max(tree[k*2].max,tree[k*2+1].max);
    tree[k].min=Min(tree[k*2].min,tree[k*2+1].min);
    tree[k].x=Max(tree[k*2].x,tree[k*2+1].x,tree[k*2].max-tree[k*2+1].min);
}



int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i,m,x,y,n,min,max;
        char c[3];
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
        }
        BuildTree(1,0,n-1);
        while(m--)
        {
            scanf("%s%d%d",c,&x,&y);
            if(c[0]=='Q')
            {
                printf("%d\n",Query(1,x,y,max,min));
            }
            else
            {
                Change(1,x,y);
            }
        }
    }
    return 0;
}
