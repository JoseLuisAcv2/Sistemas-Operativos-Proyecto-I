/*
 *		SISTEMAS DE OPERACION - PROYECTO 1
 *
 *		Función para leer entrada de datos del problema.	
 *
 *		AUTORES:
 *				Jose Acevedo 13-10006
 *				Augusto Hidalgo XX-XXXXX
 */

#include "read.h"
#include "ds.h"
#include <stdio.h>
#include <stdlib.h>

/*
 *	Función de lectura de datos desde un archivo.
 */
void read(char *file, int *pN, int *pT, int *pB, target **ptrgt, bomb **pbmb){

	freopen(file, "r", stdin);
	int N, T, B, i;
	target *trgt;
	bomb *bmb;

	scanf("%d %d",&N,&T);
	trgt = (target *) malloc(T*sizeof(target));

	for(i = 0; i < T; i++){
		int x, y, v;
		scanf("%d %d %d",&x,&y,&v);
		trgt[i].x = x;
		trgt[i].y = y;
		trgt[i].vi = v;
		trgt[i].vf = v;
	}

	scanf("%d",&B);
	bmb = (bomb *) malloc(B*sizeof(bomb));

	for(i = 0; i < B; i++){
		int x, y, r, p;
		scanf("%d %d %d %d",&x,&y,&r,&p);
		bmb[i].x = x;
		bmb[i].y = y;
		bmb[i].r = r;
		bmb[i].p = p;
	}
	
	*pN = N;
	*pT = T;
	*pB = B;
	*ptrgt = trgt;
	*pbmb = bmb;
	fclose(stdin);
}
