/*
 *		SISTEMAS DE OPERACION - PROYECTO 1
 *
 *		Función de entrada al programa.
 *
 *		AUTORES:
 *				Jose Acevedo 13-10006
 *				Augusto Hidalgo XX-XXXXX
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "sharedLib/ds.h"
#include "sharedLib/read.h"
#include "sharedLib/std_lib.h"
#include "Threads/thread_main.h"
#include "Processes/process_main.h"

int main() {

	/////////////////////////////////////////////////
	////////////// LEER FLAGS Y ARCHIVO /////////////
	/////////////////////////////////////////////////

	int N, T, B;
	target *t_arr;
	bomb *b_arr;
	char *file;

	// Leer archivo de datos
	read(file, &N, &T, &B, &t_arr, &b_arr);

	N = min(N,B);

	// aqui falta todo

	get_results(T,t_arr);

	return 0;
}