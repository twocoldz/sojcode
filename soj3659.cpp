#include <cstdio>
#include <cstring>
#include <algorithm>

char a[21][26],b[21][26];
int n,m;

int Cal(int x,int y)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(i==x)
            continue;
        int j,k;
        for(j=0,k=24;j<=k;j++,k--)
        {
            if(((a[i][j]==a[x][j])||a[i][j]==b[y][j])&&((a[i][k]==a[x][k])||(a[i][k]==b[y][k])))
                continue;
            else
                break;
        }
        if(j>k)
            ans++;
    }
    for(int i=0;i<m;i++)
    {
        if(i==y)
            continue;
        int j,k;
        for(j=0,k=24;j<=k;j++,k--)
        {
            if(((b[i][j]==a[x][j])||b[i][j]==b[y][j])&&((b[i][k]==a[x][k])||(b[i][k]==b[y][k])))
                continue;
            else
                break;
        }
        if(j>k)
            ans++;
    }
    return ans;
}

int main()
{

    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s",a[i]);
        }
        for(int i=0;i<m;i++)
        {
            scanf("%s",b[i]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                j==m-1?printf("%d\n",Cal(i,j)):printf("%d ",Cal(i,j));
            }
        }
    }
    return 0;
}
