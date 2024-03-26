#include <assert.h>
#include <stdio.h>

#define MAXN 1000 //per dichiarare una costante "visibile" da tutte le funzioni del presente file.cpp

int main() {
    freopen("input.txt", "r", stdin); //per leggere da un file chiamato input.txt
    freopen("output.txt", "w", stdout); //per scrivere su un file chiamato output.txt

	int i, S[MAXN], N, max = -1001; // il testo dell'esercizio dice che i valori dei numeri nel file input.txt sono 
	                                // compresi tra -1000 e +1000, quindi max può essere inizializzato a -1001
	                                // La variabile S[MAXN] è il vettore di interi in cui vengono scritti gli N
	                                // numeri presenti nel file input.txt

    assert(1 == scanf("%d", &N)); 
	/* scanf è la funzione di lettura dall'input specificato in precedenza, in questo caso dal file input.txt.
	   scanf ha come primo parametro il tipo di dato che verrà letto dal file (ossia un "decimal integer", un intero)
	     e come secondo parametro il puntatore alla variabile in cui verrà salvato il risultato, in questo caso N.
	   Il testo di questo esercizio precisa che nel file input.txt il primo numero è il numero di valori numerici
	   presenti nella seconda riga. Quindi l'istruzione precedente, che è la prima lettura nel file, 
	   assegna alla variabile N il numero dei numeri presenti nel file tra i quali si deve trovare il valore massimo.
	*/
    
	for(i=0; i<N; i++){  // Questo ciclo iterativo prosegue con 
		assert(1 == scanf("%d", &S[i])); // la lettura nel file di input di un numero alla volta assegnandolo a S[i]
    	if(S[i] > max){  // Con questa selezione si determina il valore massimo tra tutti gli N numeri letti nel file
    		max = S[i];    
    	}
	}
	
    printf("%d\n", max); // Questa istruzione scrive nel file di output specificato all'inizio del programma
    return 0;            // un valore numerico (%d), che si trova nella variabile max. 
	                     // Dopo aver scritto il numero va a capo.
}
