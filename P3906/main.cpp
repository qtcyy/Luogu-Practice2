#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

struct node{
    int to,next;
};
node que[N];

int head[N],dis1[N],dis2[N];
bool vis[N];
int cnt=1,n,m;

inline void add(int u,int v){
    que[cnt].to=v;
    que[cnt].next=head[u];
    head[u]=cnt++;
}

void dij1(int s){
    memset(dis1,0x3f,sizeof(dis1));
    memset(vis,false,sizeof(vis));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,s});
    dis1[s]=0;
    while (!q.empty()){
        int u=q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u]=1;
        for (int i=head[u];i!=-1;i=que[i].next){
            int k=que[i].to;
            if (dis1[k]>dis1[u]+1){
                dis1[k]=dis1[u]+1;
                q.push({dis1[k],k});
            }
        }
    }
}

void dij2(int s){
    memset(dis2,0x3f,sizeof(dis2));
    memset(vis,false,sizeof(vis));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,s});
    dis2[s]=0;
    while (!q.empty()){
        int u=q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u]=1;
        for (int i=head[u];i!=-1;i=que[i].next){
            int k=que[i].to;
            if (dis2[k]>dis2[u]+1){
                dis2[k]=dis2[u]+1;
                q.push({dis2[k],k});
            }
        }
    }
}

signed main(){
    freopen("a.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    memset(head,-1,sizeof(head));
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        add(u,v);add(v,u);
    }
    int t;cin>>t;
    while (t--){
        int u,v;
        cin>>u>>v;
        dij1(u);dij2(v);
        for (int i=1;i<=n;i++){
            if (dis1[i]+dis2[i]==dis1[v])
                cout<<i<<' ';
        }
        cout<<'\n';
    }

    return 0;
}