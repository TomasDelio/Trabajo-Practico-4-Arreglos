#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargaString(char arreglo[],int *validos);
void muestraChar(char arreglo[],int validos);
int ordenChar(char arreglo[],int validos);
int main()
{
    int validos=0,flag=0;
    char arreglo[50]={};
    cargaString(arreglo,&validos);
    muestraChar(arreglo,validos);
    while(flag!=1)
    {
        flag=ordenChar(arreglo,validos);
    }

    printf("El maximo es  es \"%c\".\n\n",arreglo[validos-1]);

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
