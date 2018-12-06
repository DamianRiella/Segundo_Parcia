#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN.h"
#include "Linkedlist.h"
#include "Employee.h"
#include "Controller.h"
#include "Parser.h"



/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int opc = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{

        printf ("\n ***************MENU PRINCIPAL*************\n");
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
                 "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
                 "3. Alta de empleado\n"
                 "4. Modificar datos de empleado\n"
                 "5. Baja de empleado\n"
                 "6. Listar empleados\n"
                 "7. Ordenar empleados\n"
                 "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
                 "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
                "10. Salir\n");
        utn_getNumeroAvanzada(&opc, " \n \n Seleccione una opcion: "," \n Seleccione una opcion valida.", 1, 10,3);

        switch(opc)
        {

            case 1:
                system("cls");
                controller_loadFromText("data.csv",listaEmpleados);
                system("pause");
                break;
            case 2:
                system("cls");
                controller_loadFromBinary("data.csv",listaEmpleados);
                system("pause");
                break;
            case 3:
                system("cls");
                controller_addEmployee(listaEmpleados);
                system("pause");
                break;
            case 4:
                system("cls");
                controller_editEmployee(listaEmpleados);
                system("pause");
                break;
            case 5:
                system("cls");
                controller_removeEmployee(listaEmpleados);
                system("pause");
                break;
            case 6:
                system("cls");
                controller_ListEmployee(listaEmpleados);
                system("pause");
                break;
            case 7:
                system("cls");
                controller_sortEmployee(listaEmpleados);
                system("pause");
                break;
            case 8:
                system("cls");
                controller_saveAsText("data.csv",listaEmpleados);
                system("pause");
                break;
            case 9:
                system("cls");
                controller_saveAsBinary("data.csv",listaEmpleados);
                system("pause");
                break;
        }
    }while(opc != 10);
    return 0;
}
