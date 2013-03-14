#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;
struct node
{
    int num,pos;
    int v;
}a[1005];

bool cmp(node a,node b)
{
    if(a.num==b.num)
        return a.pos<b.pos;
    return a.num>b.num;
}

int main()
{
    int n,c;
    while(scanf("%d%d",&n,&c)==2)
    {
        map<int,node> v;
        map<int,node>::iterator it;
        int x;
        node t;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            it=v.find(x);
            if(it==v.end())
            {
                t.num=1,t.pos=i,t.v=x;
                v[x]=t;
            }
            else
            {
                (*it).second.num++;
            }
        }
        int i=0;
        for(it=v.begin();it!=v.end();it++,i++)
        {
            a[i].v=(*it).first;
            a[i].num=(*it).second.num;
            a[i].pos=(*it).second.pos;
        }
        sort(a,a+i,cmp);
        int tt=1;
        for(int j=0;j<i;j++)
        {
            for(int k=0;k<a[j].num;k++,tt++)
                tt==n?printf("%d\n",a[j].v):printf("%d ",a[j].v);
        }
    }
    return 0;
}
