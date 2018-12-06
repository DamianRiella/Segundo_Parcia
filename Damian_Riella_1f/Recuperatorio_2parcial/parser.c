#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"


/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char var1[50],var3[50],var2[50],var4[50],var5[50];
    int r, retorno=1;

    if(pFile!=NULL && pArrayListEmployee!=NULL){

        r= fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5);

        do{
            r= fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5);
             if(r==5){

                eVendedor* p= vendedor(var1,var2,var3,var4,var5);

                ll_add(pArrayListEmployee,p);
             }
          }while(!feof(pFile));
        retorno=0;
        fclose(pFile);
    }
    else{
        printf("No se pudo parsear los datos.");
        getchar();
    }

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    FILE *pFileBin;
    char var1[50], var2[50] ,var3[50] ,var4[50];
    int rL;

  if(pFile!=NULL && pArrayListEmployee!=NULL){

    if((pFileBin=fopen("data.Bin","rb"))==NULL)
    {
        if((pFileBin=fopen("data.Bin","wb"))==NULL)
        {
            printf("\nEl archivo no puede ser abierto");
            fclose(pFile);
            return -1;
        }

    }

    rL = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);

    do {
            rL = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);

            if (rL == 4)
            {
                Employee* n= employee_newParametros(var1, var2, var3, var4);

                fwrite(n, sizeof(Employee), 1, pFileBin);
                ll_add(pArrayListEmployee, n);
            }
            else
            {
                printf("Error.\n");
                fclose(pFileBin);
                fclose(pFile);
                return -1;
            }

    } while (!feof(pFile));

  }
    else{
        printf("No se pudo parsear los datos.");
        getchar();
    }

    fclose(pFileBin);
    fclose(pFile);
    return 0;

}

