#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
char a[20],b[20];

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int h,m,s;
        scanf("%d:%d:%d",&h,&m,&s);
        for(int j=5,k=0;j>=0;j--)
        {
            if(h&(1<<j))
                a[k++]='1';
            else
                a[k++]='0';
            if(m&(1<<j))
                a[k++]='1';
            else
                a[k++]='0';
            if(s&(1<<j))
                a[k++]='1';
            else
                a[k++]='0';
        }
        a[18]='\0';
        int k=0;
        for(int j=5;j>=0;j--)
        {
            if(h&(1<<j))
                b[k++]='1';
            else
                b[k++]='0';
        }
        for(int j=5;j>=0;j--)
        {
            if(m&(1<<j))
                b[k++]='1';
            else
                b[k++]='0';
        }
        for(int j=5;j>=0;j--)
        {
            if(s&(1<<j))
                b[k++]='1';
            else
                b[k++]='0';
        }
        b[18]='\0';
        printf("%d %s %s\n",i,a,b);
    }
    return 0;
}
