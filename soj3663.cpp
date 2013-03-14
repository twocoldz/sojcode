#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node
{
    int c,lim;
}sto[105];


bool cmp(node a,node b)
{
    return a.c<b.c;
}

int main()
{
    int n,k,e;
    while(scanf("%d%d%d",&k,&e,&n)==3)
    {
        int x,c;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&x,&sto[i].lim,&c);
            sto[i].c=c+e-x;
        }
        sort(sto,sto+n,cmp);
        int cost=0;
        for(int i=0;i<n;i++)
        {
            int t=min(k,sto[i].lim);
            cost+=t*sto[i].c;
            //printf("t=%d c=%d cost=%d\n",t,sto[i].c,cost);
            k-=t;
            if(k==0)
                break;
        }
        printf("%d\n",cost);
    }
    return 0;
}
