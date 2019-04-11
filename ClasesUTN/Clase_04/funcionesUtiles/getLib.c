#include <stdio.h>
#include <stdlib.h>

/**
* \brief Solicita un número Int al usuario y lo valida
* \param mensaje Es el mensaje a ser mostrado
* \param mensajeError Es el mensaje a ser mostrado en caso de error
* \param reintentos numero de reintentos que tiene el usuario
* \param minimo Limite inferior a validar
* \param maximo Limite superior a validar
* \param resultado almacena por ref numero ingresado
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(char* mensaje, char* mensajeError, int reintentos, int minimo, int maximo, int* resultado)
{
    int retorno = -1;
    long auxiliarLong;

    do
    {
        reintentos--;
        printf("%s\n", mensaje);
        scanf("%ld",&auxiliarLong);
        if(auxiliarLong>=minimo && auxiliarLong<=maximo)
        {
           *resultado = (int)auxiliarLong;
           retorno=0;
           break;
        }
        //fflush(stdin);
        printf("%s\n", mensajeError);


    }while(reintentos>=0);

    return retorno;


}

/**
* \brief Solicita un número float al usuario y lo valida
* \param mensaje Es el mensaje a ser mostrado
* \param mensajeError Es el mensaje a ser mostrado en caso de error
* \param reintentos numero de reintentos que tiene el usuario
* \param minimo Limite inferior float a validar
* \param maximo Limite superior float a validar
* \param resultado almacena por ref numero ingresado
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloat(char* mensaje, char* mensajeError, int reintentos, float minimo, float maximo, float* resultado)
{
    int retorno = -1;
    double auxiliarDouble;

    do
    {
        reintentos--;
        printf("%s\n", mensaje);
        scanf("%lf",&auxiliarDouble);
        if(auxiliarDouble>=minimo && auxiliarDouble<=maximo)
        {
           *resultado = (float)auxiliarDouble;
           retorno=0;
           break;
        }
        //fflush(stdin);
        printf("%s\n", mensajeError);


    }while(reintentos>=0);

    return retorno;


}

/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter [0] si no [-1]
*
*/
int getChar(char* mensaje, char* mensajeError, int reintentos, char minimo, char maximo, char* resultado)
{
    int retorno = -1;
    char auxiliarChar;

    do
    {
        reintentos--;
        printf("%s\n", mensaje);
        fflush(stdin);
        scanf("%c",&auxiliarChar);
        if(auxiliarChar>=minimo && auxiliarChar<=maximo)
        {
           *resultado = auxiliarChar;
           retorno=0;
           break;
        }

        printf("%s\n", mensajeError);


    }while(reintentos>=0);

    return retorno;


}


