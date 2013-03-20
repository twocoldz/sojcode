#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char a[505],b[505];
int c[1010];

void Cal(char a[],char b[])
 {
     memset(c,0,sizeof(c));
     int lena=strlen(a);
     int lenb=strlen(b);
     int temp=0,i,j;
     for(i=lena-1;i>=0;i--)
     {
         for(j=lenb-1;j>=0;j--)
         {
             int t=(temp+c[i+j+2]+(a[i]-'0')*(b[j]-'0'));
             c[i+j+2]=t%10;
             temp=t/10;
         }
         int t=(temp+c[i+j+2]);
         c[i+j+2]=t%10;
         temp=t/10;
     }
     i=0;
     while(!c[i])
     {
         i++;
     }
     for(;i<=lena+lenb;i++)
     {
         printf("%d",c[i]);
     }
     printf("\n");
 }

int main()
 {
     while(scanf("%s%s",a,b)==2)
     {
         Cal(a,b);
     }
     return 0;
 }