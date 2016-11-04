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

	int N, T, B, nProc = 3;
	target *t_arr;
	bomb *b_arr;
	char *file = "in";

	// Leer archivo de datos
	read(file, &N, &T, &B, &t_arr, &b_arr);


	/////// prpbando.... //////

	nProc = min(nProc,B);

	//main_thread(nProc,T,t_arr,B,b_arr);
	main_process(nProc,T,t_arr,B,b_arr);

	free(t_arr);
	free(b_arr);

	return 0;
}