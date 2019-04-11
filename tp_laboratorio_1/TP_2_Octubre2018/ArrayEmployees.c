#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "funciones_yg.h"

static int buscarLugarLibre(Employee* list,int len);
static int proximoId(void);

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len)
{

    int retorno=-1;
    int i;
    if(len >0 && list != NULL)
    {
        retorno = 0;
        for(i =0; i < len; i++)
        {
            list[i].isEmpty =1;
        }
    }

    return retorno;
}

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{

    int retorno = -1;

    if(len > 0 && list != NULL)
    {
        retorno = 0;

        strcpy(list[id].name,name);
        strcpy(list[id].lastName,lastName);
        list[id].salary = salary;
        list[id].sector = sector;
        list[id].id = id;
        list[id].isEmpty = 0;


    }

    return retorno;

}

/** \brief
 *
 * \param id int*
 * \param name[] char
 * \param lastName[] char
 * \param salary *float
 * \param sector int*
 * \return int Return (-1) if Error  - (0) if Ok
 *
 */
int capDataEmployee(Employee* list, int len, int *id, char name[],char lastName[],float *salary,int *sector)
{

    int retorno = -1;
    int i;
    char nombreAux[51];
    char lastNameAux[51];
    float salarioAux;
    int sectorAux;

    i = buscarLugarLibre(list,len);
    if(i >= 0)
    {
        if(!funciones_getName("\nIngrese Nombre: ","\nError! Ingrese solo letras",3,nombreAux) &&
                !funciones_getName("\nIngrese Apellido: ","\nError! Ingrese solo Letras",3,lastNameAux) &&
                !funciones_getFloatFromString("\nIngrese salario: ","/nError!, ingrese Valor [1.0 - 10000000.0]",3,1.0,10000000.0,&salarioAux) &&
                !funciones_getIntFromString("\nIngrese Sector: ","\nError!, Ingrese Sector [0-100]: ",3,0,100,&sectorAux) )
        {

            retorno = 0;
            strcpy(name,nombreAux);
            strcpy(lastName,lastNameAux);
            *salary = salarioAux;
            *sector = sectorAux;
            *id =proximoId();


        }
        else
        {
            retorno =-3;
        }

    }
    else
    {
        retorno =-2;
    }


    return retorno;


}


/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int length)
{

    int retorno = -1;
    int i;

    if (length>0 && list !=NULL)
    {
        retorno = 0;
        sortEmployees(list,length, 1);
        printf("\n[STATUS] -      ID -            Name -           LastN -       Salary -    Sector -\n");
        for(i=0; i<length; i++)
        {
            if(!list[i].isEmpty)
                printf("[RELEASE] -   %4d -   %13s -   %13s -   %10.2f -   %7i - \n",list[i].id, list[i].name,list[i].lastName,list[i].salary,list[i].sector);
        }


    }

    return retorno;
}

static int buscarLugarLibre(Employee* list,int len)
{
    int retorno = -1;
    int i;
    if(len > 0 && list != NULL)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id)
{
    int retorno = -1;
    int i;
    if(len > 0 && list != NULL)
    {
        retorno = -2;
        for(i=0; i<len; i++)
        {
            if(!list[i].isEmpty && list[i].id==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int employees_altaForzada(Employee* list,int len,char* nombre,char* apellido, float salario, int sector)
{
    int retorno = -1;
    int i;

    if(len > 0 && list != NULL)
    {
        i = buscarLugarLibre(list,len);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(list[i].name,nombre);
            strcpy(list[i].lastName,apellido);
            list[i].salary = salario;
            list[i].sector = sector;
            //------------------------------
            //------------------------------
            list[i].id = proximoId();
            list[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}

int employees_modificacion(Employee* list,int len, int id)
{
    int retorno = -1;
    int indiceAModificar;
    char nombreAux[51];
    char lastNameAux[51];
    float salarioAux;
    int sectorAux;

    indiceAModificar = findEmployeeById(list,len,id);
    if(indiceAModificar>=0)
    {
        if(!funciones_getName("\nIngrese Nombre: ","\nError! Ingrese solo letras",3,nombreAux) &&
                !funciones_getName("\nIngrese Apellido: ","\nError! Ingrese solo Letras",3,lastNameAux) &&
                !funciones_getFloatFromString("\nIngrese salario: ","\nError!, ingrese Valor [1.0 - 100000000.0]",3,1.0,100000000.0,&salarioAux) &&
                !funciones_getIntFromString("\nIngrese Sector: ","\nError!, Ingrese Sector [0-100]: ",3,0,100,&sectorAux) )
        {

            retorno = 0;
            strcpy(list[indiceAModificar].name,nombreAux);
            strcpy(list[indiceAModificar].lastName,lastNameAux);
            list[indiceAModificar].salary = salarioAux;
            list[indiceAModificar].sector = sectorAux;


        }
        else
        {
            retorno =-3;
        }

    }
    else
    {
        retorno =-2;
    }



    return retorno;
}


int sortEmployees(Employee* list,int len, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Employee auxiliarEstructura;

    if(len > 0 && list != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0; i<len-1; i++)
            {
                if(!list[i].isEmpty && !list[i+1].isEmpty)
                {
                    if( ((strcmp(list[i].lastName,list[i+1].lastName) > 0 && orden) || (strcmp(list[i].lastName,list[i+1].lastName) < 0 && !orden)) ||

                            (strcmp(list[i].lastName,list[i+1].lastName)==0 && orden && ((list[i].sector > list[i+1].sector)&& orden)))



                    {
                        auxiliarEstructura = list[i];
                        list[i] = list[i+1];
                        list[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }
        while(flagSwap);



    }
    return retorno;
}


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    indiceAEliminar = findEmployeeById(list,len,id);
    if(indiceAEliminar>=0)
    {
        list[indiceAEliminar].isEmpty=1;
        retorno=0;
    }
    return retorno;
}

/** \brief
 *
 * \param list Employee*
 * \param len int
 * \param total int*
 * \return int
 *
 */
int totalSalaryEmployee(Employee* list, int len, double *total, double *promedio)
{
    int retorno = -1;
    int i;
    double acumulador = 0;
    double promedioAux = 0;
    int acumuladorEmpleados = 0;

    if(len > 0 && list != NULL)
    {
        retorno = 0;
        for(i=0; i<len; i++)
        {

            if(!list[i].isEmpty)
            {
                acumulador = acumulador + list[i].salary;
                acumuladorEmpleados ++;

            }
        }
        *total = acumulador;
        if(acumuladorEmpleados>0)
        {
            promedioAux = acumulador / acumuladorEmpleados;
            *promedio = promedioAux;
        }


    }

    return retorno;

}


int qtySalarySup(Employee *list, int len, double promedio, int *qtyEmployee)
{
    int retorno = -1;
    int i;
    int acumuladorEmpleados = 0;

    if(len > 0 && list != NULL)
    {
        retorno = 0;
        for(i=0; i<len; i++)
        {

            if(!list[i].isEmpty && list[i].salary > promedio)
            {
                acumuladorEmpleados ++;

            }
        }
        *qtyEmployee = acumuladorEmpleados;



    }

    return retorno;
}

int qtyEmployeeTotal(Employee *list, int len)
{
    int i;
    int employeeCount = 0;
    if(len > 0 && list != NULL)
    {
        for(i=0; i<len; i++)
        {

            if(!list[i].isEmpty)
            {
                employeeCount ++;

            }
        }

    }
    return employeeCount;

}

static int proximoId(void)
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}
