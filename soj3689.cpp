#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> p[10005];
int c[300005];
bool vis[10005];

int Bin(int a,int b,int w)
{
    int l=0,r=p[w].size()-1;
    int ll,rr;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(p[w][mid]>=a)
            ll=mid,r=mid-1;
        else
            l=mid+1;
    }
    l=0,r=p[w].size()-1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(p[w][mid]<=b)
            rr=mid,l=mid+1;
        else
            r=mid-1;
    }
    return rr-ll+1;
}

int main()
{
    int n,C;
    while(scanf("%d%d",&n,&C)==2&&n)
    {
        for(int i=1;i<=C;i++)
            p[i].clear();
        for(int i=0;i<n;i++)
        {
            scanf("%d",c+i);
            p[c[i]].push_back(i);
        }
        int Q;
        scanf("%d",&Q);
        int a,b;
        for(int i=1;i<=Q;i++)
        {
            scanf("%d%d",&a,&b);
            int j;
            a--,b--;
            for(j=0;j<20;j++)
            {
                int t=c[rand()%(b-a+1)+a];
                if(Bin(a,b,t)*2>(b-a+1))
                {
                    printf("yes %d\n",t);
                    break;
                }
            }
            if(j>=20)
                printf("no\n");
        }
    }
    return 0;
}
