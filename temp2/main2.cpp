#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

struct node{
    int s,to,next;
};
node que[N];

int head[N],dis[N],sum[N];
bool vis[N];
int cnt=1,n,m;

void add(int u,int v,int w){
    que[cnt].s=w;
    que[cnt].to=v;
    que[cnt].next=head[u];  
    head[u]=cnt++;

}

void dijkstra(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,false,sizeof(vis));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    dis[s]=0;
    q.push({0,s});
    sum[s]=1;
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=head[u];i!=-1;i=que[i].next){
            int v=que[i].to;
            if(dis[u]+que[i].s<dis[v]){
                sum[v]=sum[u];
                dis[v]=dis[u]+que[i].s;
                q.push({dis[v],v});
            }
            else if (dis[u]+que[i].s==dis[v])
                sum[v]+=sum[u];
        }
    }
}

int main() {
    freopen("a.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    memset(head,-1,sizeof(head));
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        add(u,v,1);
        add(v,u,1);
    }
    dijkstra(1);
    for (int i=1;i<=n;i++)
        cout<<sum[i]<<'\n';

    return 0;
}