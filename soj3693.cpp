#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>


int main()
 {
     int d[12];
     char *x,s[105];
     double a;
     while(scanf("%s",s))
     {
         if(s[0]=='E')
            break;
         a=strtod(s,&x);
         int f=1;
         //printf("%lf\n",a);
         for(int i=0;i<10;i++)
         {
             d[i]=a*3;
             a=a*3-(int)(a*3);
         }
         for(int i=0;i<10;i++)
             if(d[i]==1)
             {
                 f=0;
                 break;
             }
         if(f)
             puts("MEMBER");
         else
             puts("NON-MEMBER");
     }
    return 0;
 }
