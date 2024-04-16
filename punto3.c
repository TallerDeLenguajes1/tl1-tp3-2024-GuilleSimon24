#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(){

    char *buff=malloc(100*sizeof(char));

    char ** nombres = malloc(5 *sizeof(char *));


    
    for (int i = 0; i < 5; i++)
    {
        puts("Ingrese el nombre: ");
        gets(buff);

        int longitud= strlen(buff)+1;
        nombres[i]=malloc(longitud*sizeof(char));
        strcpy(nombres[i], buff);
        
    }
    puts("------------");

    for (int i = 0; i < 5; i++)
    {
        puts(nombres[i]);
    }
    
    
    
    free(buff);
    free(nombres);

    return 0;
}