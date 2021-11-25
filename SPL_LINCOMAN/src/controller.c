/*
 * controller.c
 *
 *  Created on: 22 nov. 2021
 *      Author: Compumar
 */

#include "controller.h"

/** \brief Carga los datos de los libros desde el archivo libros.csv (modo texto).
 *
 * \param LinkedList* pArrayListLibros = Lista donde se cargan los datos
 *
 * \return int error = Si los datos se cargan correctamente retorna 0, en caso de error retorna 1
 *
 */
int controller_loadFromTextLibros(LinkedList* pArrayListLibros)
{
	int error;
	char path[128];
	FILE* pArchivo;
	error = 1;
	ingresarPath(path, menuLibros, "libros.csv", "../libros.csv");
	if(path != NULL && pArrayListLibros != NULL)
	{
		//1. Abro el archivo en modo escritura

		pArchivo = fopen(path, "r");
		if(pArchivo != NULL)
		{
			//2. Si hay un error devuelve 1, si funciona retorna 0
			error = parser_LibrosFromText(pArchivo, pArrayListLibros);
		}
		//3. Cierro el archivo
		fclose(pArchivo);
	}

    return error;
}

/** \brief Carga los datos de las Editoriales desde el archivo libros.csv (modo texto).
 *
 * \param LinkedList* pArrayListEditoriales = Lista donde se cargan los datos
 *
 * \return int error = Si los datos se cargan correctamente retorna 0, en caso de error retorna 1
 *
 */
int controller_loadFromTextEditoriales(LinkedList* pArrayListEditoriales)
{
	int error;
	char path[128];
	FILE* pArchivo;
	error = 1;

	if(path != NULL && pArrayListEditoriales != NULL)
	{
		//1. Abro el archivo en modo escritura
		ingresarPath(path, menuEditoriales, "editoriales.csv", "../editoriales.csv");
		pArchivo = fopen(path, "r");
		if(pArchivo != NULL)
		{
			//2. Si hay un error devuelve 1, si funciona retorna 0
			error = parser_EditorialFromText(pArchivo, pArrayListEditoriales);
		}
		//3. Cierro el archivo
		fclose(pArchivo);
	}

    return error;
}

/** \brief Listar Libros
 *
 * \param LinkedList* pArrayListLibros = lista de libros para mostrar
 * \param LinkedList* pArrayListEditoriales = lista con las descripciones de editoriales
 *
 * \return int error = En caso de error retorna 1, si puede listar a los empleados retorna 0
 *
 */
int controller_ListLibros(LinkedList* pArrayListLibros, LinkedList* pArrayListEditoriales)
{
	int error;
	int i;
	int j;
	int len;
	int lenAutores;
	eLibros* newLibros;
	newLibros = libros_new();
	eEditorial* newEditorial;
	newEditorial = editorial_new();
	int idEditorial;
	int auxIdEditorial;
	error = 1;
	if(newLibros != NULL && pArrayListLibros != NULL && newEditorial != NULL && pArrayListEditoriales != NULL)
	{
		len = ll_len(pArrayListLibros);
		lenAutores = ll_len(pArrayListEditoriales);
		if(len > 1)
		{
			error = 0;
			printf("\n\n____________________________________________________________________________________________________________\n");
			printf("||========================================================================================================||\n");
			printf("||==============================================LIBROS UTN================================================||\n");
			printf("||________________________________________________________________________________________________________||\n");
			printf("|| ID LIBRO |             TITULO               |          AUTOR          |  PRECIO  |      EDITORIAL      ||\n");
			printf("||__________|__________________________________|_________________________|__________|_____________________||\n");

			for (i = 0; i < len; ++i) {
				newLibros = ll_get(pArrayListLibros, i);
				libros_getIdEditorial(newLibros, &idEditorial);
				for (j = 0; j < lenAutores; ++j) {
					newEditorial = ll_get(pArrayListEditoriales, j);
					editorial_getIdEditorial(newEditorial, &auxIdEditorial);
					if(idEditorial == auxIdEditorial){
						break;
					}
				}
				printf("||----------|----------------------------------|-------------------------|----------|---------------------||\n");


				libros_printLibros(newLibros, newEditorial);
				if(len-1 == i){
					printf("||__________|__________________________________|_________________________|__________|_____________________||\n");
				}
			}

		}
	}

    return error;
}

/** \brief Ordenar Libros según el criterio de ordenamiento “Autor” de manera ascendente.
 *
 * \param LinkedList* pArrayListLibros = lista que se va a clonar para odenar y mostrar
 * \param LinkedList* pArrayListEditorial = lista utilizada para tomar la descripcion de las editoriales
 *
 * \return int error = Si la lista se puede ordenar retorna 0, en caso de error retorna 1
 *
 */
int controller_sortAutorAscendente(LinkedList* pArrayListLibros, LinkedList* pArrayListEditorial)
{
	int error;
	LinkedList* clone;
	error = 1;
	if(pArrayListLibros != NULL)
	{
		clone = ll_clone(pArrayListLibros);

		error = ll_sort(clone, libros_compareByAutor,0);
		controller_ListLibros(clone, pArrayListEditorial);
		ll_deleteLinkedList(clone);
	}
    return error;
}

/** \brief Lista los libros de la editorial MINOTAURO
 *
 * \param LinkedList* pArrayListLibros = lista que se va a filtrar para odenar y mostrar
 * \param LinkedList* pArrayListEditorial = lista utilizada para tomar la descripcion de las editoriales
 *
 * \return int error = Si la lista se puede filtrar retorna 0, en caso de error retorna 1
 *
 */
int controller_filtrarMinotauro(LinkedList* pArrayListLibros, LinkedList* pArrayListEditoriales)
{
	int error;
	LinkedList* listaMinotauro = NULL;
	error = 1;
	if(pArrayListLibros != NULL)
	{
		listaMinotauro = ll_filter(pArrayListLibros, libros_filtrarEditorialMinotauro);

		if(listaMinotauro != NULL)
		{
			error = 0;
			controller_ListLibros(listaMinotauro, pArrayListEditoriales);
		}
	}
	return error;
}

/** \brief Guarda los datos mapeados desde el archivo “mapeado.csv” (modo texto).
 *
 *\param char* path = direccion del archivo
 * \param LinkedList* pArrayListLibros = Lista donde se cargan los datos
 *
 * \return int error = Si los datos se cargan correctamente retorna 0, en caso de error retorna 1
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListLibros)
{
	int id;
	char titulo[128];
	char autor[128];
	float precio;
	int idEditorial;
	int len;
	int i;
	int error;
	eLibros* newLibros;
	FILE* pArchivo;
	error = 1;

	if(pArrayListLibros != NULL)
	{
		//1. Abro el archivo en modo escritura
		pArchivo = fopen(path, "w");

		//2. Asigno espacio en memoria para el puntero a empleado
		newLibros = libros_new();

		//3. Obtengo el tamaño de la lista
		len = ll_len(pArrayListLibros);

		//4. Coloco la cabecera
		fprintf(pArchivo, "id,titulo,autor,precio,idEditorial\n");
		for(i=0; i<len;i++)
		{
			//5. obtengo el empleado con sus datos
			newLibros = ll_get(pArrayListLibros, i);
			if(newLibros != NULL)
			{
				//6. le paso los datos el empleado a las variables
				libros_getAutor(newLibros, autor);
				libros_getIdEditorial(newLibros, &idEditorial);
				libros_getIdLibro(newLibros, &id);
				libros_getPrecio(newLibros, &precio);
				libros_getTitulo(newLibros, titulo);
				//7. Escribo los datos del empleado en el archivo
				fprintf(pArchivo, "%d,%s,%s,%.2f,%d\n", id,titulo,autor,precio,idEditorial);
				error = 0;
			}else{
				error = 1;
				break;
			}
		}
		fclose(pArchivo);
	}

    return error;
}

/** \brief Lista los libros de la editorial MINOTAURO
 *
 * \param LinkedList* pArrayListLibros = lista que se va a filtrar para odenar y mostrar
 * \param LinkedList* pArrayListEditorial = lista utilizada para tomar la descripcion de las editoriales
 *
 * \return int error = Si la lista se puede filtrar retorna 0, en caso de error retorna 1
 *
 */
int controller_mapeo(LinkedList* pArrayListLibros, LinkedList* pArrayListEditoriales)
{
	int error;
	LinkedList* listaMapeada = NULL;
	error = 1;
	if(pArrayListLibros != NULL)
	{
		listaMapeada = ll_map(pArrayListLibros, libros_preciosEditoriales);

		if(listaMapeada != NULL)
		{
			error = 0;
			controller_saveAsText("mapeado.csv",listaMapeada);
			printf("\n\nEl archivo mapeado.csv fue guardado con exito\n");
		}
	}
	return error;
}
