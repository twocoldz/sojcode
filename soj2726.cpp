#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

inline int MAX(int x,int y)
 {
     return x>y?x:y;
 }
int f[2][22][22][22];

int change(char c)
{
    if(c=='T'||c=='J'||c=='Q'||c=='K')
        return 10;
    else if(c=='A')
        return 1;
    else if(c=='F')
        return 0;
    else
        return c-'0';
}

int main()
 {
     int n;
     while(scanf("%d",&n)!=EOF&&n)
     {
         char s[5];
         int t,i,j,k,r=0,sc,ans=0;
         memset(f,-1,sizeof(f));
         f[0][0][0][0]=0;
         for(t=0;t<n;t++)
         {
             scanf("%s",s);
             sc=change(s[0]);
             r^=1;
             memset(f[r],-1,sizeof(f[r]));
             for(i=0;i<=21;i++)
                 for(j=0;j<=21;j++)
                     for(k=0;k<=21;k++)
                         if(f[r^1][i][j][k]!=-1)
                         {
                             if(sc==0)
                             {
                                 if(k<21) f[r][i][j][0]=MAX(f[r^1][i][j][k]+350,f[r][i][j][0]);
                                 if(j<21) f[r][i][0][k]=MAX(f[r^1][i][j][k]+250,f[r][i][0][k]);
                                 if(i<21) f[r][0][j][k]=MAX(f[r^1][i][j][k]+150,f[r][0][j][k]);
                             }
                             else
                             {
                                 if(i+sc<21)
                                     f[r][i+sc][j][k]=MAX(f[r^1][i][j][k]+50,f[r][i+sc][j][k]);
                                 else if(i+sc==21)
                                     f[r][0][j][k]=MAX(f[r^1][i][j][k]+150,f[r][0][j][k]);
                                 else if(i<21)
                                     f[r][21][j][k]=MAX(f[r^1][i][j][k]+50,f[r][21][j][k]);
                                 if(j+sc<21)
                                     f[r][i][j+sc][k]=MAX(f[r^1][i][j][k]+50,f[r][i][j+sc][k]);
                                 else if(j+sc==21)
                                     f[r][i][0][k]=MAX(f[r^1][i][j][k]+250,f[r][i][0][k]);
                                 else if(j<21)
                                     f[r][i][21][k]=MAX(f[r^1][i][j][k]+50,f[r][i][21][k]);
                                 if(k+sc<21)
                                     f[r][i][j][k+sc]=MAX(f[r^1][i][j][k]+50,f[r][i][j][k+sc]);
                                 else if(k+sc==21)
                                     f[r][i][j][0]=MAX(f[r^1][i][j][k]+350,f[r][i][j][0]);
                                 else if(k<21)
                                     f[r][i][j][21]=MAX(f[r^1][i][j][k]+50,f[r][i][j][21]);
                             }
                         }
             for(i=0;i<=21;i++)
                 for(j=0;j<=21;j++)
                     for(k=0;k<=21;k++)
                         ans=MAX(ans,f[r][i][j][k]);
         }
         printf("%d\n",ans);
     }
     return 0;
 }
