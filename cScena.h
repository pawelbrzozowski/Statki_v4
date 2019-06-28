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
	/*std::vector<cProstokat> scena_flota_ustawiona;
	std::vector<cProstokat> scena_flota;
	std::vector<cProstokat> scena_flota_przeciwnika;
	std::vector<cProstokat> scena_flota_przeciwnika_ustawiona_losowo;
	std::vector<cPrzycisk> scena_przyciski;
	std::vector<cStrzal> scena_pociski_gracza;
	std::vector<cStrzal> scena_pociski_przeciwnika;
	std::vector<cKwarat> scena_kwadrat_flota_gracza;
	std::vector<cKwarat> scena_kwadrat_flota_przeciwnika;*/

	int ostanio_uzyte_id_, liczba_losowych_rozstawien=0;
	int aktualnie_przersuwany_statek_;
	bool mozna_obrocic_, czy_wyswietlac_menu_strzalow_,czy_statki_gracza_sa_ustawione_,czy_wyswietlac_juz_statki_gracza_;

	bool czy_ustawiono_statki_gracza_losowo_ = false;
	bool czy_ustawiono_statki_gracza_recznie_ = false;

public:
	cScena(int ostuzid = 0, bool mozna_obr = false, int aktualnieprzesuwstatek = 0, bool czywyswtlmenu = false, bool czy_statki_gracza_losowo=false, bool czy_wyswietlac_juz_statki_gracza=false);
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
