//
// Created by piotr on 27.03.19.
//

#ifndef FREEGLUT_CSCENA_H
#define FREEGLUT_CSCENA_H
#include "cProstokat.h"
#include "cStrzal.h"
#include "cPrzycisk.h"
#include "cKwadrat.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>


//bindingi dla callbacków
void resize_binding(int width, int height);
void idle_binding();
void display_binding();
//void timer_binding(int a);
void keyboard_bingidng(int key, int, int);
void mouse_binding(int button, int state, int x, int y);
void mouse_move_binding(int x, int y);

class cScena {
	std::vector<cPrzycisk> przyciski;
	bool czy_juz_wyswietlac_kwadraty = false;
	int liczba_zyc_gracza = 20;
	int liczba_zyc_przeciwnika = 20;
public:
	cScena();
	void idle();

	void resize(int width, int height);
	void display();
	void key(int key);
	void init(int argc, char* argv[], const char* window_name);
	void set_callbacks();
	void mouse_move(int x, int  y);
	void mouse(int button, int state, int x, int y);
};


#endif //FREEGLUT_CSCENA_H
