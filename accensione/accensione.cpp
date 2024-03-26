#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void Accendi(int N, int acceso[], int pulsante[]){

	for (int i = N; i > 0; i--){
		int s = 0;
		for (int j = i; j <= N; j += i)
			s += (pulsante[j]);
		pulsante[i] = (!acceso[i] != (s%2));
	}
	
}