#include <stdio.h>

int main() {
    int n, s;
    
    do{
	    printf("Entrez un nombre entier stréctemeent supérieur a 1 : ");
            scanf("%d", &n);
    }while (n<1);
    s=0;
    for (int i = 1; i <= n; i++) {
        s += i;
    }
    
    printf("La somme des entiers de 1 à %d est : %d\n", n, s);
    
    return 0;
}
