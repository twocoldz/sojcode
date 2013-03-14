#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
char a[200000];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        n++;
        int len=n/7;
        int res=7-n%7;
        if(res==7)
            res=0;
        else
            len++;
        for(int i=0;i<len;i++)
            a[i]='8';
        a[len]='\0';
        for(int i=0;i<len&&res;i++)
        {
            //printf("res=%d\n",res);
            if(i==0)
            {
                if(res==1)
                    a[i]='6',res--;
                else if(res>=5)
                    a[i]='1',res-=5;
                else if(res>=2)
                    a[i]='2',res-=2;
            }
            else
                a[i]='0',res--;
        }
        printf("%s\n",a);
    }
    return 0;
}
