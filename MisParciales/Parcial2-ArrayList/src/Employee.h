#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    int sector;
    float salary;
    int isEmpty;
}Employee;

Employee* employee_new();
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setName(Employee* this,char* name);
int employee_getName(Employee* this,char* name);

int employee_setLastName(Employee* this,char* lastName);
int employee_getLastName(Employee* this,char* lastName);

int employee_setSector(Employee* this,int sector);
int employee_getSector(Employee* this,int* sector);

int employee_setSalary(Employee* this,float salary);
int employee_getSalary(Employee* this,float* salary);

int employee_setIsEmpty(Employee* this,int isEmpty);
int employee_getIsEmpty(Employee* this,int* isEmpty);

#endif // EMPLOYEE_H_INCLUDED
