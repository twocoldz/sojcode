#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;
char a[1005][1005],b[1005][1005];
string c[1005];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s",a[i]);
            //for(int j=0;j<m;j++)
            //{
            //    b[j][n-i-1]=a[i][j];
            //}
        }
        for(int i=0;i<m;i++)
        {
            c[i]="";
            for(int j=0;j<n;j++)
            {
                c[i]+=a[n-j-1][i];
            }
        }
        sort(c,c+m);
        int ans=0;
        for(int i=0;i<m-1;i++)
        {
            int j=0;
            while(c[i][j]==c[i+1][j])
                j++;
            ans=max(ans,j);
            if(ans==n-1)
                break;
        }
        printf("%d\n",n-ans-1);
    }
    return 0;
}
