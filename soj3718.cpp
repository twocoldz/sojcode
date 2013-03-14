#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 2000000001

using namespace std;

int p[5][5];
int out[5][5];

int main()
{
    int cases;
    scanf("%d",&cases);
    for(int id=1;id<=cases;id++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int ma=inf;
        int t;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%d",p[i]+j);
                if(ma>p[i][j])
                    ma=p[i][j],t=i;
            }
        }
        for(int i=0;i<m;i++)
        {
            int k;
            int ma=inf;
            for(int j=0;j<m;j++)
            {
                if(p[t][j]<ma)
                    ma=p[t][j],k=j;
            }
            for(int j=0;j<n;j++)
            {
                out[j][i]=p[j][k];
                p[j][k]=inf;
            }
        }
        /*for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                printf("%d ",out[i][j]);
            printf("\n");
        }*/
        t=0;
        int f=0;
        printf("Scenario #%d:\n",id);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int k=0;
                while(k<m&&out[j][k]==out[t][k])
                    k++;
                if(k<m&&out[j][k]<out[t][k])
                    t=j;
            }
            for(int j=0;j<m;j++)
            {
                f==0?printf("%d",out[t][j]),f=1:printf(" %d",out[t][j]);
                out[t][j]=inf;
            }
        }
        printf("\n\n");
    }
    return 0;
}
