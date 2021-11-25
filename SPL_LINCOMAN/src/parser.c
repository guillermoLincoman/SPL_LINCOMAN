/*
 * parser.c
 *
 *  Created on: 18 nov. 2021
 *      Author: Compumar
 */

#include "parser.h"

/** \brief Parsea los datos los datos de los libros desde el archivo libros.csv (modo texto).
 *
 * \param FILE* pFile = direccion del archivo
 * \param LinkedList* pArrayListLibros = lista donde se van a guardar los datos
 *
 * \return int error = si funciona retorna 0, en caso de error retorna 1;
 *
 */
int parser_LibrosFromText(FILE* pFile , LinkedList* pArrayListLibros)
{
	int error;
	char id[60];
	char titulo[128];
	char autor[128];
	char precio[60];
	char idEditorial[60];

	eLibros* libro;
	int aux;
	error = 1;


	if(pFile != NULL && pArrayListLibros != NULL)
	{
		//1. Tomo la cabecera del archivo
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,titulo,autor,precio,idEditorial);
		//2. Repito hasta llegar al final de archivo
		while(!feof(pFile))
		{
			//3. cuento que lea los datos necesarios y los cargo en aux
			aux =  fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,titulo,autor,precio,idEditorial);
			if(aux == 5)
			{
				//4. cargo los datos leidos en el empleado
				libro = libros_newParametros(id, titulo, autor, precio, idEditorial);
				//5. valido que el empleado no sea nulo
				if(libro!=NULL)
				{
					//6. en caso de cargar el empleado retorna 0
					aux = ll_add(pArrayListLibros, libro);
					if(aux != 0)
					{
						//7. Si retorna un numero diferente a 0 borro el empleado y rompo la condicion while
						libros_delete(libro);
						error = 1;
						break;
					}else{
						error = 0;
					}
				}
			}else{
				break;
			}
		}

	}

    return error;
}

/** \brief Parsea los datos los datos de las editoriales desde el archivo editoriales.csv (modo texto).
 *
 * \param FILE* pFile = direccion del archivo
 * \param LinkedList* pArrayListEditorial = lista donde se van a guardar los datos
 *
 * \return int error = si funciona retorna 0, en caso de error retorna 1;
 *
 */
int parser_EditorialFromText(FILE* pFile , LinkedList* pArrayListEditorial)
{
	int error;
	char aId[60];
	char aNombre[128];
	eEditorial* editorial;
	int aux;
	error = 1;

	if(pFile != NULL && pArrayListEditorial != NULL)
	{

		//1. Cabecera del archivo
		fscanf(pFile,"%[^,],%[^\n]\n",aId,aNombre);
		//2. Repito hasta llegar al final de archivo
		while(!feof(pFile))
		{

			//3. cuento que lea los datos necesarios y los cargo en aux
			aux = fscanf(pFile,"%[^,],%[^\n]\n",aId,aNombre);
			if(aux == 2)
			{
				//4. cargo los datos leidos en el empleado
				editorial = editorial_newParametros(aId, aNombre);
				//5. valido que el empleado no sea nulo
				if(editorial != NULL)
				{
					//6. en caso de cargar el empleado retorna 0
					aux = ll_add(pArrayListEditorial, editorial);
					if(aux != 0)
					{
						//7. Si retorna un numero diferente a 0 borro el empleado y rompo la condicion while
						editorial_delete(editorial);
						error = 1;
						break;
					}else{
						error = 0;
					}
				}
			}else{
				break;
			}
		}

	}

    return error;
}

