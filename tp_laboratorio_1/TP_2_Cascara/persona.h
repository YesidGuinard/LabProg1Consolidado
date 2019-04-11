#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct
{

    char nombre[50];
    char dni[20];
    int edad;
    int idEPersona;
    int isEmpty;


} EPersona;


int persona_init(EPersona* array,int limite);
int persona_mostrar(EPersona* array,int limite);
//int persona_mostrarDebug(EPersona* array,int limite);
int persona_alta(EPersona* array,int limite);
//int persona_baja(EPersona* array,int limite, int id);
int persona_baja(EPersona* array,int limite, char* dni);
//int persona_modificacion(EPersona* array,int limite, int id);
int persona_ordenar(EPersona* array,int limite, int orden);
int persona_buscarPorId(EPersona* array,int limite, int id);
int persona_buscarPorDni(EPersona* array,int limite, char* dni);
int persona_altaForzada(EPersona* array,int limite,char* nombre,char* dni,int edad);
int contadorDeEdades(EPersona* array,int limite, int contadorEdad[]);
void graficar(int edades[]);

#endif // PERSONA_H_INCLUDED
