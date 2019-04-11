#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "publicacion.h"
#include "funciones.h"
#include "reporte.h"

/** \brief ordena de una publicacion por id de cliente ascendente
 * \param Publicacion* publicaciones array de publicaciones
 * \param limiteP cantidad de elementos del array  publicaciones
 * \param idC cantidad de elementos del array  clientes
 * \return Si devuelve 0 para ok, retorna -1 si hay error
 *
 */
int reporte_ordenarIdCliente(Publicacion* publicaciones,int limiteP,int idC)
{
    int i;
    int publicacionesActivas = 0;
    for(i=0; i<limiteP; i++)
    {
        publicacion_ordenarPorIdCliente(publicaciones,limiteP);
        if(!publicaciones[i].isEmpty)
        {
            if(publicaciones[i].idCliente == idC)
            {
                if(publicaciones[i].estadoPub == 1)
                {
                    publicacionesActivas ++;
                }
            }
        }
    }
    return publicacionesActivas;
}
/** \brief imprime listado de clientes con publicaciones activas
 * \param Cliente* clientes array de clientes
 * \param Publicacion* publicaciones array de publicaciones
 * \param limiteC cantidad de elementos del array  clientes
 * \param limiteP cantidad de elementos del array  publicaciones
 * \return Si devuelve 0 para ok, retorna -1 si hay error
 *
 */
int reporte_mostrarPublicacionesActivas(Cliente* clientes,Publicacion* publicaciones,int limiteC,int limiteP)
{
    int retorno = -1;
    int i,publicacionesActivas;

    if((limiteC > 0 && clientes != NULL) && (limiteP > 0 && publicaciones != NULL))
    {
        retorno = 0;
        printf("---------LISTADO DE CLIENTES--------- \n");
        printf("-IDc\t-NOMBRE\t\t-APELLIDO\t-CUIT\t\t-PUBLICACIONES\n");
        for(i=0; i<limiteC; i++)
        {
            if(!clientes[i].isEmpty)
            {
                publicacionesActivas = reporte_ordenarIdCliente(publicaciones,limiteP,clientes[i].idCliente);
                printf("%d\t%-12s\t%-12s\t%-12s\t%d\n",clientes[i].idCliente,clientes[i].nombre,clientes[i].apellido,clientes[i].cuit,publicacionesActivas);
                //printf("\n");
            }
        }
    }
    return retorno;
}
/** \brief imprime cliente o clientes con mas publicaciones activas
 * \param Cliente* clientes array de clientes
 * \param Publicacion* publicaciones array de publicaciones
 * \param limiteC cantidad de elementos del array  clientes
 * \param limiteP cantidad de elementos del array  publicaciones
 * \return Si devuelve indiceClienteMaximo
 *
 */
int reporte_masPublicacionesActivas(Cliente* clientes,Publicacion* publicaciones,int limiteC,int limiteP)
{
    int i;
    int PubActivas;
    int maximoPublicaciones = -1;
    int indiceClienteMaximo = -1;

    if((limiteC > 0 && clientes != NULL) && (limiteP > 0 && publicaciones != NULL))
    {
        for(i=0; i<limiteC; i++)
        {
            if(!clientes[i].isEmpty)
            {
                PubActivas = reporte_ordenarIdCliente(publicaciones,limiteP,clientes[i].idCliente);
                if(maximoPublicaciones < PubActivas)
                {
                    maximoPublicaciones = PubActivas;
                    indiceClienteMaximo = i;
                }
            }
        }

        if(maximoPublicaciones > 0)
        {


            printf("%d\tes:\n",maximoPublicaciones);
            cliente_mostrarClientePorId(clientes,100,indiceClienteMaximo);
        }
        else
        {
            printf("\nNo hay publicaciones activas!\n");
        }
    }

    return indiceClienteMaximo;
}
/** \brief busca en array publicaciones Publicaciones pausadas por Id Cliente
 * \param Publicacion* publicaciones array de publicaciones
 * \param Cliente* clientes array de clientes
 * \param limiteP cantidad de elementos del array  publicaciones
 * \param idC cantidad de elementos del array  clientes
 * \return Si devuelve publicacionesPausadas
 *
 */
int reporte_publicacionesPausadas(Publicacion* publicaciones,int limiteP,int idCliente)
{
    int i;
    int publicacionesPausadas = 0;
    for(i=0; i<limiteP; i++)
    {
        publicacion_ordenarPorIdCliente(publicaciones,limiteP);
        if(!publicaciones[i].isEmpty)
        {
            if(publicaciones[i].idCliente == idCliente)
            {
                if(publicaciones[i].estadoPub == 0)
                {
                    publicacionesPausadas ++;
                }
            }
        }
    }
    return publicacionesPausadas;
}
/** \brief compara clientes con mas publicaciones pausadas
 * \param Publicacion* publicaciones array de publicaciones
 * \param limiteP cantidad de elementos del array  publicaciones
 * \param limiteC cantidad de elementos del array  clientes
 * \return Si devuelve indiceClienteMaximo
 *
 */
int reporte_clienteConMasPublicacionesPausadas(Cliente* clientes,Publicacion* publicaciones,int limiteC,int limiteP)
{
    int i;
    int publicacionesPausadas;
    int maximoPublicaciones = -1;
    int indiceClienteMaximo = -1;

    if((limiteC > 0 && clientes != NULL) && (limiteP > 0 && publicaciones != NULL))
    {
        for(i=0; i<limiteC; i++)
        {
            if(!clientes[i].isEmpty)
            {
                publicacionesPausadas = reporte_publicacionesPausadas(publicaciones,limiteP,clientes[i].idCliente);
                if(maximoPublicaciones < publicacionesPausadas)
                {
                    maximoPublicaciones = publicacionesPausadas;
                    indiceClienteMaximo = i;
                }
            }
        }

        if(maximoPublicaciones > 0)
        {
            printf("%d\tes:\n",maximoPublicaciones);
            cliente_mostrarClientePorId(clientes,100,indiceClienteMaximo);
        }
        else
        {
            printf("\nNo hay publicaciones pausadas!\n");
        }
    }


    return indiceClienteMaximo;
}

/** \brief calcula total publicaciones por Id de cliente
 * \param Publicacion* publicaciones array de publicaciones
 * \param limiteP cantidad de elementos del array  publicaciones
 * \param idC cantidad de elementos del array  clientes
 * \return Si devuelve publicacionesPausadas
 *
 */
int cliente_total_publicaciones(Publicacion* publicaciones,int limiteP,int idCliente)
{
    int i;
    int cantTotalPublicaciones = 0;
    for(i=0; i<limiteP; i++)
    {
        publicacion_ordenarPorIdCliente(publicaciones,limiteP);
        if(!publicaciones[i].isEmpty)
        {
            if(publicaciones[i].idCliente == idCliente)
            {
                cantTotalPublicaciones ++;
            }
        }
    }
    return cantTotalPublicaciones;
}

/** \brief busca en array publicaciones el cliente con mas publicaciones
 * \param Publicacion* publicaciones array de publicaciones
 * \param Cliente* clientes array de clientes
 * \param limiteP cantidad de elementos del array  publicaciones
 * \param idC cantidad de elementos del array  clientes
 * \return Si devuelve publicacionesPausadas
 *
 */
int reporte_clienteConMasPublicaciones(Cliente* clientes,Publicacion* publicaciones,int limiteC,int limiteP)
{
    int i;
    int publicacionesCntCliente;
    int maximoPublicaciones = -1;
    int indiceClienteMaximo = -1;

    if((limiteC > 0 && clientes != NULL) && (limiteP > 0 && publicaciones != NULL))
    {
        for(i=0; i<limiteC; i++)
        {
            if(!clientes[i].isEmpty)
            {
                publicacionesCntCliente = cliente_total_publicaciones(publicaciones,limiteP,clientes[i].idCliente);
                if(maximoPublicaciones < publicacionesCntCliente)
                {
                    maximoPublicaciones = publicacionesCntCliente;
                    indiceClienteMaximo = i;
                }
            }
        }
        if(maximoPublicaciones > 0)
        {
            printf("%d\tes:\n",maximoPublicaciones);
            cliente_mostrarClientePorId(clientes,100,indiceClienteMaximo);
        }
        else
        {
            printf("\nNo hay publicaciones\n");
        }
    }
    return indiceClienteMaximo;
}

int reporte_ordenarPublicacionPorNumeroDeRubro(Publicacion* publicaciones,int limiteP)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Publicacion auxiliarPublicacion;

    if(limiteP > 0 && publicaciones != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limiteP-1;i++)
            {
                if(!publicaciones[i].isEmpty && !publicaciones[i+1].isEmpty)
                {
                    if(publicaciones[i].rubro > publicaciones[i+1].rubro)
                    {
                        auxiliarPublicacion = publicaciones[i];
                        publicaciones[i] = publicaciones[i+1];
                        publicaciones[i+1] = auxiliarPublicacion;
                        flagSwap = 1;
                        retorno = 0;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

int reporte_publicacionesActivasPorRubro(Publicacion* publicaciones,int limiteP,int numRubro)
{
    int i;
    int publicacionesActivas = 0;
    for(i=0;i<limiteP;i++)
    {
        reporte_ordenarPublicacionPorNumeroDeRubro(publicaciones,limiteP);
        if(!publicaciones[i].isEmpty)
        {
            if(publicaciones[i].rubro == numRubro)
            {
                if(publicaciones[i].estadoPub == 1)
                {
                    publicacionesActivas ++;
                }
            }
        }
    }
    return publicacionesActivas;
}

int reporte_rubroDeMasPublicaciones(Publicacion* publicaciones, int limiteP)
{
    int retorno = -1;
    int i;
    int numeroDeRubro;
    int numeroDeRubroMayor = -1;
    int pubActivas = 0;
    int maximoActivas = 0;
    int flag = 0;

    if(limiteP > 0 && publicaciones != NULL)
    {
        for(i=0;i<limiteP;i++)
        {
            if(!publicaciones[i].isEmpty)
            {
                if(publicaciones[i].estadoPub == 1)
                {
                    numeroDeRubro = publicaciones[i].rubro;
                    pubActivas = reporte_publicacionesActivasPorRubro(publicaciones,limiteP,numeroDeRubro);
                    if(flag == 0)
                    {
                        maximoActivas = pubActivas;
                        flag = 1;
                    }
                    else
                    {
                        if(maximoActivas < pubActivas)
                        {
                            maximoActivas = pubActivas;
                        }
                    }
                }
            }
        }
        if(maximoActivas > 0)
        {
            for(i=0;i<limiteP;i++)
            {
                if(!publicaciones[i].isEmpty)
                {
                    if(publicaciones[i].estadoPub == 1)
                    {
                        numeroDeRubro = publicaciones[i].rubro;
                        pubActivas = reporte_publicacionesActivasPorRubro(publicaciones,limiteP,numeroDeRubro);
                        if(maximoActivas == pubActivas && numeroDeRubroMayor != numeroDeRubro)
                        {
                            numeroDeRubroMayor = numeroDeRubro;
                            printf("\nRubro:%d\t #de Pub=%d",numeroDeRubro,pubActivas);
                        }
                    }
                }
            }
            printf("\n");
        }
        else
        {
            printf("\n\tSin publicaciones Activas!\n");
        }
        retorno = 0;
    }
    return retorno;
}

int reporte_rubroDeMenosPublicaciones(Publicacion* publicaciones, int limiteP)
{
   int retorno = -1;
    int i, numeroDeRubro;
    int numeroDeRubroMenor = -1;
    int pubActivas = 0;
    int minimoActivas = 0;
    int flag = 0;

    if(limiteP > 0 && publicaciones != NULL)
    {
        for(i=0;i<limiteP;i++)
        {
            if(!publicaciones[i].isEmpty)
            {
                if(publicaciones[i].estadoPub == 1)
                {
                    numeroDeRubro = publicaciones[i].rubro;
                    pubActivas = reporte_publicacionesActivasPorRubro(publicaciones,limiteP,numeroDeRubro);
                    if(flag == 0)
                    {
                        minimoActivas = pubActivas;
                        flag = 1;
                    }
                    else
                    {
                        if(minimoActivas > pubActivas)
                        {
                            minimoActivas = pubActivas;
                        }
                    }
                }
            }
        }
        if(minimoActivas > 0)
        {
            for(i=0;i<limiteP;i++)
            {
                if(!publicaciones[i].isEmpty)
                {
                    if(publicaciones[i].estadoPub == 1)
                    {
                        numeroDeRubro = publicaciones[i].rubro;
                        pubActivas = reporte_publicacionesActivasPorRubro(publicaciones,limiteP,numeroDeRubro);
                        if(minimoActivas == pubActivas && numeroDeRubroMenor != numeroDeRubro)
                        {
                            numeroDeRubroMenor = numeroDeRubro;
                            printf("\nRubro:%d\t #de Pub=%d",numeroDeRubro,pubActivas);
                        }
                    }
                }
            }
            printf("\n");
        }
        else
        {
            printf("\n\tSin publicaciones activas!\n");
        }
        retorno = 0;
    }
    return retorno;
}

int reporte_cantDePublicacionesPorRubro(Publicacion* publicaciones, int limiteP, int numeroDeRubro)
{
    int retorno = -1;
    int i;
    int publicacionesActivas = 0;

    if(limiteP > 0 && publicaciones != NULL)
    {

            for(i=0;i<limiteP;i++)
            {
                if(publicaciones[i].rubro == numeroDeRubro)
                {
                    if(publicaciones[i].estadoPub == 1)
                    {
                        publicacionesActivas ++;
                    }
                }
            }
            retorno = 0;
            printf("Rubro:%d\tPublicaciones Activas:%d\n",numeroDeRubro,publicacionesActivas);

    }
    return retorno;
}
