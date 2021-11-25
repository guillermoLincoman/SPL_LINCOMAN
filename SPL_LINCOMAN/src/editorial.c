/*
 * editorial.c
 *
 *  Created on: 22 nov. 2021
 *      Author: Compumar
 */
#include "editorial.h"

/** \brief Inicializa un nuevo libro
 *
 *
 * \return Retorna una editorial con sus campos inicializados
  */
eEditorial* editorial_new()
{
	eEditorial* newEditorial = (eEditorial*)malloc(sizeof(eEditorial));
	//inicializo las variables
	if(newEditorial != NULL)
	{
		editorial_setIdEditorial(newEditorial, 0);
		editorial_setNombre(newEditorial, " ");
	}

	return newEditorial;
}

/** \brief Carga un libro con parametros recibidos
 *
 * \param char* id = id a cargar en la estructura.
 * \param char* nombre = nombre a cargar en la estructura.
 *
 * \return un editorial con sus parametros cargados
 */
eEditorial* editorial_newParametros(char* id,char* nombre)
{
	eEditorial* editorial = editorial_new();
	if(id != NULL && nombre != NULL )
	{
		editorial_setIdEditorial(editorial, atoi(id));
		editorial_setNombre(editorial, nombre);
	}
	return editorial;
}

/** \brief Borra un editorial de la estructura
 *
 * \param eEditorial* this = puntero a estructura de libro
 *
 */
void editorial_delete(eEditorial* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

/** \brief Carga una idEditorial en el campo de la estructura editorial
 *
 * \param eEditorial* this = puntero a estructura de editorial
 * \param int idEditorial = idEditorial a cargar en la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se obtuvo el id correctamente
 */
int editorial_setIdEditorial(eEditorial* this,int idEditorial)
{
	int error;
	error = 1;
	if(this != NULL && idEditorial >= 0)
	{
		this->idEditorial = idEditorial;
		error = 0;
	}
	return error;
}

/** \brief Obtiene una idEditorial del campo de una estructura editorial
 *
 * \param eEditorial* this = puntero a estructura de editorial
 * \param int* idEditorial = idEditorial obtenido de la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se obtuvo el nombre correctamente
 */
int editorial_getIdEditorial(eEditorial* this,int* idEditorial)
{
	int error;
	error = 1;
	if(this != NULL && idEditorial != NULL)
	{
		*idEditorial = this->idEditorial;
		error = 0;
	}
	return error;
}

/** \brief Carga un nombre en el campo de la estructura editorial
 *
 * \param eEditorial* this = puntero a estructura de libro
 * \param char* nombre = nombre a cargar en la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se obtuvo el id correctamente
 */
int editorial_setNombre(eEditorial* this,char* nombre)
{
	int error;
	error=1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(this->nombre, nombre, 128);
		error = 0;
	}
	return error;
}

/** \brief Obtiene un nombre del campo de una estructura eEditorial
 *
 * \param eEditorial* this = puntero a estructura de libro
 * \param char* nombre = nombre obtenido de la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se obtuvo el nombre correctamente
 */
int editorial_getNombre(eEditorial* this,char* nombre)
{
	int error;
	error=1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(nombre, this->nombre,128);
		error = 0;
	}
	return error;
}
