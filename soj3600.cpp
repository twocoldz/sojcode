#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node
{
    int dif,pos;
}x[100005];
int a[100005],b[100005];
int suma[100005],sumb[100005];

bool cmp(node a,node b)
{
    if(a.dif==b.dif)
        return a.pos<b.pos;
    return a.dif<b.dif;
}

int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int n;
        scanf("%d",&n);
        a[0]=b[0]=0;
        for(int i=1;i<=n;i++)
            scanf("%d",a+i),a[i]+=a[i-1];
        for(int i=1;i<=n;i++)
            scanf("%d",b+i),b[i]+=b[i-1];
        if(a[n]==b[n])
        {
            printf("%d\n",n);
            continue;
        }
        for(int i=0;i<=n;i++)
        {
            x[i].dif=a[i]-b[i];
            x[i].pos=i;
        }
        sort(x,x+n+1,cmp);
        int ans=0;
        int r=0;
        for(int i=1;i<=n;i++)
        {
            if(x[i-1].dif==x[i].dif)
                ans=max(ans,x[i].pos-x[r].pos);
            else
                r=i;
        }
        printf("%d\n",ans);
    }
    return 0;
}
