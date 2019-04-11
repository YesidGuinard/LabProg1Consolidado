#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED
#include "cliente.h"
typedef struct
{
    char nombre[50];//
    char texto[60];
    int idCliente;
    int rubro;

    //------------
    int idPublicacion;
    int estadoPub;
    int isEmpty;
}Publicacion;


int publicacion_init(Publicacion* publicaciones,int limite);
int publicacion_mostrar(Publicacion* publicaciones, Cliente* clientes,int limite, int limite_clientes);
int publicacion_mostrarInactivas(Publicacion* publicaciones, Cliente* clientes,int limite, int limite_clientes);
int publicacion_mostrarPorIdCliente(Publicacion* publicaciones, Cliente* clientes,int limite, int limite_clientes,int idCliente);
int publicacion_mostrarPorIdPub(Publicacion* publicaciones,int limite,int idPub);
int publicacion_alta(Publicacion* publicaciones, Cliente* clientes,int limite, int limiteC);
int publicacion_baja(Publicacion* publicaciones,int limite, int id);
int publicacion_pausa(Publicacion* publicaciones,int limite, int id);
int publicacion_reanudar(Publicacion* publicaciones,int limite, int id);
int publicacion_ordenar(Publicacion* publicaciones,int limite, int orden);
int publicacion_ordenarPorIdCliente(Publicacion* publicaciones,int limite);
int publicacion_buscarPorId(Publicacion* publicaciones,int limite, int id);
int publicacion_buscarInactivaPorId(Publicacion* publicaciones,int limite, int id);
int publicacion_buscarClientePorIdDePublicacion(Publicacion* publicaciones,int limite, int id);
int publicacion_bajaPorIdCliente(Publicacion* publicaciones, int limite, int idCliente);

int publicacion_altaForzada(Publicacion* publicaciones,int limite,int idCliente,int rubro,char* texto);

#endif // PUBLICACION_H_INCLUDED
