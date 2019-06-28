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
public:
	cProstokat(double poz_x, double poz_y, int typ_statku, int id, double a = 1, double b = 1, double red = 1, double blue = 1, double green = 1);
	void rysuj();
	void set_kolor(float r,float g, float b);
    void przesun(double dx, double dy);
	void podazaj_za_myszka(double dx, double dy);
	void dopasuj_element_na_planszy();
	bool isClicked(double openglX, double openglY);
	bool isUnclicked(double openglX, double openglY);
	void dane();
	void obroc();
	void set_wartoscx_oraz_y(int wartosc_x,int wartosc_y);
	double get_x();
	double get_y();
	double get_a();
	double get_b();
	int get_id();
};


#endif //FREEGLUT_CPROSTOKAT_H
