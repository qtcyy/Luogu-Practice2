#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

const int N = 100010;
typedef long long ll;

struct Edge {
    int x,y,z;
};

Edge edges[N];
int n,k;
int f[N];
bool vis[N];

inline int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}

ll kruskal(){
    for (int i=1;i<=n;i++) f[i] = i;
    sort(edges+1,edges+n,[](Edge a,Edge b){return a.z>b.z;});
    int sum = 0;ll res=0;
    for (int i=1;i<n;i++){
        int x = find(edges[i].x);
        int y = find(edges[i].y);
        if (vis[x] && vis[y])
            continue;
        
        f[x]=y;
        res+=edges[i].z;
        if (vis[x])
            vis[y]=1;
        else if (vis[y])
         vis[x]=1;
    }
    return res;
}

int main() {
    freopen("a.in","r",stdin);
    memset(vis,false,sizeof(vis));
    cin>>n>>k;
    ll sum=0;
    for (int i=1;i<=k;i++){
        int x;cin>>x;
        vis[x]=1;
    }
    for (int i=1;i<n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        sum+=z;
        edges[i] = {x,y,z};
    }
    cout<<sum-kruskal()<<endl;

    return 0;
}