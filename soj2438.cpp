#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

int Fa[10005];
bool vis[10005];

int FindFa(int x)
{
    if(Fa[x]!=x)
    {
        Fa[x]=FindFa(Fa[x]);
    }
    return Fa[x];
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,num;
        scanf("%d",&n);
        map<string,int> v;
        map<string,int>::iterator it;
        for(int i=1;i<=n;i++)
        {
            Fa[i]=i;
            scanf("%d",&num);
            while(num--)
            {
                string name;
                cin>>name;
                it=v.find(name);
                if(it==v.end())
                {
                    v[name]=Fa[i];
                }
                else
                {
                    int fa=FindFa((*it).second);
                    int fb=FindFa(i);
                    Fa[fb]=fa;
                    v[name]=fa;
                }
            }
        }
 /*       for(it=v.begin();it!=v.end();it++)
        {
            cout<<(*it).first<<" "<<(*it).second<<endl;
        }
*/
        int count=0;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            FindFa(i);
//            cout<<i<<" "<<Fa[i]<<endl;
            if(!vis[Fa[i]])
            {
                vis[Fa[i]]=1;
                count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
