#include <stdio.h>
#include <stdlib.h>
#define MAXINT 32767

int sumar(int numeroUno, int numeroDos, int *resultado);
int restar(int, int);
int multiplicar(int, int);
float dividir(int, int);
float calcular(char ,int, int);

int main()
{
    int numeroUno, numeroDos;
    int total;
    char caracter;

    printf("ingrese un numero: ");
    scanf("%d",&numeroUno);
    printf("\ningrese el segundo numero: ");
    scanf("%d",&numeroDos);
    printf("\n ingrese operador +, -, *, o /");
    fflush(stdin);
    scanf("%c",&caracter);

    if(sumar(numeroUno,numeroDos,&total) == 0)
    {
        printf("Resultado de la suma %d",total);
    }
    else
    {
        printf("Error overflow");
    }

    //total=calcular(caracter, numeroUno, numeroDos);
    //printf("\n\nResultado: %f", total);

    return 0;
}

/** \brief Suma dos enteros
 *
 * \param int es el primer numero a ser sumado
 * \param int es el segundo numero a ser sumado
 * \param int* es el resultado de la operacion pasado por referencia
 * \return int -1 Error overflow, 0 Ok
 *
 */
int sumar(int numeroUno, int numeroDos, int *resultado)
{
    long resultadoAuxiliar;
    int flagRetorno = -1;
    resultadoAuxiliar = numeroDos+numeroUno;
    if(resultadoAuxiliar <= MAXINT)
    {
        *resultado = resultadoAuxiliar;
        flagRetorno = 0;
    }
    return flagRetorno;
}


int restar(int numeroUno, int numeroDos)
{
    int resultado=numeroUno-numeroDos;
    return resultado;
}
int multiplicar(int numeroUno, int numeroDos)
{
    int resultado=numeroUno*numeroDos;
    return resultado;
}
float dividir(int numeroUno, int numeroDos)
{
    float resultado=(float)numeroUno/numeroDos;
    return resultado;
}

float calcular(char calculo,int numeroUno, int numeroDos)
{
    float resultado;
        switch (calculo){
            case '*':
            resultado=multiplicar(numeroUno, numeroDos);
        break;
        case '/':
            resultado=dividir(numeroUno, numeroDos);
            break;
        case '-':
            resultado=restar(numeroUno, numeroDos);
            break;
        case '+':
            //resultado=sumar(numeroUno,numeroDos);
            break;
        default:
            printf("\n\tingrese un operador valido.");
            break;
        }
                return resultado;
}
