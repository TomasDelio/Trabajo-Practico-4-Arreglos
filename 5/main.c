#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargaFloat(float arreglo[],int dimension,int *valildos);
void sumaFloat(float arreglo[],int validos,float *suma);
int main()
{
    int validos=0;
    float suma=0;
    float arreglo[100]={};
    cargaFloat(arreglo,100,&validos);
    sumaFloat(arreglo,validos,&suma);
    printf("La sum es: %.2f\n",suma);

    return 0;
}

void cargaFloat(float arreglo[],int dimension,int *validos)
{
    int i;
    char continuar='s';
    for(i=0;i<dimension && continuar=='s';i++)
    {
        printf("Ingrese un numero real: ");
        scanf("%f",&arreglo[i]);
        printf("Desea ingresar otro numero? s/n Respuesta: ");
        fflush(stdin);
        scanf("%c",&continuar);
        printf("\n");
    }
    *validos=i;
}

void sumaFloat(float arreglo[],int validos,float *suma)
{
    int i;
    for(i=0;i<validos;i++)
    {
        *suma=*suma+arreglo[i];
    }
}
