#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "Envios.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL){

        returnAux= this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int i;
    if(this!=NULL && (nodeIndex>=0 && nodeIndex< ll_len(this))){


        for(i=0;i<=nodeIndex;i++){

            if(pNode==NULL){
                pNode= this->pFirstNode;
            }
            else{
            pNode=pNode->pNextNode;

            }
        }
    }

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* prev;
    Node* next;
    Node* nuevoNodo;

    if( this != NULL)
    {
        if(nodeIndex >= 0 && nodeIndex <= ll_len(this))
        {
            nuevoNodo = (Node*)malloc(sizeof(Node));
            if(nuevoNodo != NULL)
            {
                nuevoNodo->pElement = pElement;
                nuevoNodo->pNextNode = NULL;

                if(nodeIndex == 0)
                {
                    nuevoNodo->pNextNode = this->pFirstNode;
                    this->pFirstNode = nuevoNodo;
                }
                else
                {
                    prev = this->pFirstNode;
                    next = prev->pNextNode;

                    while( nodeIndex > 1)
                    {
                        prev  = next;
                        next  = prev->pNextNode;
                        nodeIndex--;
                    }

                    prev->pNextNode = nuevoNodo;
                    nuevoNodo->pNextNode = next;
                }
                this->size++;
                returnAux = 0;
            }
        }
    }

    return returnAux;

  /*  int i,returnAux = -1;
    Node* anterior;
    Node* siguiente;
    Node* pNodo= NULL;
        if(this!=NULL && (nodeIndex>=0 && nodeIndex<= ll_len(this))){

         pNodo= (Node*)malloc(sizeof(Node));
         if(pNodo!=NULL){
              pNodo->pElement= pElement;
              pNodo->pNextNode=NULL;
           if(nodeIndex!=0){

                anterior = this->pFirstNode;
                siguiente = anterior->pNextNode;

                for(i=0; i<nodeIndex;i++){

                anterior= siguiente;
                siguiente= anterior->pNextNode;

               }
               anterior->pNextNode = pNodo;
               pNodo->pNextNode = siguiente;
            returnAux= 0;
           }
           else{
            pNodo->pNextNode= this->pFirstNode;
            this->pFirstNode= pNodo;

            returnAux=0;
           }
            this->size++;
         }
        }

    return returnAux;*/
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int cantElemento, verifico;

        if(this!=NULL){

            cantElemento= ll_len(this);
            verifico= addNode(this,cantElemento,pElement);
             if(verifico==0){

                returnAux= 0;
             }
        }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNodo= NULL;
        if(this!=NULL && (index>=0 && index<= ll_len(this))){

            pNodo= getNode(this,index);
             if(pNodo!=NULL){
              returnAux= pNodo->pElement;
            }
        }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNodo= NULL;

            if(this!=NULL && (index>=0 && index<= ll_len(this))){

                pNodo= getNode(this,index);
                    if(pNodo!=NULL){

                        pNodo->pElement= pElement;
                        returnAux= 0;
                    }
            }


    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{

    int returnAux = - 1 ;
    Node * auxNodo;
    Node * prev;
    Node * siguiente;

    if(this!=NULL && (index>=0 && index< ll_len(this)))
    {
        if( index == 0 ) {
            auxNodo = getNode (this, index );
            this-> pFirstNode = auxNodo-> pNextNode ;
            free(auxNodo);
            this-> size --;
            returnAux = 0 ;
        }
         if( index >= 1 ) {
            auxNodo = getNode (this, index );
            prev = getNode (this, index - 1 );
            siguiente = getNode (this, index + 1 );
            prev-> pNextNode = siguiente;
            free(auxNodo);
            this-> size --;
            returnAux = 0 ;
        }

    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    int cant;

       if(this!=NULL){
            cant= ll_len(this);
            for(i=0; i<cant ;i++){
                ll_remove(this, i);
            }
           returnAux= 0;
       }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int eliminoElementos,returnAux = -1;
        if(this!=NULL){
            eliminoElementos= ll_clear(this);
             if(eliminoElementos!=-1){
                free(this);
                returnAux=0;
             }
        }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int i,cantElement, returnAux = -1;
    Node* Nodo=NULL;

        if(this!=NULL){
            cantElement= ll_len(this);

             if(cantElement!=-1){
                Nodo=this->pFirstNode;

                  for(i=0;i<=cantElement;i++){
                    if(pElement!=Nodo->pElement){
                        continue;
                    }
                    else{
                        returnAux=i;
                        break;
                    }
                  }
             }
         }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
   int returnAux = - 1 ;

    if(this!= NULL && this->size!= 0) {
        returnAux = 0 ;
    }
    if (this!= NULL && this->size== 0) {
        returnAux = 1 ;
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int validacion,returnAux = -1;
      if(this!=NULL && (index>=0 && index<= ll_len(this))){
            validacion= addNode(this,index,pElement);

             if(validacion==0){
                returnAux=0;
             }
      }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* pNodo=NULL;
    int r;
      if(this!=NULL && (index>=0 && index<= ll_len(this))){
            pNodo= getNode(this,index);

             if(pNodo!=NULL){
                 r= ll_remove(this,index);

                    if(r!=-1){
                     returnAux= pNodo->pElement;
                    }
             }
      }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i, cant, flag= 0;
    Node* axuNodo;

        cant = ll_len (this);
        if(this!= NULL){

            for(i=0; i<cant ;i++){
              axuNodo= getNode(this, i);

            if(axuNodo->pElement==pElement){
                returnAux= 1;
                flag= 1;
            }
        }
        if(flag==0){
            returnAux= 0;
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i, flag = 0;
    void* auxElement;
    int cant;

         if(this!= NULL && this2!= NULL){
            cant= ll_len(this2);

           for(i=0; i<cant ;i++){
            auxElement= ll_get(this2, i);

            if(ll_contains(this,auxElement)==0){
                returnAux=0;
                flag=1;
                break;
              }
            }
            if(flag==0){
            returnAux=1;
           }
         }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    void* auxElemento;

        if(this!=NULL &&(from>=0 && from<=ll_len(this))&&(to>from && to<=ll_len(this))){
            cloneArray= ll_newLinkedList();
                if(cloneArray!=NULL){

                    for(i=from; i<to ;i++){
                        auxElemento= ll_get(this,i);
                        ll_add(cloneArray,auxElemento);
                    }
                }
        }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray= NULL;
    int cant, i;
    void* auxElemento;

    if(this!= NULL){
     cloneArray = ll_newLinkedList ();
     cant = ll_len (this);

     if(this!= NULL){
        for(i=0; i<cant ;i++){
            auxElemento= ll_get(this, i);
            addNode(cloneArray, i, auxElemento);
        }
    }
    }
    return cloneArray;
}


/* * \ brief Algoritmo que reordena los nodos.
 * \ param pList LinkedList * Puntero a la lista
 * \ param pNodePrev Es el primer nodo que se va a intercambiar, el segundo lo obtenemos de su pNextNode
* \ return int Retorna (-1) Error: si el puntero a la lista es NULL o alguno de los nodos es NULL. (0) si ok
 */

int  ll_reOrder(LinkedList* this, Node* pNodePrev)
{
    int returnAux= - 1;
    Node* pNodeSiguiente= pNodePrev->pNextNode;
    void* auxElement = NULL ;
    if (this!= NULL && pNodePrev!= NULL && pNodeSiguiente!= NULL)
    {
        auxElement= pNodePrev->pElement;
        pNodePrev->pElement = pNodeSiguiente->pElement;
        pNodeSiguiente->pElement= auxElement;
        returnAux= 0;
    }
    return returnAux;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
/*
{
    int returnAux = -1;
    int i;
    void* auxElemento= NULL;
    Node* auxNodo;
    Node* sigNodo;

    if (this!= NULL && ll_len(this)>0 && pFunc!= NULL && (order==1 || order==0))
    {

            for(i=0; i<ll_len(this)-1 ;i ++)
            {
                auxNodo= getNode(this, i);
                if(i!= 0)
                {
                    auxNodo= auxNodo-> pNextNode;
                }
                if((order== 0 && auxNodo->pElement!= NULL && auxNodo->pNextNode->pElement!= NULL && (* pFunc)(auxNodo->pElement,auxNodo->pNextNode->pElement)== - 1)||
                   (order== 1 && auxNodo->pElement!= NULL && auxNodo->pNextNode->pElement!= NULL && (* pFunc)(auxNodo->pElement,auxNodo->pNextNode->pElement)== 1))
                {
                    sigNodo= auxNodo->pNextNode;

                    auxElemento= auxNodo->pElement;
                    auxNodo->pElement= sigNodo->pElement;
                    sigNodo->pElement= auxElemento;
                    returnAux= 0;
                }
            }
    }
    return returnAux;

}*/
{
    int returnAux= -1;
    int i;
    int flagSwap;
    Node* auxNode;

    if(this!= NULL && ll_len(this)>0 && pFunc!= NULL && (order==1 || order==0))
    {
        do
        {
            i= 0;
            auxNode= getNode(this, i);
            flagSwap= 0;
            for(i= 0; i< ll_len(this)- 1; i++)
            {
                if(i!= 0)
                {
                    auxNode= auxNode->pNextNode;
                }
                if((order== 0 && auxNode->pElement!= NULL && auxNode->pNextNode->pElement!= NULL && (*pFunc)(auxNode->pElement,auxNode->pNextNode->pElement)==-1)||
                   (order== 1 && auxNode->pElement!= NULL && auxNode->pNextNode->pElement!= NULL && (*pFunc)(auxNode->pElement,auxNode->pNextNode->pElement)==1))
                {
                   flagSwap= 1;
                   ll_reOrder(this, auxNode);
                }
            }
        }while(flagSwap== 1);
        returnAux= 0;
    }
    return returnAux;
}

int ll_map(LinkedList* this, void (*pFunc) (eEnvios*)){

    int i, returnAux=0;
    void* pElement;
    if (this != NULL && pFunc != NULL)
    {
        returnAux =1;
        for (i=0; i<ll_len(this); i++)
        {
            pElement = ll_get(this,i);
            pFunc(pElement);
        }
    }
    return returnAux;

}




