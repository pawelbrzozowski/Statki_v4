#include <GL/glut.h>
#include <GL/freeglut.h>
#include "cKwadrat.h"

cKwarat::cKwarat(int x1, int y1, bool czy_zajety, int id, int typ_startku, bool czy_trafiony, double red, double green , double blue ) : x_(x1), y_(y1), czy_kwarat_jest_zajety_(czy_zajety), id_(id), typ_statku_(typ_startku),czy_trafiony_(czy_trafiony),red_(red),green_(green),blue_(blue){

}
void cKwarat::set_czy_kwarat_jest_zajety(bool wartosc) {
	czy_kwarat_jest_zajety_ = wartosc;
}
bool cKwarat::get_czy_kwarat_jest_zajety() {
	return czy_kwarat_jest_zajety_;
}
void cKwarat::zainicjuj_kwadrat(int x, int y, int id) {
	x_ = x;
	y_ = y;
	id_ = id;
}
int cKwarat::get_x() {
	return x_;
}
int cKwarat::get_y() {
	return y_;
}
int cKwarat::get_id() {
	return id_;
}
void cKwarat::set_typ_statku(int wartosc) {
	typ_statku_ = wartosc;
}
int cKwarat::get_typ_statku() {
	return typ_statku_;
}
void cKwarat::set_czy_traiony(bool wartosc) {
	czy_trafiony_ = wartosc;
}
bool cKwarat::get_czy_trafiony() {
	return czy_trafiony_;
}
void cKwarat::rysuj() {
	if (czy_kwarat_jest_zajety_ == true)
	{
		glColor3d(red_, green_, blue_);
		glRectd(x_, y_, x_ + 1.0, y_ + 1.0);
	}
	else
	{
	glColor3d(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);//od tego miejsca zaczynamy rysowac
	glVertex2f(x_, y_);
	glVertex2f(x_ + 1, y_);
	glVertex2f(x_ + 1, y_ + 1);
	glVertex2f(x_, y_ + 1);
	glEnd();//tutaj konczy sie rysowanie
	}
}
void cKwarat::set_kolor(double red, double green, double blue) {
	red_ = red;
	green_ = green;
	blue_ = blue;
}