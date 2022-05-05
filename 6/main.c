#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargaString(char arreglo[],int *validos);
int busquedaChar(char arreglo[],int validos,char caracter);
void muestraChar(char arreglo[],int validos);
int main()
{
    int validos,flag=0;
    char caracter;
    char arreglo[50]={};
    cargaString(arreglo,&validos);
    muestraChar(arreglo,validos);
    printf("\n\nIngrese el caracter que desea buscar: ");
    fflush(stdin);
    scanf("%c",&caracter);
    flag=busquedaChar(arreglo,validos,caracter);
    if(flag==1)
    {
        printf("El caracter %c esta en el arreglo.\n",caracter);
    }
    else
    {
        printf("El caracter %c no esta en el arreglo.\n",caracter);
    }

    return 0;
}

void cargaString(char arreglo[],int *validos)
{
    printf("Introduce una cadena de caracteres: ");
    scanf("%s",arreglo);
    *validos=strlen(arreglo);
    printf("\n");
}

int busquedaChar(char arreglo[],int validos,char caracter)
{
    int i,flag=0;
    for(i=0;i<validos && flag==0;i++)
    {
        if(caracter==arreglo[i])
        {
            flag=1;
        }
    }
    return flag;
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
