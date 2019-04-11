#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "publicacion.h"
#include "funciones.h"
#include "reporte.h"
#define LEN_CLIENT 100
#define LEN_PUB 1000

int main()
{
    Cliente clientes[LEN_CLIENT];
    Publicacion publicaciones[LEN_PUB];

    int menu;
    int auxiliarId;
    int auxiliarIdCliente;

    publicacion_init(publicaciones, LEN_PUB);
    cliente_init(clientes,LEN_CLIENT);

    cliente_altaForzada(clientes,LEN_CLIENT,"Pedro","Sanchez","20123456784");
    cliente_altaForzada(clientes,LEN_CLIENT,"Adrian","Silva","20802032531");
    cliente_altaForzada(clientes,LEN_CLIENT,"Walter","Escuer","20957772154");
    cliente_altaForzada(clientes,LEN_CLIENT,"Liliana","Marin","20123456783");
    cliente_altaForzada(clientes,LEN_CLIENT,"Olga","Escuer","20123456724");
    cliente_altaForzada(clientes,LEN_CLIENT,"Macarena","Silva","20802034531");
    cliente_altaForzada(clientes,LEN_CLIENT,"Dario","Rodriguez","20957772554");
    cliente_altaForzada(clientes,LEN_CLIENT,"Matias","Gutierrez","20623456783");
    cliente_altaForzada(clientes,LEN_CLIENT,"Olga2","Escuer","20123456724");
    cliente_altaForzada(clientes,LEN_CLIENT,"Macarena3","Silva","20802034531");
    cliente_altaForzada(clientes,LEN_CLIENT,"Dario4","Rodriguez","20957772554");
    cliente_altaForzada(clientes,LEN_CLIENT,"Matias5","Gutierrez","20623456783");

    publicacion_altaForzada(publicaciones,LEN_PUB,0,0, "Se vende casa en Bernal");
    publicacion_altaForzada(publicaciones,LEN_PUB,0,0, "Alquiler de Motos y Vehiculos");
    publicacion_altaForzada(publicaciones,LEN_PUB,1,0, "Venta de Auto 100.000km");
    publicacion_altaForzada(publicaciones,LEN_PUB,1,1, "Se cuidan ninos");
    publicacion_altaForzada(publicaciones,LEN_PUB,2,1, "Se vende casa en wilde");
    publicacion_altaForzada(publicaciones,LEN_PUB,3,1, "Alquiler de departamentos");
    publicacion_altaForzada(publicaciones,LEN_PUB,4,3, "Venta de casa");
    publicacion_altaForzada(publicaciones,LEN_PUB,5,4, "Se vende computador");

    do
    {
        getValidInt("\n1.Alta Cliente\n2.Modificar usuario\n3.Baja Cliente\n4.Publicar Aviso\n5.Pausar Publicacion\n6.Activar Publicacion\n7.Imprimir Clientes\n8.Imprimir Publicaciones\n9.Informar Clientes\n10.Informar Publicaciones\n11.Informar Rubros\n12.Salir\n","\n Opcion no valida\n",&menu,1,12,1);
        switch(menu)
        {
        case 1://ALTA CLIENTE
            if(!cliente_alta(clientes,LEN_CLIENT))
            {
                printf("\nCliente dado de alta Exitosamente\n");
            }
            else
            {
                printf("\nError. Fallo alta cliente\n");
            }
            break;
        case 2:
            cliente_mostrar(clientes, LEN_CLIENT);

            if(!getValidInt("ID? de usuario a modificar \n","\nError. Por favor ingrese un Numero valido \n",&auxiliarId,0,9999,2))
            {
                if(!cliente_modificacion(clientes,LEN_CLIENT,auxiliarId))
                {
                    printf("\nCliente Modificado Exitosamente\n");
                }
                else
                {
                    printf("\nError. Fallo modificacion cliente\n");
                }
            }
            break;
        case 3:
            cliente_mostrar(clientes, LEN_CLIENT);

            if(!getValidInt("ID? de usuario a dar de baja\n","\nError. Por favor ingrese un Numero valido\n",&auxiliarId,0,9999,2))
            {
                if(cliente_buscarPorId(clientes,LEN_CLIENT,auxiliarId)>=0)
                {
                    auxiliarIdCliente=publicacion_mostrarPorIdCliente(publicaciones,clientes,LEN_PUB,LEN_CLIENT,auxiliarId);

                    if(auxiliarIdCliente==0)
                    {
                        printf("Cliente Sin Publicaciones\n");
                    }

                    if(getChar("\nPara confirmar eliminacion de cliente y todas sus Publicaciones [s]")=='s')
                    {

                        if(!cliente_baja(clientes,LEN_CLIENT,auxiliarId))
                        {
                            publicacion_bajaPorIdCliente(publicaciones, LEN_PUB, auxiliarId);
                            printf("Cliente Eliminado Exitosamente\n");
                        }

                    }
                    else
                    {
                        printf("Se cancelo eliminacion cliente\n");
                    }

                }
                else
                {
                    printf("* Error!.Id Cliente invalido.\n");
                }
            }
            break;
        case 4:
            cliente_mostrar(clientes, LEN_CLIENT);
            if( !publicacion_alta(publicaciones, clientes, LEN_PUB, LEN_CLIENT))
            {
                printf("Publicacion Exitosa!.\n");
            }
            else
            {
                printf("\nError Usuario no encontrado\n");
            }
            break;
        case 5:
            publicacion_mostrar(publicaciones, clientes, LEN_PUB, LEN_CLIENT);

            if(!getValidInt("idPublicacion a pausar?\n","\nNo es un id valido\n", &auxiliarId, 0, 1000,2))
            {
                if(publicacion_buscarPorId(publicaciones, LEN_PUB, auxiliarId)==auxiliarId)// publicacion existe
                {
                    auxiliarIdCliente = publicacion_buscarClientePorIdDePublicacion(publicaciones, LEN_PUB, auxiliarId);//retorna id cliente
                    printf("Id cliente Asociado:\n");
                    cliente_mostrarClientePorId(clientes,LEN_CLIENT,auxiliarIdCliente);
                    if(getChar("\nPara confirmar pausar la Publicacion [s]")=='s')
                    {
                        if(!publicacion_pausa(publicaciones, LEN_PUB, auxiliarId))
                        {
                            printf("Publicacion Pausada Exitosamente\n");
                        }
                    }
                    else
                    {
                        printf("Se cancelo Pausa publicacion\n");
                    }
                }
                else
                {
                    printf("Id de Publicacion Invalida\n");

                }

            }

            break;
        case 6:
            publicacion_mostrarInactivas(publicaciones,clientes,LEN_PUB,LEN_CLIENT);
            if(!getValidInt("idPublicacion a ReActivar?\n","\nNo es un id valido\n", &auxiliarId, 0, 1000,2))
            {
                if(publicacion_buscarInactivaPorId(publicaciones, LEN_PUB, auxiliarId)==auxiliarId)// publicacion existe
                {
                    auxiliarIdCliente = publicacion_buscarClientePorIdDePublicacion(publicaciones, LEN_PUB, auxiliarId);//retorna id cliente
                    printf("Id cliente Asociado:\n");
                    cliente_mostrarClientePorId(clientes,LEN_CLIENT,auxiliarIdCliente);
                    if(getChar("\nPara confirmar Reactivar la Publicacion [s]")=='s')
                    {
                        if(!publicacion_reanudar(publicaciones, LEN_PUB, auxiliarId))
                        {
                            printf("Publicacion Reactivada Exitosamente\n");
                        }
                    }
                    else
                    {
                        printf("Se cancelo Reactivacion publicacion\n");
                    }
                }
                else
                {
                    printf("Id de Publicacion Invalida\n");
                }

            }
            break;
        case 7:
            reporte_mostrarPublicacionesActivas(clientes,publicaciones,LEN_CLIENT,LEN_PUB);
            break;
        case 8:
            publicacion_mostrar(publicaciones, clientes, LEN_PUB, LEN_CLIENT);
            break;
        case 9:
            printf("\n9a) El cliente con mas publicaciones activas: ");
            reporte_masPublicacionesActivas(clientes,publicaciones,LEN_CLIENT,LEN_PUB);
            printf("\n9b) El cliente con mas publicaciones Pausadas: ");
            reporte_clienteConMasPublicacionesPausadas(clientes,publicaciones,LEN_CLIENT,LEN_PUB);
            printf("\n9c) El cliente con mas publicaciones en total: ");
            reporte_clienteConMasPublicaciones(clientes,publicaciones,LEN_CLIENT,LEN_PUB);
            break;
        case 10:
            if(!getValidInt("\nRubro a consultar[0-999]? ","\nError! rubro no valido[0-999]\n",&auxiliarId,0,999,1))
            {
                reporte_cantDePublicacionesPorRubro(publicaciones,LEN_PUB,auxiliarId);
            }
            break;
        case 11:
            printf("\n11b) El Rubro con mas publicaciones Activas: ");
            reporte_rubroDeMasPublicaciones(publicaciones,LEN_PUB);
            printf("\n11c) El Rubro con menos publicaciones Activas: ");
            reporte_rubroDeMenosPublicaciones(publicaciones,LEN_PUB);
            break;
        }

    }
    while(menu != 12);

    return 0;
}
