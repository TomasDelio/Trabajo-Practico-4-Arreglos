#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargaInt(int arreglo[],int dimension,int *valildos);
void muestraInt(int arreglo[],int validos);
void sumaAnteriores(int arreglo[],int validos,int arregloSuma[]);
void sumaInt(int arreglo[],int validos,int *suma);
int main()
{
    int validos=0;
    int arreglo[50]={},arregloFinal[50]={};
    cargaInt(arreglo,50,&validos);
    muestraInt(arreglo,validos);

    sumaAnteriores(arreglo,validos,arregloFinal);
    printf("Arreglo suma de los anteriores\n");
    muestraInt(arregloFinal,validos);
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

void sumaAnteriores(int arreglo[],int validos,int arregloSuma[])
{
    int i;
    for(i=0;i<validos;i++)
    {
        int suma=0;
        sumaInt(arreglo,i+1,&suma);
        arregloSuma[i]=suma;
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
