
#include "Venta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

S_Venta* Venta_new()
{
    S_Venta* this;
    this=malloc(sizeof(S_Venta));
    return this;
}

void Venta_delete(S_Venta* this)
{
    free(this);
}

S_Venta* Venta_newConParametros(int IdVenta,char* fechaVenta,char* codigoProducto,int cantidad,float precio_Unitario,char* CuitCliente)
{
    S_Venta* this;
    this=Venta_new();

    if(
        !Venta_setIdVenta(this,IdVenta)&&
        !Venta_setFechaVenta(this,fechaVenta)&&
        !Venta_setCodigoProducto(this,codigoProducto)&&
        !Venta_setCantidad(this,cantidad)&&
        !Venta_setPrecio_Unitario(this,precio_Unitario)&&
        !Venta_setCuitCliente(this,CuitCliente))
        return this;

    Venta_delete(this);
    return NULL;
}

int Venta_setIdVenta(S_Venta* this,int IdVenta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->IdVenta=IdVenta;
        retorno=0;
    }
    return retorno;
}

int Venta_getIdVenta(S_Venta* this,int* IdVenta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *IdVenta=this->IdVenta;
        retorno=0;
    }
    return retorno;
}

int Venta_setFechaVenta(S_Venta* this,char* fechaVenta)
{
    int retorno=-1;
    if(this!=NULL && fechaVenta!=NULL)
    {
        strcpy(this->fechaVenta,fechaVenta);
        retorno=0;
    }
    return retorno;
}

int Venta_getFechaVenta(S_Venta* this,char* fechaVenta)
{
    int retorno=-1;
    if(this!=NULL && fechaVenta!=NULL)
    {
        strcpy(fechaVenta,this->fechaVenta);
        retorno=0;
    }
    return retorno;
}

int Venta_setCodigoProducto(S_Venta* this,char* codigoProducto)
{
    int retorno=-1;
    if(this!=NULL && codigoProducto!=NULL)
    {
        strcpy(this->codigoProducto,codigoProducto);
        retorno=0;
    }
    return retorno;
}

int Venta_getCodigoProducto(S_Venta* this,char* codigoProducto)
{
    int retorno=-1;
    if(this!=NULL && codigoProducto!=NULL)
    {
        strcpy(codigoProducto,this->codigoProducto);
        retorno=0;
    }
    return retorno;
}

int Venta_setCantidad(S_Venta* this,int cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

int Venta_getCantidad(S_Venta* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

int Venta_setPrecio_Unitario(S_Venta* this,float precio_Unitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->precio_Unitario=precio_Unitario;
        retorno=0;
    }
    return retorno;
}

int Venta_getPrecio_Unitario(S_Venta* this,float* precio_Unitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *precio_Unitario=this->precio_Unitario;
        retorno=0;
    }
    return retorno;
}

int Venta_setCuitCliente(S_Venta* this,char* CuitCliente)
{
    int retorno=-1;
    if(this!=NULL && CuitCliente!=NULL)
    {
        strcpy(this->CuitCliente,CuitCliente);
        retorno=0;
    }
    return retorno;
}

int Venta_getCuitCliente(S_Venta* this,char* CuitCliente)
{
    int retorno=-1;
    if(this!=NULL && CuitCliente!=NULL)
    {
        strcpy(CuitCliente,this->CuitCliente);
        retorno=0;
    }
    return retorno;
}


/** \brief
 *
 * \param this S_Venta*
 * \param IdVenta int*
 * \param fechaVenta char*
 * \param codigoProducto char*
 * \param cantidad int*
 * \param precio_Unitario float*
 * \param CuitCliente char*
 * \return int
 *
 */
int Venta_getVenta(S_Venta* this,int* IdVenta,char* fechaVenta,char* codigoProducto,int* cantidad,float* precio_Unitario,char* CuitCliente)
{
    int retorno =-1;

    if(this!= NULL)
    {
        if( !Venta_getIdVenta(this,IdVenta)&&
                !Venta_getFechaVenta(this,fechaVenta)&&
                !Venta_getCodigoProducto(this,codigoProducto)&&
                !Venta_getCantidad(this,cantidad)&&
                !Venta_getPrecio_Unitario(this,precio_Unitario)&&
                !Venta_getCuitCliente(this,CuitCliente))
        {


            retorno =0;

        }
    }
    return retorno;
}

/** \brief
 *
 * \param pVenta void*
 * \param nivel void*
 * \return int
 *
 */
int Venta_printVenta(void* pVenta,void* nivel)
{
    int retorno =-1;
    int IdVenta;
    char fechaVenta[128];
    char codigoProducto[128];
    int cantidad;
    float precio_Unitario;
    char CuitCliente[128];

    if(pVenta!= NULL)
    {
        if(!Venta_getVenta(pVenta,&IdVenta,fechaVenta,codigoProducto,&cantidad,&precio_Unitario,CuitCliente))
        {
            printf("\n %-4i  %-10s   %-15s    %-3i   $ %-10.2f  %-15s ", IdVenta,fechaVenta,codigoProducto, cantidad,precio_Unitario,CuitCliente);
            retorno = 1;
        }

    }
    return retorno;
}


/** \brief
 *
 * \param pventa void*
 * \return int
 *
 */
int VentaCountP1(void* pventa)
{
    int cantidadDeUnidadesVendidas = 0;
    if(pventa != NULL)
    {
        if(!Venta_getCantidad(pventa,&cantidadDeUnidadesVendidas))
            return cantidadDeUnidadesVendidas;
    }
    return -1;
}

/** \brief
 *
 * \param pventa void*
 * \return int
 *
 */
int VentaCountP2(void* pventa)
{
    int cantidadVentasMontoMayor1 = 0;
    int cantidadDeUnidades;
    float precioUnitario=0.0;
    if(pventa != NULL)
    {
        if(!Venta_getPrecio_Unitario(pventa,&precioUnitario)&&
                !Venta_getCantidad(pventa,&cantidadDeUnidades))
        {
            if(precioUnitario*cantidadDeUnidades > 10000.0)
            {
                cantidadVentasMontoMayor1 = 1;
            }
        }
    }

    return cantidadVentasMontoMayor1;
}


/** \brief
 *
 * \param pventa void*
 * \return int
 *
 */
int VentaCountP3(void* pventa)
{
    int cantidadVentasMontoMayor2 = 0;
    int cantidadDeUnidades;
    float precioUnitario=0.0;
    if(pventa != NULL)
    {
        if(!Venta_getPrecio_Unitario(pventa,&precioUnitario)&&
                !Venta_getCantidad(pventa,&cantidadDeUnidades))
        {
            if(precioUnitario*cantidadDeUnidades > 20000.0)
            {
                cantidadVentasMontoMayor2 = 1;
            }
        }
    }

    return cantidadVentasMontoMayor2;
}


/** \brief
 *
 * \param pventa void*
 * \return int
 *
 */
int VentaCountP4(void* pventa)
{
    int cantidadDeUnidadesVendidasTV=0;
    char codigoProducto[128];

    if(pventa != NULL)
    {
        if(!Venta_getCodigoProducto(pventa,codigoProducto))
        {
            if(strcmp(codigoProducto,"LCD_TV") == 0)
            {
                if(!Venta_getCantidad(pventa,&cantidadDeUnidadesVendidasTV))
                    return cantidadDeUnidadesVendidasTV;
            }
        }
    }

    return cantidadDeUnidadesVendidasTV;
}
