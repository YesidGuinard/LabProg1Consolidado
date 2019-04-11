#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "funciones_yg.h"
#include "Controller.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna 0 si OK sino -1
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno =-1;

    if(pFile!= NULL && pArrayListEmployee!=NULL)
    {

        Employee* auxiliarPunteroEmployee = NULL;

        int flagOnce=1;
        char bufferId[128];
        int auxID;
        char bufferNombre[128];
        char bufferHorasTrabajadas[128];
        char bufferSueldo[128];
        int contadorEmployees=0;

        do
        {
            if(flagOnce)
            {
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
                       bufferId,
                       bufferNombre,
                       bufferHorasTrabajadas,
                       bufferSueldo);
                flagOnce = 0;
            }
            else
            {

                if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
                          bufferId,
                          bufferNombre,
                          bufferHorasTrabajadas,
                          bufferSueldo) == 4)
                {

                    if(!funciones_ValidIdStr(bufferId,&auxID))
                    {
                        if( controller_findEmployeeByID(pArrayListEmployee,auxID) <0 )
                        {
                            auxiliarPunteroEmployee = (Employee*)employee_newParametros(bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
                        }
                        else
                        {
                            printf("\nError, ID ya existe.\n");
                            auxiliarPunteroEmployee = NULL;
                        }
                    }


                    if(auxiliarPunteroEmployee != NULL)
                    {
                        ll_add(pArrayListEmployee,auxiliarPunteroEmployee);
                        contadorEmployees++;
                    }
                    else
                    {
                        printf("\n No se puede Agregar Empleado ID: %s\n",bufferId);
                    }
                }
                else
                {
                    break;
                }
            }
        }
        while(!feof(pFile));
        fclose(pFile);
        printf("\n Se Cargaron: %i Empleados\n",contadorEmployees);
        retorno = 0;
    }

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna 0 si OK sino -1
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    int retorno =-1;
    int auxID;
    char auxNombre[128];
    int auxHorasTrabajadas;
    int auxSueldo;



    if(pFile!= NULL && pArrayListEmployee!=NULL)
    {

        Employee* auxiliarPunteroEmployee;


        int contadorEmployees=0;

        do
        {
            auxiliarPunteroEmployee = employee_new();

            fread(auxiliarPunteroEmployee,sizeof(Employee),1,pFile);

            if(!employee_getEmployee(auxiliarPunteroEmployee,&auxID,auxNombre,&auxHorasTrabajadas,&auxSueldo)&& !feof(pFile))
            {
                if( funciones_isID(auxID) == 1 &&
                        funciones_isName(auxNombre) == 1 &&
                        funciones_isHorasTrabajadas(auxHorasTrabajadas) == 1 &&
                        funciones_isSueldo(auxSueldo))
                {

                    if( controller_findEmployeeByID(pArrayListEmployee,auxID) <0 )
                    {
                        ll_add(pArrayListEmployee,auxiliarPunteroEmployee);
                        contadorEmployees++;
                    }
                    else
                    {
                        printf("\nError, ID ya existe.\n");
                        employee_delete(auxiliarPunteroEmployee);
                    }

                }

            }


        }
        while(!feof(pFile));
        fclose(pFile);
        printf("\n Se Cargaron: %i Empleados\n",contadorEmployees);
        retorno = 0;


    }


    return retorno;
}



