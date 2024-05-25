#include <stdio.h>

int mp[10][10];
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
    mp[x][y]=0;
    for (int k=0;k<8;k++){
        int tx=x+nxt[k][0],ty=y+nxt[k][1];
        if (tx<1 || tx>n || ty<1 || ty>m)
            continue;
        if (mp[tx][ty]==1)
            dfs(tx,ty);
    }
}


int stx[1005],sty[1005];

void bfs(int x,int y){
    int top=0;
    
    stx[top]=x;sty[top]=y;top++;
    while (!top){
        int px=stx[top],py=sty[top];top--;
        mp[px][py]=0;
        for (int k=0;k<8;k++){
            int tx=px+nxt[k][0],ty=py+nxt[k][1];
            if (tx<1 || tx>n || ty<1 || ty>m)
                continue;
            if (mp[tx][ty]==1){
                stx[top]=tx;
                sty[top]=ty;
                top++;
            }
        }
        
    }
}

int main(){
    freopen("a.in","r",stdin);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%d",&mp[i][j]);
    
    dfs(3,3);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++)
            printf("%d ",mp[i][j]);
        printf("\n");
    }

    return 0;
}