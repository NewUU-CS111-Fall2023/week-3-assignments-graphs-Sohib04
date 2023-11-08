#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct node
{
    int v,nex;
};
node e[500005];
int f[200005],vis[200005],tot;
int d1[200005],d2[200005];
void add(int u,int v)
{
    e[tot].v=v;
    e[tot].nex=f[u];
    f[u]=tot++;
}
void dfs1(int u,int fa,int sum)
{
    d1[u]=sum;
    for(int i=f[u];i!=-1;i=e[i].nex)
    {
        int v=e[i].v;
        if(v!=fa)
        {
            vis[v]=1;
            dfs1(v,u,sum+1);
        }
    }
}
void dfs2(int u,int fa,int sum)
{
    d2[u]=sum;
    for(int i=f[u];i!=-1;i=e[i].nex)
    {
        int v=e[i].v;
        if(v!=fa)
        {
            vis[v]=1;
            dfs2(v,u,sum+1);
        }
    }
}
int main()
{
    memset(f,-1,sizeof(f));
    tot=0;
    int n,m,x,y;
    scanf("%d %d",&n,&m);
    for(int i=1;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        add(x,y);
        add(y,x);
    }
    memset(vis,0,sizeof(vis));
    vis[1]=1;
    dfs1(1,0,0);

    memset(vis,0,sizeof(vis));
    vis[m]=1;
    dfs2(m,0,0);
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(d1[i]>d2[i])
        {
            sum=max(sum,2*d1[i]);
        }
    }
    printf("%d\n",sum);
    return 0;
}
