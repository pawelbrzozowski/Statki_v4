//
// Created by piotr on 27.03.19.
//

#ifndef FREEGLUT_CPROSTOKAT_H
#define FREEGLUT_CPROSTOKAT_H
#include <GL/freeglut.h>
#include <GL/glut.h>
class cProstokat {
double a_, b_, x_, y_;
int typ_;
double red_, green_, blue_;
int id_;
bool czy_obrocono_statek_, juz_raz_mnie_obrocono_;
public:
	cProstokat(double poz_x, double poz_y, int typ_statku, int id, double a = 1, double b = 1, double red = 1, double blue = 1, double green = 1, bool czy_obrocno2 = false);
	void rysuj();
	void set_kolor(float r,float g, float b);
    void przesun(double dx, double dy);
	void podazaj_za_myszka(double dx, double dy);
	void dopasuj_element_na_planszy();
	bool isClicked(double openglX, double openglY);
	bool isUnclicked(double openglX, double openglY);
	void dane();
	void dane_rozlozenia_losowego();
	void obroc();
	void set_wartoscx_oraz_y(int wartosc_x,int wartosc_y);
	double get_x();
	double get_y();
	double get_a();
	double get_b();
	int get_id();
	int get_typ();
	void set_juz_mnie_obracano(bool wartosc);
	bool get_juz_mnie_obracano();
};


#endif //FREEGLUT_CPROSTOKAT_H
