#include <iostream>

char mp[105][105];
int n,m;

int nxt[8][2]={
    {0,1},
    {1,0},
    {0,-1},
    {-1,0},
    {1,1},
    {1,-1},
    {-1,1},
    {1,-1},
};

void dfs(int x,int y){
    mp[x][y]='.';
    for (int k=0;k<8;k++){
        int tx=x+nxt[k][0],ty=y+nxt[k][1];
        if (tx<1 || tx>n || ty<1 || ty>m) continue;
        if (mp[tx][ty]=='W')
            dfs(tx,ty);
    }
}

int main(){
    freopen("a.in","r",stdin);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            // scanf("%c",&mp[i][j]);
            std::cin>>mp[i][j];
    int ans=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            if (mp[i][j]=='W'){
                // printf("%d ",++ans);
                ans++;
                dfs(i,j);
            }
        }
    printf("%d\n",ans);

    return 0;
}