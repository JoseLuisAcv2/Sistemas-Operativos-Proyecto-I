/*
 *		SISTEMAS DE OPERACION - PROYECTO 1
 *
 *		Header de librería de funciones de los
 *		procesos ayudantes.
 *
 *		AUTORES:
 *				Jose Acevedo 13-10006
 *				Augusto Hidalgo XX-XXXXX
 */
 
#ifndef PROCESS_CHILD_H_
#define PROCESS_CHILD_H_

#include <semaphore.h>
#include "../sharedLib/ds.h"

/*
 *  Función para procesar un grupo de bombas por el proceso ayudante.
 */
void f_child_process(int , int, int , target *, int , bomb *, sem_t *);

#endif