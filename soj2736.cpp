#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 400
//破题 靠 poj能过 soj就是wa 你妹啊。。。。。。。。。。。。。。。。。。。。。。
using namespace std;
const int N=16;
int ans[N],out[N][N],a[N],flip[N],cc[N];
int n,m,cnt,Min;

void Copy()
{
    for(int i=0;i<m;i++)
        cc[i]=flip[i],ans[i]=0;
}

void Filp(int x)
{
    for(int i=0;i<n;i++)
    {
        if(x&(1<<i))
        {
            cnt++;
            ans[0]^=(1<<i);
            cc[0]^=(1<<i);
            if(i>=1)
                cc[0]^=(1<<(i-1));
            if(i+1<n)
                cc[0]^=(1<<(i+1));
            if(m>1)
                cc[1]^=(1<<i);
        }
    }
}

void FanZhuan(int k)
{
    int x=cc[k-1];
    for(int i=0;i<n;i++)
    {
        if(x&(1<<i))
        {
            cnt++;
            ans[k]^=(1<<i);
            cc[k-1]^=(1<<i);
            cc[k]^=(1<<i);
            if(k+1==m)
            {
                if(i>=1)
                    cc[k]^=(1<<(i-1));
                if(i+1<n)
                    cc[k]^=(1<<(i+1));
            }
            else
            {
                if(i>=1)
                    cc[k]^=(1<<(i-1));
                if(i+1<n)
                    cc[k]^=(1<<(i+1));
                cc[k+1]^=(1<<i);
            }
        }
    }
}

void GetOut()
{
    for(int i=0;i<m;i++)
    {
        //printf("%d\n",ans[i]);
        for(int j=0;j<n;j++)
        {
            out[i][j]=(ans[i]&(1<<j))?1:0;
        }
    }
}

bool Cleck()
{
    int t;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(ans[i]&(1<<j))
                t=1;
            else
                t=0;
            if(out[i][j]<=t)
                continue;
            else
                return true;
        }
    }
    return false;
}

void Cal()
{
    for(int i=0;i<(1<<n);i++)
    {
        cnt=0;
        Copy();
        Filp(i);
        for(int j=1;j<m;j++)
        {
            FanZhuan(j);//英语不好的伤不起啊
        }
        if(cc[m-1]==0&&cnt<Min)
        {
            Min=cnt;
            //printf("cnt=%d\n",cnt);
            GetOut();
        }
        else if(cc[m-1]==0&&cnt==Min)
        {
            if(Cleck())
            {
                GetOut();
            }
        }
    }
}

int main()
{
    a[0]=1;
    for(int i=1;i<=15;i++)
        a[i]=1<<i;
    while(scanf("%d%d",&m,&n)==2)
    {
        int t;
        for(int i=0;i<m;i++)
        {
            flip[i]=0;
            for(int j=0;j<n;j++)
            {
                scanf("%d",&t);
                flip[i]+=t*a[j];
            }
        }

        Min=inf;
        Cal();
        if(Min==inf)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                j+1==n?printf("%d\n",out[i][j]):printf("%d ",out[i][j]);
            }
        }
    }
    return 0;
}
