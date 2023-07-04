#include <stdio.h>

int main() {

    int  l , c , i , j ;

    printf("Entrez la longeur l : ");

    scanf("%d", &l);
     printf("Entrez la largeur L : ");

    scanf("%d", &c);
    for (i=1;i<=l;i++){
         for (j=1;j<=c;j++){
            if(i==1 || i==l || j==1 || j==c || j==l-i+1 || i==j) {
            printf("*  ") ;
            }
            else
             printf("   ");
         }
         printf("\n");
 }
    return 0;

 }
