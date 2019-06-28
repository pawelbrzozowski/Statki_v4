//
// Created by piotr on 27.03.19.
//

#ifndef FREEGLUT_CSCENA_H
#define FREEGLUT_CSCENA_H
#include "cProstokat.h"
#include "cStrzal.h"
#include "cPrzycisk.h"
#include <vector>
#include <cstdlib>
#include <ctime>

//bindingi dla callbacków
void resize_binding(int width, int height);
void idle_binding();
void display_binding();
//void timer_binding(int a);
void keyboard_bingidng(int key, int, int);
void mouse_binding(int button, int state, int x, int y);
void mouse_move_binding(int x, int y);

class cScena {
    std::vector<cProstokat> flota;
	std::vector<cProstokat> flota_przeciwnika;
	std::vector<cPrzycisk> przyciski;
	int ostanio_uzyte_id_;
	int aktualnie_przersuwany_statek_;
	bool mozna_obrocic_;

public:
    cScena(int ostuzid=0, bool mozna_obr= false, int aktualnieprzesuwstatek = 0);
	void idle();
	void ustaw_statki_przeciwnika_losowo();
    void resize(int width, int height);
    void display();
	void key(int key);
    void init(int argc, char *argv[], const char* window_name);
    void set_callbacks();
	void mouse_move(int x, int  y);
	void mouse(int button, int state, int x, int y);
	void set_ostanio_uzyte_id_statku(int wartosc);
	int get_ostanio_uzyte_id_statku();
	void set_mozna_obrocic_statek(int wartosc);
	bool get_mozna_obrocic_statek();
	void set_aktualnie_przesuwany_statek(int wartosc);
	int get_aktualnie_przesuwany_statek();
};


#endif //FREEGLUT_CSCENA_H
