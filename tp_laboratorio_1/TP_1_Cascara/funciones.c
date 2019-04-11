#include <stdio.h>
#include <stdlib.h>

int getInt(char* mensaje, char* mensajeError, int reintentos, int minimo, int maximo, int* resultado)
{
    int retorno = -1;
    long auxiliarLong;

    do
    {
        reintentos--;
        printf("%s\n", mensaje);
        fflush(stdin);
        scanf("%ld",&auxiliarLong);
        if(auxiliarLong>=minimo && auxiliarLong<=maximo)
        {
            *resultado = (int)auxiliarLong;
            retorno=0;
            break;
        }

        printf("%s\n", mensajeError);


    }
    while(reintentos>=0);

    return retorno;


}


void sumaEnteros(int OperandoA, int OperandoB, double* resultado)
{
    *resultado = OperandoA + OperandoB;
}

void restaEnteros(int OperandoA, int OperandoB, double* resultado)
{
    *resultado = OperandoA - OperandoB;
}


int divisionEnteros(int OperandoA, int OperandoB, double* resultado)
{
    int retorno=-1;

    if(OperandoB != 0)
    {
        *resultado = (float)OperandoA / OperandoB;
        retorno=0;
    }

    return retorno;

}


void multiplicacionEnteros(int OperandoA, int OperandoB, double* resultado)
{
    *resultado = OperandoA * OperandoB;

}


int factorialEntero(int OperandoA,double*  resultado)
{
    int retorno=-1;
    int aux;
    double acumulador = OperandoA;

    if(OperandoA==0)
    {
        *resultado=0;
        retorno=0;

    }else if(OperandoA>0 && OperandoA<=170)
    {
        for(aux=OperandoA-1;aux>1;aux--)
        {
           acumulador=acumulador*aux;

        }

    *resultado = acumulador;
     retorno=0;
    }

    return retorno;
}
