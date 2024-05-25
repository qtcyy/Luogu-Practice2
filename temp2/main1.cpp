#include <stdio.h>

int is_prim(int x){
    if (x==0 || x==1) return 0;
    for (int i=2;i*i<=x;i++)
        if (x%i==0)
            return 0;
    return 1;
}

int main(){
    int l,r;
    scanf("%d%d",&l,&r);
    int sum=0,ans=0;
    for (int i=l;i<=r;i++){
        if (is_prim(i)){
            sum++;
            ans+=i;
        }
    }
    printf("%d %d\n",sum,ans);

    return 0;
}