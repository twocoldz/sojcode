#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int len;
char str[100005];

int Cal(int b,int e)
{
    int i,j;
    for(i=b,j=e;i>=0&&j<len&&str[i]==str[j];i--,j++)
    {
        ;
    }
    i++,j--;
    return j-i+1;
}

int main()
{
    while(scanf("%s",str)!=EOF)
    {
        int ans=1;
        len=strlen(str);
        for(int i=0;i<len;i++)
        {
            int t=i;
            while(str[i]==str[t+1])
            {
                t++;
            }
            int temp=Cal(i,t);
            i=t;
            if(temp>ans)
            {
                ans=temp;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
