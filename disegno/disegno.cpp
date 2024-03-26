#include <vector>
#include <iostream>

#include "disegno.h"

using namespace std;

// ITALIANO
//
// Come usare la struct Point:
//
//  - Puoi accedere ai campi x e y di una variabile P di tipo Point tramite
//      P.x
//      P.y
//    Per esempio, per leggere la coordinata x di A[i] scrivi A[i].x,
//    e per assegnare 3 alla coordinata y di P scrivi P.y = 3.
//  - Puoi dichiarare e inizializzare una nuova variabile di tipo Point tramite
//      Point P{x, y};
//    dove x e y sono i valori da assegnare ai campi P.x e P.y.

// ENGLISH
//
// How to use the struct Point:
//
//  - To access the fields x and y of a variable P of type Point, use
//      P.x
//      P.y
//    For example, you can read the x-coordinate of A[i] by writing A[i].x,
//    and you can assign the value 3 to the y-coordinate of P by writing P.y = 3.
//  - To declare and initialize a new variable of type Point, use
//      Point P{x, y};
//    where x and y are the values to be assigned to fields P.x and P.y.

int divide(int lx, int ux, int ly, int uy, vector<Point>& ans){
	if ((ux - lx <= 1) && (uy - ly > 1))
		return 1;
	if ((uy - ly <= 1) && (ux - lx > 1))
		return 1;	
	if ((ux - lx <= 1) && (uy - ly <= 1))
		return 0;
	int j;
	ans.push_back((Point){-1, -1});
	for (j = 0; j < 4; j++){
		ans.pop_back();
		int midx = (lx + ux) / 2 + (j == 1 || j == 3);
		int midy = (ly + uy) / 2 + (j == 2 || j == 3);
		ans.push_back((Point){midx, midy});
		for (int i = max(0, (int)(ans.size()) - 10); i < ans.size(); i++)
			if (midx == ans[i].x && midy == ans[i].y)
				continue;
		if (divide(lx, midx, ly, midy, ans)) continue;
		if (divide(midx, ux, ly, midy, ans)) continue;
		if (divide(lx, midx, midy, uy, ans)) continue;
		if (divide(midx, ux, midy, uy, ans)) continue;
		break;
	}
	if (j == 4)
		ans.pop_back();
	
	return j == 4;
}

vector<Point> draw(int N, int L, vector<Point> A, vector<Point> B) {
	vector<Point> ans;

	if (divide(0, L, 0, L, ans))
		ans.resize(0);
	
	return ans;
}
