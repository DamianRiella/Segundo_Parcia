#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;

typedef struct
{
    int id;
    char nombre[128];
    int nivel;
    int cantProductos;
    float monto;
    int comision=NULL;
}eVendedor;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();
Employee* employee_newParametrosAddEmployee(int id, char* nombreStr, int horasTrabajadas, float sueldo);


int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);
int employee_sortByName(void* thisA,void* thisB);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,float sueldo);
int employee_getSueldo(Employee* this,float* sueldo);

eVendedor* vendedor(char* id,char* nombre,char* nivel, char* cantiProduc, char* montoVendido);
int set_cantidadProductos(eVendedor* this,int cantidad);
int set_montoVendido(eVendedor* this,float monto);
int set_Nivel(eVendedor* this,char nivel);

int employee_getMonto(eVendedor* this,float* monto);
int employee_getCantProduc(eVendedor* this,int* cantiProduc);
int employee_getNivel(eVendedor* this,int* nivel);
int employee_getNombre(eVendedor* this,char* nombre);
int employee_getId(eVendedor* this,int* id);




#endif // employee_H_INCLUDED
