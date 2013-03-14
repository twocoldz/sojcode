#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn=100;
char day[maxn];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int r,w;
        scanf("%d%d",&r,&w);
        scanf("%s",day);
        int len=strlen(day);
        int g,b;
        if(day[0]=='G')
        {
            g=1;
            b=0;
        }
        else
        {
            g=0;
            b=1;
        }
        int rr=1;   //记录连续猜对
        int ww=1;   //记录连续猜错
        for(int i=1;i<len;i++)
        {
            int t=(day[i]=='G'?1:0);
            int gg=g;
            int bb=b;
            if(rr==r)
            {
                g=bb+t;
                rr=1;
            }
            else
            {
                if(gg>bb)
                {
                    g=gg+t;
                    rr++;
                }
                else
                {
                    g=bb+t;
                    rr=1;
                }
            }
            if(ww==w)
            {
                b=gg+1-t;
                ww=1;
            }
            else
            {
                if(bb>gg)
                {
                    b=bb+1-t;
                    ww++;
                }
                else
                {
                    b=gg+1-t;
                    ww=1;
                }
            }
        }
        printf("%d\n",b>g?b:g);
    }
    return 0;
}
