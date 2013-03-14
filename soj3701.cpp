#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;
char str[100000];
map<int,string> dir;

int GetNum(int s,int size,int &t)
{
    int num=0;
    do
    {
        num=num*10+str[s++]-'0';
        size/=10;
        t++;
    }while(size);
    return num;
}

int main()
{
    int cases=1;
    while(scanf("%s",str))
    {
        if(strcmp(str,"0")==0)
            break;
        dir.clear();
        int n;
        scanf("%d",&n);
        string x;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            dir[i]=x;
        }
        string ans="";
        int len=strlen(str);
        for(int i=0;i<len;)
        {
            int t=0;
            int num=GetNum(i,n-1,t);
            string s="";
            s=dir[num];
            if(i>0)
            {
                dir[n-1]+=s[0];
            }
            ans+=dir[num];
            i+=t;
            dir[n++]=dir[num];
        }
        cout<<"Case "<<cases<<": "<<ans<<endl;
        cases++;
    }
    return 0;
}
