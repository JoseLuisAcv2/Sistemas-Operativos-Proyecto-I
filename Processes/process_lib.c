/*
 *		SISTEMAS DE OPERACION - PROYECTO 1
 *
 *		Librería de funciones auxiliares para resolver el problema
 *		del Comando Militar (CM) con procesos.	
 *
 *		AUTORES:
 *				Jose Acevedo 13-10006
 *				Augusto Hidalgo XX-XXXXX
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <fcntl.h>
#include "../sharedLib/ds.h"

/*
 *	Función para crear procesos ayudantes.
 *	A cada uno se le asigna un id para identificar
 *  que grupo de bombas va a procesar.
 */
void fork_children(int n, pid_t ps_parent_pid, int *id) {
	
	*id = -1;
	int i;
	for(i = 0; i < n; i++) {
		if(getpid() == ps_parent_pid) {
			fork();
			if(getpid() != ps_parent_pid && *id == -1) {
				*id = i;
			}
		}
	}
}
 
/*
 *  Función para crear semáforos en memoria compartida.
 */
void create_semaphores(sem_t **sem_arr, int n, int *shm_sem_id) {

	*shm_sem_id = shmget(IPC_PRIVATE, n*sizeof(sem_t), IPC_CREAT | 0666);
	*sem_arr = (sem_t *) shmat(*shm_sem_id, NULL, 0);

	int i;
	for(i = 0; i < n; i++) {
		sem_init(&(*sem_arr)[i],1,1);
	}
}

/*
 *  Función para destruir los semáforos creados y liberar
 *	el segmento de memoria compartida.
 */
void destroy_semaphores(sem_t *sem_arr, int n, int *shm_sems_id) {

	int i;
	for(i = 0; i < n; i++) {
		sem_destroy(&sem_arr[i]);
	}
	shmdt(sem_arr);
	shmctl(*shm_sems_id, IPC_RMID, NULL);
}

/*
 *  Función para copiar los objetivos en memoria compartida y
 *  ser modificados por varios procesos.
 */
void share_targets(target **t_arr, int n, int *shm_tgt_id) {

	target * t_arr_orig = *t_arr;
	*shm_tgt_id = shmget(IPC_PRIVATE, n*sizeof(target), IPC_CREAT | 0666);
	*t_arr = (target *) shmat(*shm_tgt_id, NULL, 0);
	
	int i;
	for(i = 0; i < n; i++) {
		(*t_arr)[i].x = t_arr_orig[i].x;
		(*t_arr)[i].y = t_arr_orig[i].y;
		(*t_arr)[i].vi = t_arr_orig[i].vi;
		(*t_arr)[i].vf = t_arr_orig[i].vf;
	}
}