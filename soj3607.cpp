#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int a[500005];
int r[500005];
int s[500005];

int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        int pos=n;
        for(int i=n;i>=1;i--)
        {
            if(a[i]>=a[pos])
                r[i]=pos;
            else
            {
                r[i]=i;
                pos=i;
            }
        }
        int sp=0,num=1;
        for(int i=1;i<=n;i++)
        {
            if(sp&&s[sp]<=a[r[i]])
            {
                while(sp&&s[sp]<=a[r[i]])
                {
                    num==n?printf("%d\n",s[sp]):printf("%d ",s[sp]);
                    num++;
                    sp--;
                }
                sp++;
                s[sp]=a[i];
            }
            else
            {
                sp++;
                s[sp]=a[i];
            }
        }
        while(sp)
        {
            num==n?printf("%d\n",s[sp]):printf("%d ",s[sp]);
            num++;
            sp--;
        }
    }
    return 0;
}
