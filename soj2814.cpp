#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn=10005;

struct node
{
    int b,e,v;
}edge[maxn*5];

int n,m,s;
int fa[maxn];
int sum[maxn];

struct Q
{
    int pos,num,ans;
}q[maxn];

bool cmpq(Q x,Q y)
{
    return x.num<y.num;
}

bool cmpq2(Q x,Q y)
{
    return x.pos<y.pos;
}

bool cmpe(node x,node y)
{
    return x.v<y.v;
}

int FindFa(int x)
{
    if(fa[x]!=x)
    {
        fa[x]=FindFa(fa[x]);
    }
    return fa[x];
}

int Un(int x,int y)
{
    fa[y]=x;
    int t=sum[x]*sum[y];
    sum[x]+=sum[y];
    return t;
}

void Init()
{
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
        sum[i]=1;
    }
}

int main()
{
        while(scanf("%d%d%d",&n,&m,&s)==3)
        {
            Init();
            for(int i=1;i<=m;i++)
            {
                scanf("%d%d%d",&edge[i].b,&edge[i].e,&edge[i].v);
            }
            sort(edge+1,edge+1+m,cmpe);
            for(int i=1;i<=s;i++)
            {
                scanf("%d",&q[i].num);
                q[i].pos=i;
            }
            sort(q+1,q+1+s,cmpq);
            int k=1;
            int ans=0;
            for(int i=1;i<=s;i++)
            {
                while(k<=m&&edge[k].v<=q[i].num)
                {
                    int fb=FindFa(edge[k].b);
                    int fe=FindFa(edge[k].e);
                    if(fe==fb)
                    {
                        k++;

                        continue;
                    }
                    else
                    {
                        ans+=Un(fb,fe);
                    }
                    k++;
                }
                q[i].ans=ans;
            }
            sort(q+1,q+1+s,cmpq2);
            for(int i=1;i<=s;i++)
            {
                printf("%d\n",q[i].ans);
            }
        }
    return 0;
}
