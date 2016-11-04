/*
 *		SISTEMAS DE OPERACION - PROYECTO 1
 *
 *		Definición de estructuras a ser usadas en la
 *		resolución del problema y declaración de sus
 *		funciones.
 *
 *		AUTORES:
 *				Jose Acevedo 13-10006
 *				Augusto Hidalgo XX-XXXXX
 */

#ifndef DS_H_
#define DS_H_

/*
 *	Estructura target para los objetivos del Comando Militar (CM)
 */
struct target {
  int x, y, vi, vf;
};

typedef struct target target;

/*
 *	Estructura de bomba para las bombas del Comando Militar (CM)
 */
struct bomb {
  int x, y, r, p;
};

typedef struct bomb bomb;

/*
 *	Deficinión de estructura de node de lista de bombas.
 */
struct bomb_node {
	int x, y, r, p;
	struct bomb_node *next;
};

typedef struct bomb_node bomb_node;

/*
 *	Deficinión de estructura de lista de bombas.
 */
struct bomb_list {
	int size;
	bomb_node *head;
};

typedef struct bomb_list bomb_list;

/*
 *	Inicializar lista de bombas.
 */
void bomb_list_init(bomb_list *l);

/*
 *	Agregar bomba a una lista de bombas.
 */
void bomb_list_add(bomb_list *l, int x, int y, int r, int p);

/*
 *	Eliminar lista de bombas.
 */
void bomb_list_free(bomb_list *l);

#endif