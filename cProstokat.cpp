//
// Created by piotr on 27.03.19.
//

#include "cProstokat.h"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
cProstokat::cProstokat(double poz_x, double poz_y, int typ_statku, int id, double a, double b, double red , double blue , double green) : a_(a), b_(b), red_(red), green_(green), blue_(blue),x_(poz_x),y_(poz_y), typ_(typ_statku), id_(id){
}
void cProstokat::przesun(double dx, double dy) {
	x_ += dx;
    y_ += dy;
}
void cProstokat::rysuj() {
	glColor3d(red_, green_, blue_);
	glRectd(x_, y_, x_ + a_, y_ + b_);
}
void cProstokat::dane() {
	std::cout << "Klinieto na prosotkat (" << x_ << "," << y_ << ")" << " dlugosc to " << a_ << "natomiast wysokosc " << b_ << " jest to: " << typ_ << "masztowiec " << "ID STATKU ---> " << id_ << endl;
}
void cProstokat::set_kolor(float r, float g, float b) {
	red_ = r;
	green_ = g;
	blue_ = b;
}
bool cProstokat::isUnclicked(double openglX, double openglY) {
	if (openglX <(x_ + a_) && openglX >x_ && openglY < (y_ + b_) && openglY >y_) {
		return true;
		
	}
	return false;
}
bool cProstokat::isClicked(double openglX, double openglY) {
	if (openglX <(x_ + a_) && openglX >x_ && openglY < (y_ + b_) && openglY >y_)
	{
		return true;
		
	}
	return false;
}
void cProstokat::podazaj_za_myszka(double x, double y) {
	x_ = x-a_/2.0;
	y_ = y-b_/2.0;
}
void cProstokat::dopasuj_element_na_planszy() {
	if (x_ < 10)
	{
		double tmp1, tmp2;
		tmp1=round(x_);
		tmp2=round(y_);
		x_ = tmp1;
		y_ = tmp2;
	}
}
double cProstokat::get_x() {
	return x_;
}
double cProstokat::get_y() {
	return y_;
}
double cProstokat::get_a() {
	return a_;
}
double cProstokat::get_b() {
	return b_;
}
int cProstokat::get_id() {
	return id_;
}
void cProstokat::obroc() {
	double tmp;
	tmp = a_;
	a_ = b_;
	b_ = tmp;
}