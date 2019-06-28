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
	glRectd(x_, y_, x_ + a_, y_ + b_);
}
double cStrzal::get_ilosc_uzyc_pozostala() {
	return ilosc_uzyc_;
}
int cStrzal::get_typ() {
	return typ_strzalu_;
}