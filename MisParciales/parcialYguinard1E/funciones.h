#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


int getInt(char* mensaje);
float getFloat(char* mensaje);
char getChar(char* mensaje);

char getNumeroAleatorio(int desde , int hasta, int iniciar);

int esNumerico(char *str) ;
int esTelefono(char *str);
int esAlfaNumerico(char *str);
int esTexto(char *str);
int esSoloLetras(char *str);
int esNumericoFlotante(char str[]);

void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);


int getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps);
int getValidInt(char requestMessage[],char errorMessage[], int* input,int lowLimit, int hiLimit,int attemps);
int getValidFloat(char requestMessage[],char errorMessage[], float* input,float lowLimit, float hiLimit,int attemps);

int validarDni(char* arrayDni);
int getStringDni(char mensaje[],char input[]);
int getValidDni(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps);

int validarCuit(char* arrayDni);
int getStringCuit(char mensaje[],char input[]);
int getValidCuit(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps);

int getStringAlfanumerico(char mensaje[],char input[]);
int getValidAlfanumerico(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps);

void clearStdin(void);
void pause(void);
void clearScreen(void);


#endif // FUNCIONES_H_INCLUDED
