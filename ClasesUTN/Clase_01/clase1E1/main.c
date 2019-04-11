#include <stdio.h>
#include <stdlib.h>

int main()
{   int numeroUno=0;
    int numeroDos=0;
    int resultado=0;
    char respuestaUsuario;



    do
    {
        printf("Ingresa el primer numero \n");
        scanf("%d",&numeroUno);
        printf("Ingresa el segundo numero\n");
        scanf("%d",&numeroDos);
        if(numeroUno>0 && numeroDos>0)
        {
        resultado=numeroUno+numeroDos;
        printf("______________________________________\n");
        printf("resultado de la suma es: %d \n",resultado);
        }
        else
        {
        printf("No se puede realizar operacion\n");
        }

        printf("Para Continuar ingrese (s/n) \n");
        fflush(stdin);
        scanf("%c",&respuestaUsuario);

    } while ( respuestaUsuario == 's' );

    return 0;
}
