#ifndef ARRAYEMPLOYEES_C_INCLUDED
#define ARRAYEMPLOYEES_C_INCLUDED

typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;



int initEmployees(Employee* list, int len);

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int capDataEmployee(Employee* list, int len, int *id, char name[],char lastName[],float *salary,int *sector);
int employees_altaForzada(Employee* list,int len,char* nombre,char* apellido, float salario, int sector);
int employees_modificacion(Employee* list,int len, int id);
int printEmployees(Employee* list, int length);
int findEmployeeById(Employee* list, int len,int id);
int sortEmployees(Employee* list,int len, int orden);
int removeEmployee(Employee* list, int len, int id);
int totalSalaryEmployee(Employee* list, int len, double *total, double *promedio);
int qtySalarySup(Employee *list, int len, double promedio, int *qtyEmployee);
int qtyEmployeeTotal(Employee *list, int len);
#endif // ARRAYEMPLOYEES_C_INCLUDED
