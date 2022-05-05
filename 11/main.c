#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargaInt(int arreglo[],int dimension,int *valildos);
void muestraInt(int arreglo[],int validos);
void ordenSeleccion(int arreglo[],int validos);
void ordenInsercion(int arreglo[],int validos);
int posicionMenor (int arreglo[],int i,int validos);
void insertar(int arreglo[], int i, int dato);
int main()
{
    int validos=0;
    char orden;
    int arreglo[50]={};
    cargaInt(arreglo,50,&validos);
    muestraInt(arreglo,validos);
    do
    {
        printf("\n\nIngrese por que metodo desea ordenar el arreglo: INSERCION I o SELECCION S: ");
        fflush(stdin);
        scanf("%c",&orden);
    }
    while(orden!='s' && orden!='i');
    switch(orden)
    {
        case 's':
        {
            ordenSeleccion(arreglo,validos);
        }
        break;
        case 'i':
        {
            ordenInsercion(arreglo,validos);
        }
        break;
    }
    printf("\nArreglo ordenado\n");
    muestraInt(arreglo,validos);
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

void ordenSeleccion(int arreglo[],int validos)
{
    int i=0,posicion;
    int aux;
    while (i<validos-1)
    {
        posicion=posicionMenor(arreglo,i,validos);
        aux=arreglo[posicion];
        arreglo[posicion]=arreglo[i];
        arreglo[i]= aux;
        i++;
    }
}
void ordenInsercion(int arreglo[],int validos)
{
    int i=0;
    while (i<validos-1)
    {
        insertar(arreglo,i,arreglo[i+1]);
        i++;
    }
}

int posicionMenor (int arreglo[],int i,int validos)
{
    int menor=arreglo[i];
    int posicion=i;
    int j=i+1;
    while (j<validos)
    {
        if(menor>arreglo[j])
        {
            menor=arreglo[j];
            posicion=j;
        }
        j++;
    }
    return posicion;
}

void insertar(int arreglo[], int i, int valor)
{
    while(i>=0 && valor<arreglo[i])
    {
        arreglo[i+1]=arreglo[i];
        i--;
    }
    arreglo[i+1]=valor;
}
