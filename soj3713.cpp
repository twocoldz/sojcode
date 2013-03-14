#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> c[50005];
int v[50005];
int u[50005];
int E,V;

void Dfs(int k,int mark)
{
    if(u[k])
        return ;
    u[k]=mark;
    V++;
    for(int i=0;i<c[k].size();i++)
    {
        Dfs(c[k][i],mark);
        E++;
    }
}

int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            c[i].clear();
        int a,b;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            c[a].push_back(b);
            c[b].push_back(a);
        }

        for(int i=1;i<=n;i++)
            scanf("%d",v+i);
        memset(u,0,sizeof(u));
        int num=0,t=0,last=-1;
        for(int i=1;i<=n;i++)
        {
            if(!u[i])
            {
                E=V=0;
                Dfs(i,++num);
                if(E/2==V-1)
                    t++,last=num;
            }
        }

        if(t>1)
        {
            printf("impossible\n");
            continue;
        }
        vector<pair<int,int> > vv;
        for(int i=1;i<=n;i++)
        {
            if(u[i]==last)
                vv.push_back(make_pair(-v[i],i));
        }
        sort(vv.begin(),vv.end());

        a=vv[0].second;
        b=vv.size()>1?vv[1].second:-1;
        bool f=vv.size()>1&&vv[0].first==vv[1].first;

        for(int i=1;i<=n;i++)
        {
            if(u[i]!=last&&(!f||i<b))
            {
                b=i;
                break;
            }
        }
        if(b<a)
            swap(a,b);
        printf("%d %d\n",a,b);
    }
    return 0;
}
