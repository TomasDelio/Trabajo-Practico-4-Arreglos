#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargaString(char arreglo[],int *validos);
void muestraChar(char arreglo[],int validos);
void invertirArreglo(char arreglo[],int validos);
int capicua(char arreglo[],int validos,char copia[]);
int main()
{
    int validos=0;
    int flag;
    char arreglo[50]={},copia[50]={};
    cargaString(arreglo,&validos);
    strcpy(copia,arreglo);
    invertirArreglo(copia,validos);
    muestraChar(arreglo,validos);
    printf("\n\n");
    flag=capicua(arreglo,validos,copia);
    if(flag==1)
    {
        printf("El arreglo es capicua.");
    }
    else
    {
        printf("El arreglo no es capicua.");
    }

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

int capicua(char arreglo[],int validos,char copia[])
{
    int i=0,flag=1;
    while(i<validos && flag==1)
    {
        if(arreglo[i]==copia[i])
        {
            i++;
            flag=1;
        }
        else
        {
            flag=0;
        }
    }
    return flag;
}
