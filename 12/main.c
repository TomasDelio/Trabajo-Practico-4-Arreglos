#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargaString(char arreglo[],int *validos);
void muestraChar(char arreglo[],int validos);
int ordenChar(char arreglo[],int validos);
void juntarArreglos(char arreglo1[],int validos1,char arreglo2[],int validos2,char arregloFinal[]);
int main()
{
    int validos1=0,validos2=2,flag1=0,flag2=0,flagFinal=0;
    char arreglo1[50]={},arreglo2[50]={},arregloFinal[100]={};
    cargaString(arreglo1,&validos1);
    cargaString(arreglo2,&validos2);
    while(flag1!=1)
    {
        flag1=ordenChar(arreglo1,validos1);
    }
    printf("Arreglo 1 ordenado\n");
    muestraChar(arreglo1,validos1);
    while(flag2!=1)
    {
        flag2=ordenChar(arreglo2,validos2);
    }
    printf("\n\nArreglo 2 ordenado\n");
    muestraChar(arreglo2,validos2);
    juntarArreglos(arreglo1,validos1,arreglo2,validos2,arregloFinal);
    while(flagFinal!=1)
    {
        flagFinal=ordenChar(arregloFinal,validos1+validos2);
    }
    printf("\n\nArreglo Final ordenado\n");
    muestraChar(arregloFinal,validos1+validos2);
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

int ordenChar(char arreglo[],int validos)
{
    int i,j,flag=0;
    char aux;
    for(i=0;i<validos-1;i++)
    {
        for (j=1;j<validos;j++)
        {
            if(arreglo[j]<arreglo[j-1])
            {
                aux=arreglo[j];
                arreglo[j]=arreglo[j-1];
                arreglo[j-1]=aux;
            }
            else
            {
                flag=1;
            }
        }
    }
    return flag;
}

void juntarArreglos(char arreglo1[],int validos1,char arreglo2[],int validos2,char arregloFinal[])
{
    int i,j=validos1;
    for(i=0;i<validos1;i++)
    {
        arregloFinal[i]=arreglo1[i];
    }
    for(i=0;i<validos2;i++)
    {
        arregloFinal[j]=arreglo2[i];
        j++;
    }
}
