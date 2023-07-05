#include <stdio.h>

int main() {
        float T[5];
	float max ;
	int i;
    printf("Entrez les mesures de tableau : \n");
    for ( int i=0;i<5;i++)
    {
     printf("T[%d] =" ,i+1);	    
     scanf("%f",&T[i]);
    }
    max = T[0];
    for (int i = 1; i <5; i++){
       if (T[i]>max)
           max = T[i];
       	
    }
    printf("le plus grand  élement du tableau est : %.1f \n",max);


    return 0;
}

