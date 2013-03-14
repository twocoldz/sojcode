#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define inf 0x3f3f3f3f

using namespace std;
int sum[305][305];
int q[305];

int main()
{
    int r,c,m;
    char str[305];
    while(scanf("%d%d%d",&r,&c,&m)==3)
    {
        if(r==0&&c==0&&m==0)
            break;
        for(int i=1;i<=r;i++)
        {
            scanf("%s",str);
            sum[i][0]=0;
            for(int j=0;j<c;j++)
            {
                if(str[j]=='.')
                    sum[i][j+1]=sum[i][j]+1;
                else
                    sum[i][j+1]=sum[i][j];
            }
        }
        int ans=inf;
        for(int i=0;i<c;i++)
        {
            for(int j=i+1;j<=c;j++)
            {
                q[0]=0;
                for(int k=1;k<=r;k++)
                {
                    q[k]=q[k-1]+sum[k][j]-sum[k][i];
                }
                int head=0,rear=1;
                while(rear<=r)
                {
                    if(q[rear]-q[head]>=m)
                    {
                        if((j-i)*(rear-head)<=ans)
                        {
                            ans=(j-i)*(rear-head);
                        }
                        head++;
                    }
                    else
                        rear++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

/*
for(int j=i+1;j<=c;j++)
            {
                int head=0,rear=0;
                q[head]=0;
                int tt=0;
                for(int k=1;k<=r;k++)
                {
                    tt+=sum[k][j]-sum[k][i];
                    q[++rear]=k;
                    while(head!=rear&&tt-(sum[q[head]][j]-sum[q[head]][i])>=m)
                    {
                        tt-=(sum[q[head]][j]-sum[q[head]][i]);
                        head++;
                    }
                    if(tt>=m&&(rear-head+1)*(j-i)<ans)
                    {
                        ans=(rear-head+1)*(j-i);
                    }
                }
            }
*/
