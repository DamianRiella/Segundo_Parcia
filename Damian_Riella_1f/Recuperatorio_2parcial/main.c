#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"

int main()
{
    int opc = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{

        printf ("\n ***************MENU PRINCIPAL*************\n\n");
        printf("1_Cargar archivo\n"
               "2_Imprimir vendedores\n"
               "3_Calcular comisiones\n"
               "4_Generar archivo de comisiones para nivel\n"
               "5_Salir\n");
        utn_getNumeroAvanzada(&opc, " \n \n Seleccione una opcion: "," \n Seleccione una opcion valida.", 1, 5,3);

        switch(opc)
        {

            case 1:
                system("cls");
                controller_loadFromText("DATA.csv",listaEmpleados);
                system("pause");
                break;
            case 2:
                system("cls");
                controller_ListEmployee(listaEmpleados);
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

        }
    }while(opc != 5);
    return 0;
}


