#include <stdio.h>
#include <stdlib.h>
#include "Person.h"

#define CANT_3

int main()
{

/** int i;
    for(i = 0; i < 10; i++)
    {
        personArray[i] = person_new(i,i);
    }
    for(i = 0; i < 10; i++)
    {
        person_setAge(personArray[i],i-4);
    }
    for(i = 0; i < 10; i++)
    {
        printf("\nAge: %2d",person_getAge(personArray[i]));
    }
    scanf(" ");**/

    Person* personArray[CANT_3];
    int opc,i,edad;
    char nom[31];
    do
    {
      system("cls");
      printf("****MENU****\n\n1_Alta\n2_Listar\n\nIngrese opcion:\n");
      scanf("%d",&opc);

          while(opc>2 && opc<1)
          {
              printf("Error. Ingrese opcion:\n");
              scanf("%d",opc);
          }
              switch(opc)
              {
              case 1:
                    system("cls");

                break;
              case 2:
                  system("cls");

                break;
              }
    printf("Desea volver al MENU?");
    fflush(stdin);
    scanf("%c",opc);
    }while(opc=='s')
    return 0;
}

