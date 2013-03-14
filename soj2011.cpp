#include <stdio.h>
int main()
 {
     int n,k,i;
     while(scanf("%d",&n)==1)
     {
         k=1;
         for(i=1;;i++)
         {
             k=k%n;
             if(k==0)
             {
                 printf("%d\n",i);
                 break;
             }
             else
                 k=k*10+1;
         }
     }
     return 0;
 }
