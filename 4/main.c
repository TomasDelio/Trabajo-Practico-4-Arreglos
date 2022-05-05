#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

void cargaInt(int arreglo[],int dimension,int *valildos);
void muestraInt(int arreglo[],int validos);
void arregloPila(int arreglo[],int validos,Pila *pila);
int main()
{
    int validos=0;
    int arreglo[50]={};
    Pila pila;
    inicpila(&pila);
    cargaInt(arreglo,50,&validos);
    muestraInt(arreglo,validos);
    arregloPila(arreglo,validos,&pila);
    printf("\nLa pila es: ");
    mostrar(&pila);
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
void arregloPila(int arreglo[],int validos,Pila *pila)
{
    int i;
    for(i=0;i<validos;i++)
    {
        apilar(pila,arreglo[i]);
    }
}
