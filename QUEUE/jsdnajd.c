#include<stdio.h>
int main(){
    int n;
    printf("enter the number\n");
    scanf("%d",&n);
    printf("your table of %d\n",n);
    for(int i =1;i<11;i++){
        int ans = n*i;
        printf(" %d * %d  = %d",n,i,ans);
        printf("\n");
        

    }
}