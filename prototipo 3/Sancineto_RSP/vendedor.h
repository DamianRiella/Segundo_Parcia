#ifndef VENDEDOR_H_INCLUDED
#define VENDEDOR_H_INCLUDED

typedef struct
{
    int id;
    char nombre[50];
    int nivel;
    int vendidos;
    int monto;
    int comision;
}Vendedor;

int ven_menu();

Vendedor* ven_new();
Vendedor* ven_newParametros(char* idStr, char *nombreStr, char* nivelStr, char* vendidosStr, char* montoStr);

int ven_getId (Vendedor* this, int* id);
int ven_getNombre (Vendedor* this, char* nombre);
int ven_getNivel (Vendedor* this, int* nivel);
int ven_getVendidos (Vendedor* this, int* vendidos);
int ven_getMonto (Vendedor* this, int* monto);
int ven_getComision (Vendedor* this, int* comision);

int ven_setId(Vendedor* this, int id);
int ven_setNombre(Vendedor* this, char *nombre);
int ven_setNivel(Vendedor* this, int nivel);
int ven_setVendidos(Vendedor* this, int vendidos);
int ven_setMonto(Vendedor* this, int monto);
int ven_setComision(Vendedor* this, int comision);

int ven_getAll(Vendedor* this,int* id, char* nombre,int* nivel,int* vendidos,int* monto);

int ven_parsearArchivo(LinkedList* this);
int ven_listarVendedores(LinkedList* this);
int ven_calcularComisiones(Vendedor* this);
void ven_listarComisiones (LinkedList* this);
int ven_generarComisiones (LinkedList* this);
int ven_filtrarJunior(Vendedor* this);
int ven_filtrarEstandard(Vendedor* this);
int ven_filtrarExperto(Vendedor* this);


#endif // VENDEDOR_H_INCLUDED
