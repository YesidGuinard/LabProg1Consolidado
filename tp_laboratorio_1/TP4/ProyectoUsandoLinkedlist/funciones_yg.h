#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_INCLUDED

void funciones_clearStdin(void);

void funciones_pause(char *message);

int funciones_isNumericInteger(char *str);

int funciones_isNumericFloat(char *str);

int funciones_isPhoneNumber(char *str);

int funciones_isName(char *name);

int funciones_isID(int id);

int funciones_isOnlyLetters(char *str);

int funciones_isAphaNumeric(char *str);

int funciones_ValidIdStr(char *str, int* id);

int funciones_isHorasTrabajadas(int horas);

int funciones_ValidHorasTrabajadasStr(char *str, int* auxHora);

int funciones_isSueldo(int sueldo);

void funciones_clearScreen(void);

int funciones_ValidSueldoStr(char *str, int* sueldo);

int isValidDni(char *dni);

int esMail(char *str);

int funciones_getStringInput(char *message,int limite, char *outputString);

int funciones_getIntFromString(char *message, char *messageError, int retries, int minimum, int maximum, int *resultInteger);

int funciones_getFloatFromString(char *message, char *messageError, int retries, float minimum,float maximum, float *resultFloat);

int funciones_getRandomNumber(int desde, int hasta, int iniciar);

int funciones_getOnlyChar(char *message, char *messageError, int retries, char minimum, char maximum,char *resultadoOnlyChar);

int funciones_getPhoneNumber(char *message, char *messageError, int retries, char *telefono);

int funciones_getName(char *message, char *messageError, int retries, char *nombre);

int funciones_getAlphaNumeric(char *message, char *messageError, int retries, int maxLenght, char *nombre);

int funciones_getOldFromString(char *message, char *messageError, int retries, int *resultEdad);

int funciones_getHeight(char *message, char *messageError, int retries, float *resultEstatura);

int funciones_getCuit(char *message, char *messageError, int retries, char *ciut);

int funciones_getDni(char *message, char *messageError, int retries, char *dni);

int funciones_getMail(char *message, char *messageError, int retries, char *mail);

int swapInt(int* primerEntero,int* segundoEntero);

int funciones_ordenarArrayEnterosBubble(int *array, int cantidadElementos, int flagOrden);

int funciones_mostrarArrayEnteros(int* array, int cantidadElementos);

int funciones_mostrarArrayCadenaCaracteres(char array[][50], int cantidadElementos);

int funciones_insertionArrayInt(int *array,int len, int FlagOrder);

int funciones_calcularMaximoArray(int* pArray, int limite, int* pMaximo);

void funciones_initArray(int* pArray, int limite, int valor);

int funciones_swapArrayChars(char *primerArray,char *segundoArray);

int funciones_sort_ordenarArrayChars(char array[][50],int cantidadElementos, int flagOrden);


#endif // YG_FUNCIONES_H_INCLUDED

