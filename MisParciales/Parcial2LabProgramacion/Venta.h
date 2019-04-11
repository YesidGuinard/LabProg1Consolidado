#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

typedef struct
{
  int IdVenta;
  char fechaVenta[128];
  char codigoProducto[128];
  int cantidad;
  float precio_Unitario;
  char CuitCliente[128];
}S_Venta;




S_Venta* Venta_new();
void Venta_delete();
S_Venta* Venta_newConParametros(int IdVenta,char* fechaVenta,char* codigoProducto,int cantidad,float precio_Unitario,char* CuitCliente);

int Venta_setIdVenta(S_Venta* this,int IdVenta);
int Venta_getIdVenta(S_Venta* this,int* IdVenta);

int Venta_setFechaVenta(S_Venta* this,char* fechaVenta);
int Venta_getFechaVenta(S_Venta* this,char* fechaVenta);

int Venta_setCodigoProducto(S_Venta* this,char* codigoProducto);
int Venta_getCodigoProducto(S_Venta* this,char* codigoProducto);

int Venta_setCantidad(S_Venta* this,int cantidad);
int Venta_getCantidad(S_Venta* this,int* cantidad);

int Venta_setPrecio_Unitario(S_Venta* this,float precio_Unitario);
int Venta_getPrecio_Unitario(S_Venta* this,float* precio_Unitario);

int Venta_setCuitCliente(S_Venta* this,char* CuitCliente);
int Venta_getCuitCliente(S_Venta* this,char* CuitCliente);

int Venta_getVenta(S_Venta* this,int* IdVenta,char* fechaVenta,char* codigoProducto,int* cantidad,float* precio_Unitario,char* CuitCliente);
int Venta_printVenta(void* pVenta,void* nivel);
int VentaCountP1(void* pventa);
int VentaCountP2(void* pventa);
int VentaCountP3(void* pventa);
int VentaCountP4(void* pventa);
#endif // VENTA_H_INCLUDED
