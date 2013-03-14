#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
#define inf 0x3f3f3f3f
#define Max 110
int max(int a,int b)
{
    return a>b?a:b;
}
inline int min(int a,int b)
{
    return a<b?a:b;
}
int pos[1010],n,k,b;
int s[1010],dp[1010][1010][4];
struct node
{
    int x,y;
    bool operator<(const node b)const
    {
        if(y==b.y)
            return x<b.x;
        return y<b.y;
    }
}a[1010];

inline int min4(int a,int b,int c,int d)
{
    return min(min(a,b),min(c,d));
}

inline int min3(int a,int b,int c)
{
    return min(min(a,b),c);
}
int main()
{
    int i,j,cnt;
    while(scanf("%d%d%d",&n,&k,&b)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i].x,&a[i].y);
        }
        cnt=1;
        sort(a+1,a+n+1);
        memset(s,0,sizeof(s));
        pos[0]=0;
        pos[cnt]=a[1].y;
        if(a[1].x==1)
            s[cnt]=0;
        else
            s[cnt]=1;
        for(i=2;i<=n;i++)
        {
            if(a[i].y==a[i-1].y)
            {
                s[cnt]=2;
                continue;
            }
            cnt++;
            pos[cnt]=a[i].y;
            if(a[i].x==1)
                s[cnt]=0;
            else
                s[cnt]=1;
            //printf("pos=%d\n",pos[cnt]);
        }

        for(i=0;i<=cnt;i++)
            for(j=0;j<=k;j++)
                for(int l=0;l<4;l++)
                    dp[i][j][l]=inf;
        dp[0][0][2]=0;
        for(i=1;i<=cnt;i++)
        {
            for(j=1;j<=k;j++)
            {
                int t2;
                int t=min4(dp[i-1][j-1][0],dp[i-1][j-1][1],dp[i-1][j-1][2],dp[i-1][j-1][3]);
                //printf("t=%d\n",t);
                if(j>=2)
                {
                    t2=min4(dp[i-1][j-2][0],dp[i-1][j-2][1],dp[i-1][j-2][2],dp[i-1][j-2][3]);
                    //printf("t2=%d\n",t2);
                }
                if(s[i]==0)
                {
                    dp[i][j][0]=min(min(dp[i-1][j][0],dp[i-1][j][3])+pos[i]-pos[i-1],t+1);
                    //dp[i][j][1]=min(dp[i-1][j][1]+pos[i]-pos[i-1],dp[i-1][j][3]+pos[i]-pos[i-1],t+1);不可能
                    dp[i][j][2]=min(dp[i-1][j][2]+2*(pos[i]-pos[i-1]),t+2);
                    dp[i][j][3]=min(dp[i-1][j][3]+2*(pos[i]-pos[i-1]),min(dp[i-1][j-1][0],dp[i-1][j-1][1])+pos[i]-pos[i-1]+1);
                    if(j>=2)
                    {
                        dp[i][j][3]=min(dp[i][j][3],t2+2);
                    }
                }
                else if(s[i]==1)
                {
                    //dp[i][j][0]=min()同样不可能
                    dp[i][j][1]=min(min(dp[i-1][j][1],dp[i-1][j][3])+pos[i]-pos[i-1],t+1);
                    dp[i][j][2]=min(dp[i-1][j][2]+2*(pos[i]-pos[i-1]),t+2);
                    dp[i][j][3]=min(dp[i-1][j][3]+2*(pos[i]-pos[i-1]),min(dp[i-1][j-1][0],dp[i-1][j-1][1])+pos[i]-pos[i-1]+1);
                    if(j>=2)
                    {
                        dp[i][j][3]=min(dp[i][j][3],t2+2);
                    }
                }
                else
                {
                    dp[i][j][2]=min(dp[i-1][j][2]+2*(pos[i]-pos[i-1]),t+2);
                    dp[i][j][3]=min(dp[i-1][j][3]+2*(pos[i]-pos[i-1]),min(dp[i-1][j-1][0],dp[i-1][j-1][1])+pos[i]-pos[i-1]+1);
                    if(j>=2)
                    {
                        dp[i][j][3]=min(dp[i][j][3],t2+2);
                    }
                }
                //printf("posi-posi-1=%d\n",pos[i]-pos[i-1]);
                //for(int l=0;l<4;l++)
                    //printf("i %d j %d l %d dp %d\n",i,j,l,dp[i][j][l]);
            }
        }

        int ans=inf;
        for(j=0;j<4;j++)
        {
            ans=min(ans,dp[cnt][k][j]);
        }
        printf("%d\n",ans);
    }
}


//dp[i][j][k]表示包含前i行的奶牛，用j个矩形，状态为k，
//k=0表示前一个状态上面一个矩形 k=1，下面一个，k=2上下同一个，k=3，上下不是同一个

//pos[i]用于记录第i行的奶牛原来的位置，因为这是离散化过后的 前面dp的i也是一样的
//s[i]用于记录奶牛在第i行的情况，0表示上面有，1表示下面有，2表示上下都有


//用t记录min(dp[i-1][j-1][0--3])
//用t2记录min(dp[i-1][j-2][0--3])
/*
case1： s[i]=0;
{
    dp[i][j][0]=min(dp[i-1][j][0]+pos[i]-pos[i-1],dp[i-1][j][3]+pos[i]-pos[i-1],t+1);
    //dp[i][j][1]=min(dp[i-1][j][1]+pos[i]-pos[i-1],dp[i-1][j][3]+pos[i]-pos[i-1],t+1);
    dp[i][j][2]=min(dp[i-1][j][2]+(pos[i]-pos[i-1])*2,t+2);
    dp[i][j][3]=min(dp[i-1][j][3]+(pos[i]-pos[i-1])*2,dp[i-1][j-1][0]+pos[i]-pos[i-1]+1,dp[i-1][j-1][1]+pos[i]-pos[i-1]+1);
    if(j>=2)
    {
        dp[i][j][3]=min(dp[i][j][3],t2+2);
    }
}

case2: s[i]=1;
{
    //dp[i][j][0]=min()
    dp[i][j][1]=min(dp[i-1][j][1]+pos[i]-pos[i-1],dp[i-1][j][3]+pos[i]-pos[i-1],t+1);
    dp[i][j][2]=min(dp[i-1][j][2]+(pos[i]-pos[i-1])*2,t+2);
    dp[i][j][3]=min(dp[i-1][j][3]+(pos[i]-pos[i-1])*2,dp[i-1][j-1][0]+pos[i]-pos[i-1]+1,dp[i-1][j-1][1]+pos[i]-pos[i-1]+1);
    if(j>=2)
    {
        dp[i][j][3]=min(dp[i][j][3],t2+2);
    }
}

case3: s[i]=2;
{
    dp[i][j][2]=min(dp[i-1][j][2]+(pos[i]-pos[i-1])*2,t+2);
    dp[i][j][3]=min(dp[i-1][j][3]+(pos[i]-pos[i-1])*2,dp[i-1][j-1][0]+pos[i]-pos[i-1]+1,dp[i-1][j-1][1]+pos[i]-pos[i-1]+1);
    if(j>=2)
    {
        dp[i][j][3]=min(dp[i][j][3],t2+2);
    }
}

for(i=1;i<=cnt;i++)
            for(j=1;j<=k;j++)
                for(int l=0;l<4;l++)
                    dp[i][j][l]=inf;
        dp[0][0][2]=dp[0][0][0]=dp[0][0][1]=dp[0][0][3]=0;
        for(i=1;i<=cnt;i++)
        {
            for(j=1;j<=k;j++)
            {
                int t2;
                int t=min4(dp[i-1][j-1][0],dp[i-1][j-1][1],dp[i-1][j-1][2],dp[i-1][j-1][3]);
                printf("t=%d\n",t);
                if(j>=2)
                {
                    t2=min4(dp[i-1][j-2][0],dp[i-1][j-2][1],dp[i-1][j-2][2],dp[i-1][j-2][3]);
                    printf("t2=%d\n",t2);
                }
                if(s[i]==0)
                {
                    dp[i][j][0]=min3(dp[i-1][j][0]+pos[i]-pos[i-1],dp[i-1][j][3]+pos[i]-pos[i-1],t+1);
                    //dp[i][j][1]=min(dp[i-1][j][1]+pos[i]-pos[i-1],dp[i-1][j][3]+pos[i]-pos[i-1],t+1);不可能
                    dp[i][j][2]=min(dp[i-1][j][2]+(pos[i]-pos[i-1])*2,t+2);
                    dp[i][j][3]=min3(dp[i-1][j][3]+(pos[i]-pos[i-1])*2,dp[i-1][j-1][0]+pos[i]-pos[i-1]+1,dp[i-1][j-1][1]+pos[i]-pos[i-1]+1);
                    if(j>=2)
                    {
                        dp[i][j][3]=min(dp[i][j][3],t2+2);
                    }
                }
                else if(s[i]==1)
                {
                    //dp[i][j][0]=min()同样不可能
                    dp[i][j][1]=min3(dp[i-1][j][1]+pos[i]-pos[i-1],dp[i-1][j][3]+pos[i]-pos[i-1],t+1);
                    dp[i][j][2]=min(dp[i-1][j][2]+(pos[i]-pos[i-1])*2,t+2);
                    dp[i][j][3]=min3(dp[i-1][j][3]+(pos[i]-pos[i-1])*2,dp[i-1][j-1][0]+pos[i]-pos[i-1]+1,dp[i-1][j-1][1]+pos[i]-pos[i-1]+1);
                    if(j>=2)
                    {
                        dp[i][j][3]=min(dp[i][j][3],t2+2);
                    }
                }
                else
                {
                    dp[i][j][2]=min(dp[i-1][j][2]+(pos[i]-pos[i-1])*2,t+2);
                    dp[i][j][3]=min3(dp[i-1][j][3]+(pos[i]-pos[i-1])*2,dp[i-1][j-1][0]+pos[i]-pos[i-1]+1,dp[i-1][j-1][1]+pos[i]-pos[i-1]+1);
                    if(j>=2)
                    {
                        dp[i][j][3]=min(dp[i][j][3],t2+2);
                    }
                }
                printf("posi-posi-1=%d\n",pos[i]-pos[i-1]);
                for(int l=0;l<4;l++)
                    printf("i %d j %d l %d dp %d\n",i,j,l,dp[i][j][l]);
            }
        }
*/
