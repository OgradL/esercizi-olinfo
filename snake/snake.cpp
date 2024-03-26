#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int riga;
	int colonna;
} cella_t;

typedef enum
{
	SOPRA,
	SOTTO,
	DESTRA,
	SINISTRA
} direzione_t;

cella_t posizione_mela();

void muovi(direzione_t);

void gioca(int R, int C){
	direzione_t* moves = (direzione_t*) malloc(R * C * sizeof(direzione_t));
	int mossa = 0;
	if (~R & 1){
		moves[mossa++] = DESTRA;
		for (int j = 0; j < R; j += 2){
			for (int i = 1; i < C-1; i++)
				moves[mossa++] = DESTRA;
			moves[mossa++] = SOTTO;
			for (int i = 1; i < C-1; i++)
				moves[mossa++] = SINISTRA;
			if (j != R - 2){
				moves[mossa++] = SOTTO;
			}
		}
		moves[mossa++] = SINISTRA;
		for (int j = 0; j < R-1; j++){
			moves[mossa++] = SOPRA;
		}
	} else if (~C & 1){
		moves[mossa++] = SOTTO;
		for (int j = 0; j < C; j += 2){
			for (int i = 1; i < R-1; i++)
				moves[mossa++] = SOTTO;
			moves[mossa++] = DESTRA;
			for (int i = 1; i < R-1; i++)
				moves[mossa++] = SOPRA;
			if (j != C - 2){
				moves[mossa++] = DESTRA;
			}
		}
		moves[mossa++] = SOPRA;
		for (int j = 0; j < C-1; j++){
			moves[mossa++] = SINISTRA;
		}
	}

	mossa = 0;
	while (1){
		muovi(moves[mossa++]);
		mossa = mossa % (R * C);
	}
}
