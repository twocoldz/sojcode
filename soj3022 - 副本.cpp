#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cctype>
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;

const int maxn=200000+20;
class P
{
public:
       int id,v;
       int operator < (const P &tt)const
       {
           return v<tt.v;
       }
}g[maxn];

int n,m;
int x[maxn],f[maxn],p[maxn];
int ax[maxn<<2];

inline void build(int t,int l,int r)
{
    if(l==r)
    {
        ax[t]=f[r]-r+1;
        return ;
    }
    int son=t<<1,mid=(l+r)>>1;
    build(son,l,mid);
    build(son+1,mid+1,r);
    ax[t]=max(ax[son],ax[son+1]);
}

inline int query(int t,int l,int r,int _l,int _r)
{
        if(_l==l&&_r==r)return ax[t];
        int son=t<<1,mid=(l+r)>>1;
        if(_r<=mid)
            return query(son,l,mid,_l,_r);
        if(_l>mid)
            return query(son+1,mid+1,r,_l,_r);
        return max(query(son,l,mid,_l,mid),query(son+1,mid+1,r,mid+1,_r));
}
int main()
{
    while(1==scanf("%d",&n))
    {
        scanf("%d",&m);
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&g[i].v);
            g[i].id=i;
        }

        printf("Pre Arr\n");
        for(int i=1;i<=n;i++)
        {
            printf("%d ",g[i].v);
        }
        printf("\n");
        for(int i=1;i<=n;i++)
        {
            printf("%d ",g[i].id);
        }
        printf("\n");

        sort(g+1,g+n+1);

        printf("After Arr\n");
        for(int i=1;i<=n;i++)
        {
            printf("%d ",g[i].v);
        }
        printf("\n");
        for(int i=1;i<=n;i++)
        {
            printf("%d ",g[i].id);
        }
        printf("\n");

        int now=1;
        x[g[1].id]=1;
        for(int i=2;i<=n;++i)
        {
            if(g[i].v!=g[i-1].v)
                x[g[i].id]=(++now);
            else
                x[g[i].id]=now;
        }

        printf("X Arr\n");
        for(int i=1;i<=n;i++)
        {
            printf("%d ",x[i]);
        }
        printf("\n");

        for(int i=1;i<=now;++i)
            p[i]=n+1;

        for(int i=1;i<=n;i++)
        {
            printf("%d ",p[i]);
        }
        printf("\n");

        f[n+1]=n+1;
        for(int i=n;i>=1;--i)
        {
            f[i]=min(f[i+1],p[x[i]]-1);
            p[x[i]]=i;
        }

        printf("f arr\n");
        for(int i=1;i<=n;i++)
        {
            printf("%d ",f[i]);
        }
        printf("P arry\n");
        for(int i=1;i<=n;i++)
        {
            printf("%d ",p[i]);
        }
        build(1,1,n);
        while(m--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            ++a;++b;
            int low=a,high=b;
            while(low<=high)
            {
                int mid=(low+high)>>1;
                if(f[mid]>b)
                    high=mid-1;
                else
                    low=mid+1;
            }
            --low;
            if(low<a)
                printf("%d\n",b-a+1);
            else if(low==b)
                printf("%d\n",query(1,1,n,a,b));
            else
                printf("%d\n",max(b-low,query(1,1,n,a,low)));
        }
    }
    return 0;
}

