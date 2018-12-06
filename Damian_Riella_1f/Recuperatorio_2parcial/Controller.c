#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int retorno=-1;
    pFile=fopen(path,"r");
    if(pFile!=NULL){
        parser_EmployeeFromText(pFile ,pArrayListEmployee);
        retorno=0;
    }
    else{
        printf("No se pudo abriri el archivo.");
        getchar();
    }
    return retorno;
}
/**********************************************************************************************/


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    if(path != NULL && pArrayListEmployee != NULL )
    {
        FILE *pFile;

        pFile=fopen(path,"rb");

        if(pFile!=NULL)
        {
            parser_EmployeeFromBinary(pFile, pArrayListEmployee);

            return 0;

        }
        else
        {
            printf("\n ERROR PUNTEROS NULL");
            fclose(pFile);
            return -1;
        }
    }
    else
    {
        printf("\n ERROR PUNTEROS NULL");
        return -1;
    }

}
/**************************************************************************************/


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int aux1, aux3, aux4, respuesta;
    char aux2[50];

    if(pArrayListEmployee != NULL )
    {
        do
        {
            utn_getNumeroAvanzada(&aux1, "Ingrese ID \n", "ERROR EN EL INGRESO DEL ID \n", 1, 10000, 10);
            utn_getCadenaDeCaracteresAvanzada( aux2, "Ingrese NOMBRE \n", "ERROR EN EL INGRESO DEL NOMBRE \n",10 );
            utn_getNumeroAvanzada(&aux3, "Ingrese HORAS TRABAJADAS \n", "ERROR EN EL INGRESO DE HORAS TRABAJADAS \n", 1, 10000, 10 );
            utn_getNumeroAvanzada(&aux4, "Ingrese SUELDO \n", "ERROR EN EL INGRESO DEL SUELDO \n", 1, 1000000, 10 );

            Employee* employeeAdd= employee_newParametrosAddEmployee(aux1, aux2, aux3, aux4);

            ll_add(pArrayListEmployee,employeeAdd);

            utn_getNumeroAvanzada(&respuesta, "Desea continuar ingresando los datos ?: 1 (si) / 0 (no) \n", "ERROR", 0, 1, 3);

        } while (respuesta == 1);

        return 1;
    }
    else
    {
        printf("\n ERROR PUNTEROS NULL");
        return -1;
    }

    return 1;
}
/*****************************************************************************************/


int controller_editEmployee(LinkedList* pArrayListEmployee)
 {
     int retorno = -1;
     int i, id, idAux, auxSueldo, auxHotasT;
     int opcion, opcionDos;
     char auxNombre[51];


     utn_getNumeroAvanzada(&opcion, "Desea ver la lista de empleados? ?: 1 (si) / 0 (no) \n", "ERROR", 0, 1, 3);

     if(opcion==1)
     {
         controller_ListEmployee(pArrayListEmployee);
     }

     if(pArrayListEmployee != NULL)
     {
         if(utn_getNumeroAvanzada(&id,"Ingrese el ID del empleado a modificar: ","Reingrese un numero valido", 0, 2000, 10)==1)
         {
             for(i = 0;i< ll_len(pArrayListEmployee);i++)
             {
                Employee* empleado = ll_get(pArrayListEmployee,i);

                employee_getId(empleado, &idAux);

                if(idAux == id)
                {
                    do
                    {
                        utn_getNumeroAvanzada(&opcionDos,"QUE CAMPO DESEA MODIFICAR ??:\n 1- Nombre \n 2- Horas de trabajo \n 3- Sueldo \n 4- SALIR \n","Reingrese OPCION VALIDA", 1, 4, 10);

                        switch(opcionDos)

                        {
                            case 1:

                                if(utn_getCadenaDeCaracteresAvanzada( auxNombre, "Ingrese NOMBRE \n", "ERROR EN EL INGRESO DEL NOMBRE \n",10 )==1)
                                {
                                     if(!employee_setNombre(empleado, auxNombre))
                                       {
                                         retorno = 0;
                                         break;
                                       }
                                }
                            break;

                            case 2:

                                if(utn_getNumeroAvanzada(&auxHotasT, "Ingrese HORAS TRABAJADAS \n", "ERROR EN EL INGRESO DE HORAS TRABAJADAS \n", 1, 10000, 10 )==1)
                                {
                                     if(!employee_setHorasTrabajadas(empleado, auxHotasT))
                                       {
                                         retorno = 0;
                                         break;
                                       }
                                }

                            break;

                            case 3:

                                if(utn_getNumeroAvanzada(&auxSueldo, "Ingrese SUELDO \n", "ERROR EN EL INGRESO DEL SUELDO \n", 1, 10000, 10 )==1)
                                {
                                    if(!employee_setSueldo(empleado, auxSueldo))
                                       {
                                         retorno = 0;
                                         break;
                                       }
                                }

                            break;
                        }

                    }while (opcionDos!= 4);
                }
             }
         }
     }

     return retorno;
 }

/***************************************************************************************/

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i, id, idAux;
    int opcion, opcionDos;

    do
    {
        utn_getNumeroAvanzada(&opcionDos,"\n QUE DESEA REALIZAR:\n \n 1- ELIMINAR EMPLEADO \n 2- SALIR \n ","Reingrese OPCION VALIDA", 0, 2, 10);

        switch(opcionDos)
        {
            case 1:

            utn_getNumeroAvanzada(&opcion, "Desea ver la lista de empleados? ?: 1 (si) / 0 (no) \n", "ERROR", 0, 1, 3);

            if(opcion==1)
            {
             controller_ListEmployee(pArrayListEmployee);
            }

            if(pArrayListEmployee != NULL)
            {
                if(utn_getNumeroAvanzada(&id,"Ingrese el ID del empleado a ELIMINAR: \n","Reingrese un numero valido", 0, 2000, 10)==1)
                {
                     for(i = 0;i< ll_len(pArrayListEmployee);i++)
                     {
                        Employee* empleado = ll_get(pArrayListEmployee,i);

                        employee_getId(empleado, &idAux);

                        if(idAux == id)
                        {
                            employee_delete(empleado);
                            ll_remove(pArrayListEmployee,i);

                            retorno = 0;

                            break;
                        }
                     }
                }
            }

            break;
        }

    }while (opcionDos!= 2);

    return retorno;
}

/***********************************************************************************************/

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
     int retorno = -1;
     int i;
     char nombre[128];
     int id, nivel,cantProductos;
     float monto;
     eVendedor* auxPunteroEmpleado;

     if(pArrayListEmployee != NULL)
     {
         for(i=0;i < ll_len(pArrayListEmployee);i++)
         {
            if(i%50==0)
            {
                system("pause");

                 auxPunteroEmpleado = ll_get(pArrayListEmployee,i);

                 employee_getId(auxPunteroEmpleado,&id);
                 employee_getNombre(auxPunteroEmpleado,nombre);
                 employee_getMonto(auxPunteroEmpleado,&monto);
                 employee_getNivel(auxPunteroEmpleado,nivel);
                 employee_getCantProduc(auxPunteroEmpleado,&cantProductos);

                 printf("\nID: %d",id);
                 printf("\nNombre: %s",nombre);
                 printf("\nNivel: %d",nivel);
                 printf("\nNivel: %d",cantProductos);
                 printf("\nMonto: %0.2f",monto);
                 printf("\n");
                 retorno = 0;
            }
            else
            {
                auxPunteroEmpleado = ll_get(pArrayListEmployee,i);

                 employee_getId(auxPunteroEmpleado,&id);
                 employee_getNombre(auxPunteroEmpleado,nombre);
                 employee_getMonto(auxPunteroEmpleado,&monto);
                 employee_getNivel(auxPunteroEmpleado,nivel);
                 employee_getCantProduc(auxPunteroEmpleado,&cantProductos);

                 printf("\nID: %d",id);
                 printf("\nNombre: %s",nombre);
                 printf("\nNivel: %d",nivel);
                 printf("\nNivel: %d",cantProductos);
                 printf("\nMonto: %0.2f",monto);
                 printf("\n");
                 retorno = 0;

            }
         }
     }
     else
     {
        printf("\n ERROR PUNTEROS NULL");
        retorno=-1;

     }
     system("pause");

     return retorno;
}
/************************************************************************************/

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        printf("\n Ordenando...\n");

        if(! ll_sort(pArrayListEmployee,employee_sortByName,1))
        {
            controller_ListEmployee(pArrayListEmployee);
            retorno = 0;
        }
    }

    return retorno;
}
/*************************************************************************************/


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE *pFile;
    pFile = fopen(path,"w");
    if(pFile != NULL && path != NULL)
    {
        parser_EmployeeFromText(pFile, pArrayListEmployee);
        return 0;
    }
    else
    {
        fclose(pFile);
        return -1;
    }

}
/**********************************************************************************/

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    if(path != NULL && pArrayListEmployee != NULL )
    {
        FILE *pFile;
        pFile=fopen(path,"wb");

        if(pFile!=NULL)
        {
            parser_EmployeeFromBinary(pFile, pArrayListEmployee);

            return 0;

        }
        else
        {
            printf("\n ERROR PUNTEROS NULL");
            fclose(pFile);
            return -1;
        }
    }
    else
    {
        printf("\n ERROR PUNTEROS NULL");
        return -1;
    }

}

