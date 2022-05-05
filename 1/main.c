#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargaInt(int arreglo[],int dimension,int *valildos);
int main()
{
    int validos=0,arreglo[50]={};

    cargaInt(arreglo,50,&validos);
    printf("La cantidad de elementos cargados es: %i\n\n",validos);

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
