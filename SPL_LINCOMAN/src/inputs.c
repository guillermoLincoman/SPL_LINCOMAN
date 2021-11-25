/*
 * inputs.c
 *
 *  Created on: 18 nov. 2021
 *      Author: Compumar
 */
#include "inputs.h"

void limpiar()
{
	printf("\n");
    system("pause");
    system("cls");
}

int validarLetra(char num[])
{
   int i=0;
   //repite hasta llegar al final de la cadena
   while(num[i] != '\0')
   {
       if (i == 0 && num[i] == '-')
       {
           i++;
           continue;
       }
       if(num[i] < '0' || num[i] > '9')
       {
          return 0;
       }
       i++;
   }
   return 1;
}

/** \brief Pide, valida y devuelve un numero entero
 *
 * \param char* mensaje: Recibe el mensaje para pedir entero
 * \param char* mensajeError: Recibe el mensaje de error al pedir entero
 * \param int rangoMin: Numero menor que recibe la funcion
 * \param int rangoMax: Numero mayor que recibe la funcion
 * \param int intentos: Cantidad de intentos de error para cargar el numero
 *
 * \return retorna el entero
 *
 */
int cargarUnEntero(char* mensaje, char* mensajeError,int rangoMin, int rangoMax, int intentos)
{
	char* auxInt;
	int aux;
	int band;

	auxInt = malloc(sizeof(int));
	//muestro el mensaje
	printf("%s", mensaje);
	//guardo el valor ingresado en el puntero
	scanf("%s", auxInt);
	//valido que no sea una letra
	band = validarLetra(auxInt);
	aux = atoi(auxInt);
	if(band==0 ||aux<rangoMin||aux>rangoMax)
	{
		//realiza intentos hasta llegar a 0
		while(intentos>0)
		{
			printf("%s", mensajeError);
			scanf("%s", auxInt);
			band = validarLetra(auxInt);
			aux = atoi(auxInt);
			if(band==0 ||aux<rangoMin||aux>rangoMax)
			{
				intentos--;
				band=-1;
			}else{
				intentos = 0;
				aux = atoi(auxInt);
			}
		}
	}else
	{
		//utilizo la variable con la que valide para guardar el numero ingresado
		//convierto el el valor de auxInt en un entero y lo guardo en la var aux
		aux = atoi(auxInt);
	}
    return aux;
}


/** \brief Pide, valida y devuelve un numero Float
 *
 * \param char* mensaje: Recibe el mensaje para pedir Float
 * \param char* mensajeError: Recibe el mensaje de error al pedir Float
 * \param int rangoMin: Numero menor que recibe la funcion
 * \param int rangoMax: Numero mayor que recibe la funcion
 * \param int intentos: Cantidad de intentos de error para cargar el numero
 *
 * \return retorna el Float
 *
 */
float cargarUnFloat(char* mensaje, char* mensajeError,int rangoMin, int rangoMax, int intentos)
{
	char* auxInt;
	float aux;
	int band;

	auxInt = malloc(sizeof(float));
	//muestro el mensaje
	printf("%s", mensaje);
	//guardo el valor ingresado en el puntero
	scanf("%s", auxInt);
	//valido que no sea una letra
	band = validarLetra(auxInt);
	aux = atof(auxInt);
	if(band==0 ||aux<rangoMin||aux>rangoMax)
	{
		//realiza intentos hasta llegar a 0
		while(intentos>0)
		{
			printf("%s", mensajeError);
			scanf("%s", auxInt);
			band = validarLetra(auxInt);
			aux = atof(auxInt);
			if(band==0 ||aux<rangoMin||aux>rangoMax)
			{
				intentos--;
				band=-1;
			}else{
				intentos = 0;
				aux = atof(auxInt);
			}
		}
	}else
	{
		//utilizo la variable con la que valide para guardar el numero ingresado
		//convierto el el valor de auxInt en un entero y lo guardo en la var aux
		aux = atof(auxInt);
	}
    return aux;
}


/** \brief Pide, valida, devuelve y pone primer caracter Mayuscula a una cadena
 *
 * \param char* guardar: variable donde se va a guardar la cadena
 * \param char* mensaje: Recibe el mensaje para pedir Float
 * \param char* mensajeError: Recibe el mensaje de error al pedir Float
 * \param int rangoMin: Numero menor que recibe la funcion
 * \param int rangoMax: Numero mayor que recibe la funcion
 * \param int intentos: Cantidad de intentos de error para cargar el numero
 *
 * \return retorna 0 si se cargo la cadena, en caso de error retorna 1
 *
 */
int getUsuario(char *guardar, char *mensaje, char *mensajeError, int rangoMin, int rangoMax, int intentos)
{
	//1.limpio el buffer
	fflush(stdin);
    int error=1;
    //2.creo una cadena auxiliar con el tamaño maximo ingresado por el usuario
    char stringAux[rangoMax];
    char aux;
    int i;
    //3.imprimo el mensaje ingresado por el usuario
    printf("%s\n",mensaje);
    //4.guardo la variable ingresada | pido el tamaño de la cadena
    fgets(stringAux,sizeof(stringAux),stdin);
    //5.Al ultimo indice le asigno "\0"
    stringAux[strlen(stringAux)-1] = '\0';
    //6.si guardar no es nulo,
    //el tamaño de auxiliar es mayor o igual al minimo y menor o igual al maximo
   // y validar letra devuelve 0 (no hay numeros)
    if(guardar !=NULL && strlen(stringAux)>=rangoMin && strlen(stringAux)<=rangoMax && validarLetra(stringAux)==0)
    {
    	strlwr(stringAux);
    	aux = toupper(stringAux[0]);
    	stringAux[0] = aux;
    	for (i = 0; i < strlen(stringAux); ++i)
    	{
    		if(stringAux[i] == ' ')
    		{
    			aux = toupper(stringAux[i+1]);
    			stringAux[i+1] = aux;
    			break;
    		}
    		i++;
    	}
    	//7.guardo la cadena del auxiliar en el puntero guardar
    	strncpy(guardar, stringAux, rangoMax);
    	//8.Devuelvo 1 porque no hubo errores
    	error=0;
    }else{
    	//9.repito en caso de error
    	while(intentos>0)
    	{
    		printf("%s", mensajeError);
    		fgets(stringAux,sizeof(stringAux),stdin);
    		stringAux[strlen(stringAux)-1] = '\0';
    		if(guardar !=NULL && strlen(stringAux)>=rangoMin && strlen(stringAux)<=rangoMax && validarLetra(stringAux)==0)
    		{
    	    	strlwr(stringAux);
    	    	aux = toupper(stringAux[0]);
    	    	stringAux[0] = aux;
    	    	for (i = 0; i < strlen(stringAux); ++i)
    	    	{
    	    		if(stringAux[i] == ' ')
    	    		{
    	    			aux = toupper(stringAux[i+1]);
    	    			stringAux[i+1] = aux;
    	    			break;
    	    		}
    	    		i++;
    	    	}
    			strncpy(guardar, stringAux, rangoMax);
    			error = 0;
    			break;
    		}
    		intentos--;
    	  }
    }

    return error;
}


/** \brief Pide, valida, devuelve y pone primer caracter Mayuscula a una cadena
 *
 * \param char* guardar: variable donde se va a guardar la cadena
 * \param void (*menu)(void): Recibe el menu que va a mostrar la funcion
 * \param char* mensajeUno: Recibe el mensaje la primer opcion
 * \param char* mensajeDos: Recibe el mensaje la segunda opcion
 *
 * \return retorna 0 si se cargo la cadena, en caso de error retorna 1
 *
 */
int ingresarPath(char *guardar,void (*menu)(void), char* mensajeUno, char* mensajeDos)
{
	//1.limpio el buffer
	fflush(stdin);
    int error=1;
    int opcion;
    //2.creo una cadena auxiliar con el tamaño maximo ingresado por el usuario

    if(guardar != NULL)
    {
    		menu();
    		opcion = cargarUnEntero("Ingrese una opcion:", "Ingrese una opcion (entre 1 y 4)", 1, 4, 4);
    		switch(opcion)
    		{
    			case 1:
			    	strncpy(guardar, mensajeUno, 128);
			    	error = 0;

    				break;
    			case 2:
			    	strncpy(guardar, mensajeDos, 128);
			    	error = 0;
			    	break;
    			case 3:
    				getString(guardar, "Ingrese el path:", "Error, ingrese un path valido: ", 1, 128, 4);
    				break;
    		}
    }

    return error;
}

/** \brief Pide, valida y devuelve una cadena
 *
 * \param char* guardar: variable donde se va a guardar la cadena
 * \param char* mensaje: Recibe el mensaje para pedir Float
 * \param char* mensajeError: Recibe el mensaje de error al pedir Float
 * \param int rangoMin: Numero menor que recibe la funcion
 * \param int rangoMax: Numero mayor que recibe la funcion
 * \param int intentos: Cantidad de intentos de error para cargar el numero
 *
 * \return retorna 0 si se cargo la cadena, en caso de error retorna 1
 *
 */
int getString(char *guardar, char *mensaje, char *mensajeError, int rangoMin, int rangoMax, int intentos)
{
	//1.limpio el buffer
	fflush(stdin);
    int error=0;
    //2.creo una cadena auxiliar con el tamaño maximo ingresado por el usuario
    char stringAux[rangoMax];
    //3.imprimo el mensaje ingresado por el usuario
    printf("%s\n",mensaje);
    //4.guardo la variable ingresada | pido el tamaño de la cadena
    fgets(stringAux,sizeof(stringAux),stdin);
    //5.Al ultimo indice le asigno "\0"
    stringAux[strlen(stringAux)-1] = '\0';
    //6.si guardar no es nulo,
    //el tamaño de auxiliar es mayor o igual al minimo y menor o igual al maximo
   // y validar letra devuelve 0 (no hay numeros)
    if(guardar !=NULL && strlen(stringAux)>=rangoMin && strlen(stringAux)<=rangoMax && validarLetra(stringAux)==0)
    {
    	//7.guardo la cadena del auxiliar en el puntero guardar
    	strncpy(guardar, stringAux, rangoMax);
    	//8.Devuelvo 1 porque no hubo errores
    	error=1;
    }else{
    	//9.repito en caso de error
    	while(intentos>0)
    	{
    		printf("%s", mensajeError);
    		fgets(stringAux,sizeof(stringAux),stdin);
    		stringAux[strlen(stringAux)-1] = '\0';
    		if(guardar !=NULL && strlen(stringAux)>=rangoMin && strlen(stringAux)<=rangoMax && validarLetra(stringAux)==0)
    		{
    			strncpy(guardar, stringAux, rangoMax);
    			error = 1;
    			break;
    		}
    		intentos--;
    	  }
    }

    return error;
}
