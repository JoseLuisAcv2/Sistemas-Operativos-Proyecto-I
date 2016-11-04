/*
 *		SISTEMAS DE OPERACION - PROYECTO 1
 *
 *		Función para resolver el problema del Comando Militar (CM)
 *		mediante el uso de hilos. Cada hilo se encarga de procesar
 *		un grupo de bombas.
 *
 *		AUTORES:
 *				Jose Acevedo 13-10006
 *				Augusto Hidalgo XX-XXXXX
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "../sharedLib/ds.h"

void *thread_function(void *blist_ptr);
void process_bomb_list(bomb_list * blist);

int T;

pthread_mutex_t *mutex;
target *cur_trgt;

/*
 *	Función principal para resolver el problema del Comando Militar
 *	mediante hilos.
 */
void main_thread(int NThread, int T, target *trgt, int B, bomb *bmb){
	
	pthread_t *tid; // Arreglo de los id de los hilos.
	
	bomb_list *blist; // Arreglo de listas de bomba, cada lista es el argumento para un hilo.

	int i;
	
	cur_trgt = (target*) calloc(T,sizeof(target)); // Arreglo de los objetivos que sera modificado por la accion de las bombas.
	
	mutex = (pthread_mutex_t*)calloc(T,sizeof(pthread_mutex_t));
	for(i=0; i<T; i++)
		pthread_mutex_init(&mutex[i], NULL);
	
	for(i=0; i<T; i++){
		cur_trgt[i].x = trgt[i].x;
		cur_trgt[i].y = trgt[i].y;
		cur_trgt[i].vi = trgt[i].vi;
		cur_trgt[i].vf = trgt[i].vf;
	}
	
	tid = (pthread_t *)malloc(NThread*sizeof(pthread_t));
	blist = (bomb_list *)calloc((NThread+1),sizeof(bomb_list));
	
	for(i=0; i<NThread+1; i++)
		bomb_list_init(&blist[i]);

	for(i=0; i<B; i++)
		bomb_list_add(&blist[i%(NThread+1)], bmb[i].x, bmb[i].y, bmb[i].r, bmb[i].p);
	
	for(i=0; i<NThread; i++)
		pthread_create(&tid[i], NULL, thread_function, &blist[i]);
	
	if(blist[NThread].size > 0)
		process_bomb_list(&blist[NThread]);
	
	for(i=0; i<NThread; i++)
		pthread_join(tid[i], NULL);
		
	for(i=0; i<NThread+1; i++)
		bomb_list_free(&blist[i]);
	free(blist);
	
	for(i=0; i<T; i++){
		pthread_mutex_destroy(&mutex[i]);
	}
	free(mutex);
	
	free(bmb);
	free(cur_trgt);
	free(trgt);
	
	free(tid);
	
}

void process_bomb_list(bomb_list *blist){
	bomb_node * bnode = blist->head;
	while(bnode!=NULL){
		int x=bnode->x, y=bnode->y, r=bnode->r, p=bnode->p;
		int i=0;
		for(i=0; i<T; i++){
			if(x-r <= cur_trgt[i].x && cur_trgt[i].x <= x+r && y-r <= cur_trgt[i].y && cur_trgt[i].y <= y+r){
				pthread_mutex_lock(&mutex[i]);
				if(cur_trgt[i].vi < 0){
					if(cur_trgt[i].vf <= -p){
						cur_trgt[i].vf += p;
					}else{
						cur_trgt[i].vf = 0;
					}
				}else if(cur_trgt[i].vi > 0){
					if(cur_trgt[i].vf >= p){
						cur_trgt[i].vf -= p;
					}else{
						cur_trgt[i].vf = 0;
					}
				}
				pthread_mutex_unlock(&mutex[i]);
			}
		}
		bnode = bnode->next;
	}
}

void *thread_function(void *blist_ptr){
	bomb_list *blist = (bomb_list *)blist_ptr;
	process_bomb_list(blist);
	return (NULL);
}

//int main(int argc, char *argv[]){
//	main_thread(argv[argc-1], 2);
//	return 0;
//}