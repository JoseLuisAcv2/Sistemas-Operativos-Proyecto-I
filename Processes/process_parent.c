/*
 *		SISTEMAS DE OPERACION - PROYECTO 1
 *
 *		Función del proceso principal para resolver el problema
 *		del Comando Militar (CM).

 *		AUTORES:
 *				Jose Acevedo 13-10006
 *				Augusto Hidalgo XX-XXXXX
 */

#include <stdio.h>
#include <sys/wait.h>
#include <semaphore.h>
#include "process_lib.h"
#include "../sharedLib/std_lib.h"
#include "../sharedLib/ds.h"

void f_parent_process(int N, int T, target *t_arr, target *t_arr_orig, int shm_tgt_id, sem_t *sem_arr, int shm_sem_id) {
	
	int i;
	for(i = 0; i < N; i++) {
		wait(NULL);
	}

	// Eliminar semáforos
	destroy_semaphores(sem_arr,T,&shm_sem_id);

	// Recuperar y eliminar segmento de memoria compartida con targets
	//retrieve_targets(t_arr,t_arr_orig,T,&shm_tgt_id);
}

/*
 *  Función para resolver el problema del CM con un único proceso.
 */
void f_only_process(int T, target *t_arr, int B, bomb *b_arr) {

	int b;
	for(b = 0; b < B; b++) {
		drop_bomb(b_arr[b],T,t_arr,0,NULL);
	}
}