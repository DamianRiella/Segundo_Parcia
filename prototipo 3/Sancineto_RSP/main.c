#include <stdio.h>
#include <stdlib.h>
#include "LinkedList/LinkedList.h"
#include "parser.h"
#include "UTN/utn.h"
#include "vendedor.h"

int main()
{
    int opt, flag = 0, otraFlag = 0, nivelBuffer = -1;
    LinkedList* listaVendedores = ll_newLinkedList();
    LinkedList* nuevaLista = ll_newLinkedList();

    do
    {
        system("cls");
        opt = ven_menu();

        switch (opt)
        {
        case 1:
            if (ven_parsearArchivo(listaVendedores))
            {
                printf("\nArchivo cargado con exito.\n");
                otraFlag = 1;
            }
            else
            {
                printf("\nError cargando el archivo.\n");
            }
            system("pause");
            break;
        case 2:
            if (otraFlag == 1)
            {
                ven_listarVendedores(listaVendedores);
                printf("\n\n");
                system("pause");
            }
            else
            {
                printf("\nDebe cargar el archivo");
            }
            break;
        case 3:
            if (otraFlag == 1)
            {
                ll_map(listaVendedores, ven_calcularComisiones);
                ven_listarVendedores(listaVendedores);
                flag = 1;
                printf("\n\n");
                system("pause");
            }
            else
            {
                printf("\nDebe cargar el archivo");
            }
            break;
        case 4:
            if (flag ==1)
            {
                nivelBuffer = utn_getValidInt("\nIngrese el nivel que desea: \n\n(0) Junior\n(1) Estandard\n(2) Experto\nOpcion: ",
                                              "Error, ingrese un nivel valido", 0, 2, 10);
                if (nivelBuffer == 0 )
                    nuevaLista = ll_filter(listaVendedores, ven_filtrarJunior);
                if (nivelBuffer == 1 )
                    nuevaLista = ll_filter(listaVendedores, ven_filtrarEstandard);
                if (nivelBuffer == 2 )
                    nuevaLista = ll_filter(listaVendedores, ven_filtrarExperto);

                if (ven_generarComisiones(nuevaLista))
                {
                    printf("\nArchivo generado con exito.\n");
                }
                else
                {
                    printf("\nError generando el archivo.\n");
                }
            }
            else
            {
                printf("\nDebe calcular comisiones");
            }
            printf("\n\n");
            system("pause");
        case 5:
            break;
        default:
            printf("\nIngrese una opcion valida");
        }
    }
    while (opt!= 5);
    return 0;
}
