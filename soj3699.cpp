#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;
int a[4];
int vis[4];
int res[1<<20];
int tot;
map<int,bool> yes;

int Cal(int a,int b,int op)
{
    if(op==0)
        return a+b;
    else if(op==1)
        return a-b;
    else if(op==2)
        return a*b;
    else if(op==3&&b!=0&&a%b==0)
        return a/b;
    else if(op==4&&a!=0&&b%a==0)
        return b/a;
    else
        return b-a;
}

void Dfs(int num)
{
    if(num==4)
    {
        for(int i=0;i<4;i++)
        {
            if(!vis[i]&&!yes[a[i]])
            {
                res[tot++]=a[i];
                yes[a[i]]=true;
            }
        }
        return ;
    }

    for(int i=0;i<4;i++)
    {
        if(!vis[i])
        {
            for(int j=i+1;j<4;j++)
            {
                if(!vis[j])
                {
                    int x=a[i],y=a[j];
                    vis[j]=true;
                    for(int k=0;k<6;k++)
                    {
                        a[i]=Cal(x,y,k);
                        Dfs(num+1);
                    }
                    vis[j]=false;
                    a[i]=x;
                }
            }
        }
    }
}

int main()
{
    int cases=1;
    while(scanf("%d%d%d%d",a+0,a+1,a+2,a+3))
    {
        if(a[0]+a[1]+a[2]+a[3]==0)
            break;
        tot=0;
        memset(vis,0,sizeof(vis));
        yes.clear();
        Dfs(1);
        sort(res,res+tot);
        int sta=-100000000;
        int end=-100000000;
        int len=-1;
        //for(int i=0;i<tot;i++)
        //    printf("%d ",res[i]);
        for(int i=0;i<tot;i++)
        {
            int j=i;
            while(j+1<tot&&res[j+1]-res[j]==1)
                j++;
            if(j-i>=len)
            {
                len=j-i;
                sta=res[i];
                end=res[j];
            }
            i=j;
        }
        printf("Case %d: %d to %d\n",cases++,sta,end);
    }
    return 0;
}
