#include <iostream>
#include <stack>
#include <cstdio>
#include <cstring>
using namespace std;

int num[30005];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,n,count;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
        }
        stack<int> v;
        v.push(num[1]);
        count=1;
        int flag=1;
        for(i=2;i<=n;i++)
        {
            if(flag==1)
            {
                if(num[i]<v.top())
                {
                    count++;
                    v.push(num[i]);
                    flag=0;
                }
                else
                {
                    v.push(num[i]);
                }
            }
            else if(flag==0)
            {
                if(num[i]>v.top())
                {
                    count++;
                    v.push(num[i]);
                    flag=1;
                }
                else
                {
                    v.push(num[i]);
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}