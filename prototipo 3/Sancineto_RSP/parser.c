#include <stdio.h>
#include <stdlib.h>
#include "LinkedList/LinkedList.h"
#include "vendedor.h"
#include "parser.h"

int parser_VendedorFromText(FILE* pFile, LinkedList* pArrayListVendedores)
{
    int returnAux = 0;
    char buffer[5][50];
    Vendedor* pVendedorAux;

    if (pFile != NULL && pArrayListVendedores != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
        while (!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
            pVendedorAux = ven_newParametros(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
            if (pVendedorAux != NULL)
            {
                ll_add(pArrayListVendedores, pVendedorAux);
                returnAux = 1;
            }
        }
    }
    return returnAux;
}


int parser_SaveToText(FILE* pFile, LinkedList* pArrayListVendedores)
{
    int returnAux = 0;
    Vendedor* pVendedorAux;
    int i, auxId, auxVendidos, auxMonto, auxComision, auxNivel;
    char auxNombre[50];

    if(pFile != NULL && pArrayListVendedores != NULL)
    {
        fprintf(pFile,"ID,Nombre_Vendedor,Nivel,cantidad_productos_vendidos,Monto_vendido,Comision\n");
        for(i=0; i<ll_len(pArrayListVendedores); i++)
        {
            pVendedorAux = ll_get(pArrayListVendedores,i);
            ven_getAll(pVendedorAux,&auxId, auxNombre,&auxNivel,&auxVendidos,&auxMonto);
            ven_getComision(pVendedorAux, &auxComision);
            fprintf(pFile,"%d,%s,%d,%d,%d,%d\n",auxId,auxNombre,auxNivel, auxVendidos,auxMonto,auxComision);
            returnAux = 1;
        }
    }
    return returnAux;
}


