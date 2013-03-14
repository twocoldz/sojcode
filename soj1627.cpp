#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int n,x;
    set<int> v;
    while(scanf("%d%d",&n,&x)==2&&n)
    {
        v.clear();
        int flag=1;
        set<int>::iterator it;
        for(int i=1;i<=n;i++)
        {
            int a;
            scanf("%d",&a);
            if(flag)
            {
                it=v.find(x-a);
                if(it!=v.end())
                {
                    flag=0;
                }
                else
                {
                    v.insert(a);
                }
            }

        }
        if(flag==0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
