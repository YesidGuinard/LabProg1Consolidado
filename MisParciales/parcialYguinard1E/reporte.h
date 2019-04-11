#ifndef REPORTE_H_INCLUDED
#define REPORTE_H_INCLUDED


int reporte_ordenarPublicacionPorIdCliente(Publicacion* publicaciones,int limiteP,int idC);
int reporte_mostrarClientePublicacionesActivas(Cliente* clientes,Publicacion* publicaciones,int limiteC,int limiteP);
int reporte_ClienteConMasPublicacionesActivas(Cliente* clientes,Publicacion* publicaciones,int limiteC,int limiteP);
int reporte_clientePublicacionesPausadas(Publicacion* publicaciones,int limiteP,int idCliente);
int reporte_totalPublicacionesPorCliente(Publicacion* publicaciones,int limiteP,int idCliente);
int reporte_clienteConMasPublicacionesPausadas(Cliente* clientes,Publicacion* publicaciones,int limiteC,int limiteP);
int reporte_clienteConMasPublicaciones(Cliente* clientes,Publicacion* publicaciones,int limiteC,int limiteP);
int reporte_ordenarPublicacionPorNumeroDeRubro(Publicacion* publicaciones,int limite);
int reporte_publicacionesActivasPorRubro(Publicacion* publicaciones,int limiteP,int numRubro);
int reporte_rubroDeMasPublicaciones(Publicacion* publicaciones, int limiteP);
int reporte_rubroDeMenosPublicaciones(Publicacion* publicaciones, int limiteP);
int reporte_cantDePublicacionesPorRubro(Publicacion* publicaciones, int limiteP, int numRubro);






#endif // REPORTE_H_INCLUDED
