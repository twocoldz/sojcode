#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
char a[11],b[11];

int ToNum(char str[],int len)
{
    int t=0;
    for(int i=0;i<len;i++)
    {
        t=t*10+str[i]-48;
    }
    return t;
}

int Rev(int n)
{
    int t=0;
    while(n)
    {
        t=t*10+n%10;
        n/=10;
    }
    return t;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",a,b);
        int lena=strlen(a),lenb=strlen(b);
        if(lena<lenb)
        {
            printf("%s\n",a);
            continue;
        }
        int numA=ToNum(a,lena);
        int numB=ToNum(b,lenb);
        //printf("numA=%d numB=%d\n",numA,numB);
        int ans=0;
        for(int i=1;i<=numB;i++)
        {
            if(i%10!=0)
            {
                int t=Rev(i);
                while(t<=numA)
                {
                    t*=10;
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
