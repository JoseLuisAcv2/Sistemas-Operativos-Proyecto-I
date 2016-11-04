/*
 *		SISTEMAS DE OPERACION - PROYECTO 1
 *
 *		Header de librería de funciones para el
 *		proceso principal.
 *
 *		AUTORES:
 *				Jose Acevedo 13-10006
 *				Augusto Hidalgo XX-XXXXX
 */
 
#ifndef PROCESS_PARENT_H_
#define PROCESS_PARENT_H_

#include "../sharedLib/ds.h"

/*
 *  Función para procesar resultado obtenido por procesos ayudantes.
 */
void f_parent_process(int , int , target *, target *, int , sem_t *, int);

/*
 *  Función para resolver el problema del CM con un único proceso.
 */
void f_only_process(int , target *, int, bomb *);

#endif