#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 1001
char a[N][N];
int b[N][N],n,m;
int sum;
void dfs(int x,int y){
	int next[8][2]={
		{0,1},
		{1,0},
		{0,-1},
		{-1,0},
		{1,1},
		{1,-1},
		{-1,1},
		{-1,-1},
	};
	int tx,ty;
	a[x][y]='!';
	for (int k=0;k<=7;k++){
		tx=x+next[k][0];
		ty=y+next[k][1];
		if (tx<1 || tx>n || ty<1 || ty>m){
			continue;
		}
		if (a[tx][ty]=='W' && b[tx][ty]==0){
			b[tx][ty]=1;
			dfs(tx,ty);
		}
	}
	return;
}
int main(){
    freopen("a.in","r",stdin);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (a[i][j]=='W'){
				sum++;
				b[i][j]=1;
				dfs(i,j);
			}
		}
	}
	printf("%d\n",sum);
	return 0;
}