#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

using namespace std;

typedef map< string , vector<pair<int ,int > > > com;

int main()
{
    int t;
    scanf("%d",&t);
    com v;
    char type[3000],name[3000];
    while(t--)
    {
        int i,n,total,ans;
        v.clear();
        scanf("%d%d",&n,&total);
        int price,q,l=1000000001,r=0;
        int pp;
        for(i=1;i<=n;i++)
        {
            scanf("%s %s %d %d",type,name,&price,&q);
            if(q<l)
            {
                l=q;
            }
            if(q>r)
            {
                r=q;
            }
            v[type].push_back(make_pair(price,q));
        }
        while(l<=r)
        {
            int mid=(l+r)>>1;
            int p=0;
            com::iterator it;
            for(it=v.begin();p<=total&&it!=v.end();it++,p+=pp)
            {
                for(i=0,pp=1<<30;i<(it->second.size());i++)
                {
                    if(it->second[i].second>=mid)
                    {
                        int temp=it->second[i].first;
                        pp=min(pp,temp);
                    }
                }
            }
            if(p<=total)
            {
                l=mid+1;
                ans=mid;
            }
            else
            {
                r=mid-1;
            }
        }
        printf("%d\n",ans);
    }
}
