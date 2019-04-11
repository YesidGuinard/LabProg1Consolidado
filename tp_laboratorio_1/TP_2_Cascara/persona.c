#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funciones.h"
#include "persona.h"


static int proximoId();
static int buscarLugarLibre(EPersona* array,int limite);

/** \brief se encarga de marcas todas las personas del array como vacias lista para uso
 *
 * \param EPersona array de personas
 * \param limite tamano maximo de array personas
 * \return Devuelve 0 en el caso de exito, otros errores retorna -1.
 *
 */
int persona_init(EPersona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

/*int persona_mostrarDebug(EPersona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            printf("[DEBUG] - %d", array[i].idEPersona);
        }
    }
    return retorno;
}*/
/** \brief se encarga de imrimir por pantalla datos almacenados
 *
 * \param EPersona array de personas
 * \param limite tamano maximo de array personas
 * \return Devuelve 0 en el caso de exito, otros errores retorna -1.
 *
 */
int persona_mostrar(EPersona* array,int limite)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        printf("---------LISTADO DE PERSONAS--------- \n");
        printf("-ID\t-NOMBRE\t\t-DNI\t\t\t -EDAD\t\n");
        for(i=0; i<limite; i++)
        {
            if(!array[i].isEmpty)
            {
                printf("%d\t%s\t\t%s\t\t%d\n",array[i].idEPersona, array[i].nombre,array[i].dni, array[i].edad);
            }
        }
        printf("---------------------------------\n");
    }
    return retorno;
}
/** \brief solicita y captura datos ingresados por el usuario adicionalmente solicita revisar si el dni se encuentra ya almacenado.
 *
 * \param EPersona array de personas
 * \param limite tamano maximo de array personas
 * \return Devuelve 0 en el caso de exito, si no encuentra lugares retorna -3 si dni ya existe retorna -4 otros errores retorna -1.
 *
 */
int persona_alta(EPersona* array,int limite)
{
    int retorno = -1;
    int i;
    char nombre[50];
    char dni[20];
    int edad;
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {

            if(!getValidDni("\nIngrese dni? ","\nEso no es un dni","El maximo es 20",dni,20,2))
            {
                if(persona_buscarPorDni(array,limite,dni)<0)
                {
                    if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 50",nombre,50,2))
                    {
                        if(!getValidInt("\n Edad? ","\nEso no es una edad valida[1-150]",&edad,1,150,2))
                        {
                            retorno = 0;
                            strcpy(array[i].nombre,nombre);
                            strcpy(array[i].dni,dni);
                            array[i].edad = edad;
                            array[i].idEPersona = proximoId();
                            array[i].isEmpty = 0;
                        }
                    }
                }
                else
                {
                    retorno = -4;
                }
            }

        }
        else
        {
            retorno = -3;
        }
    }
    else
    {
        retorno = -2;
    }
    printf("\n");
    return retorno;
}

/** \brief elimina del el array persona por dni.
 *
 * \param EPersona array de personas
 * \param limite tamano maximo de array personas
 * \param dni array tipo char que recibe el dni
 * \return Devuelve 0 en el caso de eliminar persona del arrray.
 *
 */
int persona_baja(EPersona* array,int limite, char* dni)
{
    int retorno = 0;
    int indiceAEliminar = persona_buscarPorDni(array, limite, dni);
    if(indiceAEliminar>=0)
    {
        array[indiceAEliminar].isEmpty = 1;
    }
    else
    {
        retorno=indiceAEliminar;
    }
    return retorno;
}
/*int persona_modificacion(EPersona* array,int limite, int id)
{
    int retorno = -1;
    int indiceAModificar;
    char nombre[50];
    char apellido[50];
    char cuit[20];
    indiceAModificar = persona_buscarPorId(array, limite, id);
    if(indiceAModificar>=0)
    {
        if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 50",nombre,50,2))
        {
            strcpy(array[indiceAModificar].nombre,nombre);
            if(!getValidString("\nApellido? ","\nEso no es un Apellido","El maximo es 50",apellido,50,2))
            {
               strcpy(array[indiceAModificar].apellido,apellido);

                if(!getValidCuit("\nCuit? ","\nEso no es un Cuit","El maximo es 20",cuit,20,2))
                {
                    retorno=0;
                    strcpy(array[indiceAModificar].cuit, cuit);
                }
                else
                {
                    retorno=-3;
                }

            }

        }
        else
        {
            retorno = -2;
        }
    }
    return retorno;
}*/
/** \brief ordena la el array persona en orden alfabetico por nombre.
 *
 * \param EPersona array de personas
 * \param limite tamano maximo de array personas
 * \param orden si vale 1 se ordena ascendente y si vale 0 es descendente
 * \return Devuelve 0 en el acso que ordena correctamente, si array vacio o nulo retorna -1.
 *
 */
int persona_ordenar(EPersona* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    EPersona auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0; i<limite-1; i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }
        while(flagSwap);
    }
    return retorno;
}

/**
 * \brief funcion privada Se encarga de buscar en la estructura una posicion vacia
 * \param EPersona estructura EPersona*
 * \param limite tamano maxino de array personas
 * \return La posicion libre
 *
 */
static int buscarLugarLibre(EPersona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief funcion privada que se encarga de generar el siguiente Id unico e incremental
 * \return El id unico si encuentra lugar libre si no retorna -1
 *
 */
static int proximoId()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}

/*int persona_buscarPorId(EPersona* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idEPersona==id)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}*/

/** \brief busca una Persona por DNI en el Array de Personas.
 *
 * \param EPersona array de personas
 * \param limite tamano maximo de array personas
 * \param dni array tipo char donde recibe dni digitado.
 * \return Devuelve la posicion en el array donde encontro el dni, si no encuentra retorna -1.
 *
 */
int persona_buscarPorDni(EPersona* array,int limite, char* dni)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0; i<limite; i++)
        {
            if(!array[i].isEmpty )
            {
                if(strcmp(array[i].dni,dni)==0)
                {
                    retorno=i;
                    break;
                }
            }
        }
    }
    return retorno;
}
/** \brief Funcion que ingresa datos demo para hacer pruebas
 *
 * \param array EPersona Array de Grupo de Personas.
 * \param limite tamano del array personas
 * \param nombre array tipo char recibe nombre persona
 * \param dni array tipo char recibe dni demo persona
 * \param edad  tipo int recibe edad demo persona
 * \return devuelve el total de personas en la estructura.
 *
 */
int persona_altaForzada(EPersona* array,int limite,char* nombre,char* dni,int edad)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(array[i].nombre,nombre);
            strcpy(array[i].dni,dni);
            array[i].edad=edad;
            array[i].idEPersona = proximoId();
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}
/** \brief Funcion que recorre todo el array depersona campo edad y totaliza cantidad de personas segun rango de edad
 *
 * \param array EPersona Array de Grupo de Personas.
 * \param limite tamano del array personas
 * \param contadorEdad[] vector tipo int en el cual se almacenan y retornan acumuladores
 * \return devuelve el total de personas en la estructura.
 *
 */
int contadorDeEdades(EPersona* array,int limite, int contadorEdad[])
{
    int i;
    int men18anios = 0;
    int rango19a35anios = 0;
    int may35 = 0;
    for(i=0; i<limite; i++)
    {
        if(!array[i].isEmpty)
        {
            if(array[i].edad < 18)
            {
                men18anios++;
            }
            else if(array[i].edad <= 35)
            {
                rango19a35anios++;
            }
            else
            {
                may35++;
            }
        }
    }
    contadorEdad[0] = men18anios;
    contadorEdad[1] = rango19a35anios;
    contadorEdad[2] = may35;

    return contadorEdad[0]+contadorEdad[1]+contadorEdad[2];
}
/** \brief Se encarga de graficar conjunto de datos segun rangos de edad
 *
 * \param edades, array tipo int donde se almacena el acumulador de cada rango de edad
 * \return sin retorno
 *
 */
void graficar(int edades[])
{
    int i;
    int j;
    int max = 0;

    printf("\n----------------Grafico-----------------------\n\n");

    for (i = 0; i < 3; i++)
    {
        if(edades[i] > max)
        {
            max = edades[i];
        }
    }

    for (i = max; i > 0; i--)
    {
        for (j = 0; j < 3; j++)
        {
            if(edades[j] >= i)
            {
                printf("   * ");
            }
            else
            {
                printf("     ");
            }
        }
        printf("\n");
    }
    printf("  +----+----+---\n\n");
    printf(" < 18  19-35  >35\n\n");
}
