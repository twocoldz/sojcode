#include<stdio.h>
#include<math.h>
int main()
 {
     int n;
     scanf("%d",&n);
     while(n--)
     {
         int m;
         scanf("%d",&m);
         double a=0.3494850021680094023931305526377, b=m*0.20898764024997873376927208923756;
         printf("%d\n",int(b-a)+1);
     }
     return 1;
 }
