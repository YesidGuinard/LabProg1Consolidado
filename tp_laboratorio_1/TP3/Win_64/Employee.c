#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones_yg.h"


/** \brief Reserva lugar en memoria para cargar 1 empleado
 *
 * \return Employee*
 *
 */
Employee* employee_new()
{
    Employee* this;
    this=malloc(sizeof(Employee));
    return this;
}

/** \brief Libera el espacio en memoria de una empleado
 *
 * \param this Employee*
 * \return void
 *
 */
void employee_delete(Employee* this)
{
    free(this);
}

/** \brief Se le pasan los campos de un empleado, si estan todos bien devuelve un puntero a ese empleado, si no devuelve NULL
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr, char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* this;
    this=employee_new();
    int auxID;
    int auxHorasTrabajadas;
    int auxSueldo;

    if(!funciones_ValidIdStr(idStr,&auxID) &&
            funciones_isName(nombreStr) == 1 &&
            !funciones_ValidHorasTrabajadasStr(horasTrabajadasStr,&auxHorasTrabajadas)&&
            !funciones_ValidSueldoStr(sueldoStr,&auxSueldo))
    {

        if(
            !employee_setId(this,auxID)&&
            !employee_setNombre(this,nombreStr)&&
            !employee_setHorasTrabajadas(this,auxHorasTrabajadas)&&
            !employee_setSueldo(this,auxSueldo))
            return this;
    }
    else
    {
        printf("\nError! en validacion de parametros");
    }

    employee_delete(this);
    return NULL;
}

/** \brief
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

/** \brief
 *
 * \param this Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

/** \brief
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    //if(this!=NULL && funciones_isName(nombre)==1)
    if(this!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

/** \brief
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

/** \brief
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    //if(this!=NULL && funciones_isHorasTrabajadas(horasTrabajadas))
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

/** \brief
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

/** \brief
 *
 * \param this Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

/** \brief
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}
/** \brief Imprime en pantalla todos los empleados dentro del linkedList
 *
 * \param pEmployee Employee*
 * \return void
 *
 */
void employee_printEmployee(Employee* pEmployee)
{
    int bufferId;
    char bufferNombre[128];
    int bufferHorasTrabajadas;
    int bufferSueldo;

    if(pEmployee!= NULL)
    {
        if( !employee_getEmployee(pEmployee,&bufferId,bufferNombre,&bufferHorasTrabajadas,&bufferSueldo))
        {
            printf("\n%4d - %-20s - %-6d  - $%6d", bufferId,bufferNombre, bufferHorasTrabajadas,bufferSueldo);

        }
    }
}

/** \brief hace un get de todos los campos y los carga al elemento this
 *
 * \param this Employee*
 * \param id int*
 * \param nombre char*
 * \param horasTrabajadas int*
 * \param Sueldo int*
 * \return int
 *
 */
int employee_getEmployee(Employee* this,int* id,char* nombre, int* horasTrabajadas, int* Sueldo)
{

    int retorno =-1;


    if(this!= NULL)
    {
        if( !employee_getId(this,id)&&
                !employee_getNombre(this, nombre) &&
                !employee_getHorasTrabajadas(this,horasTrabajadas)&&
                !employee_getSueldo(this, Sueldo))
        {

            retorno =0;

        }
    }
    return retorno;
}

/** \brief compara dos empleados por nombre
 *
 * \param pEmployeeA void*
 * \param pEmployeeB void*
 * \return int
 *
 */
int employee_compareEmployee(void* pEmployeeA,void* pEmployeeB)
{
    if(strcmp(((Employee*)pEmployeeA)->nombre,((Employee*)pEmployeeB)->nombre)>0)
    {
        return 1;
    }
    else if(strcmp(((Employee*)pEmployeeA)->nombre,((Employee*)pEmployeeB)->nombre)<0)
    {
        return -1;
    }
    else

    return 0;

    /*
        if(((Employee*)pEmployeeA)->horasTrabajadas > ((Employee*)pEmployeeB)->horasTrabajadas)
        {
            return 1;
        }
        if(((Employee*)pEmployeeA)->horasTrabajadas < ((Employee*)pEmployeeB)->horasTrabajadas)
        {
            return -1;
        }
        return 0;

    */

}
