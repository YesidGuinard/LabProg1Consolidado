#include "LinkedList.h"
#include "Venta.h"
#include "funciones_yg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

/** \brief
 *
 * \param filename char*
 * \param pVentaList LinkedList*
 * \return int
 *
 */
int parser_parseVentas(char* filename, LinkedList* pVentaList)
{
    int retorno =-1;

    char* p;
    const char* delim=",";
    char* token;
    char line[128];
    FILE *pFile;

    if(filename!=NULL && pVentaList!=NULL)
    {

        pFile = fopen(filename, "r");

        //printf("\npFile:%p=",pFile);
        //  printf("\nfilename:%s=",filename);
        if(pFile!= NULL )
        {
            S_Venta* pVentaAux = NULL;
            int IdVenta;
            char IdVentaChar[128];

            char fechaVenta[128];
            char codigoProducto[128];

            int cantidad;
            char cantidadChar[128];

            float precio_Unitario;
            char precio_UnitarioChar[128];

            char CuitCliente[128];

            int contadorVentas=0;
            fgets(line,128,pFile);

            while(1)
            {
                // leo linea
                p = fgets(line,128,pFile);
                if(p==NULL)
                    break;
             //   printf("%s",line);

                token = strtok(line,delim);
                strcpy(IdVentaChar,token);
                strcpy(fechaVenta,strtok(NULL,delim));
                strcpy(codigoProducto,strtok(NULL,delim));
                strcpy(cantidadChar,strtok(NULL,delim));
                strcpy(precio_UnitarioChar,strtok(NULL,delim));
                strcpy(CuitCliente,strtok(NULL,delim));
                IdVenta = atoi(IdVentaChar);
                cantidad = atoi(cantidadChar);
                precio_Unitario = atof(precio_UnitarioChar);

               //  printf("\n%s",CuitCliente);

                pVentaAux = (S_Venta*)Venta_newConParametros(IdVenta,fechaVenta,codigoProducto,cantidad,precio_Unitario,CuitCliente);

                if(pVentaAux != NULL)
                {
                    ll_add(pVentaList,pVentaAux);
                    contadorVentas++;
                }
                else
                {
                   printf("\n No se puede Agregar Venta IDp: %s\n",IdVentaChar);
                }

            }

            fclose(pFile);
            printf("\n Se Cargaron: %i Ventas\n",contadorVentas);
            retorno = 1;
        }
    }
    return retorno;
}


