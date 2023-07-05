#include <stdio.h>

int main() {

float x ;
float  p ;
float  CA ;

    printf("Entrez le nombre des stylo : ");
    scanf("%f", &x);
    
    printf("Entrez le prix des stylo : ");
    scanf("%f", &p);
    CA=x*p ;
    printf("la chifre d'affaire egale : %.2f \n",CA);

    return 0;
}

