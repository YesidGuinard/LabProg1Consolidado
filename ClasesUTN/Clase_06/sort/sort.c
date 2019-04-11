#include <stdio.h>
#include <stdlib.h>

int swapInt(int* primerEntero,int* segundoEntero);


/** \brief  Ordena un array de enteros
 *
 * \param array int* Puntero al array
 * \param cantidadElementos int cantidad de elementos del array
 * \param flagOrden int [1] Ordena de mayor a menor [0] Ordena de menor a mayor
 * \return int [-1] Error [0] Ok
 *
 */
int sort_ordenarArrayEnteros(int* array,int cantidadElementos, int flagOrden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    if(cantidadElementos > 0)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<cantidadElementos-1;i++)
            {
                if((array[i] < array[i+1] && flagOrden)||(array[i] > array[i+1] && !flagOrden))
                {
                    swapInt(&array[i],&array[i+1]);
                    flagSwap = 1;
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

/** \brief Intercambia dos enteros
 *
 * \param primerEntero int*
 * \param segundoEntero int*
 * \return int
 *
 */
int swapInt(int* primerEntero,int* segundoEntero)
{
    int auxiliar;
    auxiliar = *primerEntero;
    *primerEntero = *segundoEntero;
    *segundoEntero = auxiliar;
    return 0;
}


/** \brief
 *
 * \param array int*
 * \param cantidadElementos int
 * \return int
 *
 */
int sort_mostrarArrayEnteros(int* array, int cantidadElementos)
{
    int retorno = -1;
    int i;
    if(cantidadElementos > 0)
    {
        retorno = 0;
        for(i=0;i<cantidadElementos;i++)
        {
            printf("\n%d",array[i]);
        }
    }
    return retorno;
}
