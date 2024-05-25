#include <stdio.h>

int fib(int n){
    if (n==1 || n==2)
        return 1;
    return fib(n-1)+fib(n-2);
}


void fib2(int n){
    static int res=0;
    if (n==1 || n==2)
        res++;
    fib(n-1);fib(n-2);
}

void solve(int n){
    static int p=0;
    p=n;

    if (n==2) return;
    printf("%d\n",p);
    solve(2);
    printf("%d\n",p);
}

int main(){
    solve(5);

    return 0;
}