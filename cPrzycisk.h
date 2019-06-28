#ifndef FREEGLUT_CPRZYCISK_H
#define FREEGLUT_CPRZYCISK_H

#include <GL/freeglut.h>
#include <GL/glut.h>
#include <iostream>
class cPrzycisk {
	double a_, b_, x_, y_;
	int typ_;
	double red_, green_, blue_;
	bool przycisk_klikniety_;
public:
	cPrzycisk(double poz_x, double poz_y, int typ_statku, double a = 1, double b = 1, double red = 1, double blue = 1, double green = 1, bool przyclick = false);
	void rysuj();
	void set_kolor(float r, float g, float b);
	void przesun(double dx, double dy);
	bool isClicked(double openglX, double openglY);
	bool isUnclicked(double openglX, double openglY);
	void dane();
	int get_typ();
	void set_stan_klikniety();
	bool get_stan_klikniety();
};


#endif 