#include <GL/glut.h>
#include <GL/freeglut.h>
#include "cSiatka.h"

cSiatka::cSiatka(int x1 , int y1 , int x2 , int y2, int id_siatki) : x1_(x1), y1_(y1), x2_(x2),y2_(y2), id_siatki_(id_siatki) {

}
void cSiatka::zainicjuj_siatke(int x1, int y1, int x2, int y2,int id_siatki){
	x1_ = x1;
	y1_ = y1;
	x2_ = x2;
	y2_ = y2;
	id_siatki_=id_siatki;
}
void  cSiatka::rysuj_siatke() { 
	for (int i = x1_; i < x2_; i++)
	{
		for (int j = y1_ ; j < y2_; j++)
		{
			glColor3d(1.0, 1.0, 1.0);
			kwadracik(i, j);
		}
	}
}
void cSiatka::kwadracik(int x, int y)//specyfikacja meijsca gdzie bd narysoway prostokacik
{
	glPushMatrix();
	glBegin(GL_LINE_LOOP);//od tego miejsca zaczynamy rysowac
		glVertex2f(x, y);
		glVertex2f(x+1, y);
		glVertex2f(x+1, y+1);
		glVertex2f(x, y+1);
	glEnd();//tutaj konczy sie rysowanie
	glPopMatrix();
}