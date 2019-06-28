#include "cStrzal.h"

cStrzal::cStrzal(double x, double y, double typstrzalu, double iloscuzyc, bool czywieloraz, double red, double green, double blue, double a, double b): x_(x), y_(y), typ_strzalu_(typstrzalu), ilosc_uzyc_(iloscuzyc), czy_mozna_uzwac_bezkonca_(czywieloraz),red_(red),green_(green),blue_(blue),a_(a),b_(b){
	if (typ_strzalu_ == 1.0)
	{
		a_ = 4.0;
		b_ = 1.0;
	}
	if (typ_strzalu_ == 2.0)
	{
		a_ = 2.0;
		b_ = 2.0;
	}
	if (typ_strzalu_ == 3.0)
	{
		a_ = 7.0;
		b_ = 1.0;
	}
	if (typ_strzalu_ == 4.0)
	{
		a_ = 1.0;
		b_ = 1.0;
	}
}
void cStrzal::rysuj() {
	glColor3d(red_, green_, blue_);
	if (get_ilosc_uzyc_pozostala() == 0)
	{
		glColor3d(0.7, 0.7, 0.7);
	}
	if (get_ilosc_uzyc_pozostala() > 0)
	{
		glColor3d(red_, green_, blue_);
	}
	glRectd(x_, y_, x_ + a_, y_ + b_);
}
double cStrzal::get_ilosc_uzyc_pozostala() {
	return ilosc_uzyc_;
}
int cStrzal::get_typ() {
	return typ_strzalu_;
}
bool cStrzal::isUnclicked(double openglX, double openglY) {
	if (openglX <(x_ + a_) && openglX >x_ && openglY < (y_ + b_) && openglY >y_) {
		return true;

	}
	return false;
}
bool cStrzal::isClicked(double openglX, double openglY) {
	if (openglX <(x_ + a_) && openglX >x_ && openglY < (y_ + b_) && openglY >y_)
	{
		return true;

	}
	return false;
}
void cStrzal::dopasuj_element_na_planszy() {
	if (x_ >= 19)
	{
		double tmp1, tmp2;
		tmp1 = round(x_);
		tmp2 = round(y_);
		x_ = tmp1;
		y_ = tmp2;
	}
}
void cStrzal::podazaj_za_myszka(double x, double y) {
	x_ = x - a_ / 2.0;
	y_ = y - b_ / 2.0;
}
double cStrzal::get_x() {
	return x_;
}
double cStrzal::get_y() {
	return y_;
}
double cStrzal::get_a() {
	return a_;
}
double cStrzal::get_b() {
	return b_;
}
void cStrzal::set_x_y(double x, double y) {
	x_ = x;
	y_ = y;
}
void cStrzal::zmniejsz_ilosc__uzyc_o_1() {
	ilosc_uzyc_--;
}