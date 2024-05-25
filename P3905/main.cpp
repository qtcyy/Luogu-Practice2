#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n,m,d;

struct node{
    int s,to,next;
};
node que[N];

struct csys{
    int x,y,z;
    csys(int x,int y,int z){this->x=x;this->y=y;this->z=z;};
};

int head[N],dis[N];
bool vis[N];
int cnt=1;
int mp[1005][1005];

inline void add(int u,int v,int w){
    que[cnt].s=w;
    que[cnt].to=v;
    que[cnt].next=head[u];
    head[u]=cnt++;
}

void dij(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,false,sizeof(vis));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    dis[s]=0;
    q.push({0,s});
    while (!q.empty()){
        int u=q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u]=1;
        for (int i=head[u];i!=0;i=que[i].next){
            int k=que[i].to;
            if (dis[k]>dis[u]+que[i].s){
                dis[k]=dis[u]+que[i].s;
                q.push({dis[k],k});
            }
        }
    }
}

signed main(){
    freopen("a.in","r",stdin);
    cin>>n>>m;
    vector<csys> cdt;
    for (int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        cdt.push_back(csys(u,v,w));
    }
    cin>>d;
    for (int i=1;i<=d;i++){
        int u,v;
        cin>>u>>v;
        mp[u][v]=mp[v][u]=1;
    }
    for (auto p:cdt){
        if (mp[p.x][p.y]==1){
            add(p.x,p.y,p.z);
            add(p.y,p.x,p.z);
        }
        else{
            add(p.x,p.y,0);
            add(p.y,p.x,0);
        }
    }
    int s,t;cin>>s>>t;
    dij(s);
    cout<<dis[t]<<endl;

    return 0;
}