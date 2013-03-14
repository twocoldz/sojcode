#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct Node
{
    char c;
    int l,r;
}node[60];
int vis[60];

void Init()
{
     memset(vis,0,sizeof(vis));
     for(int i=0;i<26;i++)
     {
         node[i].c=65+i;
         node[i].l=node[i].r=-1;
     }
     for(int i=30;i<56;i++)
     {
         node[i].c=67+i;
         node[i].l=node[i].r=-1;
     }
}

void AddSon(int f,int s)
{
    if(node[f].l==-1)
    {
        node[f].l=s;
    }
    else
    {
        if(node[f].l<s)
        {
            node[f].r=node[f].l;
            node[f].l=s;
        }
        else
        {
            node[f].r=s;
        }
    }
}

void Print(int f,int num)
{
    if(node[f].r!=-1)
        Print(node[f].r,num+1);
    for(int i=0;i<num;i++)
        printf(" ");
    printf("%c\n",node[f].c);
    if(node[f].l!=-1)
        Print(node[f].l,num+1);
}

int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int n;
        Init();
        char f[2],s[2];
        scanf("%d",&n);
        for(int i=1;i<n;i++)
        {
            scanf("%s %s",f,s);
            if(f[0]>='A'&&f[0]<='Z')
            {
                if(!vis[f[0]-'A'])
                    vis[f[0]-'A']=1;
                if(s[0]>='A'&&s[0]<='Z')
                {
                    vis[s[0]-'A']=2;
                    AddSon(f[0]-'A',s[0]-'A');
                }
                else
                {
                    vis[s[0]-'a'+30]=2;
                    AddSon(f[0]-'A',s[0]-'a'+30);
                }
            }
            else
            {
                if(!vis[f[0]-'a'+30])
                    vis[f[0]-'a'+30]=1;
                if(s[0]>='A'&&s[0]<='Z')
                {
                    vis[s[0]-'A']=2;
                    AddSon(f[0]-'a'+30,s[0]-'A');
                }
                else
                {
                    vis[s[0]-'a'+30]=2;
                    AddSon(f[0]-'a'+30,s[0]-'a'+30);
                }
            }
        }
        int root;
        for(int i=0;i<60;i++)
        {
            if(vis[i]==1)
            {
                root=i;
                break;
            }
        }
        //printf("root=%d\n",root);
        Print(root,0);
    }
    return 0;
}
