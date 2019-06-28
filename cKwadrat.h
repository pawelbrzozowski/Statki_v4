#ifndef CKWARAT_H_INCLUDE
#define CKWARAT_H_INCLUDE
#endif
#include <vector>

class cKwarat {
	int x_, y_, id_, typ_statku_;
	bool czy_kwarat_jest_zajety_,czy_trafiony_;

public:
	friend class cScena;
	cKwarat(int x1 = 0, int y1 = 0, bool czy_zajety = false,int id=0,int typ_startku=0,bool czy_trafiony=false);
	void zainicjuj_kwadrat(int x, int y, int id);
	void set_czy_kwarat_jest_zajety(bool wartosc);
	bool get_czy_kwarat_jest_zajety();
	int get_x();
	int get_y();
	int get_id();
	void set_typ_statku(int wartosc);
	int get_typ_statku();
	void set_czy_traiony(bool wartosc);
	bool get_czy_trafiony();
};