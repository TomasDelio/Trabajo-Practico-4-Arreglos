#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargaString(char arreglo[],int *validos);
void muestraChar(char arreglo[],int validos);
void invertirArreglo(char arreglo[],int validos);
int main()
{
    int validos=0;
    char arreglo[50]={};
    cargaString(arreglo,&validos);
    muestraChar(arreglo,validos);

    invertirArreglo(arreglo,validos);
    printf("Arreglo invertido es \n");
    muestraChar(arreglo,validos);

    return 0;
}

void cargaString(char arreglo[],int *validos)
{
    printf("Introduce una cadena de caracteres: ");
    scanf("%s",arreglo);
    *validos=strlen(arreglo);
}

void muestraChar(char arreglo[],int validos)
{
    int i;
    printf("El arreglo es: \n");
    for(i=0;i<validos;i++)
    {
        printf("| %c |",arreglo[i]);
    }
}

void invertirArreglo(char arreglo[],int validos)
{
    int i;
    char caracter;
    for(i=0;i<validos/2;i++)
    {
        caracter=arreglo[i];
        arreglo[i]=arreglo[validos-1-i];
        arreglo[validos-1-i]=caracter;
    }
}
