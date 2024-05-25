#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
const int inf = 1e9;

struct csys{
    int x, y,z;
};
csys cdt[N];

struct node{
    int s,to,next;
};
node que[N];

int head[N],anc[N][21],w[N][21],deep[N];
bool vis[N];
int cnt=1,f[N];
int n,m,q;

inline int find(int x){
    return x==anc[x][0]?x:anc[x][0]=find(anc[x][0]);
}

bool cmp(csys a,csys b){
    return a.x>b.x;
}

void add(int u,int v,int w){
    que[cnt].s=u,que[cnt].to=v,que[cnt].next=head[u],head[u]=cnt++;
}

void dfs(int u){
    vis[u]=true;
    for (int i=head[u];i;i=que[i].next){
        int v=que[i].to;
        if (!vis[v]){
            anc[v][0]=u,w[v][0]=que[i].s,deep[v]=deep[u]+1;
            dfs(v);
        }
    }
}

int getlca(int x,int y){
    if (find(x)!=find(y)) return -1;
    if (deep[x]<deep[y])
        swap(x,y);
    int ans=inf;
    for (int i=20;i>=0;i--)
        if (deep[anc[x][i]]>=deep[y]){
            ans=min(ans,w[x][i]);
            x=anc[x][i];
        }
    if (x==y) return ans;
    for (int i=20;i>=0;i--)
        if (anc[x][i]!=anc[y][i]){
            ans=min(ans,min(w[x][i],w[y][i]));
            x=anc[x][i],y=anc[y][i];
        }
    return ans;
}

void kruskal(){
    for (int i=1;i<=n;i++) f[i]=i;
    sort(cdt+1,cdt+m+1,cmp);
    for (int i=1;i<=m;i++){
        int u=find(cdt[i].x),v=find(cdt[i].y);
        if (u!=v){
            f[u]=v;
            add(cdt[i].x,cdt[i].y,cdt[i].z);
            add(cdt[i].y,cdt[i].x,cdt[i].z);
        }
    }
}

signed main() {
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        cdt[i]={u,v,w};
    }
    kruskal();
    for (int i=1;i<=n;i++)
        if (!vis[i]){
            anc[i][0]=0;
            w[i][0]=inf;
            deep[i]=1;
            dfs(i);
        }
    for (int i=1;i<=20;i++)
        for (int j=1;j<=n;j++){
            w[j][i]=min(w[j][i-1],w[anc[j][i-1]][i-1]);
            anc[j][i]=anc[anc[j][i-1]][i-1];
        }

    return 0;
}