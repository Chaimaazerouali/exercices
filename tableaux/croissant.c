#include <stdio.h>

int main() {
    int  T [100];
    int i , j ,taille , c;
     printf("entrer la taille du tableau : ");
             scanf("%d",&taille);
     for (i=0;i<taille;i++){
             printf("entrer les valeur du tableau %d ",i+1);
             scanf("%d",&T[i]);
     }

  for (i=0;i<taille;i++){
           for (j=i+1;j<taille;j++){
  		if(T[i]>T[j]){
		c=T[i];
		T[i]=T[j];
		T[j]=c;
		}
	   
	   }
  }

  printf("\n les elements du tableau par ordre croissant sont : ");
   for (i=0;i<taille;i++)
	   printf("%d ",T[i]);
    return 0;
}
