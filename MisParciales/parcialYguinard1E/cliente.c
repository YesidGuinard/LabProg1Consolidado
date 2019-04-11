#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "funciones.h"


static int proximoId();
static int buscarLugarLibre(Cliente* clientes,int limiteC);

/** \brief Inicia  cliente array
 * \param clientes Cliente* array clientes
 * \param limiteC cantidad de elementos de array cliente
 * \return Si devuelve 0 para ok, retorna -1 si hay error
 *
 */
int cliente_init(Cliente* clientes,int limiteC)
{
    int retorno = -1;
    int i;
    if(limiteC > 0 && clientes != NULL)
    {
        retorno = 0;
        for(i=0; i<limiteC; i++)
        {
            clientes[i].isEmpty=1;
        }
    }
    return retorno;
}

/** \brief muestra todos los clientes activos
 * \param clientes Cliente* array clientes
 * \param limiteC cantidad de elementos de array cliente
 * \return Si devuelve 0 para ok, retorna -1 si hay error
 *
 */
int cliente_mostrar(Cliente* clientes,int limiteC)
{
    int retorno = -1;
    int i;
    // float promedio;
    if(limiteC > 0 && clientes != NULL)
    {
        retorno = 0;
        printf("---------LISTADO DE CLIENTES--------- \n");
        printf("-IDc\t-NOMBRE\t\t-APELLIDO\t-CUIT\n");
        for(i=0; i<limiteC; i++)
        {

            if(!clientes[i].isEmpty)
            {
                printf("%d\t%-12.12s\t%-12.12s\t%s\n",clientes[i].idCliente, clientes[i].nombre,clientes[i].apellido,
                       clientes[i].cuit);

            }


        }

    }
    return retorno;
}

/** \brief imorime cliente segun id
 * \param clientes Cliente* array clientes
 * \param limiteC cantidad de elementos de array cliente
 * \param id numero de ID cliente a consultar
 * \return Si devuelve 0 para ok, retorna -1 si hay error
 *
 */
int cliente_mostrarClientePorId(Cliente* clientes,int limiteC,int id)
{
    int retorno = -1;

    if(limiteC > 0 && clientes != NULL)
    {
        retorno = 0;
        printf("-IDc:%d\t-NOMBRE: %s\t-APELLIDO: %s\t-CUIT: %s\n",clientes[id].idCliente, clientes[id].nombre,clientes[id].apellido,clientes[id].cuit);
    }
    return retorno;
}

/** \brief alta de  cliente ingresaado por usuario
 * \param clientes Cliente* array clientes
 * \param limiteC cantidad de elementos de array cliente
 * \return Si devuelve 0 para ok, retorna -1 si hay error
 *
 */
int cliente_alta(Cliente* clientes,int limiteC)
{
    int retorno = -1;
    int i;
    char nombre[50];
    char apellido[50];
    char cuit[20];
    if(limiteC > 0 && clientes != NULL)
    {
        i = buscarLugarLibre(clientes,limiteC);
        if(i >= 0)
        {
            if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 50",nombre,50,2))
            {
                if(!getValidString("\nApellido? ","\nEso no es un Apellido","El maximo es 50",apellido,50,2))
                {
                    if(!getValidCuit("\nCuit sin guiones? ","\nEso no es un Cuit","El maximo es 11 digitos",cuit,12,2))
                    {
                        retorno = 0;
                        strcpy(clientes[i].nombre,nombre);
                        strcpy(clientes[i].apellido,apellido);
                        strcpy(clientes[i].cuit,cuit);
                        //clientes[i].cantidadPublicaciones = 0;
                        //------------------------------
                        //------------------------------
                        clientes[i].idCliente = proximoId();
                        clientes[i].isEmpty = 0;
                    }
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

/** \brief da de baja a un usuario por id
 * \param clientes Cliente* array clientes
 * \param limiteC cantidad de elementos de array cliente
  * \param id numero de ID cliente a bajar
 * \return Si devuelve 0 para ok, retorna -1 si hay error
 *
 */
int cliente_baja(Cliente* clientes,int limiteC, int id)
{
    int retorno = 0;
    int indiceAEliminar = cliente_buscarPorId(clientes, limiteC, id);
    if(indiceAEliminar>=0)
    {
        printf("\nindice a eliminar: %d\n",indiceAEliminar);
        clientes[indiceAEliminar].isEmpty = 1;
    }
    else
    {
        retorno=indiceAEliminar;
    }
    return retorno;
}

/** \brief modificacion cliente por id
 * \param clientes Cliente* array clientes
 * \param limiteC cantidad de elementos de array cliente
 * \param id numero de ID cliente a modificar
 * \return Si devuelve 0 para ok, retorna -1 si hay error
 *
 */

int cliente_modificacion(Cliente* clientes,int limiteC, int id)
{
    int retorno = -1;
    int indiceAModificar;
    char nombre[50];
    char apellido[50];
    char cuit[20];
    indiceAModificar = cliente_buscarPorId(clientes, limiteC, id);
    if(indiceAModificar>=0)
    {
        if(!getValidString("\nNuevo Nombre? ","\nEso no es un nombre","El maximo es 50",nombre,50,2))
        {
            strcpy(clientes[indiceAModificar].nombre,nombre);
            if(!getValidString("\nNuevo Apellido? ","\nEso no es un Apellido","El maximo es 50",apellido,50,2))
            {
                strcpy(clientes[indiceAModificar].apellido,apellido);

                if(!getValidCuit("Nuevo Cuit sin guiones? ","\nEso no es un Cuit\n","El maximo es 11 digitos",cuit,12,2))
                {
                    retorno=0;
                    strcpy(clientes[indiceAModificar].cuit, cuit);
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
}

/** \brief ordenar array cliente por nombre ascendente
 * \param clientes Cliente* array clientes
 * \param limiteC cantidad de elementos de array cliente
 * \param orden 0 para ascendente 1 para descendente
 * \return Si devuelve 0 para ok, retorna -1 si hay error
 *
 */
int cliente_ordenar(Cliente* clientes,int limiteC, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Cliente auxiliarEstructura;

    if(limiteC > 0 && clientes != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0; i<limiteC-1; i++)
            {
                if(!clientes[i].isEmpty && !clientes[i+1].isEmpty)
                {
                    if((strcmp(clientes[i].nombre,clientes[i+1].nombre) > 0 && orden) || (strcmp(clientes[i].nombre,clientes[i+1].nombre) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = clientes[i];
                        clientes[i] = clientes[i+1];
                        clientes[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }
        while(flagSwap);
    }
    return retorno;
}

/** \brief Busca un lugar libre en array  clientes
 * \param clientes Cliente* array clientes
 * \param limiteC cantidad de elementos de array cliente
 * \return Si devuelve 0 para ok, retorna -1 si hay error
 *
 */
static int buscarLugarLibre(Cliente* clientes,int limiteC)
{
    int retorno = -1;
    int i;
    if(limiteC > 0 && clientes != NULL)
    {
        for(i=0; i<limiteC; i++)
        {
            if(clientes[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief crea un proximo id clientes
 * \return Devuelve el numero de proximo id clientes
 *
 */
static int proximoId()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}

/** \brief Busca por cleintes Activas por id de cleintes
 * \param clientes Cliente* array clientes
 * \param limite cantidad de elementos del array  clientes
 * \param limiteC cantidad de elementos de array cliente
 * \return Si devuelve 0 para ok, retorna -1 si hay error
 *
 */
int cliente_buscarPorId(Cliente* clientes,int limiteC, int id)
{
    int retorno = -1;
    int i;
    if(limiteC > 0 && clientes != NULL)
    {
        retorno = -2;
        for(i=0; i<limiteC; i++)
        {
            if(!clientes[i].isEmpty && clientes[i].idCliente==id)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Da de alta clientes hardcode
 * \param clientes Cliente* array clientes
 * \param limiteC cantidad de elementos del array  cl
 * \param nombre del cliente
 * \param apellido del cliente
 * \param cuit  del cliente
 * \return Si devuelve 0 para ok, retorna -1 si hay error
 *
 */
int cliente_altaForzada(Cliente* clientes,int limiteC,char* nombre,char* apellido,char* cuit)
{
    int retorno = -1;
    int i;

    if(limiteC > 0 && clientes != NULL)
    {
        i = buscarLugarLibre(clientes,limiteC);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(clientes[i].nombre,nombre);
            strcpy(clientes[i].apellido,apellido);
            strcpy(clientes[i].cuit,cuit);
            //clientes[i].cantidadPublicaciones = 0;
            //------------------------------
            //------------------------------
            clientes[i].idCliente = proximoId();
            clientes[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}
