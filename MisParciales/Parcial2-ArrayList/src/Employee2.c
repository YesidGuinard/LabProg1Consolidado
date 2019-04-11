#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Employee* employee_new()
{
    Employee* this;
    this=malloc(sizeof(Employee));
    return this;
}

void employee_delete(Employee* this)
{
    free(this);
}

int employee_setId(Employee* this,int id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

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

int employee_setName(Employee* this,char* name)
{
    int retorno=-1;
    if(this!=NULL && name!=NULL)
    {
        strcpy(this->name,name);
        retorno=0;
    }
    return retorno;
}

int employee_getName(Employee* this,char* name)

{
    int retorno=-1;
    if(this!=NULL && name!=NULL)
    {
        strcpy(name,this->name);
        retorno=0;
    }
    return retorno;
}

int employee_setLastName(Employee* this,char* lastName)
{
    int retorno=-1;
    if(this!=NULL && lastName!=NULL)
    {
        strcpy(this->lastName,lastName);
        retorno=0;
    }
    return retorno;
}

int employee_getLastName(Employee* this,char* lastName)

{
    int retorno=-1;
    if(this!=NULL && lastName!=NULL)
    {
        strcpy(lastName,this->lastName);
        retorno=0;
    }
    return retorno;
}

int employee_setSector(Employee* this,int sector)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->sector=sector;
        retorno=0;
    }
    return retorno;
}

int employee_getSector(Employee* this,int* sector)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sector=this->sector;
        retorno=0;
    }
    return retorno;
}

int employee_setSalary(Employee* this,float salary)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->salary=salary;
        retorno=0;
    }
    return retorno;
}

int employee_getSalary(Employee* this,float* salary)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *salary=this->salary;
        retorno=0;
    }
    return retorno;
}

int employee_setIsEmpty(Employee* this,int isEmpty)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->isEmpty=isEmpty;
        retorno=0;
    }
    return retorno;
}

int employee_getIsEmpty(Employee* this,int* isEmpty)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *isEmpty=this->isEmpty;
        retorno=0;
    }
    return retorno;
}

