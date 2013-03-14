#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int f[2][1002],g[2][1002],h[2][1002],s[2][1002],q[2][1002];
int b[3][1002],a[3][1002];
inline int MAX(int x,int y,int z=-110000000)
 {
     if(z>x) x=z;
     return x>y?x:y;
 }
int main()
 {
     int n,m,r,pre,i,j,ans,sum,df,dg,dh,t;
     while(scanf("%d%d",&n,&m)!=EOF)
     {
         for(i=1;i<=2;i++)
             for(j=1;j<=n;j++)
                 scanf("%d%d",a[i]+j,b[i]+j);
         sum=r=0;
         for(i=1;i<=n;i++) sum+=b[1][i]+b[2][i];
         df=a[1][1]-b[1][1];
         dg=a[2][1]-b[2][1];
         dh=df+dg;
         for(i=0;i<2;i++)
             f[i][0]=g[i][0]=h[i][0]=s[i][0]=q[i][0]=sum;
         f[r][1]=df+sum;
         g[r][1]=dg+sum;
         h[r][1]=dh+sum;
         s[r][1]=-110000000;
         q[r][1]=sum;
         for(j=2;j<=m;j++)
         {
             f[r][j]=df+sum;
             g[r][j]=dg+sum;
             h[r][j]=dh+sum;
             s[r][j]=sum+dh;
             q[r][j]=sum;
         }
         t=MAX(f[r][m],g[r][m],h[r][m]);
         ans=MAX(t,s[r][m],q[r][m]);
         for(i=2;i<=n;i++)
         {
             pre=r;
             r^=1;
             df=a[1][i]-b[1][i];
             dg=a[2][i]-b[2][i];
             dh=df+dg;
             f[r][1]=MAX(f[pre][1],sum)+df;
             g[r][1]=MAX(g[pre][1],sum)+dg;
             h[r][1]=MAX(h[pre][1],sum)+dh;
             s[r][1]=-110000000;
             q[r][1]=MAX(f[pre][1],g[pre][1],h[pre][1]);
             q[r][1]=MAX(q[r][1],q[r][0],q[pre][1]);
             for(j=2;j<=m;j++)
             {
                 t=MAX(MAX(s[pre][j-1],h[pre][j-1],q[pre][j-1]),f[pre][j-1],g[pre][j-1]);
                 f[r][j]=MAX(f[pre][j],s[pre][j],t)+df;
                 f[r][j]=MAX(f[r][j-1],f[r][j]);
                 g[r][j]=MAX(g[pre][j],s[pre][j],t)+dg;
                 g[r][j]=MAX(g[r][j-1],g[r][j]);
                 h[r][j]=MAX(h[r][j-1],h[pre][j]+dh,t+dh);
                 t=MAX(q[pre][j-2],s[pre][j-2],h[pre][j-2]);
                 s[r][j]=MAX(f[pre][j-1],g[pre][j-1],t)+dh;
                 s[r][j]=MAX(s[r][j-1],s[pre][j]+dh,s[r][j]);
                 t=MAX(q[pre][j],f[pre][j],g[pre][j]);
                 q[r][j]=MAX(t,h[pre][j],s[pre][j]);
                 q[r][j]=MAX(q[r][j],q[r][j-1]);
             }
             t=MAX(f[r][m],g[r][m],h[r][m]);
             ans=MAX(ans,s[r][m],q[r][m]);
             ans=MAX(t,ans);
         }
         printf("%d\n",ans);
     }
     return 0;
 }
