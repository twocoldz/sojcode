#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
int f[200001];
int n,m;
queue<int> v;

void Bfs()
{
    memset(f,-1,sizeof(f));
    f[n]=0;
    while(!v.empty())
        v.pop();
    v.push(n);
    while(!v.empty())
    {
        int t=v.front();
        v.pop();
        if(t-1>=0&&f[t-1]==-1)
        {
            f[t-1]=f[t]+1;
            if(t-1==m)
                return;
            v.push(t-1);
        }
        if(t+1<m*2&&f[t+1]==-1)
        {
            f[t+1]=f[t]+1;
            if(t+1==m)
                return;
            v.push(t+1);
        }
        if(t*2<m*2&&f[t*2]==-1)
        {
            f[t*2]=f[t]+1;
            if(t*2==m)
                return;
            v.push(t*2);
        }

    }
}

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        if(m<=n)
        {
            printf("%d\n",n-m);
            continue;
        }
        Bfs();
        printf("%d\n",f[m]);
    }
    return 0;
}
