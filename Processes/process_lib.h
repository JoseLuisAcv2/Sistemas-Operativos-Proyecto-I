/*
 *		SISTEMAS DE OPERACION - PROYECTO 1
 *
 *		Header de librería de funciones auxiliares para resolver
 *		el problema del Comando Militar (CM) con procesos.	
 *
 *		AUTORES:
 *				Jose Acevedo 13-10006
 *				Augusto Hidalgo XX-XXXXX
 */
 
#ifndef PROCESS_LIB_H_
#define PROCESS_LIB_H_

#include "../sharedLib/ds.h"

/*
 *	Función para crear procesos ayudantes.
 */
void fork_children(int , pid_t, int *);

/*
 *  Función para crear semáforos en memoria compartida.
 */
void create_semaphores(sem_t **, int, int *);

/*
 *  Función para destruir los semáforos creados y liberar
 *	el segmento de memoria compartida.
 */
void destroy_semaphores(sem_t *, int, int *);

/*
 *  Función para copiar los objetivos en memoria compartida y
 *  ser modificados por varios procesos.
 */
void share_targets(target **, int, int *);

#endif