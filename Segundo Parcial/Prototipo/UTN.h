#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

 int utn_esNumericoAvanzada (char cadena []);
 int utn_getIntAvanzada(int* pResultado);
 int utn_getNumeroAvanzada(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
 int utn_getNumeroAvanzadaSinMax(int* pResultado, char* mensaje, char* mensajeError, int minimo, int reintentos);
 int utn_esDecimalAvanzada (char cadena []);
 int utn_getFloatAvanzada(float* pResultado);
 int utn_getNumeroConDecimalesAvanzada(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
 int utn_esStringAvanzada(char cadena []);
 int utn_getStringAvanzada(char cadena []);
 int utn_getCadenaDeCaracteresAvanzada(char cadena [], char* mensaje, char* mensajeError, int reintentos);
 int utn_esAlfanumericoAvanzada (char cadena []);
 int utn_getAlfanumerico(char cadena []);
 int utn_getAlfanumericoAvanzada (char cadena [], char* mensaje, char* mensajeError, int reintentos);
 int utn_esTelefonoAvanzada (char cadena []);
 int utn_getTelefono(char cadena []);
 int utn_getTelefonoAvanzada(char cadena [], char* mensaje, char* mensajeError, int reintentos);
 int utn_esDniAvanzada (char cadena []);
 int utn_getDni(char cadena []);
 int utn_getDniAvanzada(char cadena [], char* mensaje, char* mensajeError, int reintentos);
 int utn_esCuilAvanzada (char cadena []);
 int utn_getCuil(char cadena []);
 int utn_getCuilAvanzada(char cadena [], char* mensaje, char* mensajeError, int reintentos);
 int utn_esMailAvanzada (char cadena []);
 int utn_getMail(char cadena []);
 int utn_getMailAvanzada(char cadena [], char* mensaje, char* mensajeError, int reintentos);
 char* getDynamicString (char* message);


 #endif



