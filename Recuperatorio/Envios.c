#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "Envios.h"


eEnvios* employee_new(){
    eEnvios* persona = malloc(sizeof(eEnvios));
    return persona;
}

eEnvios* employee_newParametros(char *var1, char *var2, char *var3, char *var4, char *var5, char *var6)
{
    int idEnvios,idCamion, auxTipoEntrega;
    float auxKm;
    eEnvios* p = employee_new();
    idEnvios = atoi(var1);
    idCamion = atoi(var3);
    auxKm= atof(var5);
    auxTipoEntrega = atoi(var6);
    envios_setIdEnvios(p, idEnvios);
    envios_setIdCamion(p, idCamion);
    envios_setNombre(p, var2);
    envios_setZona(p, var4);
    envios_setKm(p, auxKm);
    envios_setTipoEntrega(p,auxTipoEntrega);
    return p;
}

void envios_setIdEnvios(eEnvios* this, int id)
{
    if(id > 0)
        this->idEnvios = id;
}

void envios_setIdCamion(eEnvios* this, int id)
{
    if(id > 0)
        this->idCamion = id;
}

void envios_setNombre(eEnvios* this, char* nombre)
{
   if(nombre[0] != '\0')
    strncpy(this->nombre, nombre, sizeof(this->nombre));
}

void envios_setZona(eEnvios* this, char* zona)
{
   if(zona[0] != '\0')
    strncpy(this->zona, zona, sizeof(this->zona));
}

void envios_setKm(eEnvios* this, float km)
{
    if(km > 0)
        this->km = km;
}

void envios_setTipoEntrega(eEnvios* this, int tipoEntrega)
{
    if(tipoEntrega > 0)
        this->tipoEntrega = tipoEntrega;
}
/*****************************************************************/

int envios_getIdEnvios(eEnvios* this)
{
    return this->idEnvios;
}

int envios_getIdCamion(eEnvios* this)
{
    return this->idCamion;
}

char* envios_getNombre(eEnvios* this)
{
    return this->nombre;
}

char* envios_getZona(eEnvios* this)
{
    return this->zona;
}

float envios_getKm(eEnvios* this)
{
    return this->km;
}

int envios_getTipoEntrega(eEnvios* this)
{
    return this->tipoEntrega;
}

int envios_getCosto(eEnvios* this)
{
    return this->costoEnvio;
}
/************************************************/

int envios_Costo(eEnvios* this)
{
    float auxKm, resultado;
    if(this->tipoEntrega==0){
        auxKm= this->km;
        if(auxKm<50){
            resultado= (auxKm*100)+250;
        }
        else{
            resultado= (auxKm*50)+250;
        }
        this->costoEnvio= resultado;
    }
    if(this->tipoEntrega==1){
        auxKm= this->km;
        if(auxKm<50){
            resultado= (auxKm*100)+420;
        }
        else{
            resultado= (auxKm*50)+420;
        }
        this->costoEnvio= resultado;
    }
    if(this->tipoEntrega==2){
        auxKm= this->km;
        if(auxKm<50){
            resultado= (auxKm*100)+75;
        }
        else{
            resultado= (auxKm*50)+75;
        }
        this->costoEnvio= resultado;
    }
}
