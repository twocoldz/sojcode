#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
char a[25],b[26];
map<int,int> vis1,vis2;
int len,s,e;

int Reserve(int x,int l,int r)
 {
     char s[25];
     int i,j;
     for(i=0;i<len;i++)
     {
         s[i]=(x&1)+'0';
         x>>=1;
     }
     s[len]='\0';
     for(i=0,j=len-1;i<j;i++,j--)
        swap(s[i],s[j]);
     for(i=l,j=r;i<j;i++,j--)
     {
         swap(s[i],s[j]);
     }
     int sum=0;
     for(i=0;i<len;i++)
        sum=(sum<<1)+s[i]-'0';
     return sum;
 }
/*
int Dbfs()
{
    queue<int> p,q;
    vis1[s]=1;
    vis2[e]=1;
    p.push(s);
    q.push(e);
    while(!p.empty()||!q.empty())
    {
        int s1=p.size();
        for(int i=0;i<s1;i++)
        {
            int t1=p.front();
            p.pop();
            for(int j=0;j<len;j++)
            {
                for(int k=j+1;k<len;k++)
                {
                    int l=Reserve(t1,j,k);
                    if(vis2[l]!=0)
                    {
                        return (vis2[l]+vis1[t1]-1);
                    }
                    else if(!vis1[l])
                    {
                        vis1[l]=vis1[t1]+1;
                        p.push(l);
                    }
                }
            }
        }
        s1=q.size();
        for(int i=0;i<s1;i++)
        {
            int t1=q.front();
            q.pop();
            for(int j=0;j<len;j++)
            {
                for(int k=j+1;k<len;k++)
                {
                    int l=Reserve(t1,j,k);
                    if(vis1[l]!=0)
                    {
                        return (vis1[l]+vis2[t1]-1);
                    }
                    else if(!vis2[l])
                    {
                        vis2[l]=vis2[t1]+1;
                        q.push(l);
                    }
                }
            }
        }
    }
    return -1;
}*/

int Dbfs()
 {
       queue<int> p,q;
       int i,j,k,l;
       vis1[s]=1;
       vis2[e]=1;
       p.push(s);
       q.push(e);
       int s1,s2;
       while(!p.empty()||!q.empty())
       {
           s1=p.size();
           for(l=0;l<s1;l++)
           {
               int temp1=p.front();
               p.pop();
               for(i=0;i<len;i++)
               {
                   for(j=i+1;j<len;j++)
                   {
                       k=Reserve(temp1,i,j);
                       if(vis2[k]!=0)
                       {
                           return (vis2[k]+vis1[temp1]-1);
                       }
                       else if(!vis1[k])
                       {
                           vis1[k]=vis1[temp1]+1;
                           p.push(k);
                       }

                   }
               }
           }
           s2=q.size();
           for(l=0;l<s2;l++)
           {
               int temp2=q.front();
               q.pop();
               for(i=0;i<len;i++)
               {
                   for(j=i+1;j<len;j++)
                   {
                       k=Reserve(temp2,i,j);
                       if(vis1[k]!=0)
                           return vis2[temp2]+vis1[k]-1;
                       else if(!vis2[k])
                       {
                           vis2[k]=vis2[temp2]+1;
                           q.push(k);
                       }
                   }
               }

           }
       }
       return -1;
 }

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",a,b);
        len=strlen(a);
        s=e=0;
        vis1.clear();
        vis2.clear();
        for(int i=0;i<len;i++)
        {
            s=(s<<1)+a[i]-'0';
            e=(e<<1)+b[i]-'0';
        }
        if(s==t)
            printf("0\n");
        else
            printf("%d\n",Dbfs());
    }
    return 0;
}
