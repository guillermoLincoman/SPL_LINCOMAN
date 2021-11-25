/*
 * LinkedList.c
 *
 *  Created on: 18 nov. 2021
 *      Author: Compumar
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"




/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{

	LinkedList* lista = NULL;

	//1. Le doy un espacio en memoria a la linkedlist
    lista = (LinkedList*)malloc(sizeof(LinkedList));
    if(lista != NULL)
    {
    	//2.Inicializo el tamaño de la lista
    	lista->size=0;
    	//3. Apunto el primer nodo a null
    	lista->pFirstNode= NULL;
    }
    return lista;
}
/** \brief Crea un nuevo nodo y le asigna espacio en memoria
 *
 *  \param void
 *  \return Node* newNode* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
Node* newNode(void)
{
	//1.creo un nuevo nodo
	Node* newNode = NULL;
	newNode = (Node*)malloc(sizeof(Node));
	return newNode;
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
    int len;
    //1. verifico la lista
    if(this!=NULL)
    {
    	//2. Obtengo el tamaño
    	len = this->size;
    	if(len>-1)
    	{
    		returnAux=len;
    	}
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
Node* getNode(LinkedList* this, int nodeIndex)
{

	int i;
	int len;
	Node* node = NULL;

	if(this != NULL)
	{
		node = newNode();
		if(node != NULL)
		{
			//1. Obtengo el tamaño de la lista
			len = ll_len(this);
			if(nodeIndex > -1 && nodeIndex < len)
			{
				//2. Apunto el nuevo nodo al primer nodo de la cabecera
				node = this->pFirstNode;
				//3. Verifico que el nodo no apunte a nulo
				if(node != NULL)
				{
					//4. Recorro la lista hasta la posicion donde se encuentra el nodo solicitado
					for (i=0;i<nodeIndex;++i)
					{
						node = node->pNextNode;
					}
				}
			}
		}
	}
    return node;
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
int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    int len;
    int flag;
    flag = 1;
	Node* nodoAnterior = NULL;
	Node* nuevoNodo = NULL;
    if(this!=NULL)
    {
    	//1. Obtengo el tamaño de la lista para verificar
        len = ll_len(this);
        if(nodeIndex >-1 && nodeIndex <=len)
        {
        	nuevoNodo = newNode();
        	//2. Verifico nulidad del nuevo nodo
        	if(nuevoNodo != NULL)
        	{
        		//3. Apunto el pElement del nuevo nodo al pElement ingresado
        		nuevoNodo->pElement = pElement;
        		//Si es el primer nodo...
        		if(nodeIndex==0)
        		{
        			//4.Apunto el nodo al primer nodo de la lista
        			nuevoNodo->pNextNode = this->pFirstNode;
        			//5. Apunto el primer nodo de la lista al nuevo nodo
        			this->pFirstNode = nuevoNodo;
        		    flag = 0;
        		}else{
        			//Si no es el primer nodo...
        			//4. Obtengo el nodo anterior a mi nuevo nodo
        			nodoAnterior = getNode(this, nodeIndex-1);
        			if(nodoAnterior != NULL)
        			{
        				//5.Apunto el nuevo nodo al nodo anterior
        				nuevoNodo->pNextNode = nodoAnterior->pNextNode;
        				//6.Apunto el nodo anterior al nuevo nodo
        				nodoAnterior->pNextNode = nuevoNodo;
            		    flag = 0;
        			}
        		}
        	}
        	if(flag == 0)
        	{
        		//7. Le sumo 1 al tamaño de la lista
        		this->size++;
        		returnAux = 0;
        	}
        }

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
    int returnAux;
    int len;
    returnAux = -1;
    //1. Verifico la lista
    if(this != NULL)
    {
    	//2. Obtengo el tamaño de la lista
    	len = ll_len(this);
    	//3. Si se logra agregar el nodo retorno 0
    	returnAux = addNode(this, len, pElement);
    }

    return returnAux;
}

/** \brief Retorna un puntero al elemento que se encuentra en el indice especificado
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */

void* ll_get(LinkedList* this, int index)
{
    void* pElement = NULL;
    int len;
	Node* nodo = NULL;

    //1. Verifico la lista
    if(this!=NULL)
    {
    	//2. Obtengo el tamaño de la lista
    	len = ll_len(this);
    	if(index >-1 && index < len)
    	{
    		//3. Obtengo el nodo en el indice solicitado
    		nodo = getNode(this, index);
    		if(nodo != NULL)
    		{
    			//4. Retorno el pElement en el nodo solicitado
    			pElement = nodo->pElement;
    		}
    	}
    }
    return pElement;
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
    int len;
	Node* nodo = NULL;

    //1. Verifico nulidad
    if(this!=NULL)
    {
    	//2. Obtengo el tamaño de la lista
       	len = ll_len(this);
       	if(index >=0 || index <= len)
       	{
       		//3. Obtengo el nodo que quiero modificar
       		nodo = getNode(this, index);
       		if(nodo != NULL)
       		{
       			//4. Cargo el pElement  en el nodo a modificar
       			nodo->pElement = pElement;
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
int ll_remove(LinkedList* this, int index)
{
    int returnAux;
    int len;
    int flag;
    Node* nodoBorrar;
    Node* nodoAnt;
    flag = 1;
    returnAux = -1;

    if(this != NULL)
    {
    	//1. Obtengo el tamaño de la lista
    	len = ll_len(this);
    	if(index >= 0 && index < len)
    	{
	        //2. Obtengo el nodo a borrar en el indice solicitado
	        nodoBorrar = getNode(this, index);

    		if(nodoBorrar != NULL)
    		{
    			//Si es el primer nodo....
    			if(index == 0)
    			{
    				//3. Apunto la cabecera de la lista a lo que apuntaba el nodo a borrar
    				// al nodo en la posicion 1 o en caso de ser el unico nodo a null
    				this->pFirstNode = nodoBorrar->pNextNode;
    				flag = 0;
    			}
    			else
    			{	//Si no es el primer nodo....
    				//3.Obtengo el nodo anterior al nodo a borrar
    				nodoAnt = getNode(this, index-1);

    				if(nodoAnt != NULL)
    				{
    					//4.Apunto el nodo anterior al borrado a lo que apuntaba el borrado
    					nodoAnt->pNextNode = nodoBorrar->pNextNode;
    					flag = 0;
    				}
    			}
    			if(flag == 0)
    			{
        			//5. Achico 1 la lista
        			this->size--;
        			//6. Borro el nodo
        			free(nodoBorrar);
        			returnAux = 0;
    			}

    		}
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
 *///CAMBIOS DE POSICION
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len;
    int i;
    int aux;

    if(this != NULL)
    {
    	//1. Obtengo el tamaño de la lista
    	len = ll_len(this);
    	for(i=0;i<len;i++)
    	{
    		aux = 0;
    		//2.Borro todas los elementos de la lista
    		ll_remove(this, aux);
    	}
    	returnAux = 0;
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
    int borrar;
    if(this != NULL)
    {
    	//1.Borro todos los nodos de la lista y verifico
    	borrar= ll_clear(this);
    	if(borrar == 0)
    	{
    		//2. Si puedo borrar todos los nodos de la lista, borro la lista
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
    int len;
    int i;
	Node* node;

    if(this != NULL)
    {
    	//1. Obtengo el tamaño de la lista
    	len = ll_len(this);
    	for(i=0;i<len;i++)
    	{
    		//2. Obtengo nodo por nodo hasta encontrar la primer ocurrencia
    		node = getNode(this, i);
    		if(node != NULL)
    		{
    			//4.Busco que el pElemento coincida con el pElement del nodo
    			if(pElement==node->pElement)
    			{
    				//5.Retorno el indice y rompo la condicion
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
    int returnAux = -1;
    int len;

    if(this != NULL)
    {
    	//1.Obtengo el tamaño de la lista
    	len = ll_len(this);
    	//2.Si len retorna 1 no entra al if retorno que esta vacia
    	returnAux = 1;
    	if(len > 0 )
    	{
    		//3. Si len retorna un numero mayor a 0 retorna 0
    		returnAux = 0;
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
    int len;

    if(this != NULL)
    {
    	//1.Obtengo el tamaño de la lista
    	len = ll_len(this);
    	//2.verifico el index
    	if(index >-1 && index <= len)
    	{
    		//3. Agrego el elemento en el indice indicado
    		addNode(this, index, pElement);
    		returnAux = 0;
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
    void* pElement = NULL;
    int len;

    if(this != NULL)
    {
    	//1.Obtengo el tamaño de la lista
    	len = ll_len(this);
    	//2.verifico el index
    	if(index >= 0 && index < len)
    	{
    		//3.Obtengo el elemento en el indice solicitado
    		pElement = ll_get(this, index);
    		//3. elimino el elemento en el indice indicado
		    ll_remove(this, index);
    	}
    }

    return pElement;
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
    int elemento;

    if(this != NULL)
    {
    	//1.Busco el elemento en la lista y retorno el inidice donde se encuentra
    	elemento = ll_indexOf(this, pElement);
    	//2.Retorno 1 en caso de no entra al if
    	returnAux = 0;
    	if(elemento > -1)
    	{
    		returnAux = 1;
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
    int len;
    int i;
    int aux;
    void* pElemento = NULL;
    if(this != NULL && this2 != NULL)
    {
    	//1 Obtengo el tamaño de las listas
    	len = ll_len(this2);
    	//2.Retorno 1 en caso de no entrar al if del for
        returnAux = 1;
    	for(i = 0; i<len;i++)
    	{
    		//3. obtengo los elementos de la lista 2 y verifico que esten en la lista 1
    		pElemento =ll_get(this2, i);
    		aux = ll_contains(this, pElemento);
    		//4. Si un elemento no esta en la lista ll_contains retorna 0 y rompo la condicion
    		if(aux == 0)
    		{
    			returnAux = 0;//retorno 0
    			break;//rompo el for
    		}
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
    int len;
    void* pElement;

    if(this != NULL)
    {
    	//1. Obtengo el tamaño de la lista
    	len = ll_len(this);
    	//2. valido que el los indices que se me piden
    	if(from <= to && from >= 0 && to<=len)
    	{
    		//3. Le doy un espacio en memoria a la lista clonada
    		cloneArray = ll_newLinkedList();
    		if(cloneArray != NULL)
    		{
    			for(i=from;i<to;i++)
    			{
    				//4. Tomo los elementos de la lista y los copio en la lista clonada
    				pElement = ll_get(this, i);
    				ll_add(cloneArray, pElement);
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
    int len;
    int i;
    void* pElement;
    if(this != NULL)
    {
    	len = ll_len(this);
		//1. Le doy un espacio en memoria a la lista clonada
    	cloneArray = ll_newLinkedList();
    	if(cloneArray != NULL)
    	{
    		for (i = 0; i < len; ++i) {
        		//2. Copio la lista en la lista clonada
				pElement = ll_get(this, i);
				ll_add(cloneArray, pElement);
			}
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
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int i;
    int j;
    int rFuncion;
    int len;
    void* iEle = NULL;
	void* jEle = NULL;

	if(this != NULL && pFunc != NULL)
	{
		if(order == 0 || order == 1)
		{
			//1.Obtengo el tamaño de la lista
			len = ll_len(this);
			//2.Valido que haya mas de 1 nodo para ordenar
			if(len>0)
			{
				//3.Realizo un burbujeo para ordenar la lista
				for(i=0; i<len-1 ;i++)
				{
					for(j=i+1; j<len;j++)
					{
						//4.Obtengo los elementos a Analizar
						iEle = ll_get(this, i);
						jEle = ll_get(this, j);
						//5. Utilizo la funcion recibida por parametro para comparar los elementos
						rFuncion = (*pFunc)(iEle, jEle);
						//6. Si cumple la condicion hago el swap de los nodos
						if((rFuncion == 1 && order == 0 ) || (rFuncion == 0 && order== 1))
						{
							ll_set(this, i, jEle);
							ll_set(this, j, iEle);
						}
					}
				}
				returnAux = 0;
			}
		}
	}
    return returnAux;
}


int ll_count(LinkedList* this, int (*fn)(void* element))
{
	int acum;
	int len;
	int i;
	void* pElement;
	int ret;
	acum = 0;
	if(this != NULL && fn != NULL)
	{
		len = ll_len(this);
		if(len>-1){
			for (i = 0; i < len; ++i) {
				pElement = ll_get(this, i);
				ret = fn(pElement);
				acum = acum + ret;
			}
		}
	}
	return acum;
}

LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element))
{
	int len;
	int i;
	void* pElement;
	LinkedList* linCopyFilter = NULL;
	int ret;
	if(this != NULL && fn != NULL)
	{
		linCopyFilter = ll_newLinkedList();
		if(linCopyFilter != NULL)
		{
			len = ll_len(this);
			if(len>-1){
				for (i = 0; i < len; ++i) {
					pElement = ll_get(this, i);
					ret = fn(pElement);
					if(ret == 1){
						ll_add(linCopyFilter, pElement);
					}
				}
			}
		}
	}
	return linCopyFilter;
}

LinkedList* ll_map(LinkedList* this, int(*pFunc)(void* element))
{
	int len;
	int i;
	int ret;
	int index;
	void* pElement;
	LinkedList* listaPrecios = NULL;
	if(this != NULL)
	{
		listaPrecios = ll_clone(this);
		len = ll_len(this);
		for (i = 0; i < len; ++i) {
			pElement = ll_get(this, i);
			ret = pFunc(pElement);
			if(ret == 1){
				index = ll_indexOf(this, pElement);
				ll_set(listaPrecios, index, pElement);
			}
		}
	}
	return listaPrecios;
}
