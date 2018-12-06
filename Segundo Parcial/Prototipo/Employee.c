#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"

/****************************************/
/*****************EMPLEADOS**************/

Employee* employee_new()
{
    Employee* empleado = (Employee*)malloc(sizeof(Employee));
    return empleado;
}
/**************************************************************/

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    int id, horas, sueldo;
    Employee* ptr=NULL;

    ptr= employee_new();
    if(ptr!=NULL){

    id= atoi(idStr);
    horas= atoi(horasTrabajadasStr);
    sueldo= atof(sueldoStr);

    employee_setId(ptr,id);
    employee_setNombre(ptr,nombreStr);
    employee_setHorasTrabajadas(ptr,horas);
    employee_setSueldo(ptr,sueldo);
    }
    else{
        printf("\nError.");
    }

    return ptr;

}
/*************************************************************************/

void employee_delete(Employee* this){


        if(this != NULL)
        {
             free(this);

        }

    return;

}
/********************************************/
/****************SETER***********************/

int employee_setId(Employee* this,int id){

    int retorno=-1;
        if(id > 0){
            this->id = id;
            retorno=0;
        }
        else{
            printf("Error.No se pudo cargar Id.");
            getchar();
        }
         return retorno;
}
/*************************************************************************/

int employee_setNombre(Employee* this,char* nombre){

    int retorno=-1;
        if(nombre[0] != '\0'){
            strncpy(this->nombre, nombre, sizeof(this->nombre));
            retorno=0;
        }
        else{
            printf("Error.No se pudo cargar nombre.");
            getchar();
        }
    return retorno;
}
/*************************************************************************/

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){

    int retorno=-1;
        if(horasTrabajadas > 0){
            this->horasTrabajadas = horasTrabajadas;
            retorno=0;
        }
         else{
            printf("Error.No se pudo cargar las horas trabajadas.");
            getchar();
        }
    return retorno;
}
/**************************************************************************/

int employee_setSueldo(Employee* this,float sueldo){

    int retorno=-1;
        if(sueldo>0 && sueldo<1000000){
            this->sueldo = sueldo;
            retorno=0;
        }
        else{
            printf("Error.No se pudo cargar el sueldo.");
            getchar();
        }
    return retorno;
}
/***************************************/
/****************GETERS****************/

int employee_getId(Employee* this,int* id){

  int retorno=-1;

    if(this!=NULL)
    {
        *id = this->id;
        retorno=0;
    }
    return retorno;
}
/****************************************************************************/

int employee_getNombre(Employee* this,char* nombre){

  int retorno=-1;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}
/****************************************************************************/

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){

  int retorno=-1;

    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}
/***************************************************************************/

int employee_getSueldo(Employee* this,float* sueldo){

int retorno=-1;

    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}
/**************************************************************************/

Employee* employee_newParametrosAddEmployee(int id, char* nombreStr, int horasTrabajadas, float sueldo)
{
    Employee* this = employee_new();

    if (this != NULL)
    {
        employee_setId(this, id);
        employee_setNombre(this, nombreStr);
        employee_setHorasTrabajadas(this, horasTrabajadas);
        employee_setSueldo(this, sueldo);

        return this;

      }
    else
    {
        printf("ERROR, PUNTERO NULL");

        return NULL;
    }
}
/***********************************************************************/

int employee_sortByName(void* thisA,void* thisB)
{
    int retorno = 0;

    char nameA[51];
    char nameB[51];

   employee_getNombre(thisA,nameA);
   employee_getNombre(thisB,nameB);

   if(strcmp(nameA,nameB) > 0)
   {
        retorno = 1;
   }
   else if(strcmp(nameA,nameB)< 0)
   {
        retorno = -1;
   }

    return retorno;
}




