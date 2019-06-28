//
// Created by piotr on 27.03.19.
//

#include "cPrzycisk.h"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
cPrzycisk::cPrzycisk(double poz_x, double poz_y, int typ_statku, double a, double b, double red, double blue, double green, bool przyclick) : a_(a), b_(b), red_(red), green_(green), blue_(blue), x_(poz_x), y_(poz_y), typ_(typ_statku), przycisk_klikniety_(przyclick) {
}
void cPrzycisk::przesun(double dx, double dy) {
	x_ += dx;
	y_ += dy;
}
void cPrzycisk::rysuj() {
	glColor3d(red_, green_, blue_);
	glRectd(x_, y_, x_ + a_, y_ + b_);
}
void cPrzycisk::dane() {
	std::cout << "Klinieto na przycysk (" << x_ << "," << y_ << ")" << "typ przysisku to: " << typ_ << endl;
}
void cPrzycisk::set_kolor(float r, float g, float b) {
	red_ = r;
	green_ = g;
	blue_ = b;
}
bool cPrzycisk::isUnclicked(double openglX, double openglY) {
	if (openglX <(x_ + a_) && openglX >x_ && openglY < (y_ + b_) && openglY >y_) {
		return true;

	}
	return false;
}
bool cPrzycisk::isClicked(double openglX, double openglY) {
	if (openglX <(x_ + a_) && openglX >x_ && openglY < (y_ + b_) && openglY >y_)
	{
		return true;

	}
	return false;
}
void cPrzycisk::set_stan_klikniety() {
	przycisk_klikniety_ = true;
}
bool cPrzycisk::get_stan_klikniety() {
	return przycisk_klikniety_;
}
int cPrzycisk::get_typ() {
	return typ_;
}