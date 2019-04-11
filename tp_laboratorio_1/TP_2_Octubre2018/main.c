#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funciones_yg.h"
#include "ArrayEmployees.h"


#define ELEMENTS 1000


int main()
{
    int retornoFunciones;
    int retornoMenu;

    char name_Aux[51];
    char lastName_Aux[51];
    float salary_Aux;
    int sectorAux;
    int idAux;
    double totalSalarios;
    double promedioSalarios;
    int qtySalarioSuperior;

    Employee arrayEmployees[ELEMENTS];
    retornoFunciones = initEmployees(arrayEmployees, ELEMENTS);


        employees_altaForzada(arrayEmployees,ELEMENTS,"Yesid","Guinard",8000.0,10);
        employees_altaForzada(arrayEmployees,ELEMENTS,"Dario","Silva",9000,21);
        employees_altaForzada(arrayEmployees,ELEMENTS,"Soledad","Escuer",21000,22);
        employees_altaForzada(arrayEmployees,ELEMENTS,"Martias","Escuer",21000,11);
        employees_altaForzada(arrayEmployees,ELEMENTS,"Marta","Vrana",15000,32);


    if(!retornoFunciones)
    {
        printf("\nSe inicializo array Empleados Correctamente!\n\n\n");
    }

    do
    {

        retornoMenu = funciones_menuDeOpciones();
        printf("opcion elegida:%i\n", retornoMenu);

        switch (retornoMenu)
        {
        case 1:
            if(!capDataEmployee(arrayEmployees, ELEMENTS,&idAux, name_Aux, lastName_Aux, &salary_Aux, &sectorAux ))
            {
                if(!addEmployee(arrayEmployees, ELEMENTS,idAux,name_Aux,lastName_Aux,salary_Aux,sectorAux))
                {
                    printf("\nSe cargo empleado Correctamente!");
                }
                else
                {
                    printf("\nError, No se cargo empleado Correctamente");
                }
            }
            else
            {
                printf("\nError, No se cargo Datos empleado Correctamente\n");
            }
            funciones_pause("\nPulse cualquier Tecla para Continuar");
            break;
        case 2:

            if(qtyEmployeeTotal(arrayEmployees,ELEMENTS)>0)
            {
                printEmployees(arrayEmployees,ELEMENTS );
                if(!funciones_getIntFromString("\nIngrese ID a Modificar: ","\nError!, Ingrese rango valido [0-10000]",3,0,10000,&idAux))
                {
                    if(!employees_modificacion(arrayEmployees,ELEMENTS,idAux))
                    {
                        printEmployees(arrayEmployees,ELEMENTS );
                        printf("\nModificacion Exitosa\n");
                    }
                    else
                    {
                        printf("\nError Modificacion Empleado Id invalida\n");
                    }
                }

            }
            else
            {
                printf("\nError No hay  Empleados Cargados\n");
            }
            funciones_pause("\nPulse cualquier Tecla para Continuar");
            break;
        case 3:

            if(qtyEmployeeTotal(arrayEmployees,ELEMENTS)>0)
            {

                printEmployees(arrayEmployees,ELEMENTS );
                if(!funciones_getIntFromString("\nIngrese ID a Eliminar: ","\nError!, Ingrese ID en rango valido [0-10000]",3,0,10000,&idAux))
                {
                    if(!removeEmployee(arrayEmployees,ELEMENTS,idAux))
                    {
                        printEmployees(arrayEmployees,ELEMENTS );
                        printf("\nEliminacion Exitosa\n");
                    }
                    else
                    {
                        printf("\nError No se elimino Empleado Id invalida\n");
                    }
                }
            }
            else
            {
                printf("\nError No hay  Empleados Cargados\n");
            }


            funciones_pause("\nPulse cualquier Tecla para Continuar");

            break;


        case 4:
            if(qtyEmployeeTotal(arrayEmployees,ELEMENTS)>0)
            {
                printEmployees(arrayEmployees,ELEMENTS );

                if(!totalSalaryEmployee(arrayEmployees,ELEMENTS,&totalSalarios,&promedioSalarios))
                {
                    printf("\nTotal de Salarios Empleados: $ %.2f\n", totalSalarios);
                    printf("\nPromedio de Salarios Empleados: $ %.2f\n", promedioSalarios);
                    if(!qtySalarySup(arrayEmployees,ELEMENTS,promedioSalarios,&qtySalarioSuperior))
                    {
                        printf("\nCantidad de Empleados con salario Superior al Promedio: %d\n", qtySalarioSuperior);
                    }
                }
            }
            else
            {
                printf("\nError No hay  Empleados Cargados\n");
            }

            funciones_pause("\nPulse cualquier Tecla para Continuar");
            break;
        }

    }
    while(retornoMenu!=5);

    return 0;
}
