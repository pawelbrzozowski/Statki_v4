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
	std::vector<cProstokat> flota_ustawiona;
	std::vector<cProstokat> flota;
	std::vector<cProstokat> flota_przeciwnika;
	std::vector<cProstokat> flota_przeciwnika_ustawiona_losowo;
	std::vector<cPrzycisk> przyciski;
	std::vector<cStrzal> pociski;

	int ostanio_uzyte_id_;
	int aktualnie_przersuwany_statek_;
	bool mozna_obrocic_, czy_wyswietlac_menu_strzalow_;

public:
	cScena(int ostuzid = 0, bool mozna_obr = false, int aktualnieprzesuwstatek = 0, bool czywyswtlmenu = false);
	void idle();
	void ustaw_statki_przeciwnika_losowo();
	void ustaw_statki_gracza_losowo();
	void resize(int width, int height);
	void display();
	void key(int key);
	void init(int argc, char* argv[], const char* window_name);
	void set_callbacks();
	void mouse_move(int x, int  y);
	void mouse(int button, int state, int x, int y);

	void sprawdz_i_wstaw(cProstokat element, int licznik, int& liczba_obroconych_elementow, int max_liczba_obronych_elementow);
	void sprawdz_i_wstaw_gracz(cProstokat element, int licznik, int zakres_los_x, int zakres_los_y, int zakres_los_x_max, int zakres_los_y_max, int gracz_czy_przeciwnik);
	void set_ostanio_uzyte_id_statku(int wartosc);
	int get_ostanio_uzyte_id_statku();
	void set_mozna_obrocic_statek(int wartosc);
	bool get_mozna_obrocic_statek();
	void set_aktualnie_przesuwany_statek(int wartosc);
	int get_aktualnie_przesuwany_statek();

	void set_czy_mozna_wyswietlic_menu_strzalow(int wartosc);
	bool get_czy_mozna_wyswietlic_menu_strzalow();

	void stan_arsenalu();
};


#endif //FREEGLUT_CSCENA_H
