#include <stdio.h>
#include <stdlib.h>

int main(){

    int produ[12][5];

    // Apartado a)
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            produ[i][j] =10000+rand()%40001; 
        }
        
    }

    // Apartado b)

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", produ[i][j]);
        }
        printf("\n");
    }

    // Apartado c)

    float anio1=0;
    float anio2=0;
    float anio3=0;
    float anio4=0;
    float anio5=0;
    
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            switch (j)
            {
            case 0:
                anio1 += produ[i][j];
                break;
            case 1:
                anio2 += produ[i][j];
                break;
            case 2:
                anio3 += produ[i][j];
                break;
            case 3:
                anio4 += produ[i][j];
                break;
            case 4:
                anio5 += produ[i][j];
                break;
            }

        }
        
    }
    anio1 /= 12;
    anio2 /= 12;
    anio3 /= 12;
    anio4 /= 12;
    anio5 /= 12;

    printf("Primer anio: %.2f\n", anio1);
    printf("Segundo anio: %.2f\n", anio2);
    printf("tercer anio: %.2f\n", anio3);
    printf("Cuarto anio: %.2f\n", anio4);
    printf("Quinto anio: %.2f\n", anio5);

    // Apartado d)
    int mayorAnio = -1;
    int mayorMes = -1;
    int mayorProdu = 0;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (mayorProdu < produ[i][j])
            {
                mayorProdu = produ[i][j];
                mayorMes = i+1;
                mayorAnio = j+1;
            }
            
        }
        
    }

    printf("La mayor produccion fue de: %d\n", mayorProdu);
    printf("En el mes: %d\n", mayorMes);
    printf("Del anio: %d\n", mayorAnio);


    return 0;
}