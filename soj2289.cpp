#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int k,n,i,j,ans[21];
    long long int c;
    long long int w[21][21],m[21][21];
    bool at_w,have_use[21];
    memset(w,0,sizeof(w));
    memset(m,0,sizeof(m));
    w[1][1]=m[1][1]=1;
    for (i=2;i<=20;i++)
        for (j=1;j<=i;j++)
        {
            w[i][j]=w[i][j-1]+m[i-1][j-1];
            m[i][i-j+1]=w[i][j];
        }
    while(scanf("%d",&k)!=EOF)
    {
        while (k--)
        {
            scanf("%d%lld",&n,&c);
            for (i=1,at_w=false;i<=20;i++)
            {
                if (c<=w[n][i]+m[n][i])
                {
                    ans[1]=i;
                    if (c<=w[n][i])
                        at_w=true;
                    else
                        c-=w[n][i];
                    break;
                }
                else
                    c-=w[n][i]+m[n][i];
            }
            for (i=2;i<=n;i++)
            {
                if (at_w)
                    for (j=1;j<ans[i-1];j++)
                        if (c<=m[n-i+1][j])
                        {
                            ans[i]=j;
                            at_w=false;
                            break;
                        }
                        else
                            c-=m[n-i+1][j];
                else
                    for (j=ans[i-1];j<=n-i+1;j++)
                        if (c<=w[n-i+1][j])
                        {
                            ans[i]=j;
                            at_w=true;
                            break;
                        }
                        else
                            c-=w[n-i+1][j];
            }
            memset(have_use,false,sizeof(have_use));
            printf("%d",ans[1]);
            have_use[ans[1]]=true;
            for (i=2;i<=n;i++)
            {
                for (j=1;ans[i]>0;j++)
                    if (have_use[j]==false)
                        ans[i]--;
                ans[i]=j-1;
                have_use[ans[i]]=true;
                printf(" %d",ans[i]);
            }
            printf("\n");
        }
    }

    return 0;
}
