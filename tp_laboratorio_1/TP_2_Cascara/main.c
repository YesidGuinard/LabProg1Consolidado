#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "persona.h"
#define MUESTRA 20

int main()
{
    EPersona personas[MUESTRA];
    char seguir='s';
    int opcion=0;
    int auxiliar;
    int estadistica[3];
    char auxDni[20];

    persona_init(personas,MUESTRA);

    /*persona_altaForzada(personas,MUESTRA,"Pedro ", "42345678",5);
    persona_altaForzada(personas,MUESTRA,"Juan ","80203253",10);
    persona_altaForzada(personas,MUESTRA,"Walter ","24957772",15);
    persona_altaForzada(personas,MUESTRA,"Liliana","20523456",20);
    persona_altaForzada(personas,MUESTRA,"Pedro ", "12645678",25);
    persona_altaForzada(personas,MUESTRA,"Adrian","80273253",30);
    persona_altaForzada(personas,MUESTRA,"Walter","20987772",32);
    persona_altaForzada(personas,MUESTRA,"Liliana","20923456",16);
    persona_altaForzada(personas,MUESTRA,"Pedrogt", "10345678",26);
    persona_altaForzada(personas,MUESTRA,"Adrian","80208253",45);
    persona_altaForzada(personas,MUESTRA,"Walter","20967772",39);
    persona_altaForzada(personas,MUESTRA,"Liliana","25123456",50);
    persona_altaForzada(personas,MUESTRA,"Liliana","23143456",20);
    persona_altaForzada(personas,MUESTRA,"Pedro", "12355678",25);
    persona_altaForzada(personas,MUESTRA,"Adrian","80233253",30);
    persona_altaForzada(personas,MUESTRA,"Walter","20947772",32);
    persona_altaForzada(personas,MUESTRA,"Liliana","20323456",16);
    persona_altaForzada(personas,MUESTRA,"Pedro", "12325678",26);
    persona_altaForzada(personas,MUESTRA,"Adrian","802533253",45);
    persona_altaForzada(personas,MUESTRA,"Fabian","802533253",3);*/

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            auxiliar = persona_alta(personas,MUESTRA);
            if(auxiliar == 0)
            {
                printf("\nSe agrego persona correctamente\n\n");
            }
            else
            {
                if(auxiliar==-3)
                    printf("\nNo se pueden agregar mas personas \n\n");
                if(auxiliar==-4)
                    printf("\n el Dni ya se encuentra registrado \n\n");

            }

            break;
        case 2:
            persona_ordenar(personas,MUESTRA, 1);
            persona_mostrar(personas,MUESTRA);
            if(!getValidDni("\nIngrese dni  de Persona a eliminar\n","\nEso no es un dni","El maximo es 20",auxDni,20,2))
            {
                if(persona_baja(personas,MUESTRA,auxDni)==0)
                {
                    printf("Se elimino persona correctamente\n\n");
                }
                else
                {
                    printf("No se elimino persona Ingrese dni valido\n\n");
                }
            }

            break;
        case 3:
            if(contadorDeEdades(personas,MUESTRA,estadistica)>0)
            {
                persona_ordenar(personas,MUESTRA, 1);
                persona_mostrar(personas,MUESTRA);
            }
            else
            {
                printf("No Existen Datos Para Mostrar\n\n");
            }

            break;
        case 4:
            if(contadorDeEdades(personas,MUESTRA,estadistica)>0)
            {
                graficar(estadistica);
            }
            else
            {
                printf("No Existen Datos Para Graficar\n\n");
            }
            break;
        case 5:
            seguir = 'n';
            break;
        }
    }

    return 0;
}
