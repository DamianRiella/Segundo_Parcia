#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "Envios.h"

int main()
{
   int opc;
   char nombreArchivo[31], auxZona[31];
   LinkedList* listaEnvios= ll_newLinkedList();
   do
   {
       printf("\n************MENU PRINCIPAL**********\n\n");
       printf("1_Cargar Archivo.\n"
              "2_Imprimir Envios.\n"
              "3_Calcular Costo.\n"
              "4_Generar archivo de costo para zona.\n"
              "5_Imprimir lista de zona.\n"
              "6_Salir.\n");
       utn_getNumeroAvanzada(&opc, " \n \n Seleccione una opcion: "," \n Seleccione una opcion valida.", 1, 6,3);

       switch(opc){
            case 1:
                system("cls");
                printf("\nIngrese nombre del archivo:\n");
                scanf("%s",nombreArchivo);
                controller_loadFromText(nombreArchivo,listaEnvios);
                break;
            case 2:
                system("cls");
                controller_ListEmployee(listaEnvios);
                break;
            case 3:
                system("cls");
                ll_map(listaEnvios,envios_Costo);
                controller_ImprimeCosto(listaEnvios);
                break;
            case 4:
                system("cls");
                printf("Ingrese Zona:");
                scanf("%s",auxZona);
                controller_saveAsText(auxZona, listaEnvios);
                break;
            case 5:
                break;
       }
   }while(opc!=6);
   return 0;
}
