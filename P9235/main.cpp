#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
const int INF = 0x3f3f3f3f;

struct csys{
    int x,y,z;    
};
csys cdt[N];

struct node{
    int s,to,next;
};
node que[N];

int head[N],anc[N][21],w[N][21],deep[N];
bool vis[N];
int cnt=1,n,m,q,f[N];

inline void add(int u,int v,int w){
    que[cnt].s=w;
    que[cnt].to=v;
    que[cnt].next=head[u];
    head[u]=cnt++;
}

inline int find(int x){
    if (f[x]==x) return x;
    return f[x]=find(f[x]);
}

bool cmp(csys p1,csys p2){
    return p1.z>p2.z;
}

void dfs(int u){
    vis[u]=1;
    for (int i=head[u];i!=0;i=que[i].next){
        int k=que[i].to;
        if (vis[k]) continue;
        deep[k]=deep[u]+1;
        anc[k][0]=u;
        w[k][0]=que[i].s;
        dfs(k);
    }
}

void kruskal(){
    for (int i=1;i<=n;i++) f[i]=i;
    sort(cdt+1,cdt+m+1,cmp);
    for (int i=1;i<=m;i++){
        int x=find(cdt[i].x),y=find(cdt[i].y);
        if (x!=y){
            f[x]=y;
            add(cdt[i].x,cdt[i].y,cdt[i].z);
            add(cdt[i].y,cdt[i].x,cdt[i].z);
        }
    }
    return;
}

int getlca(int x,int y){
    if (find(x)!=find(y)) return -1;
    if (deep[x]<deep[y]) swap(x,y);
    int ans=INF;
    for (int i=20;i>=0;i--)
        if (deep[anc[x][i]]>=deep[y]){
            ans=min(ans,w[x][i]);
            x=anc[x][i];
        }
    if (x==y) return ans;
    for (int i=20;i>=0;i--)
        if (anc[x][i]!=anc[y][i]){
            ans=min(ans,min(w[x][i],w[y][i]));
            x=anc[x][i];
            y=anc[y][i];
        }
    return min(ans,min(w[x][0],w[y][0]));
}

signed main(){
    freopen("a.in","r",stdin);
    cin>>n>>m>>q;
    for (int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        cdt[i]=(csys){u,v,w};
    }
    kruskal();
    for (int i=1;i<=n;i++)
        if (!vis[i]){
            deep[i]=1;
            anc[i][0]=0;
            w[i][0]=INF;
            dfs(i);
        }
    for (int i=1;i<=20;i++)
        for (int j=1;j<=n;j++){
            w[j][i]=min(w[j][i-1],w[anc[j][i-1]][i-1]);
            anc[j][i]=anc[anc[j][i-1]][i-1];
        }
    while (q--){
        int x,y;
        cin>>x>>y;
        cout<<getlca(x,y)<<endl;
    }

    return 0;
}