#include <stdio.h>
#include <stdlib.h>
#include "lib.h"


int main()
{
    int primerNumero;
    int segundoNumero;
    float resultadoMain;
    char operadorSelecionado;

    printf("Ingrese Operacion deseada:\n\n");
    printf("+  Para suma (A+B)\n");
    printf("-  Para resta (A-B)\n");
    printf("*  Para multiplicacion (A*B)\n");
    printf("/  Para division (A/B)\n");
    fflush(stdin);
    scanf("%c",&operadorSelecionado);

    printf("Ingrese un numero 1: ");
    scanf("%d",&primerNumero);
    printf("Ingrese un numero 2: ");
    scanf("%d",&segundoNumero);

        switch(operadorSelecionado)
        {
            case '+':
                //printf("operacion suma! ");
                if(sumaEnteros(primerNumero,segundoNumero,&resultadoMain)== 0)
                {
                    printf("el resultado suma es %.2f", resultadoMain);

                }
                else
                {
                    printf("Error en suma");
                }

                break;

            case '-':
               //printf("operacion suma! ");
                if(restaEnteros(primerNumero,segundoNumero,&resultadoMain)== 0)
                {
                    printf("el resultado resta es %.2f", resultadoMain);

                }
                else
                {
                    printf("Error en resta");
                }
                break;

            case '*':
                if(multiplicacionEnteros(primerNumero,segundoNumero,&resultadoMain)== 0)
                {
                    printf("el resultado multiplicacion es %.2f", resultadoMain);

                }
                else
                {
                    printf("Error en multiplicacion");
                }
                break;

                break;

            case '/':
                 if(divisionEnteros(primerNumero,segundoNumero,&resultadoMain)== 0)
                {
                    printf("el resultado div es %.2f", resultadoMain);

                }
                else
                {
                    printf("Error en div");
                }
                break;

        }

   // printf("el resultado de la operacion es: %.1f\n",resultadoOperacion);
    return 0;
}
