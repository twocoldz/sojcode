#include <cstdio>
#include <cstring>

int times[26];

int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        char a[2],b[11];
        int c,t=0;
        int s=0;
        memset(times,0,sizeof(times));
        for(int i=0;i<n;i++)
        {
            scanf("%s %d %s",a,&c,b);
            if(b[0]=='i')
            {
                times[a[0]-'A']++;
            }
            else
            {
                t++;
                s+=(c+times[a[0]-'A']*20);
            }
        }
        printf("%d %d\n",t,s);
    }
    return 0;
}
