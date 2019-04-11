#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "publicacion.h"
#include "cliente.h"
#include "funciones.h"


static int proximoId();
static int buscarLugarLibre(Publicacion* publicaciones,int limite);

/** \brief inicializa array de tipo publicaciones.
 * \param publicaciones array de tipo Publicacion*
 * \param limite tamano del array publicaciones
 * \return devueve 0 para ok. y -1 para error
 *
 */
int publicacion_init(Publicacion* publicaciones,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && publicaciones != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            publicaciones[i].isEmpty=1;
        }
    }
    return retorno;
}

/** \brief Busca cliente por Id de Publicacion
 * \param Publicacion* array de publicacion
 * \param limite cantidad de elementos del array  publicaciones
 * \param id #id de publicacion a buscar
 * \return el Id del cliente correspondiente a la publicacion, retorna -1 si hay error
 *
 */
int publicacion_buscarClientePorIdDePublicacion(Publicacion* publicaciones,int limite, int id)
{
    int retorno=-1;
    if(limite>=0)
    {
        if(!publicaciones[id].isEmpty &&  publicaciones[id].idPublicacion==id)
        {
            retorno = publicaciones[id].idCliente;
        }

    }
    return retorno;
}

/** \brief Imprime publicaciones activas
 * \param Publicacion Publicacion* array de publicaciones
 * \param limite cantidad de elementos del array  publicaciones
 * \param limite_clientes cantidad de elementos del array  clientes
 * \return Si devuelve 0 para ok, retorna -1 si hay error
 *
 */
int publicacion_mostrar(Publicacion* publicaciones, Cliente* clientes,int limite, int limite_clientes)
{
    int i;
    int retorno=-1;
    int indiceCliente;
    if(limite>0)
    {
        printf("-----------LISTADO DE PUBLICACIONES ACTIVAS----------\n");
        printf("-Idpub\t-IDc\t-TEXTO\t\t\t\t-RUBRO\t-CUIT\n");
        for(i=0; i<limite; i++)
        {
            retorno = 0;
            if(publicaciones[i].estadoPub && publicaciones[i].isEmpty!=1)
            {
                // printf("%d\t%-12s\t%-12s\t%-12s\t%d\n"
                indiceCliente = cliente_buscarPorId(clientes, limite_clientes, publicaciones[i].idCliente);
                printf("%d\t%d\t%-23.23s\t\t%d\t%-12s\n", publicaciones[i].idPublicacion,clientes[indiceCliente].idCliente,
                       publicaciones[i].texto, publicaciones[i].rubro, clientes[indiceCliente].cuit);
            }
        }
    }
    printf("\n");
    return retorno;
}

/** \brief Imprime publicaciones activas
 * \param Publicacion Publicacion* array de publicaciones
 * \param limite cantidad de elementos del array  publicaciones
 * \param limite_clientes cantidad de elementos del array  clientes
 * \return Si devuelve 0 para ok, retorna -1 si hay error
 *
 */
int publicacion_mostrarInactivas(Publicacion* publicaciones, Cliente* clientes,int limite, int limite_clientes)
{
    int i;
    int retorno=-1;
    int indiceCliente;
    if(limite>0)
    {
        printf("-----------LISTADO DE PUBLICACIONES INACTIVAS----------\n");
        for(i=0; i<limite; i++)
        {
            retorno = 0;
            if(!publicaciones[i].estadoPub && publicaciones[i].isEmpty!=1)
            {
                indiceCliente = cliente_buscarPorId(clientes, limite_clientes, publicaciones[i].idCliente);
                printf("IDpub: %d - Texto: %s - Rubro: %d - Cuit Cliente: %s\t -Estado:%d\n", publicaciones[i].idPublicacion,
                       publicaciones[i].texto, publicaciones[i].rubro, clientes[indiceCliente].cuit,publicaciones[i].estadoPub);
            }
        }
    }
    printf("\n");
    return retorno;
}

/** \brief Imprime publicacione activa por id de publicacion
 * \param Publicacion Publicacion* array de publicaciones
 * \param limite cantidad de elementos del array  publicaciones
 * \param idPub numero de iDde publicacion a mostrar
 * \return Si devuelve 0 para ok, retorna -1 si hay error
 *
 */
int publicacion_mostrarPorIdPub(Publicacion* publicaciones,int limite,int idPub)
{

    int retorno=-1;

    if(limite>0)
    {

        retorno = 0;
        if(publicaciones[idPub].estadoPub && publicaciones[idPub].isEmpty!=1)
        {
            printf("IDpub: %d - Texto: %s - Rubro: %d \t -Estado:%d\n", publicaciones[idPub].idPublicacion,
                   publicaciones[idPub].texto, publicaciones[idPub].rubro,publicaciones[idPub].estadoPub);
        }

    }
    printf("\n");
    return retorno;
}

/** \brief Imprime publicacione activa por id de cliente
 * \param Publicacion Publicacion* array de publicaciones
 * \param clientes Cliente* array de clientes
 * \param limite cantidad de elementos del array  publicaciones
 * \param limite_clientes cantidad de elementos del array  clientes
 * \param idCliente numero de iD de cliente a mostrar
 * \return Si devuelve 0 para ok, retorna -1 si hay error
 *
 */
int publicacion_mostrarPorIdCliente(Publicacion* publicaciones, Cliente* clientes,int limite, int limite_clientes,int idCliente)
{
    int i;
    int j;
    int retorno=-1;
    if(limite>0)
    {
        j=0;
        retorno = 0;
        printf("\nPUBLICACIONES CLIENTE:\n");
        printf("-IDpub\t-IDc\t-TEXTO\t\t\t\t-RUBRO\t-ESTADO Pub\n");
        for(i=0; i<limite; i++)
        {
            if(!publicaciones[i].isEmpty && publicaciones[i].idCliente==idCliente)
            {
                printf("%d\t%d\t%-23.23s\t\t%d\t%d\n", publicaciones[i].idPublicacion,
                       clientes[idCliente].idCliente, publicaciones[i].texto, publicaciones[i].rubro, publicaciones[i].estadoPub);
                j++;
                retorno=j;
            }
        }
    }
    return retorno;
}

/** \brief Alta de una publicacion
 * \param Publicacion* publicaciones array de publicaciones
 * \param clientes Cliente* array de clientes
 * \param limite cantidad de elementos del array  publicaciones
 * \param limite_clientes cantidad de elementos del array  clientes
 * \return Si devuelve 0 para ok, retorna -1 si hay error
 *
 */
int publicacion_alta(Publicacion* publicaciones, Cliente* clientes,int limite, int limiteC)
{
    int retorno = -1;
    int idCliente, rubro;
    int i;
    char texto[64];

    if(limite > 0 && publicaciones != NULL)
    {
        i = buscarLugarLibre(publicaciones,limite);
        if(i >= 0)
        {
            if(!getValidInt("\nId del usuario? ","\nEso no es un id",&idCliente,0,1000,2))
            {
                if(cliente_buscarPorId(clientes, limiteC, idCliente)>=0)
                {
                    if(!getValidAlfanumerico("\nTexto de Publicacion? ","\nEso no es un texto valido","El maximo es 64",texto,64,2))
                    {

                        if(!getValidInt("\nRubro [0-999]?", "\nRubro no valido[0-999]", &rubro,0,999,2))
                        {
                            retorno = 0;
                            publicaciones[i].idCliente = idCliente;
                            strcpy(publicaciones[i].texto,texto);
                            publicaciones[i].rubro = rubro;

                            //------------------------------
                            //------------------------------
                            publicaciones[i].idPublicacion = proximoId();
                            publicaciones[i].isEmpty = 0;
                            publicaciones[i].estadoPub = 1;
                            publicacion_mostrarPorIdPub(publicaciones,limite, publicaciones[i].idPublicacion);
                        }

                    }
                }
            }
        }
    }
    else
    {
        retorno = -3;
    }
    return retorno;
}

/** \brief Alta de una publicacion cliente
 * \param Publicacion* publicaciones array de publicaciones
 * \param clientes Cliente* array de clientes
 * \param limite cantidad de elementos del array  publicaciones
 * \param limite_clientes cantidad de elementos del array  clientes
 * \return Si devuelve 0 para ok, retorna -1 si hay error
 *
 */
int publicacion_bajaPorIdCliente(Publicacion* publicaciones, int limite, int idCliente)
{
    int retorno = 0;
    int i;
    for(i=0; i<limite; i++)
    {
        if(!publicaciones[i].isEmpty && publicaciones[i].idCliente==idCliente)
        {
            publicaciones[i].isEmpty=1;
        }
    }
    return retorno;
}

/** \brief Baja de una publicacion por idPub
 * \param Publicacion* publicaciones array de publicaciones
 * \param limite cantidad de elementos del array  publicaciones
 * \return Si devuelve 0 para ok, retorna -1 si hay error
 *
 */
int publicacion_baja(Publicacion* publicaciones,int limite, int id)
{
    int retorno = -1;
    int indiceAEliminar = publicacion_buscarPorId(publicaciones, limite, id);
    if(indiceAEliminar>=0)
    {
        publicaciones[indiceAEliminar].isEmpty = 1;
        retorno=0;
    }

    return retorno;
}

/** \brief Pausa de una publicacion por idPub
 * \param Publicacion* publicaciones array de publicaciones
 * \param limite cantidad de elementos del array  publicaciones
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int publicacion_pausa(Publicacion* publicaciones,int limite, int id)
{
    int retorno = -1;
    int indiceAEliminar = publicacion_buscarPorId(publicaciones, limite, id);
    if(indiceAEliminar>=0)
    {
        publicaciones[indiceAEliminar].estadoPub = 0;
        retorno=indiceAEliminar;
    }
    return retorno;
}

/** \brief Reanudar de una publicacion por idPub
 * \param Publicacion* publicaciones array de publicaciones
 * \param limite cantidad de elementos del array  publicaciones
 * \return Si devuelve 0 para ok, retorna -1 si hay error
 *
 */
int publicacion_reanudar(Publicacion* publicaciones,int limite, int id)
{
    int retorno = 0;
    int indiceAreanudar = publicacion_buscarInactivaPorId(publicaciones, limite, id);
    if(indiceAreanudar>=0)
    {
        retorno = 0;
        publicaciones[indiceAreanudar].estadoPub = 1;

    }
    else
    {
        retorno=indiceAreanudar;
    }
    return retorno;
}

/** \brief ordena de una publicacion por nombre ascendente
 * \param Publicacion* publicaciones array de publicaciones
 * \param limite cantidad de elementos del array  publicaciones
 * \return Si devuelve 0 para ok, retorna -1 si hay error
 *
 */
int publicacion_ordenar(Publicacion* publicaciones,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Publicacion auxiliarEstructura;

    if(limite > 0 && publicaciones != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0; i<limite-1; i++)
            {
                if(!publicaciones[i].isEmpty && !publicaciones[i+1].isEmpty)
                {
                    if((strcmp(publicaciones[i].nombre,publicaciones[i+1].nombre) > 0 && orden) || (strcmp(publicaciones[i].nombre,publicaciones[i+1].nombre) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = publicaciones[i];
                        publicaciones[i] = publicaciones[i+1];
                        publicaciones[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }
        while(flagSwap);
    }
    return retorno;
}

/** \brief ordena de una publicacion por id de cliente ascendente
 * \param Publicacion* publicaciones array de publicaciones
 * \param limite cantidad de elementos del array  publicaciones
 * \return Si devuelve 0 para ok, retorna -1 si hay error
 *
 */
int publicacion_ordenarPorIdCliente(Publicacion* publicaciones,int limite)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Publicacion auxiliarEstructura;

    if(limite > 0 && publicaciones != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0; i<limite-1; i++)
            {
                if(!publicaciones[i].isEmpty && !publicaciones[i+1].isEmpty)
                {
                    if(publicaciones[i].idCliente > publicaciones[i+1].idCliente)
                    {
                        auxiliarEstructura = publicaciones[i];
                        publicaciones[i] = publicaciones[i+1];
                        publicaciones[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }
        while(flagSwap);
    }
    return retorno;
}

/** \brief Busca un lugar libre en array  publicaciones
 * \param publicaciones array de publicaciones
 * \param limite cantidad de elementos del array  publicaciones
 * \return Si devuelve 0 para ok, retorna -1 si hay error
 *
 */
static int buscarLugarLibre(Publicacion* publicaciones,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && publicaciones != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(publicaciones[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief crea un proximo id
 * \return Devuelve el numero de proximo id
 *
 */
static int proximoId()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}

/** \brief Busca por Publicacion Activas por id de Publicacion
 * \param publicaciones array de publicaciones
 * \param limite cantidad de elementos del array  publicaciones
 * \param id numero de la publicacion a buscar
 * \return Si devuelve 0 para ok, retorna -1 si hay error
 *
 */
int publicacion_buscarPorId(Publicacion* publicaciones,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && publicaciones != NULL)
    {
        retorno = -2;
        for(i=0; i<limite; i++)
        {
            if(!publicaciones[i].isEmpty && publicaciones[i].idPublicacion==id)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca por Publicacion Inactivas por id de Publicacion
 * \param publicaciones array de publicaciones
 * \param limite cantidad de elementos del array  publicaciones
 * \param id numero de la publicacion a buscar
 * \return Si devuelve 0 para ok, retorna -1 si hay error
 *
 */
int publicacion_buscarInactivaPorId(Publicacion* publicaciones,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && publicaciones != NULL)
    {
        retorno = -2;
        for(i=0; i<limite; i++)
        {
            if(!publicaciones[i].isEmpty && publicaciones[i].idPublicacion==id && publicaciones[i].estadoPub==0)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Da de alta publicaciones harcode
 * \param Publicacion* publicaciones array de publicaciones
 * \param clientes Cliente* array de clientes
 * \param limite cantidad de elementos del array  publicaciones
 * \param limite_clientes cantidad de elementos del array  clientes
 * \param  idCliente id  cliente
 * \param  rubro numero de rubro de  publicacion
 * \param  texto texto de publicacion
 * \return Si devuelve 0 para ok, retorna -1 si hay error
 *
 */
int publicacion_altaForzada(Publicacion* publicaciones,int limite,int idCliente,int rubro,char* texto)
{
    int retorno = -1;
    int i;

    if(limite > 0 && publicaciones != NULL)
    {
        i = buscarLugarLibre(publicaciones,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(publicaciones[i].texto,texto);
            publicaciones[i].idCliente=idCliente;
            publicaciones[i].rubro = rubro;
            //------------------------------
            //------------------------------
            publicaciones[i].idPublicacion = proximoId();
            publicaciones[i].isEmpty = 0;
            publicaciones[i].estadoPub = 1;
        }
        retorno = 0;
    }
    return retorno;
}
