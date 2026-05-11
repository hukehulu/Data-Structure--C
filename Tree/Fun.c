#include <stdio.h>


int Fun(int n){
    if(n==1||n==2){
        return 1;
    }
    return Fun(n-1)+Fun(n-2);
}


int main(){
    int n;
    scanf("%d",&n);
    printf("%d",Fun(n));
    return 0;
}
