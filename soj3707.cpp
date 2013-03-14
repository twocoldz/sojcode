#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
char a[10];
bool vis[10];
bool prime[10000000];
bool used[10000000];
int ans;

void Dfs(int num,int len)
{
    //printf("%d\n",num);
    if(prime[num]&&!used[num])
        ans++,used[num]=1;
    for(int i=0;i<len;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            Dfs(num*10+a[i]-'0',len);
            vis[i]=0;
        }
    }
}

void Init()
{
    memset(prime,1,sizeof(prime));
    prime[0]=prime[1]=0;
    for(int i=2;i<10000000;i++)
    {
        if(prime[i])
        {
            for(int j=i+i;j<10000000;j+=i)
            {
                prime[j]=0;
            }
        }
    }
}

int main()
{
    Init();
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        memset(vis,0,sizeof(vis));
        memset(used,0,sizeof(used));
        ans=0;
        scanf("%s",a);
        int len=strlen(a);
        Dfs(0,len);
        printf("%d\n",ans);
    }
    return 0;
}
