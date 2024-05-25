#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;

struct Edge{
    int s,to,next;
};
Edge que[N];

int head[N],dis[N];
bool vis[N];
int cnt=1,n,m;

inline void add(int u,int v,int w){
    que[cnt].s=u,que[cnt].to=v,que[cnt].next=head[u],head[u]=cnt++;
}

void dijkstra(int s){
    memset(dis,-1,sizeof(dis));
    memset(vis,0,sizeof(vis));
    priority_queue<pair<int,int>> q;
    dis[s]=0;
    q.push(make_pair(0,s));
    while (!q.empty()){
        int u=q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u]=true;
        for (int i=head[u];i!=-1;i=que[i].next){
            int v=que[i].to;
            if (dis[u]+que[i].s>dis[v]){
                dis[v]=dis[u]+que[i].s;
                q.push(make_pair(dis[v],v));
            }
        }
    }
}

void spfa(int s){
    memset(dis,-1,sizeof(dis));
    memset(vis,0,sizeof(vis));
    queue<int> q;
    dis[s]=0;
    q.push(s);
    while (!q.empty()){
        int u=q.front();
        q.pop();
        if (vis[u]) continue;
        vis[u]=true;
        for (int i=head[u];i!=-1;i=que[i].next){
            int v=que[i].to;
            if (dis[u]+que[i].s>dis[v]){
                dis[v]=dis[u]+que[i].s;
                q.push(v);
            }
        }
    }
}

signed main(){
    freopen("a.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    memset(head,-1,sizeof(head));
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        add(u,v,w);
    }


    spfa(1);

    cout<<dis[n]<<'\n';

    return 0;
}