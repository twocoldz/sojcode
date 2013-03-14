#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;
char c[10005][55];

int main()
{
    string str;
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%s",c[i]);
        cin>>str;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(str.find(c[i])!=str.npos)
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
