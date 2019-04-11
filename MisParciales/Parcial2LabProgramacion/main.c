#include <stdio.h>
#include <stdlib.h>
#include "Venta.h"
#include "LinkedList.h"
#include "Parser.h"
#include "funciones_yg.h"


int generarArchivoInforme(char* path,LinkedList* listaVentas);

int main()
{
    LinkedList* listaVentas;
    listaVentas = ll_newLinkedList();

    // Leer compras de archivo data.csv
    if(parser_parseVentas("data.csv",listaVentas)==1)
    {
        printf("\n * Ventas Cargadas de data.csv *");
        printf("\n ID_Venta,Fecha_Venta,Codigo_Producto,Cantidad,Precio_Unitario,CUIT_Cliente");
        ll_map(listaVentas,Venta_printVenta,NULL);

        if(generarArchivoInforme("informes.txt",listaVentas)==1)
        {
            printf("\nArchivo generado correctamente\n");
        }
        else
            printf("\nError generando archivo\n");
    }
    else
        printf("\nError leyendo Ventas\n");


    return 0;
}

int generarArchivoInforme(char* path,LinkedList* listaVentas)
{
    int retorno =-1;
    int cantidadDeVentasTotalesP1 ;
    int cantidadDeVentasTotalesP2;
    int cantidadDeVentasTotalesP3;
    int cantidadDeVentasTotalesP4;


    cantidadDeVentasTotalesP1 = ll_count(listaVentas,VentaCountP1) ;
    printf("\n Cantidad de unidades Totales= %i",cantidadDeVentasTotalesP1);

    cantidadDeVentasTotalesP2 = ll_count(listaVentas,VentaCountP2) ;
    printf("\n Cantidad de ventas monto mayor a $10000= %i",cantidadDeVentasTotalesP2);

    cantidadDeVentasTotalesP3 = ll_count(listaVentas,VentaCountP3) ;
    printf("\n Cantidad de ventas monto mayor a $20000= %i",cantidadDeVentasTotalesP3);

    cantidadDeVentasTotalesP4 = ll_count(listaVentas,VentaCountP4) ;
    printf("\n Cantidad de TV_LCD = %i",cantidadDeVentasTotalesP4);


    if(path!=NULL && listaVentas!=NULL)
    {

        FILE* pArchivoInforme;

        pArchivoInforme = fopen(path,"w");

        if(pArchivoInforme!=NULL )
        {

            fprintf(pArchivoInforme, "**************\n");
            fprintf(pArchivoInforme, "Informe Ventas\n");
            fprintf(pArchivoInforme, "**************\n");
            fprintf(pArchivoInforme, "Cantidad de Unidades vendidas Totales: %i\n",cantidadDeVentasTotalesP1);
            fprintf(pArchivoInforme, "Cantidad de Ventas por Monto mayor a 10000: %i\n",cantidadDeVentasTotalesP2);
            fprintf(pArchivoInforme, "Cantidad de Ventas por Monto mayor a 20000: %i\n",cantidadDeVentasTotalesP3);
            fprintf(pArchivoInforme, "Cantidad de Unidades TV LCD vendidas : %i\n",cantidadDeVentasTotalesP4);
            retorno = 1;
            fclose(pArchivoInforme);
        }
    }
    return retorno;
}
