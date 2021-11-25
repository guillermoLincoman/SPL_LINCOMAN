/*
 * parser.h
 *
 *  Created on: 18 nov. 2021
 *      Author: Compumar
 */
#include "LinkedList.h"
#include "editorial.h"
#include "libros.h"
#ifndef PARSER_H_
#define PARSER_H_

int parser_LibrosFromText(FILE* pFile , LinkedList* pArrayListLibros);
int parser_EditorialFromText(FILE* pFile , LinkedList* pArrayListEditorial);
#endif /* PARSER_H_ */
