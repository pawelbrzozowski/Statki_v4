#pragma once
#ifndef FREEGLUT_CSTRZAL_H
#define FREEGLUT_CSTRZAL_H
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <cmath>
class cStrzal {
	double x_, y_, typ_strzalu_, ilosc_uzyc_, red_, green_, blue_, a_, b_;
	bool czy_mozna_uzwac_bezkonca_;

public:
	cStrzal(double x, double y, double typstrzalu, double iloscuzyc, bool czywieloraz,double red=1, double green=1, double blue=0,double a=1, double b=1);
	void rysuj();
	double get_ilosc_uzyc_pozostala();
	int get_typ();
	bool isClicked(double openglX, double openglY);
	bool isUnclicked(double openglX, double openglY);
	void dopasuj_element_na_planszy();
	void podazaj_za_myszka(double dx, double dy);
	double get_x();
	double get_y();
	double get_a();
	double get_b();
	void set_x_y(double x, double y);
	void zmniejsz_ilosc__uzyc_o_1();
};


#endif 