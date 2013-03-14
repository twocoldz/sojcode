#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

struct node
{
    string str;
    int pos;
}a[7];

bool cmp(node a,node b)
{
    return a.str<b.str;
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int l,i;
        int len=0;
        string str[7];
        scanf("%d",&l);
        for(i=0;i<l;i++)
        {
            cin>>str[i];
            a[i].str=str[i];
            a[i].pos=i;
            if(str[i].length()>len)
                len=str[i].length();
        }
        for(i=0;i<l;i++)
        {
            int temp=str[i].length();
            for(int j=temp;j<len;j++)
            {
                a[i].str+=str[i][(j-temp)%temp];
            }
        }
        sort(a,a+l,cmp);
        string ans="";
        for(i=l-1;i>=0;i--)
        {
            ans+=str[a[i].pos];
        }
        cout<<ans<<endl;
    }
    return 0;
}
