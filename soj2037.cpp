#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <map>

using namespace std;
map<string,string> v;

int main()
{
    char str[22];
    while(gets(str))
    {
        int i,j;
        string a="";
        string b="";
        if(str[0]=='\0')
            break;
        for(i=0;str[i]!=' ';i++)
        {
            a+=str[i];
        }
        for(i++;str[i];i++)
        {
            b+=str[i];
        }
        cout<<a<<" "<<b<<endl;
        v[b]=a;
    }
    map<string,string>::iterator it;
    while(gets(str))
    {
        it=v.find(str);
        if(it==v.end())
        {
            printf("eh\n");
        }
        else
        {
            cout<<(*it).second<<endl;
        }
    }
    return 0;
}
