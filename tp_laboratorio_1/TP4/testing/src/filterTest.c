#include "../../testing/utest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//INCLUDE LIBRARY TO TEST

#include "../../inc/LinkedList.h"
#include "../../testing/inc/Employee.h"


//DEFINES OF THIS TEST
#define LENGTH 6


static char* unsortedList[] = {"Za","Zb","Xd","Xb","Ya","Yc"};
static int sector[] = {1,1,2,3,4,6};
//static float salary[] = {1001,2000,1002,3000,4000,8000};
static float salary[] = {8000,14000,11000,2000,28000,1000};
static int id[] = {11,20,3,4,9,99};


void filterTestSetup(void)
{
    utest_print("Setup...\r\n");
}


void filterTestCase01(void)
{
    int r;
    int i;
    LinkedList* list;
    LinkedList* listFiltered;
    Employee* pAux[LENGTH];
    Employee* auxEmployee;

    list = ll_newLinkedList();
    listFiltered = ll_newLinkedList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        ll_add(list,pAux[i]);
        printEmployee(pAux[i]);
    }

    listFiltered = ll_filter(list, BigSalaryEmployee);

    printf("\n---------------------- nueva lista salarios >10000\n");
    int sizefiltered;
    if(listFiltered!=NULL)
    {

        sizefiltered = ll_len(listFiltered);

        for(r=0; r<sizefiltered; r++)
        {
            auxEmployee = ll_get(listFiltered,r);
            printEmployee(auxEmployee);
        }

        printf("\n-lista filtrada + map\n");
        if(ll_map(listFiltered,increaseSalaryEmployee)==0)
        {
            printf("\n-map success!\n");
            for(r=0; r<sizefiltered; r++)
            {
                auxEmployee = ll_get(listFiltered,r);
                printEmployee(auxEmployee);
            }
        }


    }





    //utest_assertEqualsIntMsg(r,0,"\nError en el valor de retorno de <sort> si los parametros son correctos\n la funcion retorna 0\n");

}


void filterTestCase02(void)
{
    /*int i;
     LinkedList* list;
     Employee* pAux[LENGTH];
     Employee* pAuxGet[LENGTH];

     list = ll_newLinkedList();

     for(i=0; i < LENGTH; i++)
     {
         pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
         ll_add(list,pAux[i]);
     }

     ll_sort(list, compareEmployee,0);

     for(i=0; i < LENGTH; i++)
     {
         pAuxGet[i] = ll_get(list,i);
         utest_assertNotNullMsg(pAuxGet[i],"Error al intentar obtener un elemento luego de ordenar");
         utest_assertEqualsFloatMsg(((Employee*)pAuxGet[i])->salary,salarySortedUp[i],"El orden de la lista es incorrecto");
     }*/

}
