#ifndef CSIATKA_H_INCLUDED
#define CSIATKA_H_INCLUDED
#endif
#include <vector>
#include "cProstokat.h"
#include "cKwadrat.h"
#include "cStrzal.h"
#include "cPrzycisk.h"
#include <cstdlib>
#include <ctime>
#include <string>
class cSiatka {
	std::vector<cProstokat> flota_ustawiona;
	std::vector<cProstokat> flota;
	std::vector<cProstokat> flota_przeciwnika;
	std::vector<cProstokat> flota_przeciwnika_ustawiona_losowo;
	std::vector<cPrzycisk> przyciski;
	std::vector<cStrzal> pociski_gracza;
	std::vector<cStrzal> pociski_przeciwnika;
	std::vector<cKwarat> kwadrat_flota_gracza;
	std::vector<cKwarat> kwadrat_flota_przeciwnika;

	int x1_, y1_, x2_, y2_, id_siatki_;
	int ostanio_uzyte_id_, aktualnie_przesuwany_statek_;
	bool czy_mozna_wyswietlic_menu_strzalow_, czy_wyswietlac_juz_statki_gracza_,czy_mozna_obrocic_statek_, czy_statki_gracza_sa_ustawione_,siatka_gracza_,czy_ustawiono_liczbe_zyc_;

	bool czy_ustawiono_statki_gracza_losowo_ = false;
	bool czy_ustawiono_statki_gracza_recznie_ = false;

	bool wykonano_strzal = false;

	int liczbazycgracza = 20, liczbazycprzeciwnika = 20;
public:
	friend class cScena;
	cSiatka(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, int id_siatki = 0, int ostatnio_uzyte_id = 0, bool czymoznawyswietlicmenustrzal = false, bool czy_wyswielic_juz_statki_gracza=false,double czy_mozna_obrcic_statek = false,bool czy_statki_gracza_sa_ustawione = false,bool siatka_gracza = false, bool czy_ustawiono_liczbe_zyc = false);
	void zainicjuj_siatke(int x1, int y1, int x2, int y2, int id_siatki, bool siatka_gracza);
	void rysuj_siatke(bool czy_juz_wyswietlac_kwadraty);
	void kwadracik(int x, int y);
	//setters&getters
	void set_czy_mozna_wyswietlic_menu_strzalow(bool wartosc);
	bool get_czy_mozna_wyswietlic_menu_strzalow();
	void set_czy_wyswietlac_juz_statki_gracza(bool wartosc);
	bool get_czy_wyswietlac_juz_statki_gracza();
	void set_ostanio_uzyte_id_statku(int wartosc);
	int get_ostanio_uzyte_id_statku();
	void set_aktualnie_przesuwany_statek(int wartosc);
	int get_aktualnie_przesuwany_statek();
	void set_mozna_obrocic_statek(int wartosc);
	bool get_mozna_obrocic_statek();
	bool get_czy_wykonano_strzal();
	void set_czy_wykonano_strzal(bool wartosc);

	void uzupelnij_vektor_pol();
	void zainicjuj_vektory_pol();
	void dane_vektora_pol(std::vector<cKwarat> vektor);
	void stan_arsenalu();

	void ustaw_statki_gracza_losowo();
	void ustaw_statki_przeciwnika_losowo();
	void sprawdz_i_wstaw(cProstokat element, int licznik, int& liczba_obroconych_elementow, int max_liczba_obronych_elementow);
	void sprawdz_i_wstaw_gracz(cProstokat element, int licznik, int& liczba_obroconych_elementow, int max_liczba_obronych_elementow);

	void wyczysc_dane_ustawionej_floty();
	void przekopiuj_ustawione_recznie_statki_do_ostatecznego_vektora();
	void sprawdz_czy_nie_ustawiono_statkow_recznie_w_razie_co_wyczysc();


	void metoda_mouse_right_button_down(double openglX, double openglY, bool& czy_juz_wyswietlac_kwadraty);
	void metoda_mouse_right_button_up(double openglX, double openglY);
	void metoda_mouse_move(double openglX, double openglY);
	void sprawdz_czy_nie_ma_bledu();

	void liczba_zyc(int& liczba_zyc_gracza, int& liczba_zyc_przeciwnika);

	void wykonaj_strzal();

	

};