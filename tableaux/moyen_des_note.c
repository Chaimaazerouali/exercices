#include <stdio.h>

int main() {
    float T [5];
    float s , M ;
    int i;
     for (i=0;i<5;i++){
	     printf("entrer la note de l'etudient %d ",i+1);
	     scanf("%f",&T[i]);
     }
 s=0;
  for (i=0;i<5;i++){
	  s+=T[i];
  }
   M=s/5;
printf("la moyenne des notes %.2f \n",M);
    return 0;
}

