/*
 *		SISTEMAS DE OPERACION - PROYECTO 1
 *
 *		Header de funciones de entrada de datos.
 *
 *		AUTORES:
 *				Jose Acevedo 13-10006
 *				Augusto Hidalgo XX-XXXXX
 */

#ifndef _READ_H_INCLUDED
#define _READ_H_INCLUDED

#include "ds.h"

/*
 *	Función de lectura de datos desde un archivo.
 */
void read(char *file, int *pN, int *pT, int *pB, target **ptrgt, bomb **pbmb);

#endif