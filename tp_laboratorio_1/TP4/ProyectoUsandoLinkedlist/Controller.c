#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "funciones_yg.h"
#include "controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno =-1;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        FILE* pArchivoEmpleados;
        pArchivoEmpleados = fopen(path,"r");
        if( ! parser_EmployeeFromText(pArchivoEmpleados,pArrayListEmployee))
        {
            retorno = 0;
        }

    }


    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
        int retorno =-1;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        FILE* pArchivoEmpleados;
        pArchivoEmpleados = fopen(path,"rb");
        if( ! parser_EmployeeFromBinary(pArchivoEmpleados,pArrayListEmployee))
        {
            retorno = 0;
        }

    }


    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno =-1;
    Employee* auxiliarPunteroEmployee =NULL;

    char bufferNombre[128];
    char bufferHorasTrabajadas[128];
    char bufferSueldo[128];
    int varTemporal;


    if(pArrayListEmployee!=NULL)
    {



        if( !funciones_getStringInput("\nAgregar Empledo.\nIngrese Nombre: ",128,bufferNombre) &&
                !funciones_getStringInput("\nIngrese Horas Trabajadas: ",128,bufferHorasTrabajadas) &&
                !funciones_getStringInput("\nIngrese Sueldo: ",128,bufferSueldo))
        {

            if( funciones_isName(bufferNombre) == 1 &&
                    !funciones_ValidHorasTrabajadasStr(bufferHorasTrabajadas,&varTemporal)&&
                    !funciones_ValidSueldoStr(bufferSueldo,&varTemporal))
            {
                auxiliarPunteroEmployee = (Employee*)employee_newParametros("-1",bufferNombre,bufferHorasTrabajadas,bufferSueldo);
            }
            else
            {
                printf("\nError! en validacion de parametros");
            }
        }
        else
        {
            printf("\nError! en ingreso de parametros");
        }

        if(auxiliarPunteroEmployee != NULL)
        {
            if(!ll_add(pArrayListEmployee,auxiliarPunteroEmployee))
            {
                retorno = 0;
                // printf("\nEmpleado Agregado Exitosamente");
            }


        }
    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno =-1;
    Employee* auxiliarPunteroEmployee =NULL;
    auxiliarPunteroEmployee = employee_new();
    int AuxID;
    int flagFoundEmployee= 0;
    char bufferNombre[128];
    char bufferHorasTrabajadas[128];
    char bufferSueldo[128];
    int auxHorasInt;
    int auxSueldoInt;
    int AuxPosArrayListEmployee;

    if(pArrayListEmployee!=NULL)
    {
        if(!funciones_getIntFromString("\nIngrese ID Employee A modificar: ","Id Fuera de Rango",3,0,10000,&AuxID))
        {

            AuxPosArrayListEmployee = controller_findEmployeeByID(pArrayListEmployee,AuxID);

            if(AuxPosArrayListEmployee>=0)
            {
                auxiliarPunteroEmployee = (Employee*)ll_get(pArrayListEmployee,AuxPosArrayListEmployee);

                if(auxiliarPunteroEmployee != NULL)
                {
                    flagFoundEmployee = 1;
                }
            }
            else
            {
                printf("\nID empleado no encontrado.\n");
            }
        }

        if(flagFoundEmployee == 1)
        {
            employee_printEmployee(auxiliarPunteroEmployee);

            if( !funciones_getStringInput("\nEditar Empledo.\nIngrese Nombre: ",128,bufferNombre) &&
                    !funciones_getStringInput("\nIngrese Horas Trabajadas: ",128,bufferHorasTrabajadas) &&
                    !funciones_getStringInput("\nIngrese Sueldo: ",128,bufferSueldo))
            {

                if( funciones_isName(bufferNombre) == 1 &&
                        !funciones_ValidHorasTrabajadasStr(bufferHorasTrabajadas,&auxHorasInt)&&
                        !funciones_ValidSueldoStr(bufferSueldo,&auxSueldoInt))
                {
                    if( !employee_setNombre(auxiliarPunteroEmployee, bufferNombre)&&
                            !employee_setHorasTrabajadas(auxiliarPunteroEmployee,auxHorasInt)&&
                            !employee_setSueldo(auxiliarPunteroEmployee, auxSueldoInt))
                    {
                        retorno = 0;
                    }


                }
                else
                {
                    printf("\nError! en validacion de parametros");
                }
            }
            else
            {
                printf("\nError! en ingreso de parametros");
            }


        }

    }



    return retorno;

}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int AuxID;
    int AuxPosArrayListEmployee;

    int retorno =  -1;

    if(pArrayListEmployee!= NULL)
    {
        if(!funciones_getIntFromString("\nIngrese ID Employee A Eliminar: ","Id Fuera de Rango",3,0,10000,&AuxID))
        {
            AuxPosArrayListEmployee = controller_findEmployeeByID(pArrayListEmployee,AuxID);

            if(AuxPosArrayListEmployee>=0)
            {
                if(!ll_remove(pArrayListEmployee,AuxPosArrayListEmployee))
                {
                    retorno = 0;
                }
            }
        }

    }


    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int lenList;
    int i;
    int retorno = -1;

    if(pArrayListEmployee !=NULL)
    {
        Employee* auxiliarPunteroEmployee;

        auxiliarPunteroEmployee = employee_new();

        lenList = ll_len(pArrayListEmployee);
         printf("\nID:  - NOMBRE:               - HORAS: - SUELDO:");
        for(i=0; i<lenList; i++)
        {
            auxiliarPunteroEmployee = (Employee*)ll_get(pArrayListEmployee,i);

            if(auxiliarPunteroEmployee != NULL)
            {
                employee_printEmployee(auxiliarPunteroEmployee);
                retorno = 0;
            }
        }
    }

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        if(!ll_sort(pArrayListEmployee,employee_compareEmployee,1))
            retorno = 0;
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno =-1;
    int i;
    int lenArrayList;

    int bufferId;
    char bufferNombre[128];
    int bufferHorasTrabajadas;
    int bufferSueldo;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        lenArrayList = ll_len(pArrayListEmployee);
        FILE* pArchivoEmpleados;
        Employee* auxiliarPunteroEmployee = NULL;
        auxiliarPunteroEmployee = employee_new();
        pArchivoEmpleados = fopen(path,"w");

        if(pArchivoEmpleados!=NULL )
        {
            fprintf(pArchivoEmpleados, "%s,%s,%s,%s\n", "id", "nombre", "horasTrabajadas", "sueldo");
            for(i=0; i<lenArrayList; i++)
            {
                auxiliarPunteroEmployee = (Employee*)ll_get(pArrayListEmployee,i);

                if(auxiliarPunteroEmployee != NULL)
                {

                    if(!employee_getEmployee(auxiliarPunteroEmployee,&bufferId,bufferNombre,&bufferHorasTrabajadas,&bufferSueldo))
                    {
                        fprintf(pArchivoEmpleados, "%i,%s,%i,%i\n", bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo);
                    }
                    else
                    {
                        printf("Error\n");
                    }
                    retorno = 0;
                }
            }

            fclose(pArchivoEmpleados);
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno =-1;
    int i;
    int lenArrayList;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        lenArrayList = ll_len(pArrayListEmployee);
        FILE* pArchivoEmpleados;
        Employee* auxiliarPunteroEmployee;
        auxiliarPunteroEmployee =employee_new();
        pArchivoEmpleados = fopen(path,"wb");

        if(pArchivoEmpleados!=NULL )
        {   //printf("open ok\n");
            for(i=0; i<lenArrayList; i++)
            {
                auxiliarPunteroEmployee = (Employee*)ll_get(pArrayListEmployee,i);

                if(auxiliarPunteroEmployee != NULL)
                {
                    fwrite(auxiliarPunteroEmployee,sizeof(Employee),1,pArchivoEmpleados);
                    retorno = 0;
                }
            }

            fclose(pArchivoEmpleados);
        }
    }
    return retorno;
}

/** \brief busca un empleado dentro del linkedllist por ID
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int
 * \return int
 *
 */
int controller_findEmployeeByID(LinkedList* pArrayListEmployee, int id)
{
    int retorno = -1;
    int i;
    int lenList;
    int AuxID;
    Employee* auxiliarPunteroEmployee=NULL;

    if( pArrayListEmployee != NULL)
    {
        lenList = ll_len(pArrayListEmployee);
        retorno = -2;
        for(i=0; i<lenList; i++)
        {

            auxiliarPunteroEmployee = (Employee*)ll_get(pArrayListEmployee,i);

            if(auxiliarPunteroEmployee != NULL)
            {
                if(employee_getId(auxiliarPunteroEmployee,&AuxID) == 0)
                    if(AuxID == id)
                    {
                        retorno = i;

                        break;
                    }
            }
        }
    }
    return retorno;
}

/** \brief Imprime en pantalla menu de Opciones Principal
 *
 * \param void
 * \return int
 *
 */
int controller_menuDeOpciones(void)
{
    int menu;
    printf("\n\nPROYECTO DE PRUEBA LINKEDLIST TP4\n");
    printf("\n\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto). \n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("3. Alta de empleado\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("4. Modificar datos de empleado\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("5. Baja de empleado\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("6. Listar empleados\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("7. Ordenar empleados\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("--------------------------------------------------------------------------------------\n");
    funciones_getIntFromString("10-SALIR.\n\nDigite opcion Deseada: ","la opcion no exite\n", 10, 1, 10, &menu);

    return menu;

}



