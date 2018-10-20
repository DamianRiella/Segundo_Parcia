#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int edad;
    char nombre[31];
}ePersona;

int main()
{
    ePersona per[3], *p;
    int i;


    p= per;
   for(i=0;i<3;i++)
   {
    printf("Ingrese edad:\n");
    scanf("%d",&(*(p+i)).edad);
    fflush(stdin);
    printf("Ingrese nombre:\n");
    fflush(stdin);
    scanf("%s",(*(p+i)).nombre);
    }
    for(i=0;i<3;i++)
    {
    printf("Edad:%d\n",(*(p+i)).edad);
    printf("Nombre:%s\n\n",(*(p+i)).nombre);
    }
    return 0;
}


