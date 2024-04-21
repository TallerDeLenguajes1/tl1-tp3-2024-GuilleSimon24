#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(){

    int canti;

    printf("Ingrese la cantidad de nombres a guardar: ");
    scanf("%d", &canti);

    char *buff=malloc(100*sizeof(char));



    char ** nombres = malloc(canti *sizeof(char *));


    
    for (int i = 0; i < canti; i++)
    {
        puts("Ingrese el nombre: ");
        fflush(stdin);
        gets(buff);

        int longitud= strlen(buff)+1;
        nombres[i]=malloc(longitud*sizeof(char));
        strcpy(nombres[i], buff);
        
    }
    puts("------------");

    for (int i = 0; i < canti; i++)
    {
        puts(nombres[i]);
    }
    
    
    
    free(buff);
    free(nombres);

    return 0;
}