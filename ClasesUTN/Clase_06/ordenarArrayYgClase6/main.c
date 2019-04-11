#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


int main()
{
    int myArray[10]={55,66,2,10,100,21,17,78,43,55};

    if(!sort_mostrarArrayEnteros(myArray,10))
    {
        printf("Se imprime Array Correctamente!\n");
    }
    else
    {
        printf("Error! No Se imprime Array Correctamente!\n");
    }

    if(!sort_ordenarArrayEnteros(myArray,10,1))
    {
        printf("Se imprime Array Ascendente!\n\n");
    }
    else
    {
        printf("Error! No Se imprime Array Correctamente!\n");
    }

    if(!sort_mostrarArrayEnteros(myArray,10))
    {
        printf("Se imprime Array Correctamente!\n");
    }
    else
    {
        printf("Error! No Se imprime Array Correctamente!\n");
    }




    return 0;
}

