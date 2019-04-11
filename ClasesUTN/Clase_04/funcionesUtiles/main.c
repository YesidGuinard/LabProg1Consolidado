#include <stdio.h>
#include <stdlib.h>
#include "getLib.h"


int main()
{   int edad;
    float estaturaMetros;
    char continuar;

  /*  if(getInt("ingresa tu Edad?","Ingrese  valor de edad valido [0-199]",2,0,199,&edad)==0)
    {
        printf("tu edad es: %d \n",edad);
    }
    else
    {
        printf("Agoto numero de intentos validos\n");
    }



    if(getFloat("ingresa tu estatura en m [0.0-3.0]?","Ingrese  valor de estatura valido [0.0-3.0]",2 ,0.0, 3.0 ,&estaturaMetros)==0)
    {
        printf("tu estatura es: %.2f \n",estaturaMetros);
    }
    else
    {
        printf("Agoto numero de intentos validos estatura\n");
    }
    */

    if(getChar("Ingrese Opcion [A] [B] [C]","Solo [A] [B] [C]",2 ,'A','C' ,&continuar)==0)
    {
        printf("tu Opcion es: %c \n",continuar);
    }
    else
    {
        printf("agoto reinitentos char\n");
    }

    return 0;
}

