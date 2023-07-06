#include <stdio.h>

int main() {
    float T[5],F[5];
    int i , j, c;

     printf("entrer la taille du tableau : \n");
      
     for (i=0;i<5;i++){
             printf("entrer les numéro %d ",i+1);
             scanf("%f",&T[i]);
     }
 for (i=0;i<5;i++){
         F[i] = -1 ;
}
for (i=0;i<5;i++){
     c=1;
	for (j=i+1;j<5;j++){	 
             if(T[i]==T[j]){
             c++;
	     F[j]=0;
	  }
  }
          if (F[i] !=0) {
           F[i]=c;
}	 
 }
 printf("les element uniques sont est : \n");
for (i=0;i<5;i++){
   if (F[i] ==1)
	   printf("%.1f \n",T[i]);
}
    return 0;
}
