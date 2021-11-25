/*
 * menu.c
 *
 *  Created on: 18 nov. 2021
 *      Author: Compumar
 */

#include "menu.h"

void menuPrincipal()
{
    printf("\n\n___________________________________________\n");
    printf("||=======================================||\n");
    printf("||==============LIBROS  UTN==============||\n");
    printf("||=======================================||\n");
    printf("||============MENU PRINCIPAL=============||\n");
    printf("||=======================================||\n");
	printf("||                                       ||\n");
    printf("|| 1. Cargar archivo de Libros           ||\n");
    printf("|| 2. Cargar archivo de Editoriales      ||\n");
    printf("|| 3. Ordenar lista por autor ascendente ||\n");
    printf("|| 4. Listar libros                      ||\n");
    printf("|| 5. Listar libros editorial MINOTAURO  ||\n");
    printf("|| 6. Salir                              ||\n");
	printf("||_______________________________________||\n");
}

void menuLibros()
{
    printf("\n\n________________________________________________________\n");
    printf("||====================================================||\n");
    printf("||==========INGRESE LA DIRECCION DEL ARCHIVO==========||\n");
    printf("||======================LIBROS========================||\n");
    printf("||===================MENU ARCHIVO=====================||\n");
    printf("||====================================================||\n");
	printf("||                                                    ||\n");
    printf("|| 1. libros.csv (Recomendable en consola de eclipse) ||\n");
    printf("|| 2. ../libros.csv (Recomendable en archivo .exe)    ||\n");
    printf("|| 3. Ingresar manualmente                            ||\n");
    printf("|| 4. Salir                                           ||\n");
	printf("||____________________________________________________||\n");
}

void menuEditoriales()
{
    printf("\n\n_____________________________________________________________\n");
    printf("||=========================================================||\n");
    printf("||=============INGRESE LA DIRECCION DEL ARCHIVO============||\n");
    printf("||========================EDITORIALES======================||\n");
    printf("||=======================MENU ARCHIVO======================||\n");
    printf("||=========================================================||\n");
	printf("||                                                         ||\n");
    printf("|| 1. editoriales.csv (Recomendable en consola de eclipse) ||\n");
    printf("|| 2. ../editoriales.csv (Recomendable en archivo .exe)    ||\n");
    printf("|| 3. Ingresar manualmente                                 ||\n");
    printf("|| 4. Salir                                                ||\n");
	printf("||_________________________________________________________||\n");
}
