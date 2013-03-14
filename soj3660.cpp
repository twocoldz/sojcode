#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node
{
    int r,c,dis;
}s[55*105];
int mid;
int v[55][105];

inline void getDis(int r,int c,int k)
{
    s[k].dis=r*r+(c-mid)*(c-mid);
}

bool cmp(node a,node b)
{
    if(a.dis==b.dis)
    {
        if(a.r==b.r)
        {
            return a.c<b.c;
        }
        return a.r<b.r;
    }
    return a.dis<b.dis;
}


int main()
{
    int n,m;
    while(scanf("%d%d",&m,&n)==2)
    {
        int k=1;
        mid=(m-1)>>1;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                s[k].r=i,s[k].c=j,getDis(i,j,k),k++;
        sort(s+1,s+1+n*m,cmp);
        for(int i=1;i<=n*m;i++)
        {
            v[s[i].r][s[i].c]=i;
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<m;j++)
            {
                j+1==m?printf("%d\n",v[i][j]):printf("%d ",v[i][j]);
            }
        }
    }
    return 0;
}
