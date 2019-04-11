#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct
{
    char nombre[50];
    char apellido[50];
    char cuit[20];
    //------------
    int idCliente;
    int isEmpty;
}Cliente;


int cliente_init(Cliente* clientes,int limiteC);
int cliente_mostrar(Cliente* clientes,int limiteC);
int cliente_mostrarClientePorId(Cliente* clientes,int limiteC, int id);
int cliente_alta(Cliente* clientes,int limiteC);
int cliente_baja(Cliente* clientes,int limiteC, int id);
int cliente_modificacion(Cliente* clientes,int limiteC, int id);
int cliente_ordenar(Cliente* clientes,int limiteC, int orden);
int cliente_buscarPorId(Cliente* clientes,int limiteC, int id);
int cliente_altaForzada(Cliente* clientes,int limiteC,char* nombre,char* apellido,char* cuit);

#endif // CLIENTE_H_INCLUDED




