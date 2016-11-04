/*
 *		SISTEMAS DE OPERACION - PROYECTO 1
 *
 *		Header de funciónes auxiliares para resolver el problema del
 *		Comando Militar (CM). Las funciones son utilizadas tanto por la
 *		solución con procesos como por la solución por hilos.
 *
 *		AUTORES:
 *				Jose Acevedo 13-10006
 *				Augusto Hidalgo XX-XXXXX
 */

#ifndef STD_LIB_H_
#define STD_LIB_H_

#include <semaphore.h>
#include "ds.h"

/*
 *  Función que retorna el mínimo entre dos valores.
 */
int min(int, int);

/*
 *	Función que determina si un objetivo se encuentra dentro del rango
 *  de alcance de la bomba.
 */
int in_range(bomb, target);

/*
 *	Función que actualiza el valor del objetivo alcanzado por una bomba.
 */
void update_range(target *, int);

/*
 *	Función que determina los objetivos alcanzables por una bomba y
 *  aplica el daño mediante el uso de semaforos.
 */
void drop_bomb(bomb, int, target *, int, sem_t *);

/*
 *	Determinar los resultados del ataque e imprimir por consola.
 */
void get_results(int, target *);

#endif