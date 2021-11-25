/*
 * inputs.h
 *
 *  Created on: 18 nov. 2021
 *      Author: Compumar
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>

#ifndef INPUTS_H_
#define INPUTS_H_

void limpiar();
int validarLetra(char num[]);
int cargarUnEntero(char* mensaje, char* mensajeError,int rangoMin, int rangoMax, int intentos);
float cargarUnFloat(char* mensaje, char* mensajeError,int rangoMin, int rangoMax, int intentos);
int getUsuario(char *guardar, char *mensaje, char *mensajeError, int rangoMin, int rangoMax, int intentos);
int getString(char *guardar, char *mensaje, char *mensajeError, int rangoMin, int rangoMax, int intentos);
int ingresarPath(char *guardar,void (*menu)(void),char* mensajeUno, char* mensajeDos);

#endif /* INPUTS_H_ */
