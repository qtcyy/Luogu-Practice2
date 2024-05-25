#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int *b=(int *)malloc(5*sizeof(int));
    int b[5];
    for (int i=0;i<5;i++)
        scanf("%d",&b[i]);
    
    // b+i=&(b[i])
    // *(b+i)=b[i]

    for (int i=0;i<5;i++)
        printf("%d ",b[i]);
    printf("\n");
    
    return 0;
}