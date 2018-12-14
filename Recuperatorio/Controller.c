#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "Envios.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    pArchivo = fopen(path,"r+");
    if(pArchivo == NULL){
        printf("Error al leer el archivo");
    }
    else{
        parser_EmployeeFromText(pArchivo,pArrayListEmployee);
        printf("\n\nDatos cargados con Exito!\n\n");
    }
    fclose(pArchivo);
    return 0;
}





/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i,cant;
    cant = ll_len(pArrayListEmployee);
    eEnvios* lista;
    for (i=1;i<cant;i++){
        lista = (eEnvios*)ll_get(pArrayListEmployee,i);
        printf("%d\t %s\t %d\t %s\t %2.f\t %d\t\n",envios_getIdEnvios(lista),envios_getNombre(lista),envios_getIdCamion(lista),envios_getZona(lista),envios_getKm(lista),envios_getTipoEntrega(lista));
    }
    return 1;
}
/*************************************************/

int controller_ImprimeCosto(LinkedList* pArrayListEmployee)
{
    int i,cant;
    cant = ll_len(pArrayListEmployee);
    eEnvios* lista;
    for (i=1;i<cant;i++){
        lista = (eEnvios*)ll_get(pArrayListEmployee,i);
        printf("%d\t %s\t %d\t %s\t %f\t %d\t %f\t\n",envios_getIdEnvios(lista),envios_getNombre(lista),envios_getIdCamion(lista),envios_getZona(lista),envios_getKm(lista),envios_getTipoEntrega(lista), envios_getCosto(lista));
    }
    return 1;
}




/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int len,i;
    int total= 0;
    eEnvios* auxEnvios;
    len = ll_len(pArrayListEmployee);
    pArchivo = fopen(path,"r+");
    if (pArchivo == NULL){
        pArchivo = fopen(path,"w+");
    }
    if (len>0){
        for (i=0;i<len;i++){
        if(path->zona==zona){
        auxEnvios = ll_get(pArrayListEmployee,i);
        fprintf(pArchivo,"%d,%s,%d,%s,%2.f,%d,%2.f\n",auxEnvios->idEnvios,auxEnvios->nombre,auxEnvios->idCamion,auxEnvios->zona,auxEnvios->km,auxEnvios->tipoEntrega,auxEnvios->costoEnvio);
        total++;
         }
        }
    printf("\nSe escribieron %d caracteres\n\n", total);
    }
    fclose(pArchivo);
    return 1;
}



