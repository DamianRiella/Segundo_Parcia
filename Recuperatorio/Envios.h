#ifndef ENVIOS_H_INCLUDED
#define ENVIOS_H_INCLUDED

typedef struct{

 int idEnvios;
 char nombre[128];
 int idCamion;
 char zona[128];
 float km;
 int tipoEntrega;
 float costoEnvio;

}eEnvios;

eEnvios* employee_newParametros(char *var1, char *var2, char *var3, char *var4, char *var5, char *var6);
eEnvios* employee_new();
void envios_setIdEnvios(eEnvios* this, int id);
void envios_setIdCamion(eEnvios* this, int id);
void envios_setNombre(eEnvios* this, char* nombre);
void envios_setZona(eEnvios* this, char* zona);
void envios_setKm(eEnvios* this, float km);
void envios_setTipoEntrega(eEnvios* this, int tipoEntrega);
int envios_getIdEnvios(eEnvios* this);
int envios_getIdCamion(eEnvios* this);
char* envios_getNombre(eEnvios* this);
char* envios_getZona(eEnvios* this);
float envios_getKm(eEnvios* this);
int envios_getTipoEntrega(eEnvios* this);
int envios_getCosto(eEnvios* this);
int envios_Costo(void* this);



#endif
