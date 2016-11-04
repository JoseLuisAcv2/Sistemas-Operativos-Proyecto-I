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
#include <sys/shm.h>
#include <sys/wait.h>
#include <semaphore.h>
#include "process_lib.h"
#include "../sharedLib/std_lib.h"
#include "../sharedLib/ds.h"

void f_parent_process(int N, int T, target *t_arr, int shm_tgt_id, sem_t *sem_arr, int shm_sem_id) {
	
	int i;
	for(i = 0; i < N; i++) {
		wait(NULL);
	}

	// Calcular e imprimir resultados del ataque.
	get_results(T,t_arr);

	// Desacoplar y eliminar segmento de memoria compartida con objetivos.
	shmdt(t_arr);
	shmctl(shm_tgt_id, IPC_RMID, NULL);

	// Desacoplar y eliminar semáforos.
	destroy_semaphores(sem_arr,T,&shm_sem_id);
}

/*
 *  Función para resolver el problema del CM con un único proceso.
 */
void f_only_process(int T, target *t_arr, int B, bomb *b_arr) {

	int b;
	for(b = 0; b < B; b++) {
		drop_bomb(b_arr[b],T,t_arr,0,NULL);
	}
	// Calcular e imprimir resultados del ataque.
	get_results(T,t_arr);
}