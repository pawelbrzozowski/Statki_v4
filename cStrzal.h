#pragma once
#ifndef FREEGLUT_CSTRZAL_H
#define FREEGLUT_CSTRZAL_H
#include <GL/freeglut.h>
#include <GL/glut.h>
class cStrzal {
	double x_, y_, typ_strzalu_, ilosc_uzyc_, red_, green_, blue_, a_, b_;
	bool czy_mozna_uzwac_bezkonca_;

public:
	cStrzal(double x, double y, double typstrzalu, double iloscuzyc, bool czywieloraz,double red=1, double green=1, double blue=0,double a=1, double b=1);
	void rysuj();
};


#endif 