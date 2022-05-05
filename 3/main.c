#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargaInt(int arreglo[],int dimension,int *valildos);
void muestraInt(int arreglo[],int validos);
void sumaInt(int arreglo[],int validos,int *suma);

int main()
{
    int validos=0,suma=0;
    int arreglo[50]={};
    cargaInt(arreglo,50,&validos);
    muestraInt(arreglo,validos);
    sumaInt(arreglo,validos,&suma);
    printf("\n\nLa suma de los elementos del arreglo es: %i\n\n",suma);

    return 0;
}

void cargaInt(int arreglo[],int dimension,int *validos)
{
    int i;
    char control='s';
    for(i=0;i<dimension && control=='s';i++)
    {
        printf("Ingrese un numero entero: ");
        scanf("%i",&arreglo[i]);
        printf("Desea ingresar otro numero? s/n Respuesta: ");
        fflush(stdin);
        scanf("%c",&control);
    }
    *validos=i;
}

void muestraInt(int arreglo[],int validos)
{
    int i;
    printf("El arreglo es: \n");
    for(i=0;i<validos;i++)
    {
        printf("| %i |",arreglo[i]);
    }
}

void sumaInt(int arreglo[],int validos,int *suma)
{
    int i;
    for(i=0;i<validos;i++)
    {
        *suma=*suma+arreglo[i];
    }
}
