#ifndef CSIATKA_H_INCLUDED
#define CSIATKA_H_INCLUDED
#endif
#include <vector>

class cSiatka {
	int x1_, y1_, x2_, y2_, id_siatki_;
public:
	friend class cScena;
	cSiatka(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, int id_siatki = 0);
	void zainicjuj_siatke(int x1, int y1, int x2, int y2, int id_siatki);
	void rysuj_siatke();
	void kwadracik(int x, int y);
};