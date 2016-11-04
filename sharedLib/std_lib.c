/*
 *		SISTEMAS DE OPERACION - PROYECTO 1
 *
 *		Funciónes auxiliares para resolver el problema del
 *		Comando Militar (CM). Son utilizadas tanto por la
 *		solución con procesos como por la solución por hilos.
 *
 *		AUTORES:
 *				Jose Acevedo 13-10006
 *				Augusto Hidalgo XX-XXXXX
 */

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include "ds.h"

/*
 *  Función que retorna el mínimo entre dos valores.
 */
int min(int a, int b){return a<b ? a:b;}

/*
 *	Función que determina si un objetivo se encuentra dentro del rango
 *  de alcance de la bomba.
 */
int in_range(bomb b, target t) {
	return abs(b.x - t.x) <= b.r && abs(b.y - t.y) <= b.r;	
}

/*
 *	Función que actualiza el valor del objetivo alcanzado por una bomba.
 */
void update_target(target *t, int p) {
	// Objetivo militar
	if(t->vi < 0) {
		t->vf += p;
	} 
	// Objetivo civil
	else {
		t->vf -= p;
	}
}

/*
 *	Función que determina los objetivos alcanzables por una bomba y
 *  aplica el daño mediante el uso de semaforos.
 */
void drop_bomb(bomb b, int T, target *t_arr, int sem_on, sem_t *sem_arr) {

	int i;
	for(i = 0; i < T; i++) {
		if(in_range(b, t_arr[i])) {
			if(sem_on) sem_wait(&sem_arr[i]);
			update_target(&t_arr[i], b.p);
			if(sem_on) sem_post(&sem_arr[i]);
		}
	}
}

/*
 *	Determinar los resultados del ataque e imprimir por salida estándar.
 */
void get_results(int T, target *t_arr) {

	int OMT = 0, OMP = 0, OMN = 0, OCT = 0, OCP = 0, OCN = 0, i;
	for(i = 0; i < T; i++) {
		// Objetivo civil
		if(t_arr[i].vi > 0) {
			// No afectado
			if(t_arr[i].vf == t_arr[i].vi) {
				OCN++;
			} else if(t_arr[i].vf > 0) {
				OCP++;
			} else {
				OCT++;
			}
		}
		// Objetivo militar
		else if(t_arr[i].vi < 0){
			// No afectado
			if(t_arr[i].vf == t_arr[i].vi) {
				OMN++;
			} else if(t_arr[i].vf < 0) {
				OMP++;
			} else {
				OMT++;
			}
		}
	}

	printf("Objetivos Militares totalmente destruidos: %d\n", OMT);
	printf("Objetivos Militares parcialmente destruidos: %d\n", OMP);
	printf("Objetivos Militares no afectados: %d\n", OMN);
	printf("Objetivos Civiles totalmente destruidos: %d\n", OCT);
	printf("Objetivos Civiles parcialmente destruidos: %d\n", OCP);
	printf("Objetivos Civiles no afectados: %d\n", OCN);
}