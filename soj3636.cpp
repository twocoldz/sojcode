#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define inf 0x3f3f3f3f

using namespace std;
int a,b,n;
int mar[1002][1002];
int lmax[1002][1002],lmin[1002][1002],hmax[1002][1002],hmin[1002][1002];
int q[1005];

int main()
{
    while(scanf("%d%d%d",&a,&b,&n)==3)
    {
        for(int i=0;i<a;i++)
            for(int j=0;j<b;j++)
                scanf("%d",mar[i]+j);
        for(int i=0;i<a;i++)
        {
            int head=0,rear=-1;
            for(int j=0;j<b;j++)
            {
                while(rear!=head-1&&mar[i][q[rear]]>mar[i][j])
                {
                    rear--;
                }
                q[++rear]=j;
                while(j-q[head]>=n)
                    head++;
                if(j-n+1>=0)
                {
                    hmin[i][j-n+1]=mar[i][q[head]];
                    //printf("hmin[%d][%d]=%d\n",i,j-n+1,hmin[i][j-n+1]);
                }

            }
            head=0,rear=-1;
            for(int j=0;j<b;j++)
            {
                while(rear!=head-1&&mar[i][q[rear]]<mar[i][j])
                {
                    rear--;
                }
                q[++rear]=j;
                while(j-q[head]>=n)
                    head++;
                if(j-n+1>=0)
                {
                    hmax[i][j-n+1]=mar[i][q[head]];
                    //printf("hmax[%d][%d]=%d\n",i,j-n+1,hmax[i][j-n+1]);
                }

            }
        }
        for(int i=0;i<=b-n;i++)
        {
            int head=0,rear=-1;
            for(int j=0;j<a;j++)
            {
                while(rear!=head-1&&hmin[q[rear]][i]>hmin[j][i])
                {
                    rear--;
                }
                q[++rear]=j;
                while(j-q[head]>=n)
                    head++;
                if(j-n+1>=0)
                {
                    lmin[j-n+1][i]=hmin[q[head]][i];
                    //printf("lmin[%d][%d]=%d\n",j-n+1,i,lmin[j-n+1][i]);
                }
            }
            head=0,rear=-1;
            for(int j=0;j<a;j++)
            {
                while(rear!=head-1&&hmax[q[rear]][i]<hmax[j][i])
                {
                    rear--;
                }
                q[++rear]=j;
                while(j-q[head]>=n)
                    head++;
                if(j-n+1>=0)
                {
                    lmax[j-n+1][i]=hmax[q[head]][i];
                    //printf("lmax[%d][%d]=%d\n",j-n+1,i,lmax[j-n+1][i]);
                }

            }
        }
        int ans=inf;
        for(int i=0;i<=a-n;i++)
        {
            for(int j=0;j<=b-n;j++)
            {
                ans=min(ans,lmax[i][j]-lmin[i][j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
