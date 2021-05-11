#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto {
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
};
typedef struct Producto Producto;


struct Cliente {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (alteatorio entre 1 y 5)
Producto *Productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
};
typedef struct Cliente Cliente;


struct Nodo {
    Cliente NuevoCliente;
    struct Nodo* siguiente;
};
typedef struct Nodo Lista;


//FUNCIONES
Lista* CrearListaVacia();
void CrearCliente(int CantClientes);


int main(){
    int CantClientes =0;
    printf("Ingrese la cantidad de clientes: \n");
    scanf(" %d",&CantClientes);
    
    CrearCliente(CantClientes);




    return 0;
}


Lista* CrearListaVacia(){
    return NULL;
}

void CrearCliente(int CantClientes){

    Lista *Clientes;Lista*Producto;int ProductAleatorio = rand() % 5 * 1;
    char nombre[10],IdProduct[10];int PrecioTotalPorUnidad = 0,SumaTotal=0;
    Clientes = CrearListaVacia();
    Producto = CrearListaVacia();

    Clientes = (Lista*) malloc(sizeof(Lista)*CantClientes);

for (int j = 1; j <= CantClientes; j++)
{   
    printf("Ingrese el nombre del cliente: \n");
    scanf(" %s",&nombre);
    printf("Ingrese el nombre del producto para calcular el precio total\n(Galletas,Snack,Cigarrillos,Caramelos,Bebidas) :\n");
    scanf(" %s",IdProduct);

    printf("Cliente ID: %d\n",Clientes->NuevoCliente.ClienteID = j);
    printf("Cantidad de productos: %d\n",Clientes->NuevoCliente.CantidadProductosAPedir = ProductAleatorio);
    strcpy(Clientes->NuevoCliente.NombreCliente, nombre);
    printf("Nombre: %s\n",Clientes->NuevoCliente.NombreCliente);

    Producto = (Lista*) malloc(sizeof(Lista)*ProductAleatorio);

    for (int i = 1; i <= ProductAleatorio; i++)
    {   
        int Cantidad =rand() % 10 * 1,PrecUnitario =rand() % 100 * 10,Posicion =rand() % 5 * 1;

        printf("Id: %d\n",Clientes->NuevoCliente.Productos->ProductoID = i);
        printf("Cantidad: %d\n",Clientes->NuevoCliente.Productos->Cantidad = Cantidad);
        printf("Precio Unitario: %d\n",Clientes->NuevoCliente.Productos->PrecioUnitario = PrecUnitario);
        strcpy(Clientes->NuevoCliente.Productos->TipoProducto, TiposProductos[Posicion]);
        printf("Tipo producto: %s\n\n",Clientes->NuevoCliente.Productos->TipoProducto);

        if (strcmp(IdProduct,TiposProductos[Posicion])==0)
        {
            PrecioTotalPorUnidad = PrecioTotalPorUnidad + PrecUnitario;
        }
        

        SumaTotal = SumaTotal + Clientes->NuevoCliente.Productos->PrecioUnitario;
        Producto = Producto->siguiente;
    }
    printf("\n\nEl total del precio por la unidad solicitada es: %d\nY el total a pagar del cliente es: %d\n\n",PrecioTotalPorUnidad,SumaTotal);
    PrecioTotalPorUnidad=0;
    SumaTotal=0;

    Producto->siguiente = NULL;

    while (Producto != NULL)
    {
        free(Producto);
        Producto=Producto->siguiente;
    }
    
    ProductAleatorio = rand() % 5 * 1;

    
    Clientes = Clientes->siguiente;
}  

    while (Clientes != NULL)
    {
        free(Clientes);
        Clientes=Clientes->siguiente;
    }
    

    return;
}