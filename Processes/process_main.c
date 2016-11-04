/*
 *		SISTEMAS DE OPERACION - PROYECTO 1
 *
 *		Función para resolver el problema del Comando Militar (CM)
 *		mediante el uso de procesos ayudantes. Cada proceso ayudante
 *		se encarga de procesar un grupo de bombas.
 *
 *		Se utiliza segmento de memoria compartida y semáforos 
 *		POSIX sin nombre para sincronizar los procesos participantes.
 *
 *		AUTORES:
 *				Jose Acevedo 13-10006
 *				Augusto Hidalgo XX-XXXXX
 */

#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include "process_lib.h"
#include "process_parent.h"
#include "process_child.h"
#include "../sharedLib/ds.h"

/*
 *	Función principal para resolver el problema del Comando Militar
 *	mediante procesos.
 */
void main_process(int N, int B, int T, bomb *b_arr, target *t_arr) {
	/*
	 *  Resolver problema con procesos ayudantes.
	 */
	if(N > 0) {

		// Ubicar targets en memoria compartida
		int shm_tgt_id;
		target *t_arr_orig;
		//compartir_targets(t_arr,t_arr_orig,T,&shm_tgt_id);

		// Crear semáforos
		int shm_sem_id;
		sem_t *sem_arr;
		create_semaphores(&sem_arr,T,&shm_sem_id);

		pid_t ps_parent_pid = getpid();

		// Creación de procesos ayudantes.
		int child_id;
		fork_children(N,ps_parent_pid,&child_id);
		
		if(getpid() == ps_parent_pid) {
			// Trabajo del padre
			f_parent_process(N,T,t_arr,t_arr_orig,shm_tgt_id,sem_arr,shm_sem_id);
		} else {
			// Trabajo de los hijos
			f_child_process(child_id,N,T,t_arr,B,b_arr,sem_arr);
		}
	} 
	/*
	 *  Resolver problema con un único proceso.
	 */
	else {
		f_only_process(T,t_arr,B,b_arr);
	}
}
