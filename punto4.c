#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Producto {
    int ProductoID;                     //Numerado en ciclo iterativo
    int Cantidad;                       // entre 1 y 10
    char *TipoProducto;                 // Algún valor del arreglo TiposProductos
    float PrecioUnitario;               // entre 10 - 100
}typedef Producto;

struct Cliente {
    int ClienteID;                      // Numerado en el ciclo iterativo
    char *NombreCliente;                // Ingresado por usuario
    int CantidadProductosAPedir;        // (aleatorio entre 1 y 5)
    Producto *Productos;                 //El tamaño de este arreglo depende de la variable
    // "CantidadProductosAPedir"
}typedef Cliente;

float costoTotal(Producto produ){

    float total;
    total= produ.Cantidad * produ.PrecioUnitario;

    return total;
}

int main(){
    srand(time(NULL));

    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    
    int cantClie;

    printf("Ingrese la cantidad de clientes: \n");
    scanf("%d", &cantClie);
    fflush(stdin);
    puts("------------------");

    Cliente *Clientes =(Cliente *)malloc(cantClie * sizeof(Cliente));
    char *buff=malloc(100*sizeof(char));

    printf("Cargue los clientes:\n");
    for (int i = 0; i < cantClie; i++)
    {
        printf("Cliente numero %d: \n", i+1);
        Clientes[i].ClienteID= i;

        printf("Nombre del cliente: \n");
        gets(buff);
        int longi = strlen(buff);
        Clientes[i].NombreCliente = malloc(longi*sizeof(char));
        strcpy(Clientes[i].NombreCliente, buff);

        puts("Productos a pedir:");
        Clientes[i].CantidadProductosAPedir = 1+rand()%5;
        
        Clientes[i].Productos = malloc(Clientes[i].CantidadProductosAPedir * sizeof(Producto));

        for (int j = 0; j < Clientes[i].CantidadProductosAPedir; j++)
        {
            printf("Producto numero %d:\n", j+1);
            Clientes[i].Productos[j].ProductoID = j;

            puts("Cantidad: ");
            Clientes[i].Productos[j].Cantidad = 1+rand()%10;

            Clientes[i].Productos[j].TipoProducto = TiposProductos[rand()%5];

            Clientes[i].Productos[j].PrecioUnitario = (100+rand()%901)/10;
        }
        


    }
    
    /*
    puts(Clientes[0].NombreCliente);
    printf("%d\n", Clientes[0].CantidadProductosAPedir);
    printf("%d\n", Clientes[0].Productos->ProductoID);
    printf("%d\n", Clientes[0].Productos->Cantidad);
    puts(Clientes[0].Productos->TipoProducto);
    printf("%.2f\n", Clientes[0].Productos->PrecioUnitario);

    printf("%.2f\n", costoTotal(Clientes[0].Productos[0]));
    */
    for (int i = 0; i < cantClie; i++)
    {
        float totalPagar = 0;
        printf("Cliente numero: %d\n", Clientes[i].ClienteID +1 );
        printf("Nombre del cliente: ");
        puts(Clientes[i].NombreCliente);
        printf("Productos pedidos: %d\n", Clientes[i].CantidadProductosAPedir);

        for (int j = 0; j < Clientes[i].CantidadProductosAPedir; j++)
        {
            puts("------------------");
            printf("Producto numero: %d\n", Clientes[i].Productos[j].ProductoID +1);
            printf("Tipo del producto: ");
            puts(Clientes[i].Productos[j].TipoProducto);
            printf("Cantidad: %d\n", Clientes[i].Productos[j].Cantidad);
            printf("Precio unitario: %.2f\n", Clientes[i].Productos[j].PrecioUnitario);
            printf("Costo total: %.2f\n", costoTotal(Clientes[i].Productos[j]));
            puts("-----------------");
            totalPagar += costoTotal(Clientes[i].Productos[j]) ;
        }
        printf("Total a pagar por el cliente: %.2f\n", totalPagar);
        puts("---------------");       
    }
    
    
    free(buff);
    free(Clientes);
    return 0;
}