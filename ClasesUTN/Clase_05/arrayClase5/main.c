/******************************************************************
* Programa: Ejemplo Clase 5
*
* Objetivo:
*   Solicitar al usuario 5 números, permitir listarlos por pantalla
*   indicando el máximo, el mínimo y el promedio
*   Permitir Modificar el valor de cualquiera de los números cargados
*   indicando el índice del mismo y su nuevo valor.
*
* Aspectos a destacar:
*   -Utilización de array
*
* Version: 0.1 del 29 diciembre de 2015
* Autor: Mauricio Dávila
* Revisión: Ernesto Gigliotti
*
* *******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define CANTIDAD 5 // constante con tamaño del array

int calcularPromedioArray(int arrayDeNumeros[],int cantidad, float* promedio);

int main()
{
    int arrayDeNumeros[CANTIDAD];
    int numeroIngresado;
    int indiceArray;


    int suma=0;

    int maximo;
    int minimo;
    float promedio;

    for(indiceArray = 0 ; indiceArray < CANTIDAD ; indiceArray++ )
    {
            numeroIngresado = getInt("Ingrese el valor: \n");
            arrayDeNumeros[indiceArray] = numeroIngresado;
    }



    if(calcularPromedioArray(&arrayDeNumeros, 5 , &promedio)==0)
    {
        printf("\n el promedio es:%.2f",promedio);
    }
    else
    {
        printf("No se calculo Prom");
    }



    return 0;
}



int calcularPromedioArray(int *arrayDeNumero,int cantidad, float* promedio)
{
    int retorno =-1;
    int indiceArray;
    int suma = 0;
    if(cantidad>=0 || promedio==NULL)
    {

        for(indiceArray = 0 ; indiceArray < cantidad ; indiceArray++ )
        {
            suma=suma + arrayDeNumero[indiceArray];
        }

        *promedio = (float)suma/cantidad;

        retorno = 0;
    }


    return retorno;



}
