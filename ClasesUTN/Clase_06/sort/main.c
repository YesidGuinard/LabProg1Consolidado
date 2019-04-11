#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int main()
{
    int array[11] = {1,2,8,9,1,3,7,56,55,66,2};
    sort_mostrarArrayEnteros(array,11);
    printf("\n\n");

    if(!sort_ordenarArrayEnteros(array,11,1))
    {
        sort_mostrarArrayEnteros(array,11);
        printf("\n\n");
    }
    else
    {
        printf("ERROR");
    }
    return 0;
}
