/*
 *		SISTEMAS DE OPERACION - PROYECTO 1
 *
 *		Funciones para las estructuras de datos.
 *
 *		AUTORES:
 *				Jose Acevedo 13-10006
 *				Augusto Hidalgo XX-XXXXX
 */
 
#include <stdlib.h>
#include "ds.h"

/*
 *	Inicializar lista de bombas.
 */
void bomb_list_init(bomb_list *l){
	l->size = 0;
	l->head = NULL;
}  

/*
 *	Agregar bomba a una lista de bombas.
 */
void bomb_list_add(bomb_list *l, int x, int y, int r, int p){
	bomb_node *node = (bomb_node*)malloc(sizeof(bomb_node));
	node->x = x;
	node->y = y;
	node->r = r;
	node->p = p;
	node->next = l->head;
	l->head = node;
	l->size++;
}

/*
 *	Eliminar lista de bombas.
 */
void bomb_list_free(bomb_list *l){
	bomb_node *node, *prevnode;
	node = l->head;
	prevnode = NULL;
	while(node != NULL){
		prevnode = node;
		node = node->next;
		free(prevnode);
	}
	l->head = NULL;
	l->size = 0;
}