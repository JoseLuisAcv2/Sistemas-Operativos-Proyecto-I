/*
 *		SISTEMAS DE OPERACION - PROYECTO 1
 *
 *		Función de los procesos ayudantes para resolver el problema
 *		del Comando Militar (CM). Cada proceso ayudante se encarga de
 *		procesar un grupo de bombas.
 *
 *		AUTORES:
 *				Jose Acevedo 13-10006
 *				Augusto Hidalgo XX-XXXXX
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>
#include <semaphore.h>
#include "../sharedLib/std_lib.h"
#include "../sharedLib/ds.h"

/*
 *  Función para procesar un grupo de bombas por el proceso ayudante.
 */
void f_child_process(int id, int N, int T, target *t_arr, int B, bomb *b_arr, sem_t *sem_arr) {

	// Procesar bombas asignadas
	int b;
	for(b = 0; b < B; b++) {
		if(b % N == id) {
			drop_bomb(b_arr[b], T, t_arr, 1, sem_arr);
		}
	}

	// Desacoplar memoria compartida con targets
	shmdt(t_arr);

	// Desacoplar memoria compartida con semáforos
	shmdt(sem_arr);
}