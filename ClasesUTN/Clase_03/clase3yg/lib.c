#include "lib.h"

int sumaEnteros(int numeroUno, int numeroDos, float *resultadoOperacion)
{
    long resultadoCalculo;
    int retorno= -1;
    resultadoCalculo = numeroUno + numeroDos;

    if(resultadoCalculo<=32767)
    {
        *resultadoOperacion = resultadoCalculo;
        retorno  = 0;
    }
    return retorno;
}

int restaEnteros(int numeroUno, int numeroDos, float *resultadoOperacion)
{
    long resultadoCalculo;
    int retorno= -1;
    resultadoCalculo = numeroUno - numeroDos;

    if(resultadoCalculo <= 32767 && resultadoCalculo> -32766)
    {
        *resultadoOperacion = resultadoCalculo;
        retorno  = 0;
    }
    return retorno;
}

int multiplicacionEnteros(int numeroUno, int numeroDos, float *resultadoOperacion)
{
    long resultadoCalculo;
    int retorno= -1;
    resultadoCalculo = numeroUno * numeroDos;

    if(resultadoCalculo <= 32767)
    {
        *resultadoOperacion = resultadoCalculo;
        retorno  = 0;
    }
    return retorno;
}

int divisionEnteros(int numeroUno, int numeroDos, float *resultadoOperacion)
{
    float resultadoCalculo;
    int retorno= -1;

    if(numeroDos!= 0)
    {
        resultadoCalculo = (float)numeroUno / numeroDos;
        if(resultadoCalculo <= 32767)
        {
            *resultadoOperacion = resultadoCalculo;
            retorno  = 0;
        }
    }

    return retorno;
}

