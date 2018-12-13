
int utn_getInt(char mensaje[]);
float utn_getFloat(char mensaje[]);
char utn_getChar(char mensaje[]);

char utn_getNumeroAleatorio(int desde , int hasta, int iniciar);

int utn_esNumerico(char str[]) ;
int utn_esTelefono(char str[]);
int utn_esAlfaNumerico(char str[]);
int utn_esSoloLetras(char str[]);
int utn_esNumericoFlotante(char str[]);

void utn_getString(char mensaje[],char input[]);
int utn_getStringLetras(char mensaje[],char input[], int len);
int utn_getStringAlfa(char mensaje[],char input[], int len);
int utn_getStringNumeros(char mensaje[],char input[], int len);
int utn_getStringNumerosFlotantes(char mensaje[],char input[]);

int utn_getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit, int len);
void utn_getValidString(char requestMessage[],char errorMessage[], char input[], int len);

void utn_cleanStdin(void);
