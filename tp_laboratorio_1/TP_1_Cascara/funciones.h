/**
* \brief Solicita un número Int al usuario y lo valida
* \param mensaje Es el mensaje a ser mostrado
* \param mensajeError Es el mensaje a ser mostrado en caso de error
* \param reintentos numero de reintentos que tiene el usuario
* \param minimo Limite inferior a validar
* \param maximo Limite superior a validar
* \param resultado almacena por ref numero ingresado
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(char* mensaje, char* mensajeError, int reintentos, int minimo, int maximo, int* resultado);
/**
* \brief Suma dos Numeros enteros
* \param OperandoA de tipo entero
* \param OperandoB de tipo entero
* \param resultado de la suma por referencia
* \return void
*
*/
void sumaEnteros(int OperandoA, int OperandoB, double* resultado);
/**
* \brief Resta dos Numeros enteros
* \param OperandoA de tipo entero
* \param OperandoB de tipo entero
* \param resultado de la resta por referencia
* \return void
*
*/
void restaEnteros(int OperandoA, int OperandoB, double* resultado);
/**
* \brief divide dos Numeros enteros
* \param OperandoA de tipo entero
* \param OperandoB de tipo entero diferente de 0
* \param resultado de la division por referencia
* \return 0 si la division es posible y -1 si es div/0
*
*/
int divisionEnteros(int OperandoA, int OperandoB, double* resultado);
/**
* \brief multiplicacion dos Numeros enteros
* \param OperandoA de tipo entero
* \param OperandoB de tipo entero
* \param resultado de la multiplicacion por referencia
* \return void
*
*/
void multiplicacionEnteros(int OperandoA, int OperandoB, double* resultado);
/**
* \brief factorial de Numero entero Positivo
* \param OperandoA de tipo entero ente 1 y 170
* \param resultado de la division por referencia
* \return 0 si el factorial es posible y -1 si es el operandoA en negativo o mayor a 170
*
*/
int factorialEntero(int OperandoA, double*  resultado);
