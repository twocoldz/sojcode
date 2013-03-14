#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

int main()
{
    map<int,int> v;
    map<int,int>::iterator it;
    int x;
    int flag=1;
    int ans;
    for(int i=1;i<=99999;i++)
    {
        scanf("%d",&x);
        if(flag)
        {
            it=v.find(x);
            if(it==v.end())
            {
                v[x]=1;
            }
            else
            {
                v[x]++;
                if(v[x]>=50000)
                {
                    ans=x;
                    flag=0;
                }
            }
        }
    }
    printf("%d\n",ans);
}
