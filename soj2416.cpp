#include <iostream>
#include <cstdio>
using namespace std;

int main()
 {
     int t;
     scanf("%d",&t);
     while(t--)
     {
         int n,a,b,c;
         scanf("%d",&n);
         scanf("%d%d%d",&a,&b,&c);
         int x,y;
         int sum;
         bool flag1=0;
         bool flag2=0;
         for(x=9;x>0;x--)
         {
             for(y=9;y>=0;y--)
             {
                 sum=x*10000+a*1000+b*100+c*10+y;
                 if(sum%n==0)
                 {
                     printf("%d %d %d\n",x,y,sum/n);
                     flag1=1;
                     flag2=1;
                     break;
                 }
             }
             if(flag2==1) break;
         }
         if(flag2==0) printf("0\n");
     }
     return 0;
 }
