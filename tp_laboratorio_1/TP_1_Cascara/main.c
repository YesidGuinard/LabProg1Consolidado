#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    char seguir;
    int opcion = 0;
    int operandoA = 0;
    int operandoB = 0;
    double resultado;
    double resultadoFactorial;

    do
    {
        printf("--------Calculadora TP------------------------\n");
        printf("1- Ingresar 1er operando (A= %d)\n",operandoA);
        printf("2- Ingresar 2do operando (B= %d)\n",operandoB);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        fflush(stdin);
        scanf("%d",&opcion);
        seguir = 's';

        switch(opcion)
        {

        case 1:
            if(!getInt("Ingresar 1er operando (A) entre [-32768 y 32767].", "Error!, Ingrese un numero valido entre [-32768 y 32767]",3,-32768,32767, &operandoA))
            {
                printf("Valor de Operando A: %d \n\n",operandoA);
            }
            else
            {
                printf("Agoto numero de intentos validos\n");
            }

            break;
        case 2:

            if(!getInt("Ingresar 2do operando (B) entre [-32768 y 32767].", "Error!, Ingrese un numero valido entre [-32768 y 32767]",3,-32768,32767, &operandoB))
            {
                printf("Valor de Operando B: %d \n\n",operandoB);
            }
            else
            {
                printf("Agoto numero de intentos validos\n");
            }

            break;
        case 3:
            sumaEnteros(operandoA, operandoB, &resultado);
            printf("Resultado de Suma:  %d + %d = %.0f \n\n",operandoA,operandoB,resultado);

            break;
        case 4:

            restaEnteros(operandoA, operandoB, &resultado);
            printf("Resultado de Resta:  %d - %d = %.0f \n\n",operandoA,operandoB,resultado);
            break;
        case 5:

            if(!divisionEnteros(operandoA, operandoB, &resultado))
            {
                printf("Resultado de Division:  %d / %d = %.2f \n\n",operandoA,operandoB,resultado);
            }
            else
            {
                printf("No se pude realizar division por 0 \n");
            }
            break;
        case 6:

            multiplicacionEnteros(operandoA, operandoB, &resultado);
            printf("Resultado de Multiplicacion: %d * %d = %.0f \n\n",operandoA,operandoB,resultado);

            break;
        case 7:

            if(!factorialEntero(operandoA,&resultadoFactorial))
            {
                printf("Resultado de Factorial: (%d)!  = %.0lf\n\n",operandoA,resultadoFactorial);
            }
            else
            {
                printf("No se pude realizar factorial, rango de Operando A [0 - 170] \n");
            }
            break;
        case 8:
            sumaEnteros(operandoA, operandoB, &resultado);
            printf("Resultado de Suma:  %d + %d = %.0f \n\n",operandoA,operandoB,resultado);

            restaEnteros(operandoA, operandoB, &resultado);
            printf("Resultado de Resta:  %d - %d = %.0f \n\n",operandoA,operandoB,resultado);

            if(!divisionEnteros(operandoA, operandoB, &resultado))
            {
                printf("Resultado de Division:  %d / %d = %.2f \n\n",operandoA,operandoB,resultado);
            }
            else
            {
                printf("No se pude realizar division por 0 \n");
            }

            multiplicacionEnteros(operandoA, operandoB, &resultado);
            printf("Resultado de Multiplicacion: %d * %d = %.0f \n\n",operandoA,operandoB,resultado);

            if(!factorialEntero(operandoA,&resultadoFactorial))
            {
                printf("Resultado de Factorial: (%d)!  = %.0lf\n\n",operandoA,resultadoFactorial);
            }
            else
            {
                printf("No se pude realizar factorial, rango de Operando A [0 - 170] \n");
            }

            break;
        case 9:
            seguir = 'n';
            break;
        default :
            printf("ERROR,opcion no valida!, Ingrese opcion del 1 al 9\n\n");

        }
        system("pause");
        system("cls");
    }
    while(seguir == 's');

    return 0;
}

