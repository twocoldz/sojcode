#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define LL(k) k<<1
#define RR(k) (k<<1|1)

using namespace std;

const int maxn=200005;

struct sep
{
    int v,pos;
}num[maxn];

int f[maxn],x[maxn],p[maxn];
//f[i]维护以num[i]开头，最大可达
//x[i]用于离散化
//p[i]用于帮助求出f[i]

bool cmp(sep a,sep b)
{
    return a.v<b.v;
}

struct node
{
    int l,r;
    int cnt;
}tree[maxn*4];

void BuildTree(int k,int l,int r)
{
    tree[k].l=l;
    tree[k].r=r;
    if(l==r)
    {
        tree[k].cnt=f[l]-l+1;
        return ;
    }
    int mid=(l+r)>>1;
    BuildTree(LL(k),l,mid);
    BuildTree(RR(k),mid+1,r);
    tree[k].cnt=max(tree[LL(k)].cnt,tree[RR(k)].cnt);
}

int Query(int k,int l,int r)
{
    if(tree[k].l==l&&tree[k].r==r)
    {
        return tree[k].cnt;
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

int main()
{
    int n,q;
    while(scanf("%d",&n)==1)
    {
        scanf("%d",&q);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num[i].v);
            num[i].pos=i;
        }
        sort(num+1,num+1+n,cmp);
        int index=1;
        x[num[1].pos]=1;
        for(int i=2;i<=n;i++)
        {
            if(num[i].v!=num[i-1].v)
                index++;
            x[num[i].pos]=index;
        }
        for(int i=1;i<=index;i++)
        {
            p[i]=1+n;
        }
        f[n+1]=n+1;
        for(int i=n;i>=1;i--)
        {
            f[i]=min(f[i+1],p[x[i]]-1);
            p[x[i]]=i;
        }
        BuildTree(1,1,n);
        while(q--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            a++,b++;
            int l=a,r=b;
            while(l<=r)
            {
                int mid=(l+r)>>1;
                if(f[mid]>b)
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            --l;
            if(l<a)
            {
                printf("%d\n",b-a+1);
            }
            else if(l==b)
            {
                printf("%d\n",Query(1,a,b));
            }
            else
            {
                printf("%d\n",max(b-l,Query(1,a,l)));
            }
        }
    }
    return 0;
}
