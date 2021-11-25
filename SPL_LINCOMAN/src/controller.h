/*
 * controller.h
 *
 *  Created on: 22 nov. 2021
 *      Author: Compumar
 */
#include "libros.h"
#include "editorial.h"
#include "LinkedList.h"
#include "parser.h"
#include "menu.h"
#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadFromTextLibros(LinkedList* pArrayListLibros);
int controller_loadFromTextEditoriales(LinkedList* pArrayListEditoriales);
int controller_sortAutorAscendente(LinkedList* pArrayListLibros, LinkedList* pArrayListEditorial);
int controller_ListLibros(LinkedList* pArrayListLibros, LinkedList* pArrayListEditoriales);
int controller_filtrarMinotauro(LinkedList* pArrayListLibros, LinkedList* pArrayListEditoriales);
int controller_mapeo(LinkedList* pArrayListLibros, LinkedList* pArrayListEditoriales);
int controller_loadFromTextEditoriales(LinkedList* pArrayListEditoriales);
#endif /* CONTROLLER_H_ */
