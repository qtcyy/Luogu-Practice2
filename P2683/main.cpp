#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int N = 7e3+5;
const int INF = 0x3f3f3f3f;

struct node{
    int s,to,next;
};
node que[N];

int head[N],dis[N];
bool vis[N];
int cnt=1,n,m;

inline void add(int u,int v,int w){
    que[cnt].s=w,que[cnt].to=v,que[cnt].next=head[u],head[u]=cnt++;
    que[cnt].s=w,que[cnt].to=u,que[cnt].next=head[v],head[v]=cnt++;
}

void dijkstra(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s]=0;
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,s));
    while (!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u]=1;
        for (int i=head[u];i!=-1;i=que[i].next){
            int v=que[i].to;
            if (dis[u]+que[i].s<dis[v]){
                dis[v]=dis[u]+que[i].s;
                pq.push(make_pair(-dis[v],v));
            }
        }
    }
}

int main() {
    freopen("a.in","r",stdin);
    memset(head,-1,sizeof(head));
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int ch;cin>>ch;
        if (ch==1){
            int u,v,w;cin>>u>>v>>w;
            add(u,v,w);
        }
        else{
            int s,t;cin>>s>>t;
            dijkstra(s);
            if (dis[t]==INF)
                cout<<"-1\n";
            else
                cout<<dis[t]<<"\n";
        }
    }

    return 0;
}
