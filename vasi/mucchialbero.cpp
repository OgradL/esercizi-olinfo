#include <iostream>
#include <stdio.h>
using namespace std;

struct nodo {
	int valore;
	long long priorita;
	int dimensione_sottoalbero;
	nodo *sinistrorso, *destrorso;
	nodo () {}
};

nodo magazzino[10000069];
int indice_allocazione = 0;
nodo *alloca_nodo () {
	return magazzino+(indice_allocazione++);
}

nodo *alloca_nodo(int valore) {
	nodo *nuovo_nodo = magazzino+
		(indice_allocazione++);
	nuovo_nodo->valore = valore;
	nuovo_nodo->priorita = rand();
	nuovo_nodo->dimensione_sottoalbero = 1;
	nuovo_nodo->destrorso = NULL;
	nuovo_nodo->sinistrorso = NULL;
	return nuovo_nodo;
}

struct mucchialbero {
	nodo *radice_vera = NULL;

	int dimensione_sottoalbero (nodo *nodo_a_caso) {
		if (!nodo_a_caso) return 0;
		return nodo_a_caso->dimensione_sottoalbero;
	}

	void aggiorna_nodo (nodo *nodo_a_caso) {
		if (!nodo_a_caso) return;
		nodo_a_caso->dimensione_sottoalbero = 1+
			dimensione_sottoalbero(nodo_a_caso->sinistrorso)+
			dimensione_sottoalbero(nodo_a_caso->destrorso);
	}

	void dividi_mucchialbero ( 
		nodo *radice,
		nodo *& sinistro,
		nodo *& destro,
		int cappa,
		int saltati = 0 ) {
		if (!radice) {
			destro = sinistro = NULL;
			return;
		}

		int indice = saltati+
			dimensione_sottoalbero(radice->sinistrorso);

		if (indice <= cappa) {
			sinistro = radice;
			dividi_mucchialbero(    
				sinistro->destrorso,
				sinistro->destrorso,
				destro,cappa,indice+1 );
		} else {
			destro = radice;
			dividi_mucchialbero(    
				destro->sinistrorso,
				sinistro,destro->sinistrorso,
				cappa,saltati );
		}
		aggiorna_nodo(sinistro);
		aggiorna_nodo(destro);
	}

	void unifica_mucchialberi ( 
		nodo *& radice, 
		nodo *sinistro, 
		nodo *destro ) {

		if (!sinistro) {
			return void ( radice = destro );
		}
		if (!destro) {
			return void ( radice = sinistro );
		}
		if (sinistro->priorita < destro->priorita) {
			radice = sinistro;
			unifica_mucchialberi (  
				radice->destrorso,
				radice->destrorso,destro);
		} else {
			radice = destro;
			unifica_mucchialberi (
				radice->sinistrorso,
				sinistro,radice->sinistrorso);
		}
		aggiorna_nodo (radice);
	}

	int ennesimo_elemento (
		nodo *radice,
		int enne,
		int saltati = 0) {

		int indice = saltati+
			dimensione_sottoalbero(radice->sinistrorso);

		if (indice == enne) {
			return radice->valore;
		}
		if (indice < enne) {
			return ennesimo_elemento (
				radice->destrorso,
				enne, indice+1);
		} else {
			return ennesimo_elemento (
				radice->sinistrorso,
				enne, saltati);
		}
	}

	int ennesimo_elemento (int enne) {
		return ennesimo_elemento (radice_vera,enne);
	}

	void sposta (int da,int a) {
		nodo *sinistro,*destro,*elemento;
		dividi_mucchialbero (
			radice_vera,sinistro,destro,da
		);
		dividi_mucchialbero (
			sinistro,sinistro,elemento,da-1
		);
		unifica_mucchialberi (
			radice_vera,sinistro,destro
		);
		dividi_mucchialbero (
			radice_vera,sinistro,destro,a-1
		);
		unifica_mucchialberi (
			radice_vera,sinistro,elemento
		);
		unifica_mucchialberi (
			radice_vera,radice_vera,destro
		);
	}

	void ammucchia (nodo *radice) {
		nodo *massimo = radice;
		if (
			radice->sinistrorso &&
			radice->sinistrorso->priorita 
			< radice->priorita
		) {
			massimo = radice->sinistrorso;
		}
		if (
			radice->destrorso &&
			radice->destrorso->priorita
			< massimo->priorita
		) {
			massimo = radice->destrorso;
		}
		if (massimo == radice) return;
		swap(radice->priorita,massimo->priorita);
		ammucchia (massimo);
	}

	void costruisci_linearmente (
		nodo *& radice,
		int sinistra,int destra ) {
		if (destra-sinistra < 1) return;    
		int meta = (sinistra + destra) / 2;
		radice = alloca_nodo(meta);
		costruisci_linearmente (
			radice->sinistrorso,
			sinistra,meta
		);
		costruisci_linearmente (
			radice->destrorso,
			meta+1,destra
		);
		aggiorna_nodo (radice);
		ammucchia (radice);
	}

	mucchialbero (int dimensione) {
		costruisci_linearmente(radice_vera,0,dimensione);
	}
};


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cout.tie(0);
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	int dimensione,richieste;
	cin >> dimensione;
	cin >> richieste;

	mucchialbero dante (dimensione);

	while (richieste--) {
		char tipo;
		cin >> tipo;
		if (tipo == 'c') {
			int posizione;
			cin >> posizione;
			int valore;
			valore = dante.ennesimo_elemento(posizione);
			cout << valore << " ";
		} else {
			int da,a;
			cin >> da;
			cin >> a;
			dante.sposta(da,a);
		}
	}
	cout << endl;

	return 0;
}