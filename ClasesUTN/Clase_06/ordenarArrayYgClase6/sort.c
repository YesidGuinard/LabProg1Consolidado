#include <stdio.h>
#include <stdlib.h>

int swapInt(int* primerEntero,int* segundoEntero);
int sort_mostrarArrayEnteros(int* array,int cantidadElementos)
{

    int retorno=-1;
    int aux;

    for(aux=0;aux<cantidadElementos;aux++)
    {
        printf("%d\n",array[aux]);
    }
    retorno=0;
    printf("-------------------------------------\n\n");
        return retorno;

}


int sort_ordenarArrayEnteros(int* array,int cantidadElementos,int flagOrden)
{
    int retorno = -1;
    int aux;
    int swapFlag;
    int j;

    if(cantidadElementos>0)
    {
        retorno = 0;
        do
        {
            swapFlag = 1;
            for(j=0; j<cantidadElementos-1; j++)
            {
                if(flagOrden)
                {
                    if(array[j]>array[j+1])
                        {
                            aux    = array[j+1];
                            array[j+1] = array[j];
                            array[j]   = aux;
                            swapFlag=0;
                        }
                }
                else
                {
                    if(array[j]<array[j+1])
                    {
                        aux    = array[j+1];
                        array[j+1] = array[j];
                        array[j]   = aux;
                        swapFlag=0;
                    }
                }
                retorno=0;
            }
        } while(swapFlag == 0);

    }

    return retorno;
}
int swapInt(int* primerEntero,int* segundoEntero)
{
    int auxiliar;
    auxiliar = *primerEntero;
    *primerEntero = *segundoEntero;
    *segundoEntero = auxiliar;
    return 0;
}
