#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


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
    if(this != NULL)
    {
        returnAux=this->size;
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

    int lenLinkedList;
    int indexNodoActual = 0;

    if(this!=NULL)
    {
        lenLinkedList = ll_len(this);

        if((lenLinkedList > nodeIndex) && (nodeIndex >= 0) && (lenLinkedList!=0))
        {
            pNode = this->pFirstNode;
            // printf("\npNode:%p",pNode);

            for(indexNodoActual=0; indexNodoActual<nodeIndex; indexNodoActual++)
            {
                if(pNode!=NULL)
                    pNode = pNode->pNextNode;
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
    int sizeLinkedList;
    Node* nodoNew = NULL;
    Node* nodoAux = NULL;

    if(this!= NULL && nodeIndex>=0)
    {
        sizeLinkedList= ll_len(this);

        if(sizeLinkedList>=nodeIndex)
        {
            nodoNew = (Node *)malloc(sizeof(Node));
        }

    }

    if(nodoNew!=NULL)
    {
        nodoNew->pElement = pElement;
        nodoNew->pNextNode = NULL;


        if(nodeIndex == 0 )
        {
            if(sizeLinkedList >= 1)
            {
                nodoNew->pNextNode = getNode(this,nodeIndex);
            }

            this->pFirstNode = nodoNew;
        }
        else if(nodeIndex == sizeLinkedList)// es el ultimo elemento
        {
            nodoAux = getNode(this,nodeIndex-1);
            nodoAux -> pNextNode = nodoNew;

        }
        else
        {
            nodoNew->pNextNode = getNode(this,nodeIndex);
            nodoAux = getNode(this,nodeIndex-1);
            nodoAux->pNextNode = nodoNew;
        }

        this-> size++;
        returnAux = 0;

    }

    return returnAux;
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
    int sizeList;

    //if(this!=NULL && pElement!=NULL)
    if(this!=NULL)
    {
        sizeList = ll_len(this);
        if(!addNode(this,sizeList,pElement))
        {
            returnAux = 0 ;
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
    Node* auxNode=NULL;

    int sizeList;
    if(this!=NULL)
    {
        sizeList = ll_len(this);
        if(index<=sizeList && index >= 0)
        {
            auxNode = getNode(this,index);
            if(auxNode!=NULL)
                returnAux = auxNode->pElement;
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
    int sizeList;
    Node* auxNode = NULL;

    if(this != NULL)
    {
        sizeList = ll_len(this);
        if(index<=sizeList && index >=0)
        {
            auxNode = getNode(this,index);
            if(auxNode!=NULL)
            {
                auxNode->pElement = pElement;
                returnAux = 0;
            }
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
    int returnAux = -1;
    Node* auxNode = NULL;
    Node* auxNode2 = NULL;
    Node* nodeToRemove = NULL;
    int sizeList;
    int temp;

    if(this != NULL)
    {
        sizeList = ll_len(this);

        if(index<sizeList && index >= 0 && sizeList > 0)
        {
            nodeToRemove = getNode(this,index);
            temp  = index + 1;

            if( temp == sizeList && nodeToRemove != NULL && index > 0) // es el ultimo excepto cuando el indice a borrar es el 0
            {
                auxNode = getNode(this,index-1);
                auxNode -> pNextNode = NULL;
            }
            else if( temp == sizeList && nodeToRemove != NULL && index == 0) //es el unico
            {
                this->pFirstNode = NULL;
            }
            else if(nodeToRemove != NULL && index > 0) // eliminar uno en medio
            {
                auxNode = nodeToRemove->pNextNode; // nodo siguiente
                auxNode2 = getNode(this,index-1); // nodo anterior
                auxNode2 ->pNextNode = auxNode;
            }
            else if (nodeToRemove != NULL && index ==0)
            {
                this->pFirstNode = nodeToRemove->pNextNode;
            }
            free(nodeToRemove);
            this->size--;
            returnAux = 0;
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
    int auxCounter = 0;
    //Node* nodeToRemove = NULL;
    int sizeList;

    if(this != NULL)
    {
        sizeList = ll_len(this);
        if(sizeList>=0)
        {
            for (i = 0; i <sizeList ; i++)
            {
                if(!ll_remove(this,i))
                {
                    auxCounter++;
                }
            }
            if(sizeList==auxCounter)
            {
                returnAux = 0;
            }

        }
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
    int returnAux = -1;


    if(this != NULL)
    {
        if(!ll_clear(this))
        {
            free(this);
            returnAux = 0;
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
    int returnAux = -1;
    int sizeList;
    void* auxPelement = NULL;
    int i;
    Node* pNodeAux = NULL;

    if(this != NULL)
    {
        sizeList = ll_len(this);
        if(sizeList>0)
        {   ll_startIter(this);
            for (i = 0; i < sizeList ; i++)
            {
               // auxPelement = ll_get(this,i);
                pNodeAux = ll_getNextNode(this);
                if(pNodeAux!=NULL)
                {
                    auxPelement = pNodeAux ->pElement;

                    if(auxPelement == pElement)
                    {
                        returnAux = i;
                        break;
                    }
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
    int returnAux = -1;
    int sizeList;
    if(this != NULL)
    {
        sizeList = ll_len(this);
        if(sizeList>0)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
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
    int returnAux = -1;
    int sizeList;

    if(this!=NULL)
    {
        sizeList = ll_len(this);
        if(index <= sizeList && index>=0)
        {
            if(!addNode(this,index,pElement))
            {
                returnAux = 0;
            }
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
    Node* nodeAux = NULL;
    int sizeList;

    if(this!=NULL)
    {
        sizeList = ll_len(this);

        if(index < sizeList && index>=0)
        {
            nodeAux = getNode(this,index);
            returnAux = nodeAux->pElement;
            //printf("\nnodePop%p",returnAux);
            ll_remove(this,index);
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
    int r;
    if(this != NULL)
    {
        r = ll_indexOf(this,pElement);

        if(r>=0)
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
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
    int sizeList2;
    int equalsCounter = 0;
    int i;

    void* pElement;
    Node* pNodeAux = NULL;


    if(this != NULL && this2 !=NULL)
    {
        //sizeList1 = ll_len(this);
        sizeList2 = ll_len(this2);
        ll_startIter(this2);
        for (i = 0; i <sizeList2 ; ++i)
        {
           // pElement = ll_get(this2, i);
            pNodeAux = ll_getNextNode(this2);

            if(pNodeAux!=NULL)
            {
                pElement = pNodeAux ->pElement;

                if(ll_contains(this,pElement) == 1)
                {
                    equalsCounter++;
                }
                else
                {
                    break;
                }
            }

        }

        if(equalsCounter == sizeList2)
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
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
    void* pElement;
    Node* pNodeAux = NULL;
    int sizeList;
    int i;

    if(this!=NULL)
    {
        sizeList = ll_len(this);

        if(from>= 0 && to >= 0  && from <= sizeList && to <= sizeList && from <= to && sizeList >= 0)
        {
            cloneArray = ll_newLinkedList();

        }
    }

    if(cloneArray!=NULL)
    {
        ll_startIter(this);
        for ( i = from; i <= to ; ++i)
        {
            //pElement = ll_get(this,i);
            pNodeAux = ll_getNextNode(this);
            if(pNodeAux != NULL)
            {
                pElement = pNodeAux ->pElement;

                if(ll_add(cloneArray,pElement) !=0)
                {
                    ll_deleteLinkedList(cloneArray);
                    cloneArray=NULL;
                    break;
                }
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
    LinkedList* cloneArray = NULL;
    int sizeList;

    if(this!=NULL)
    {
        sizeList = ll_len(this);

        if(sizeList >= 0)
        {
            cloneArray = ll_subList(this,0,sizeList);
        }
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    int i;
    void* pElementAux=NULL;
    Node* pNode;
    Node* pNextNode;
    int flagSwap;
    int sizeList;

    if(this!=NULL && pFunc!= NULL&& (order==1 ||!order)&& this->size>0)
    {
        sizeList = ll_len(this);
        if(sizeList > 0)
        {
            do
            {
                flagSwap = 0;
                ll_startIter(this);

                for(i=0; i<sizeList-1; i++)
                {
                    pNode = ll_getNextNode(this);
                    pNextNode = pNode ->pNextNode;
                    // pNextNode = this->pIterNode;


                    if(((pFunc(pNode->pElement, pNextNode->pElement) <0 && order==0)||
                            (pFunc(pNode->pElement, pNextNode->pElement) >0 && order==1)) && pNextNode!=NULL)
                    {
                        pElementAux = pNode->pElement;
                        // ll_set(this,i,pNextNode->pElement); slow
                        //ll_set(this,i+1,pElementAux);

                        pNode->pElement = pNextNode->pElement; // fast
                        pNextNode->pElement = pElementAux;
                        flagSwap=1;
                    }
                }

            }
            while(flagSwap);
            returnAux =0;

        }
    }
    return returnAux;
}

/** \brief
 *
 * \param void*
 * \return LinkedList* ll_filter(LinkedList* this,int
 *
 */
LinkedList* ll_filter(LinkedList* this,int (*pFunc)(void*,void*),void* filter)
{

    LinkedList* newArrayFilter = NULL;
    int sizeList;
    int i;
    void* pElementAux;
    Node* pNodeAux = NULL;


    if(this!=NULL && pFunc!=NULL)
    {
        sizeList = ll_len(this);
        newArrayFilter = ll_newLinkedList();

        if(sizeList>0 && newArrayFilter != NULL)
        {
            ll_startIter(this);
            for(i=0; i<sizeList; i++)
            {
                pNodeAux = ll_getNextNode(this);
                if(pNodeAux!=NULL)
                {
                    pElementAux = pNodeAux ->pElement;
                    //pElementAux = ll_get(this,i);

                    if(pFunc(pElementAux,filter)==1)
                    {
                        ll_add(newArrayFilter,pElementAux);

                    }
                }
            }
        }
    }

    return newArrayFilter;

}

/** \brief
 *
 * \param void*
 * \return int ll_map(LinkedList* this,int
 *
 */
int ll_map(LinkedList* this,int (*pFunc)(void*,void*),void* nivel)
{

    int returnAux = -1;
    int i;
    int auxCounter=0;
    int sizeList;
    void* pElementAux;
    Node* NodeAux=NULL;



    if(this!=NULL && pFunc!=NULL)
    {
        sizeList = ll_len(this);
        if(sizeList > 0)
        {
            ll_startIter(this);
            for(i=0; i<sizeList; i++)
            {
                // pElementAux = ll_get(this,i);
                NodeAux = ll_getNextNode(this);

                if(NodeAux!=NULL)
                {
                    pElementAux = NodeAux->pElement;

                    if(pFunc(pElementAux,nivel)==1)
                    {
                        auxCounter++;
                    }
                }

            }
            if(auxCounter==sizeList)
            {
                returnAux = 0;
            }
        }
    }

    return returnAux;
}

void ll_startIter(LinkedList* this)
{
    Node* auxNode= NULL;

    if(this!= NULL)
    {
        auxNode = this -> pFirstNode;
        this -> pIterNode = auxNode;
    }

}
/**
 *
 * @param this
 * @return
 */
Node* ll_getNextNode(LinkedList* this)
{

    Node* pNode = NULL;

    if( this != NULL)
    {
        if(this -> pIterNode!=NULL)
        {
            pNode = this -> pIterNode;
            this -> pIterNode = this -> pIterNode -> pNextNode;

        }

    }

    return pNode;
}

/**
 *
 * @param this
 * @param pFunc
 * @param total
 * @return
 */
void* ll_reduce(LinkedList* this,void (*pFunc)(void* acumulador,void* pElement),void* total)
{
    int i;
    int sizeList;
    void* pElementAux;
    Node* NodeAux=NULL;

    if(this!=NULL && pFunc!=NULL )
    {
        sizeList = ll_len(this);
        if(sizeList > 0)
        {
            ll_startIter(this);
            for(i=0; i<sizeList; i++)
            {
                NodeAux = ll_getNextNode(this);

                if(NodeAux!=NULL)
                {
                    pElementAux = NodeAux->pElement;
                    pFunc(total, pElementAux);
                }
            }

        }
    }

    return total;
}


int ll_count(LinkedList* this,int (*pFunc)(void*))
{

    int contadorRet = -1;
    int sizeList;
    int i;
    void* pElementAux;
    Node* pNodeAux = NULL;


    if(this!=NULL && pFunc!=NULL)
    {
        sizeList = ll_len(this);


        if(sizeList>0 )
        {
            ll_startIter(this);
            contadorRet=0;
            for(i=0; i<sizeList; i++)
            {
                pNodeAux = ll_getNextNode(this);
                if(pNodeAux!=NULL)
                {
                    pElementAux = pNodeAux ->pElement;

                    contadorRet = contadorRet + pFunc(pElementAux);

                }
            }
        }
    }



    return contadorRet;


}
