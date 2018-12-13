#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList/LinkedList.h"
#include "vendedor.h"
#include "UTN/utn.h"
#include "parser.h"

/**
 * \brief ultimoId cuenta los id para vincularlo directamente con el espacio del array de indice
 * \return id el ultimo numero contado
 *
 */


int ven_menu()
{
    int opt=0;

    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    printf("\n||                                                           ||");
    printf("\n||\t\t\t   *** MENU ***                      ||");
    printf("\n||                                                           ||");
    printf("\n||\t(1). Cargar archivo\t\t\t\t     ||");
    printf("\n||\t(2). Imprimir vendedores  \t\t\t     ||");
    printf("\n||\t(3). Calcular comisiones                             ||");
    printf("\n||\t(4). Generar archivo de comisiones para nivel        ||");
    printf("\n||\t(5). Salir\t\t                             ||");
    printf("\n||                                                           ||");
    printf("\n||\t\t   *** ELIJA UNA OPCION ***                  ||");
    printf("\n||                                                           ||");
    printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    printf("\n\nOpcion: ");
    scanf("%d", &opt);

    return opt;
}

Vendedor* ven_new()
{
    Vendedor* newVendedor;
    newVendedor = (Vendedor*) malloc(sizeof(Vendedor));
    return newVendedor;
}

Vendedor* ven_newParametros(char* idStr, char *nombreStr, char* nivelStr, char* vendidosStr, char* montoStr)
{
    Vendedor* newVendedor = ven_new();
    int idAux, vendidosAux, montoAux, nivelAux;

    if (idStr != NULL && nombreStr != NULL && nivelStr != NULL && vendidosStr != NULL && montoStr != NULL)
    {
        vendidosAux = atoi(vendidosStr);
        montoAux = atoi(montoStr);
        idAux = atoi(idStr);
        nivelAux = atoi(nivelStr);

        ven_setId(newVendedor, idAux);
        ven_setNombre(newVendedor, nombreStr);
        ven_setNivel(newVendedor, nivelAux);
        ven_setVendidos(newVendedor, vendidosAux);
        ven_setMonto(newVendedor, montoAux);
    }
    return newVendedor;
}

int ven_getId (Vendedor* this, int* id)
{
    int returnAux = 0;
    if (this != NULL && id != NULL)
    {
        *id = this->id;
        returnAux = 1;
    }
    return returnAux;
}

int ven_getNombre (Vendedor* this, char* nombre)
{
    int returnAux = 0;
    if (this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        returnAux = 1;
    }
    return returnAux;
}

int ven_getNivel (Vendedor* this, int* nivel)
{
    int returnAux = 0;
    if (this != NULL && nivel != NULL)
    {
        *nivel= this->nivel;
        returnAux = 1;
    }
    return returnAux;
}

int ven_getVendidos (Vendedor* this, int* vendidos)
{
    int returnAux = 0;
    if (this != NULL && vendidos != NULL)
    {
        *vendidos = this->vendidos;
        returnAux = 1;
    }
    return returnAux;
}

int ven_getMonto (Vendedor* this, int* monto)
{
    int returnAux = 0;
    if (this != NULL && monto != NULL)
    {
        *monto = this->monto;
        returnAux = 1;
    }
    return returnAux;
}



int ven_setId(Vendedor* this, int id)
{
    int returnAux=0;

    if(this!=NULL && id > 0)
    {
        this->id = id;

        returnAux = 1;
    }
    return returnAux;
}

int ven_setNombre(Vendedor* this, char *nombre)
{
    int returnAux = 0;
    if (this != NULL && nombre != NULL)
    {
        strcpy(this->nombre,nombre);
        returnAux = 1;
    }
    return returnAux;
}

int ven_setNivel(Vendedor* this, int nivel)
{
    int returnAux = 0;
    if (this != NULL && nivel <3)
    {
        this->nivel = nivel;
        returnAux = 1;
    }
    return returnAux;
}

int ven_setVendidos(Vendedor* this, int vendidos)
{
    int returnAux = 0;
    if (this != NULL && vendidos >0)
    {
        this->vendidos = vendidos;
        returnAux = 1;
    }
    return returnAux;
}

int ven_setMonto(Vendedor* this, int monto)
{
    int returnAux = 0;
    if (this != NULL && monto >0)
    {
        this->monto = monto;
        returnAux = 1;
    }
    return returnAux;
}


int ven_getAll(Vendedor* this,int* id, char* nombre,int* nivel,int* vendidos,int* monto)
{
    int returnAux = 0;

    if(this != NULL)
    {
        ven_getId(this,id);
        ven_getNombre(this,nombre);
        ven_getNivel(this,nivel);
        ven_getVendidos(this,vendidos);
        ven_getMonto(this,monto);
        returnAux = 1;
    }
    return returnAux;
}

int ven_parsearArchivo(LinkedList* this)
{
    int returnAux = 0;
    FILE* pFile;
    char path[50];

    utn_getString("Ingrese el nombre del archivo: ", path);

    if (path != NULL && this != NULL)
    {
        pFile = fopen(path, "r");
        if(parser_VendedorFromText(pFile,this))
        {
            returnAux = 1;
        }
        fclose(pFile);
    }
    return returnAux;
}


int ven_listarVendedores(LinkedList* this)
{
    int i, idAux, vendidosAux, montoAux, returnAux = 0, nivelAux, comisionAux;
    char nombreAux[50];
    Vendedor* vendedorAux;

    if (this != NULL)
    {
        for (i=0; i<ll_len(this); i++)
        {
            vendedorAux = ll_get(this, i);
            ven_getAll(vendedorAux, &idAux, nombreAux, &nivelAux, &vendidosAux, &montoAux);

            printf("\n\n********VENDEDOR********");
            printf("\n*");
            printf("\n* ID: %d", idAux);
            printf("\n* Nombre: %s", nombreAux);
            printf("\n* Nivel: %d", nivelAux);
            printf("\n* Cantidad vendidos: %d", vendidosAux);
            printf("\n* Monto vendidos: %d", montoAux);
            if (ven_getComision(vendedorAux, &comisionAux) && comisionAux != 0)
            printf("\n* Comision: %d", comisionAux);
            printf("\n*");
            printf("\n************************");
        }
        returnAux = 1;
    }
    return returnAux;
}

int ven_calcularComisiones(Vendedor* this)
{
    int returnAux = 0, comision, nivel, monto, vendidos;

    if (ven_getNivel(this, &nivel) && ven_getMonto(this, &monto) && ven_getVendidos(this, &vendidos))
    {
        if (nivel == 0)
        {
            comision = monto * 0.02;
        }

        if ((nivel == 1) || (nivel == 2))
        {
            if (vendidos > 100)
            {
                comision = monto * 0.05;
            }
            else
            {
                comision = monto * 0.035;
            }
        }
        if (ven_setComision(this, comision))
        returnAux = 1;
    }

    return returnAux;
}

int ven_setComision(Vendedor* this, int comision)
{
    int returnAux = 0;

    if (this != NULL && comision >0)
    {
        this->comision = comision;
        returnAux = 1;
    }
    return returnAux;
}


int ven_getComision(Vendedor* this, int* comision)
{
    int returnAux = 0;

    if (this != NULL && comision != NULL)
    {
        *comision = this->comision;
        returnAux = 1;
    }
    return returnAux;
}


int ven_generarComisiones (LinkedList* this)
{
    int returnAux = 0;
    char nivel[50];
    FILE* pNewFile;

    if (this != NULL)
    {
    pNewFile = fopen("newData.csv", "w");
    parser_SaveToText(pNewFile, this);
    fclose(pNewFile);
    returnAux = 1;
    }
    return returnAux;
}


int ven_filtrarJunior(Vendedor* this)
{
    int returnAux = 0, nivelAux;

    if (this != NULL)
    {
        ven_getNivel(this, &nivelAux);

        if (nivelAux == 0)
            returnAux = 1;
    }
    return returnAux;
}

int ven_filtrarEstandard(Vendedor* this)
{
    int returnAux = 0, nivelAux;

    if (this != NULL)
    {
        ven_getNivel(this, &nivelAux);

        if (nivelAux == 1)
            returnAux = 1;
    }
    return returnAux;
}

int ven_filtrarExperto(Vendedor* this)
{
    int returnAux = 0, nivelAux;

    if (this != NULL)
    {
        ven_getNivel(this, &nivelAux);

        if (nivelAux == 2)
            returnAux = 1;
    }
    return returnAux;
}
