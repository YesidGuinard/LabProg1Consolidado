#include <stdio.h>
#include <stdlib.h>
#define MAX_NUMEROS 5
int main()
{
    int numeroIngresado;
    int acumulador=0;
    float promedio;
    int contador;

    for(contador=1 ; contador<=MAX_NUMEROS;contador++)
    {

        printf("Ingrese el numero %d\n",contador);
        //fflush(stdin);
        scanf("%d",&numeroIngresado);
        acumulador=acumulador+numeroIngresado;
    }
    promedio= (float)acumulador/MAX_NUMEROS;
    printf("El promedio es: %.2f",promedio);

    return 0;
}
