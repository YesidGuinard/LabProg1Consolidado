#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "funciones_yg.h"

int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        option = controller_menuDeOpciones();

        switch(option)
        {
        case 1:

            if(!controller_loadFromText("data.csv",listaEmpleados))
                printf("\nArchivo data.csv Leido Exitosamente\n");
            else
                printf("\nError cargando archivo data.csv\n");
            break;
        case 2:
            if(!controller_loadFromBinary("data.bin", listaEmpleados))
                printf("\nArchivo data.bin Leido Exitosamente\n");
            else
                printf("\nError cargando archivo data.bin \n");
            break;
        case 3:
            if(!controller_addEmployee(listaEmpleados))
                printf("\nEmpleado Agregado Exitosamente\n");
            else
                printf("\nError agregando Empleado \n");
            break;
        case 4:
            if(!controller_editEmployee(listaEmpleados))
                printf("\nEmpleado editado Exitosamente\n");
            else
                printf("\nError editando Empleado \n");
            break;
        case 5:
            if(!controller_removeEmployee(listaEmpleados))
                printf("\nEmpleado eliminado Exitosamente\n");
            else
                printf("\nError eliminando Empleado \n");
            break;
        case 6:
            if(!controller_ListEmployee(listaEmpleados))
                printf("\nEmpleados Listados Exitosamente\n");
            else
                printf("\nError listando Empleados \n");
            break;
        case 7:
            if(!controller_sortEmployee(listaEmpleados))
                printf("\nEmpleados Ordenados Exitosamente\n");
            else
                printf("\nError Ordenando Empleados \n");
            break;
        case 8:
            if(!controller_saveAsText("data.csv",listaEmpleados))
                printf("\nEmpleados Guardandos Exitosamente en datatst.csv\n");
            else
                printf("\nError Guardando Empleados en datatst.csv\n");
            break;
        case 9:
            if(!controller_saveAsBinary("data.bin",listaEmpleados))
                printf("\nEmpleados Guardandos Exitosamente en data.bin\n");
            else
                printf("\nError Guardando Empleados en data.bin \n");

            break;
        }

        funciones_pause("\nPresione Una Tecla para continuar.");
        funciones_clearScreen();
    }
    while(option != 10);
    return 0;
}
