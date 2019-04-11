#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funciones_yg.h"
#define false 0
#define true 1
#define DATO_INVALIDO -1


/* inicio validaciones*/
/** \brief verifica si el valor recibido es numerico
 *
 * \param str char*  entrada a validar
 * \return int retorna 1 si es numerico y 0 si no.
 *
 */
int funciones_isNumericInteger(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

/** \brief verifica si array char es numero flotante
 *
 * \param str char* entrada a validar
 * \return int  retorna 1 si es numerico flotante y 0 si no.
 *
 */
int funciones_isNumericFloat(char *str)
{
    int i = 0;
    int cantidadPuntos = 0;
    while (str[i] != '\0')
    {
        //printf("Char: %x\n",str[i]);
        if (str[i] == '.' && cantidadPuntos == 0)
        {
            cantidadPuntos++;
            i++;
            continue;

        }
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

/** \brief verifica si array char es numero telefonico valido
 *
 * \param str char* entrada a validar
 * \return int retorna 1 si es numero de telefono y 0 si no.
 *
 */
int funciones_isPhoneNumber(char *str)
{
    int i=0;
    int contadorGuiones=0;
    int contadorEspacios=0;

    while(str[i] != '\0')
    {
        // printf("Char: %x\n",str[i]);

        if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
        {

            return 0;
        }

        if(str[i] == '-')
            contadorGuiones++;
        if(str[i]== ' ')
            contadorEspacios++;
        i++;

    }

    if(contadorGuiones == 1 && strlen(str) == 12 && contadorEspacios == 1 ) // debe tener un guion
        return 1;

    return 0;
}

/** \brief verifica si el valor recibido contiene solo letras
 *
 * \param str char* entrada a validar
 * \return int retorna 1 si la cadena contiene solo letras y 0 si no.
 *
 */
int funciones_isOnlyLetters(char *str)
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

/** \brief verifica si cadena es nombre valido
 *
 * \param name char* cadena a analizar
 * \return int retorna 1 si es nombre valido y 0 si no.
 *
 */
int funciones_isName(char *name)
{
    int retorno=-1;
    if(name!=NULL)
    {
        if(funciones_isOnlyLetters(name)==1 && strlen(name)>2 && strlen(name)<15)
        {
            retorno= 1;
        }
    }
    else
        printf("name es NULL");

    return retorno;

}

/** \brief verifica si cadena es Alfanumerica
 *
 * \param str char* cadena a analizar
 * \return int retorna 1 si cadena contiene numeros y letras y 0 si no.
 *
 */
int funciones_isAphaNumeric(char *str)
{
    int i=0;
    int retorno = -1;

    int alpha = 0 ;
    int num = 0 ;
    while(str[i] != '\0')
    {
        //     printf("%x\t",str[i]);
        if(str[i] != ' ' && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')  )
        {

            if((str[i] < '0' || str[i] > '9'))
            {
                retorno = 0;
                break;

            }
            else
            {
                num =1;
            }

        }
        else
        {
            alpha = 1;
        }
        i++;
    }
    if(num + alpha == 2)
        retorno = 1;

//  printf("retorno %i\n",retorno);
    return retorno;
}
/** \brief vefifica si numero es edad valida
 *
 * \param edad int valor a ser analizado
 * \return int retorna 1 si valor se encuentra entre 0 y 200 o 0 si no.
 *
 */
int esEdad(int edad)
{
    if(edad>0 && edad<200)
        return 1;
    return 0;
}

/** \brief verifica si valor float se encuentra en rango de estatura humana
 *
 * \param altura float valor a ser analizado
 * \return int retorna 1 si estatura en metros se encuentra entre 0.1 y 2.5 o 0 si no.
 *
 */
int isAltura(float altura)
{
    if(altura>0.1 && altura<2.5)
        return 1;
    return 0;
}

/** \brief verifica cadena si es cuit con guiones validos
 *
 * \param cuit char* cadena a se analizada
 * \return int retorna 1 si cadena es cuit valido o 0 si no.
 *
 */
int esCiut(char *cuit)
{
    int i;
    int retorno=1;
    //strtok(cuit,"\n");


    if(strlen(cuit)!=13)
    {

        retorno=-1;
    }

    else
    {
        for(i=0; i<=1; i++)
        {
            if((cuit[i]<'0'||cuit[i]>'9'))
            {
                retorno=-1;

                break;
            }
        }
        for(i=3; i<=10; i++)
        {
            if((cuit[i]<'0'||cuit[i]>'9'))
            {
                retorno=-1;
                break;
            }
        }
        for(i=2; i<13; i+=9)
        {
            if(cuit[i]!='-')
            {
                retorno=-1;
                break;
            }
        }
        if(cuit[12]<'0' || cuit[12]>'9')
        {
            retorno=-1;

        }

    }

    return retorno;
}
/** \brief verifica cadena si es dni valido
 *
 * \param dni char* cadena a se analizada
 * \return int retorna 1 si cadena es dni valido o 0 si no.
 *
 */
int isValidDni(char*dni)
{
    int retorno=-1;
    if(dni!=NULL)
    {
        //strtok(dni,"\n");
        if(funciones_isNumericInteger(dni)==1)
        {
            if(strlen(dni) > 8)
            {
                printf("un DNI valido no puede exeder los 8 caracteres");
            }
            else if(strlen(dni)<8)
            {
                printf("un DNI valido no puede tener menos de 8 caracteres");
            }
            else
            {
                retorno=1;
            }
        }
        else
            printf("el Dni debe ser solo Numeros");

    }
    else
        printf("ERROR, 'dni' es NULL");
    return retorno;
}

int esMail(char *str)
{
    int i=0;
    int retorno=-1;
    int contadorArroba=0;
    while(str[i] != '\0')
    {
        if((str[i] != '@')&&(str[i] != '-')&&(str[i] != '_') &&(str[i] != '.')&& (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            retorno= 0;//si hay error
        if(str[i]=='@')
        {
            contadorArroba++;
        }
        i++;
    }
    if(contadorArroba==1)
    {
        retorno=1;//si esta todo ok
    }
    return retorno;
}

/* fin validaciones*/

/** \brief limpia buffer de stdin
 *
 * \param void
 * \return void
 *
 */
void funciones_clearStdin(void)
{
    fflush(stdin);
    // setbuf(stdin, NULL) //?linux? revisar luego

}

/** \brief funcion que realiza una pausa a la espera de ingreso de caracter para continuar
 *
 * \param message char*
 * \return void
 *
 */
void funciones_pause(char *message)
{
    printf("%s", message);
    getchar();
    funciones_clearStdin();
}

/** \brief limpia plantalla en la consola
 *
 * \param void
 * \return void
 *
 */
void clearScreen(void)
{
    //system("clear"); //
    system("cls");
}

/** \brief funcion que captura datos ingresados por teclado
 *
 * \param message char* mensaje a mostrar al usuario
 * \param limite int limite de caracteres maximos a ser capturados y almacenados
 * \param outputString char* array con caracteres capturados se le quita el '\n' y se inserta en el ultimo caracter '\0'
 * \return int retorna 0 si se capturo exitosamente y -1 en caso de error
 *
 */
int funciones_getStringInput(char *message,int limite, char *outputString)
{
    char bufferString [4096];
    int retorno = -1;
    if(outputString != NULL && limite > 0)
    {
        printf("%s", message);
        funciones_clearStdin();
        fgets(bufferString,sizeof(bufferString),stdin);

        if(bufferString[strlen(bufferString)-1]=='\n')
        {
            bufferString[strlen(bufferString)-1]='\0';
        }
        if(strlen(bufferString) <= limite)
        {
            strncpy(outputString,bufferString,limite);
            retorno = 0;
        }
    }
    return retorno;

}

/** \brief funcion que solicita al usuario dato tipo entero mediante consola en un rango determinado limitado por intentos
 *
 * \param message char* mensaje inicial para el usuario
 * \param messageError char* mensaje de error en caso de ingreso de datos invalidos
 * \param retries int numero de intentos maximos que se tienen para ingresar dato valido
 * \param minimum int tope minimo de valor solicitado
 * \param maximum int tope maximo de valor solicitado
 * \param resultInteger int* variable con el valor entero en rango correcto
 * \return int retorna 0 si el usuario ingreso correctamente dato en rango solicitado
 *
 */
int funciones_getIntFromString(char *message, char *messageError, int retries, int minimum, int maximum, int *resultInteger)
{
    int retorno = -1;
    long auxiliarLong;
    char auxStr[1024];

    do
    {
        retries--;
        funciones_getStringInput(message, sizeof(auxStr), auxStr);
        //  strtok(auxStr, "\n"); // Eliminate line jump

        if (funciones_isNumericInteger(auxStr) == 1)
        {
            auxiliarLong = atoi(auxStr);

            if (auxiliarLong >= minimum && auxiliarLong <= maximum)
            {
                *resultInteger = (int) auxiliarLong;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s\n", messageError);
            }

        }
        else
        {
            funciones_clearStdin();
            printf("%s\n", messageError);
        }

    }
    while (retries >= 0);

    return retorno;

}

/** \brief solicita al usuario dato tipo float en rango determinado limitado por intentos
 *
 * \param message char* mensaje inicial a mostrar al usuario
 * \param messageError char* mensaje de error en caso de ingreso de datos invalidp
 * \param retries int numero de intentos maximo que se tienen oara ingresar dato valido
 * \param minimum float tope minimo de valor solicitado
 * \param maximum float tope maximo de valor solicitado
 * \param resultFloat float* variable  con el valor float en rango correcto
 * \return int retorna 0 si el usuario ingreso correctamente dato en rango solicitado
 *
 */
int funciones_getFloatFromString(char *message, char *messageError, int retries, float minimum,float maximum, float *resultFloat)
{
    int retorno = -1;
    double auxDouble;
    char auxStr[1024];

    do
    {
        retries--;
        funciones_getStringInput(message, sizeof(auxStr), auxStr);

        //strtok(auxStr, "\n"); // Eliminate line jump

        if (funciones_isNumericFloat(auxStr) == 1)
        {
            auxDouble = atof(auxStr);

            if (auxDouble >= minimum && auxDouble <= maximum)
            {
                *resultFloat = (float) auxDouble;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s\n", messageError);
            }

        }
        else
        {
            funciones_clearStdin();
            printf("%s\n", messageError);
        }

    }
    while (retries >= 0);

    return retorno;

}

/** \brief genera numero aletoreo
 *
 * \param desde int rango minimo
 * \param hasta int rango maximo
 * \param iniciar int se debe inicar si es la primera vez que se llama a la funcion
 * \return int retorna numero aleatoreo en rango acotado por limites  desde hasta
 *
 */
int funciones_getRandomNumber(int desde, int hasta, int iniciar)
{
    if (iniciar)
        srand(time(NULL));
    return desde + (rand() % (hasta + 1 - desde));
}

/** \brief solicita al usuario un solo caracter por consola dentro de un rango
 *
 * \param message char* mensaje inicial para usuario
 * \param messageError char* mensaje para usuario en caso de ingresoo de datos invalidps
 * \param retries int  nummero de intentos para ingresar dato correctamente
 * \param minimum char  limite inferior de dato valido
 * \param maximum char limite superior de dato valido
 * \param resultadoOnlyChar char*  variable con caracter digitado
 * \return int retorna 0 si se ingreso caractaer correctamente y -1 en caso contrario
 *
 */
int funciones_getOnlyChar(char *message, char *messageError, int retries, char minimum, char maximum, char *resultadoOnlyChar)
{
    int retorno = -1;
    char auxiliarChar[3];

    do
    {
        retries--;
        funciones_getStringInput(message, 3, auxiliarChar);
        //strtok(auxiliarChar, "\n"); // Eliminate line jump

        if (auxiliarChar[0] >= minimum && auxiliarChar[0] <= maximum && auxiliarChar[1] == '\0')
        {

            *resultadoOnlyChar = auxiliarChar[0];
            retorno = 0;
            break;
        }

        printf("%s\n", messageError);

    }
    while (retries >= 0);

    return retorno;
}

/** \brief solicita al usuario por consola numero de telefono limitado por numero de intentos
 *
 * \param message char* mensaje inicial para usuario
 * \param messageError char* mensaje para el usurio en caso de ingresar datos en formato incorrecto
 * \param retries int numemro de intentos maximos
 * \param telefono char*  array numero de telefono valido
 * \return int retorna 0 en caso exitoso y 0 en caso de error
 *
 */
int funciones_getPhoneNumber(char *message, char *messageError, int retries, char *telefono)
{
    int retorno = -1;
    char auxiliarChar[1024];

    do
    {
        retries--;
        funciones_getStringInput(message, sizeof(auxiliarChar), auxiliarChar);
        //printf("\n----tel:%s",auxiliarChar);

        if(funciones_isPhoneNumber(auxiliarChar) == 1 )
        {

            strncpy(telefono,auxiliarChar,strlen(auxiliarChar));
            retorno = 0;
            break;
        }
        else
        {
            printf("%s", messageError);
        }

    }
    while (retries >= 0);

    return retorno;
}

/** \brief Solicita al usuario ingresar nombre limitado por numero de intentos
 *
 * \param message char* mensaje inicial para usuario
 * \param messageError char* mensaje para usiario en caso de ingresar caracteres invalidos
 * \param retries int munero de intentos validos
 * \param nombre char* array donde se almacena cadena de cararacterres correcta
 * \return int
 *
 */
int funciones_getName(char *message, char *messageError, int retries, char *nombre)
{
    int retorno = -1;
    char auxiliarChar[1024];

    do
    {
        retries--;
        funciones_getStringInput(message, sizeof(auxiliarChar), auxiliarChar);
        if(funciones_isName(auxiliarChar) == 1 )
        {

            strncpy(nombre,auxiliarChar,strlen(auxiliarChar)+1);
            retorno = 0;
            break;
        }
        else
        {
            printf("%s", messageError);
        }

    }
    while (retries >= 0);

    return retorno;
}

/** \brief solicita al usuario valores alfanumericos limitados por # de intentos y cantida de caracteres
 *
 * \param message char* mensaje inicial para usuario
 * \param messageError char* mensaje para usuario en caso de caraacteres invalidos o fuera de rango
 * \param retries int numero de intentos maximos
 * \param maxLenght int cantidad de caracteres maximos a digitar
 * \param nombre char* variable con valor alfanumerico digitado
 * \return int retorna 0 en caso de OK y -1 en caso de error
 *
 */
int funciones_getAlphaNumeric(char *message, char *messageError, int retries, int maxLenght, char *nombre)
{
    int retorno = -1;
    char auxiliarChar[maxLenght+2];

    do
    {
        retries--;
        funciones_getStringInput(message, maxLenght + 2, auxiliarChar);

        if(funciones_isAphaNumeric(auxiliarChar) == 1 && strlen(auxiliarChar) <= maxLenght +1 )
        {
            strncpy(nombre,auxiliarChar,strlen(auxiliarChar)+1);
            retorno = 0;
            break;
        }
        else
        {
            printf("%s", messageError);
        }

    }
    while (retries >= 0);

    return retorno;
}

/** \brief solicita al usuario edad humana en anios rango valido por IsEdadValida()
 *
 * \param message char* mensaje inicial para usuario
 * \param messageError char* mensaje para usuario en caso de edad fuera de rango
 * \param retries int numero de intentos maximos
 * \param resultEdad int* variable entera que almacena edad en anios
 * \return int retorna 0 en caso de OK y -1 en caso de error
 *
 */
int funciones_getOldFromString(char *message, char *messageError, int retries, int *resultEdad)
{
    int retorno = -1;
    int auxiliarInt;
    char auxStr[10];

    do
    {
        retries--;
        funciones_getStringInput(message, sizeof(auxStr), auxStr);
        //strtok(auxStr, "\n"); // Eliminate line jump

        if (funciones_isNumericInteger(auxStr) == 1)
        {
            auxiliarInt =(int) atoi(auxStr);
            //printf("Aux%i\n",auxiliarInt);

            if (esEdad(auxiliarInt)==1)
            {
                // printf("Aux%i\n",auxiliarInt);
                *resultEdad =  auxiliarInt;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s\n", messageError);
            }

        }
        else
        {
            funciones_clearStdin();
            printf("%s\n", messageError);
        }

    }
    while (retries >= 0);

    return retorno;

}

/** \brief solicita por consola estatura en rango humano valido
 *
 * \param message char* mensaje inicial usuario
 * \param messageError char* mensaje para usuario en caso de estatura fuera de rango
 * \param retries int maximo de intentos
 * \param resultEstatura float* variable que almacena valor de estatura ingresada valida
 * \return int retorna 0 si todo OK y -1 en caso de error.
 *
 */
int funciones_getHeight(char *message, char *messageError, int retries, float *resultEstatura)
{
    int retorno = -1;
    float auxiliarEstatura;
    char auxStr[1024];

    do
    {
        retries--;
        funciones_getStringInput(message, sizeof(auxStr), auxStr);
        //strtok(auxStr, "\n"); // Eliminate line jump

        if (funciones_isNumericFloat(auxStr) == 1)
        {
            auxiliarEstatura =(float) atof(auxStr);
            //printf("Aux%i\n",auxiliarInt);

            if (isAltura(auxiliarEstatura)==1)
            {
                // printf("Aux%i\n",auxiliarInt);
                *resultEstatura =  auxiliarEstatura;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s\n", messageError);
            }

        }
        else
        {
            funciones_clearStdin();
            printf("%s\n", messageError);
        }

    }
    while (retries >= 0);

    return retorno;

}

/** \brief solicita al usuario por consola cuit y valida formato con guiones
 *
 * \param message char* mensaje inicial para usuario
 * \param messageError char* mensaje en caso de ingreso en formato invalido
 * \param retries int maximo de intentos validos
 * \param cuit char* array que almacena cuit valido
 * \return int retorna 0 en caso de OK y -1 en caso de error
 *
 */
int funciones_getCuit(char *message, char *messageError, int retries, char *cuit)
{
    int retorno = -1;
    char auxiliarChar[128];

    do
    {
        retries--;
        funciones_getStringInput(message, sizeof(auxiliarChar), auxiliarChar);
        if(esCiut(auxiliarChar) == 1 )
        {
            //printf("%s\n, %i\n",auxiliarChar,strlen(auxiliarChar));
            strncpy(cuit,auxiliarChar,strlen(auxiliarChar));
            //cuit[14]=0;
            retorno = 0;
            break;
        }
        else
        {
            printf("%s", messageError);
        }

    }
    while (retries >= 0);

    return retorno;
}

/** \brief solicita al usuario por consola dni y valida logitud
 *
 * \param message char*  mensaje inicial para usuario
 * \param messageError char*  mensaje en caso de ingreso en formato invalido
 * \param retries int int maximo de intentos validos
 * \param dni char* array que almacena dni valido
 * \return int retorna 0 en caso de OK y -1 en caso de error
 *
 */
int funciones_getMail(char *message, char *messageError, int retries, char *mail)
{
    int retorno = -1;
    char auxiliarChar[128];

    do
    {
        retries--;
        funciones_getStringInput(message, sizeof(auxiliarChar), auxiliarChar);
        if(esMail(auxiliarChar) == 1 )
        {
            //printf("%s\n, %i\n",auxiliarChar,strlen(auxiliarChar));
            strncpy(mail,auxiliarChar,strlen(auxiliarChar)+1);
            //dni[14]=0;
            retorno = 0;
            break;
        }
        else
        {
            printf("%s", messageError);
        }

    }
    while (retries >= 0);

    return retorno;
}

int funciones_getDni(char *message, char *messageError, int retries, char *dni)
{
    int retorno = -1;
    char auxiliarChar[128];

    do
    {
        retries--;
        funciones_getStringInput(message, sizeof(auxiliarChar), auxiliarChar);
        if(isValidDni(auxiliarChar) == 1 )
        {
            //printf("%s\n, %i\n",auxiliarChar,strlen(auxiliarChar));
            strncpy(dni,auxiliarChar,strlen(auxiliarChar)+1);
            //dni[14]=0;
            retorno = 0;
            break;
        }
        else
        {
            printf("%s", messageError);
        }

    }
    while (retries >= 0);

    return retorno;
}

/** \brief intercambia el orden de dos numeros enteros
 *
 * \param primerEntero int* Numero 1
 * \param segundoEntero int* numero 2
 * \return int int retorna 0 en caso de OK.
 *
 */
int swapInt(int* primerEntero,int* segundoEntero)
{
    int auxiliar;
    auxiliar = *primerEntero;
    *primerEntero = *segundoEntero;
    *segundoEntero = auxiliar;
    return 0;
}

/** \brief ordena ascend o desce array  de enteros mediante algoritmo burbuuja
 *
 * \param array int* array de entrada
 * \param cantidadElementos int cantidad de elementos del array
 * \param flagOrden int bandera si es 0 ordena ascendente si es 1 descendente.
 * \return int retorna 0 en caso de OK y -1 en caso de error
 *
 */
int funciones_ordenarArrayEnterosBubble(int *array, int cantidadElementos, int flagOrden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    if(cantidadElementos > 0)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0; i<cantidadElementos-1; i++)
            {
                if((array[i] < array[i+1] && flagOrden)||(array[i] > array[i+1] && !flagOrden))
                {
                    swapInt(&array[i],&array[i+1]);
                    flagSwap = 1;
                }
            }
        }
        while(flagSwap);
    }
    return retorno;
}


/** \brief imprime en consola array de enteros
 *
 * \param array int* array a mostrar
 * \param cantidadElementos int cantidad de elementos del array
 * \return int retorna 0 en caso de OK y -1 en caso de error
 *
 */
int funciones_mostrarArrayEnteros(int* array, int cantidadElementos)
{
    int retorno = -1;
    int i;
    if(cantidadElementos > 0)
    {
        retorno = 0;
        for(i=0; i<cantidadElementos; i++)
        {
            printf("%d\t",array[i]);
        }
        printf("\n");
    }
    return retorno;
}

/** \brief imprime en consola array con cadena de caracteres
 *
 * \param array[][50] char array a mostrar
 * \param cantidadElementos int cantidad de elementos del array
 * \return int retorna 0 en caso de OK y -1 en caso de error
 *
 */
int funciones_mostrarArrayCadenaCaracteres(char array[][50], int cantidadElementos)
{
    int retorno = -1;
    int i;
    if(cantidadElementos > 0)
    {
        retorno = 0;
        for(i=0; i<cantidadElementos; i++)
        {
            printf("\n%s",array[i]);
        }
    }
    return retorno;
}

/** \brief ordena array de enteros con  algoritmo insertion
 *
 * \param array int* array de entrada a ordenar
 * \param len int cantidad de elementos del array
 * \param FlagOrder int bandera que indica 0 para asced y 1 para desce
 * \return int retorna 0 en caso de OK y -1 en caso de error
 *
 */
int funciones_insertionArrayInt(int *array,int len, int FlagOrder)
{
    int i,j;
    int temp;
    for(i=1; i<len; i++)
    {
        temp=array[i];
        j=i-1;
        if(FlagOrder==0)
        {
            while(j>=0 && temp<array[j])
            {
                array[j+1]=array[j];
                j--;
            }
            array[j+1]=temp;
        }
        else
        {

            while(j>=0 && temp>array[j])
            {
                array[j+1]=array[j];
                j--;
            }
            array[j+1]=temp;

        }

    }
    return 0;
}

/** \brief encuentra el maximo en una array de enteros
 *
 * \param pArray int* array de entrada
 * \param limite int numero de elemntos del array
 * \param pMaximo int* variable con el maximo encontrado
 * \return int retorna 0 en caso de OK y -1 en caso de error
 *
 */
int funciones_calcularMaximoArray(int* pArray, int limite, int* pMaximo)
{
    int retorno=-1;
    int i;

    int maximo;
    int flagPrimerMaximo = false;

    if(pArray != NULL && limite > 0)
    {

        for(i=0; i<limite; i++)
        {
            if(pArray[i] != DATO_INVALIDO)
            {
                if(flagPrimerMaximo == false)
                {
                    maximo = pArray[i];
                    flagPrimerMaximo = true;
                }
                else if(pArray[i] > maximo)
                {
                    maximo = pArray[i];
                }
            }
        }

        if(flagPrimerMaximo == 0)
        {
            retorno = -2;
        }
        else
        {
            *pMaximo = maximo;
            // printf("%i\n",maximo);
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief inicializa un vector de enteros con el valor deseado
 *
 * \param pArray int* array a inicializar
 * \param limite int numero de elementos del array
 * \param valor int valor con el que se inicializa cada elemento
 * \return void
 *
 */
void funciones_initArray(int* pArray, int limite, int valor)
{
    int i;
    if(pArray != NULL && limite > 0)
    {
        for(i=0; i<limite; i++)
        {
            pArray[i] = valor;
        }
    }
}

/** \brief intercambia el contenido de dos cadenas de caracteres
 *
 * \param primerArray char* cadena 1
 * \param segundoArray char* cadena 2
 * \return int retorna 0 si intercambio OK y -1 en caso de error
 *
 */
int funciones_swapArrayChars(char *primerArray,char *segundoArray)
{
    char auxiliar[50];
    strcpy(auxiliar,primerArray);
    strcpy(primerArray,segundoArray);
    strcpy(segundoArray,auxiliar);

    return 0;
}

/** \brief ordena cadenas dentro de array
 *
 * \param array[][50] char array de entrada a ordenar
 * \param cantidadElementos int cantidad de cadenas a ordenar
 * \param flagOrden int  badera en 1 para orden ascendente y 0 para descendente
 * \return int retorna 0 en caso de OK y -1 en caso de error
 *
 */
int funciones_sort_ordenarArrayChars(char array[][50],int cantidadElementos, int flagOrden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    if(cantidadElementos > 0)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0; i<cantidadElementos-1; i++)
            {
                if((strcmp(array[i],array[i+1])==1 && flagOrden) || ((strcmp(array[i],array[i+1])==-1 && !flagOrden)))
                {
                    funciones_swapArrayChars(array[i],array[i+1]);
                    flagSwap = 1;
                }
            }

        }
        while(flagSwap);
    }
    return retorno;
}

int funciones_menuDeOpciones(void)
{
    int menu;
    clearScreen();
    printf("\n*****MENU PRINCIPAL*****\n\n");
    printf("1-Alta Empleado \n");
    printf("-------------------------------------------\n");
    printf("2-Modificar Empleado \n");
    printf("-------------------------------------------\n");
    printf("3-Baja Empleado\n");
    printf("-------------------------------------------\n");
    printf("4-Informar\n");
    printf("-------------------------------------------\n");
    printf("5-salir\n");
    printf("-------------------------------------------\n");

    funciones_getIntFromString("\nSelecciona Opcion: ","\nla opcion no exite\n", 10, 1, 5, &menu);
    return menu;

}
