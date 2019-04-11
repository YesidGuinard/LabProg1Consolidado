/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/ArrayList.h"
#include "../inc/Employee.h"



int main()
{
        startTesting(1);
        startTesting(2);
        startTesting(3);
        startTesting(4);
        startTesting(5);
        startTesting(6);
        startTesting(7);
        startTesting(8);
        startTesting(9);
        startTesting(10);
        startTesting(11);
        startTesting(12);
        startTesting(13);
        startTesting(14);
        startTesting(15);
        startTesting(16);
        startTesting(17);

        ArrayList* lista;
        lista=al_newArrayList();
        Employee* empleado[10];
        Employee* pruebaPop;
        Employee* pruebaPush;

        int i;

        empleado[0]=newEmployee(0,"Aorge","Aorge",10500,1);
        empleado[1]=newEmployee(1,"Borge","Borge",20500,2);
        empleado[2]=newEmployee(2,"Corge","Corge",30500,3);
        empleado[3]=newEmployee(3,"Dorge","Dorge",40500,4);
        empleado[4]=newEmployee(4,"Eorge","Eorge",50500,5);

        al_add(lista,empleado[0]);
        al_add(lista,empleado[1]);
        al_add(lista,empleado[2]);
        al_add(lista,empleado[3]);
        al_add(lista,empleado[4]);




        for(i=0;i<al_len(lista);i++)
        {
            pruebaPop=al_get(lista,i);
            printf("index: %d - Nombre: %s\n",i,pruebaPop->name);
        }

        printf("\nOrdeno el array\n\n");
        al_sort(lista,compareEmployee,0);
        for(i=0;i<al_len(lista);i++)
        {
            pruebaPop=al_get(lista,i);
            printf("index: %d - Nombre: %s\n",i,pruebaPop->name);
        }


        pruebaPop=al_pop(lista,3);

        printf("\nPopeo index 3: %s\n\n",pruebaPop->name);
        for(i=0;i<al_len(lista);i++)
        {
            pruebaPop=al_get(lista,i);
            printf("index: %d - Nombre: %s\n",i,pruebaPop->name);
        }

        printf("\nPusheo a Forge en index 3\n\n");
        pruebaPop=newEmployee(4,"Forge","Forge",60500,6);
        al_push(lista,3,pruebaPop);

        for(i=0;i<al_len(lista);i++)
        {
            pruebaPop=al_get(lista,i);
            printf("index: %d - Nombre: %s\n",i,pruebaPop->name);
        }

        printf("\nOrdeno el array\n\n");
        al_sort(lista,compareEmployee,0);
        for(i=0;i<al_len(lista);i++)
        {
            pruebaPop=al_get(lista,i);
            printf("index: %d - Nombre: %s\n",i,pruebaPop->name);
        }

        printf("\nBorro a index 0, retorno da %d\n\n",al_remove(lista,0));


        for(i=0;i<al_len(lista);i++)
        {
            pruebaPop=al_get(lista,i);
            printf("index: %d - Nombre: %s %p\n",i,pruebaPop->name,pruebaPop);
        }

        printf("\nOrdeno el array\n\n");
        al_sort(lista,compareEmployee,1);
        for(i=0;i<al_len(lista);i++)
        {
            pruebaPop=al_get(lista,i);
            printf("index: %d - Nombre: %s\n",i,pruebaPop->name);
        }

    return 0;


}





