#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node
{
    int a,b,l;
}e[100005];
struct T
{
    int l,r,v,lazy;
}tree[100005*4];
int a[100005];

bool cmp(node x,node y)
{
    if(x.b==y.b)
        return x.a>y.a;
    return x.b<y.b;
}

void BuildTree(int l,int r,int rt)
{
    tree[rt].l=l,tree[rt].r=r,tree[rt].lazy=0;
    if(l==r)
    {
        tree[rt].v=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    BuildTree(l,mid,rt<<1);
    BuildTree(mid+1,r,rt<<1|1);
    tree[rt].v=min(tree[rt<<1].v,tree[rt<<1|1].v);
}

bool Query(int l,int r,int rt)
{
    if(tree[rt].l==l&&tree[rt].r==r)
    {
        return tree[rt].v+tree[rt].lazy>0;
    }
    if(tree[rt].lazy)
    {
        tree[rt].v+=tree[rt].lazy;
        tree[rt<<1].lazy+=tree[rt].lazy;
        tree[rt<<1|1].lazy+=tree[rt].lazy;
        tree[rt].lazy=0;
    }
    int mid=(tree[rt].l+tree[rt].r)>>1;
    if(r<=mid)
        return Query(l,r,rt<<1);
    else if(l>mid)
        return Query(l,r,rt<<1|1);
    else
        return Query(l,mid,rt<<1)&&Query(mid+1,r,rt<<1|1);
}

void Insert(int l,int r,int rt)
{
    if(tree[rt].l==l&&tree[rt].r==r)
    {
        tree[rt].lazy--;
        return ;
    }
    if(tree[rt].lazy)
    {
        tree[rt].v+=tree[rt].lazy;
        tree[rt<<1].lazy+=tree[rt].lazy;
        tree[rt<<1|1].lazy+=tree[rt].lazy;
        tree[rt].lazy=0;
    }
    int mid=(tree[rt].l+tree[rt].r)>>1;
    if(r<=mid)
        Insert(l,r,rt<<1);
    else if(l>mid)
        Insert(l,r,rt<<1|1);
    else
        Insert(l,mid,rt<<1),Insert(mid+1,r,rt<<1|1);
    tree[rt].v=min(tree[rt<<1].v+tree[rt<<1].lazy,tree[rt<<1|1].v+tree[rt<<1|1].lazy);
}

int main()
{
    int n,q;
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        BuildTree(1,n,1);
        for(int i=1;i<=q;i++)
            scanf("%d%d",&e[i].a,&e[i].b),e[i].l=e[i].b-e[i].a;
        sort(e+1,e+1+q,cmp);
        int ans=0;
        for(int i=1;i<=q;i++)
        {
            bool f=Query(e[i].a,e[i].b,1);
            if(f)
            {
                ans++;
                Insert(e[i].a,e[i].b,1);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
