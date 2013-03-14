#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define UP 1
#define DOWN -1

using namespace std;
const int maxn=1000005;

int f[maxn],g[maxn];

bool cmp(const int &a,const int &b)
{
    return a>b;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        int flag=UP;
        int pre=0;
        int aft;
        int p1=0,p2=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&aft);
            if(aft>pre&&flag==DOWN)
            {
                g[p1++]=pre;
                flag=UP;
            }
            if(aft<pre&&flag==UP)
            {
                f[p2++]=pre;
                flag=DOWN;
            }
            pre=aft;
        }
        if(flag==1)
        {
            f[p2++]=pre;
        }
        sort(f,f+p2,cmp);
        sort(g,g+p1,cmp);
        for(int i=1;i<=q;i++)
        {
            int day;
            scanf("%d",&day);
            if(p1>0)
            {
                while(g[p1-1]<=day)
                {
                    p1--;
                    if(p1==0)
                        break;
                }
            }
            if(p2>0)
            {
                while(f[p2-1]<=day)
                {
                    p2--;
                    if(p2==0)
                        break;
                }
            }
            i==q?printf("%d\n",p2-p1):printf("%d ",p2-p1);
        }
    }
    return 0;
}

