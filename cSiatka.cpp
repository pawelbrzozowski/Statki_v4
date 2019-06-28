#include <GL/glut.h>
#include <GL/freeglut.h>
#include "cSiatka.h"

cSiatka::cSiatka(int x1 , int y1 , int x2 , int y2, int id_siatki, int ostatnio_uzyte_id, bool czymoznawyswietlicmenustrzal, bool czy_wyswielic_juz_statki_gracza, double czy_mozna_obrcic_statek, bool czy_statki_gracza_sa_ustawione, bool siatka_gracza) : x1_(x1), y1_(y1), x2_(x2),y2_(y2), id_siatki_(id_siatki),ostanio_uzyte_id_(ostatnio_uzyte_id), czy_mozna_wyswietlic_menu_strzalow_(czymoznawyswietlicmenustrzal), czy_wyswietlac_juz_statki_gracza_(czy_wyswielic_juz_statki_gracza), czy_mozna_obrocic_statek_(czy_mozna_obrcic_statek), czy_statki_gracza_sa_ustawione_(czy_statki_gracza_sa_ustawione), siatka_gracza_(siatka_gracza) {
	cProstokat cztermasztowiec(15, 9, 4, 1, 4, 1, 1);
	flota.push_back(cztermasztowiec);

	cProstokat trojmasztowiec_1(12, 7, 3, 2, 3, 1, 2);
	flota.push_back(trojmasztowiec_1);

	cProstokat trojmasztowiec_2(16, 7, 3, 3, 3, 1, 3);
	flota.push_back(trojmasztowiec_2);

	cProstokat dwumasztowiec_1(11, 5, 2, 4, 2, 1, 4);
	flota.push_back(dwumasztowiec_1);

	cProstokat dwumasztowiec_2(14, 5, 2, 5, 2, 1, 5);
	flota.push_back(dwumasztowiec_2);

	cProstokat dwumasztowiec_3(17, 5, 2, 6, 2, 1, 6);
	flota.push_back(dwumasztowiec_3);

	cProstokat jednomasztowiec_1(12, 3, 1, 7, 1, 1, 7);
	flota.push_back(jednomasztowiec_1);

	cProstokat jednomasztowiec_2(14, 3, 1, 8, 1, 1, 8);
	flota.push_back(jednomasztowiec_2);

	cProstokat jednomasztowiec_3(16, 3, 1, 9, 1, 1, 9);
	flota.push_back(jednomasztowiec_3);

	cProstokat jednomasztowiec_4(18, 3, 1, 10, 1, 1, 10);
	flota.push_back(jednomasztowiec_4);

	////// GENEROWANIE FLOTY PRZECIWNIKA ////////

	cProstokat cztermasztowiec_przeciwnika(250, 9, 4, 1, 4, 1, 1);
	flota_przeciwnika.push_back(cztermasztowiec_przeciwnika);

	cProstokat trojmasztowiec_1_przeciwnika(210, 7, 3, 2, 3, 1, 2);
	flota_przeciwnika.push_back(trojmasztowiec_1_przeciwnika);

	cProstokat trojmasztowiec_2_przeciwnika(260, 7, 3, 3, 3, 1, 3);
	flota_przeciwnika.push_back(trojmasztowiec_2_przeciwnika);

	cProstokat dwumasztowiec_1_przeciwnika(210, 5, 2, 4, 2, 1, 4);
	flota_przeciwnika.push_back(dwumasztowiec_1_przeciwnika);

	cProstokat dwumasztowiec_2_przeciwnika(240, 5, 2, 5, 2, 1, 5);
	flota_przeciwnika.push_back(dwumasztowiec_2_przeciwnika);

	cProstokat dwumasztowiec_3_przeciwnika(270, 5, 2, 6, 2, 1, 6);
	flota_przeciwnika.push_back(dwumasztowiec_3_przeciwnika);

	cProstokat jednomasztowiec_1_przeciwnika(220, 3, 1, 7, 1, 1, 7);
	flota_przeciwnika.push_back(jednomasztowiec_1_przeciwnika);

	cProstokat jednomasztowiec_2_przeciwnika(240, 3, 1, 8, 1, 1, 8);
	flota_przeciwnika.push_back(jednomasztowiec_2_przeciwnika);

	cProstokat jednomasztowiec_3_przeciwnika(260, 3, 1, 9, 1, 1, 9);
	flota_przeciwnika.push_back(jednomasztowiec_3_przeciwnika);

	cProstokat jednomasztowiec_4_przeciwnika(280, 3, 1, 10, 1, 1, 10);
	flota_przeciwnika.push_back(jednomasztowiec_4_przeciwnika);

	ustaw_statki_przeciwnika_losowo();

	//DODAJEMY PRZYCYSKI
	cPrzycisk przyczik_obroc(10.5, 0.5, 1, 1, 1, 0.7, 0.7, 0);
	przyciski.push_back(przyczik_obroc);

	cPrzycisk przycisk_losowo(14, 0.5, 2, 2, 1, 0.7, 0.7, 0);
	przyciski.push_back(przycisk_losowo);

	cPrzycisk przycisk_dalej(16.5, 0.5, 3, 2, 1, 0.7, 0.7, 0);
	przyciski.push_back(przycisk_dalej);

	//DODAJEMY STRZALY
	cStrzal nalot_samolotu(11, 8.5, 1, 2, false);
	pociski_gracza.push_back(nalot_samolotu);

	cStrzal bombardowanie(11, 6, 2, 1, false);
	pociski_gracza.push_back(bombardowanie);

	cStrzal torpeda(11, 4.5, 3, 2, false);
	pociski_gracza.push_back(torpeda);

	cStrzal zwykly_strzal(11, 3, 4, 1000, true);
	pociski_gracza.push_back(zwykly_strzal);

	cStrzal nalot_samolotu_przeciwnik(11000, 8.5, 1, 2, false);
	pociski_przeciwnika.push_back(nalot_samolotu);

	cStrzal bombardowanie_przeciwnik(10001, 6, 2, 1, false);
	pociski_przeciwnika.push_back(bombardowanie);

	cStrzal torpeda_przeciwnik(10001, 4.5, 3, 2, false);
	pociski_przeciwnika.push_back(torpeda);

	cStrzal zwykly_strzal_przeciwnik(10001, 3, 4, 1000, true);
	pociski_przeciwnika.push_back(zwykly_strzal);

	zainicjuj_vektory_pol();
}
void cSiatka::zainicjuj_siatke(int x1, int y1, int x2, int y2,int id_siatki, bool siatka_gracza){
	x1_ = x1;
	y1_ = y1;
	x2_ = x2;
	y2_ = y2;
	id_siatki_=id_siatki;
	siatka_gracza_ = siatka_gracza;
}
void  cSiatka::rysuj_siatke() {
	int licznik = 1;

	if (siatka_gracza_ == true)
	{
		if(get_czy_mozna_wyswietlic_menu_strzalow() == false) // rysujemy g�owna siatke tylko do momentu ysownia vektora kwadrat, pozniej on spe�nia tez funkcje rysownia siatki wiec tutaj nie trzeba jej rysowac
			for (int i = x1_; i < x2_; i++) //rysowanie glownej siatki 
			{
				for (int j = y1_; j < y2_; j++)
				{
					glColor3d(1.0, 1.0, 1.0);
					kwadracik(i, j);
				}
			}
		for (auto& el : flota) // rysowanie floty przed ustawieniem oraz przeskanowaniem do ostatecznego vektora
			el.rysuj();
		for (auto& el : przyciski) //rysuje przyciski obroc,dalej,losuj
			el.rysuj();

		if (get_czy_mozna_wyswietlic_menu_strzalow() == true) // gdy_wyswietlamy_menu_strzalow to rysujemy to:
		{
			for (auto& el : pociski_gracza)
				el.rysuj();
			for (auto& el : kwadrat_flota_gracza)
			{
				el.rysuj();
			}
			
				
		}
		if (get_czy_mozna_wyswietlic_menu_strzalow() == false)
		{
			if (czy_wyswietlac_juz_statki_gracza_ == true) //sprawdzamy czy wyeitlicz ostateczny wektor statkow zanim przekopiujemy je do vektora kwadratow
			{
				for (auto& el : flota_ustawiona)
					el.rysuj();
			}
		}
	}
	if(siatka_gracza_ == false)
	{
		if (get_czy_mozna_wyswietlic_menu_strzalow() == false) // rysujemy g�owna siatke tylko do momentu ysownia vektora kwadrat, pozniej on spe�nia tez funkcje rysownia siatki wiec tutaj nie trzeba jej rysowac
		{
			for (int i = x1_; i < x2_; i++) //rysowanie glownej siatki 
			{
				for (int j = y1_; j < y2_; j++)
				{
					glColor3d(1.0, 1.0, 1.0);
					kwadracik(i, j);
				}
			}
		}
		if (get_czy_mozna_wyswietlic_menu_strzalow() == true)
		{
			for (auto& el : kwadrat_flota_przeciwnika)
				el.rysuj();
		}
		if (get_czy_mozna_wyswietlic_menu_strzalow() == false)
		{
			for (auto& el : flota_przeciwnika_ustawiona_losowo)
				el.rysuj();
		}
	}



	/*for (int i = x1_; i < x2_; i++) //rysowanie glownej siatki 
	{
		for (int j = y1_ ; j < y2_; j++)
		{
			glColor3d(1.0, 1.0, 1.0);
			kwadracik(i, j);
		}
	}

	for (auto& el : flota)
		el.rysuj();
	for (auto& el : przyciski)
		el.rysuj();
	if (get_czy_mozna_wyswietlic_menu_strzalow() == true)
	{
		for (auto& el : pociski_gracza)
			el.rysuj();
		for (auto& el : kwadrat_flota_gracza)
			el.rysuj();
		for (auto& el : kwadrat_flota_przeciwnika)
			el.rysuj();
	}
	if (get_czy_mozna_wyswietlic_menu_strzalow() == false)
	{
		if (czy_wyswietlac_juz_statki_gracza_ == true)
		{
			for (auto& el : flota_ustawiona)
				el.rysuj();
		}
		for (auto& el : flota_przeciwnika_ustawiona_losowo)
			el.rysuj();
	}*/
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
void cSiatka::set_czy_mozna_wyswietlic_menu_strzalow(bool wartosc) {
	czy_mozna_wyswietlic_menu_strzalow_ = wartosc;
}
bool cSiatka::get_czy_mozna_wyswietlic_menu_strzalow() {
	return czy_mozna_wyswietlic_menu_strzalow_;
}
void cSiatka::set_czy_wyswietlac_juz_statki_gracza(bool wartosc) {
	czy_wyswietlac_juz_statki_gracza_ = wartosc;
}
bool cSiatka::get_czy_wyswietlac_juz_statki_gracza() {
	return czy_wyswietlac_juz_statki_gracza_;
}
void cSiatka::set_ostanio_uzyte_id_statku(int wartosc) {
	ostanio_uzyte_id_ = wartosc;
	std::cout << "ostanio klinketo na statek z id [" << get_ostanio_uzyte_id_statku() << "]" << std::endl;
}
int cSiatka::get_ostanio_uzyte_id_statku() {
	return ostanio_uzyte_id_;
}
void cSiatka::set_aktualnie_przesuwany_statek(int wartosc) {
	aktualnie_przesuwany_statek_ = wartosc;
}
int cSiatka::get_aktualnie_przesuwany_statek() {
	return aktualnie_przesuwany_statek_;
}
void cSiatka::set_mozna_obrocic_statek(int wartosc) {
	czy_mozna_obrocic_statek_ = wartosc;
}
bool cSiatka::get_mozna_obrocic_statek() {
	return czy_mozna_obrocic_statek_;
}
void cSiatka::metoda_mouse_right_button_down(double openglX, double openglY) {
	if (czy_mozna_wyswietlic_menu_strzalow_ == false)
	{
		for (auto& el : flota)
		{
			if (el.isClicked(openglX, openglY))
			{
				el.dane();
				set_ostanio_uzyte_id_statku(el.get_id()); //ustawiamy parametr sceny ostanie_uzyte_id na wartosc id statku ktory klinlelismy
				set_aktualnie_przesuwany_statek(el.get_id()); //ustawiamy parametr sceny aktualnie_przesuwany_statek na ide statku wlasnie kliknietego
				if ((get_ostanio_uzyte_id_statku() > 0) && (get_mozna_obrocic_statek()))
				{
					el.obroc();
					set_ostanio_uzyte_id_statku(0);
					set_mozna_obrocic_statek(false);
					for (auto& el : przyciski)
					{
						if (el.get_typ() == 1)
						{
							el.dane();
						}
					}
				}
			}
		}
		for (auto& el : flota_ustawiona)
		{
			if (el.isClicked(openglX, openglY))
			{
				el.dane();
				set_ostanio_uzyte_id_statku(el.get_id()); //ustawiamy parametr sceny ostanie_uzyte_id na wartosc id statku ktory klinlelismy
				set_aktualnie_przesuwany_statek(el.get_id()); //ustawiamy parametr sceny aktualnie_przesuwany_statek na ide statku wlasnie kliknietego
				if ((get_ostanio_uzyte_id_statku() > 0) && (get_mozna_obrocic_statek()))
				{
					el.obroc();
					set_ostanio_uzyte_id_statku(0);
					set_mozna_obrocic_statek(false);
					for (auto& el : przyciski)
					{
						if (el.get_typ() == 1)
						{
							el.dane();
						}
					}
				}
			}

		}
	}
	for (auto& el : przyciski)
	{
		if (el.isClicked(openglX, openglY))
		{
			if (el.get_typ() == 3) // sprawdzanie czy klinketo na przycisk dalej, gdy tak ustwaimy jego stan na true
			{
				przekopiuj_ustawione_recznie_statki_do_ostatecznego_vektora();
				std::cout << "KLIKNIETO DALEJ " << std::endl;
				uzupelnij_vektor_pol(); //modyfikuje wartosci zajete dla poszczegolnych kwadratow
				set_czy_mozna_wyswietlic_menu_strzalow(true);
				stan_arsenalu();
			}
			if (el.get_typ() == 2) // sprawdzanie czy klinketo na przycisk dalej, gdy tak ustwaimy jego stan na true
			{
				czy_ustawiono_statki_gracza_losowo_ == true;
				sprawdz_czy_nie_ustawiono_statkow_recznie_w_razie_co_wyczysc();

				if (czy_statki_gracza_sa_ustawione_ == true)
				{
					wyczysc_dane_ustawionej_floty();
					ustaw_statki_gracza_losowo();
				}
				if (czy_statki_gracza_sa_ustawione_ == false)
				{
					ustaw_statki_gracza_losowo();
					czy_wyswietlac_juz_statki_gracza_ = true;
					czy_statki_gracza_sa_ustawione_ = true;
				}

			}
			if (el.get_typ() == 1)
			{
				set_mozna_obrocic_statek(true); //ustwaimy parametr sceny mozna_orocic na true
			}
			el.dane();
		}
	}


}
void cSiatka::metoda_mouse_right_button_up(double openglX, double openglY){
	for (auto& el : flota)
	{
		el.isUnclicked(openglX, openglY);
		el.dopasuj_element_na_planszy();
	}
	for (auto& el : flota_ustawiona)
	{
		el.isUnclicked(openglX, openglY);
		el.dopasuj_element_na_planszy();
	}
}
void cSiatka::przekopiuj_ustawione_recznie_statki_do_ostatecznego_vektora()
{
	if (czy_ustawiono_statki_gracza_losowo_ == false)
	{
		czy_ustawiono_statki_gracza_recznie_ == true;
		for (auto& el : flota)
		{
			flota_ustawiona.push_back(el);
		}
	}
	czy_ustawiono_statki_gracza_recznie_ == true;
}
void cSiatka::uzupelnij_vektor_pol() {
	int ilosc_ustawionych_pol_gracz = 0, ilosc_ustawionych_pol_przeciwnik = 0;
	for (auto& el : flota_przeciwnika_ustawiona_losowo)
	{
		int x_poczatek, x_koniec, y_poczatek, y_koniec;
		x_poczatek = el.get_x();
		x_koniec = el.get_x() + el.get_a();
		y_poczatek = el.get_y();
		y_koniec = el.get_b() + el.get_y();
		for (int i = x_poczatek; i < x_koniec; i++)
		{
			for (int j = y_poczatek; j < y_koniec; j++)
			{
				for (auto& el2 : kwadrat_flota_przeciwnika)
				{
					if ((el2.get_x() == i) && (el2.get_y() == j))
					{
						el2.set_czy_kwarat_jest_zajety(true);
						el2.set_typ_statku(el.get_typ());
						ilosc_ustawionych_pol_przeciwnik++;
					}
				}
			}
		}
	}
	for (auto& el : flota_ustawiona)
	{
		int x_poczatek, x_koniec, y_poczatek, y_koniec;
		x_poczatek = el.get_x();
		x_koniec = el.get_x() + el.get_a();
		y_poczatek = el.get_y();
		y_koniec = el.get_b() + el.get_y();
		for (int i = x_poczatek; i < x_koniec; i++)
		{
			for (int j = y_poczatek; j < y_koniec; j++)
			{
				for (auto& el2 : kwadrat_flota_gracza)
				{
					if ((el2.get_x() == i) && (el2.get_y() == j))
					{
						el2.set_czy_kwarat_jest_zajety(true);
						el2.set_typ_statku(el.get_typ());
						ilosc_ustawionych_pol_gracz++;
					}
				}
			}
		}
	}
	std::cout << "Ustawiono status zajety dla: " << ilosc_ustawionych_pol_gracz << " pol na planszy gracza oraz dla: " << ilosc_ustawionych_pol_przeciwnik << " pol na plasnszy przeciwnika" << std::endl << std::endl;
	std::cout << "INFORMACJE dla kwadratow z floty GRACZA:" << std::endl;
	dane_vektora_pol(kwadrat_flota_gracza);
	std::cout << "INFORMACJE dla kwadratow z floty PRZECIWNIKA:" << std::endl;
	dane_vektora_pol(kwadrat_flota_przeciwnika);
}
void cSiatka::dane_vektora_pol(std::vector<cKwarat> vektor) {
	for (auto& el : vektor)
	{
		//if(el.get_czy_kwarat_jest_zajety()==true)
		if (el.get_id() <= 9)
		{
			if (el.get_czy_kwarat_jest_zajety() == true)
			{
				std::cout << "Pole nr: 0" << el.get_id() << " ma wspolrzedne: (" << el.get_x() << "," << el.get_y() << "), jego stan to ZAJETY [" << el.get_czy_kwarat_jest_zajety() << "]" << " przez " << el.get_typ_statku() << "masztowiec" << std::endl;
			}
			else
			{
				//std::cout << "Pole nr: 0" << el.get_id() << " ma wspolrzedne: (" << el.get_x() << "," << el.get_y() << "), jego stan to wolny  [" << el.get_czy_kwarat_jest_zajety() << "]" << std::endl;
			}
		}
		else
		{
			if (el.get_czy_kwarat_jest_zajety() == true)
			{
				std::cout << "Pole nr: " << el.get_id() << " ma wspolrzedne: (" << el.get_x() << "," << el.get_y() << "), jego stan to ZAJETY [" << el.get_czy_kwarat_jest_zajety() << "]" << " przez " << el.get_typ_statku() << "masztowiec" << std::endl;
			}
			else
			{
				//std::cout << "Pole nr: " << el.get_id() << " ma wspolrzedne: (" << el.get_x() << "," << el.get_y() << "), jego stan to  wolny [" << el.get_czy_kwarat_jest_zajety() << "]" << std::endl;
			}
		}

	}
}
void cSiatka::zainicjuj_vektory_pol() {
	int licznik = 1, licznik_2 = 1;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cKwarat tmp;
			tmp.zainicjuj_kwadrat(i, j, licznik);
			kwadrat_flota_gracza.push_back(tmp);
			licznik++;
		}
	}
	for (int i = 19; i < 29; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cKwarat tmp;
			tmp.zainicjuj_kwadrat(i, j, licznik_2);
			kwadrat_flota_przeciwnika.push_back(tmp);
			licznik_2++;
		}
	}
	std::cout << "INICJACJA VEKTOROW POL KWADRATOW:" << std::endl;
	if ((kwadrat_flota_gracza.size() == 100) && (kwadrat_flota_przeciwnika.size() == 100))
	{
		std::cout << "SUKCES -> stworzono " << kwadrat_flota_gracza.size() << " pol dla siatki gracza oraz " << kwadrat_flota_przeciwnika.size() << " pol dla siatki przeciwnika" << std::endl << std::endl;
	}
	else
	{
		std::cout << "COS POSZLO NIE TAK -> stworzono " << kwadrat_flota_gracza.size() << " pol dla siatki gracza oraz " << kwadrat_flota_przeciwnika.size() << " pol dla siatki przeciwnika" << std::endl << std::endl;
	}
}
void cSiatka::stan_arsenalu() {
	std::string a = "nalotu", b = "bombardowania", c = "torped", d = "zwyklego ostrzalu";
	int tmp;
	std::cout << "|------------------------------------------------|" << std::endl;
	std::cout << "|Pozostalo Ci:                                   |" << std::endl;
	std::cout << "|                                                |" << std::endl;
	for (auto& el : pociski_gracza)
	{
		tmp = el.get_typ();
		switch (tmp)
		{
		case 1:
		{
			std::cout << "|  [" << el.get_ilosc_uzyc_pozostala() << "] uzyc " << a << "                               |" << std::endl;
		}break;
		case 2:
		{
			std::cout << "|  [" << el.get_ilosc_uzyc_pozostala() << "] uzyc " << b << "                        |" << std::endl;
		}break;
		case 3:
		{
			std::cout << "|  [" << el.get_ilosc_uzyc_pozostala() << "] uzyc " << c << "                               |" << std::endl;
		}break;
		case 4:
		{
			std::cout << "|  [nieskonczonosc] uzyc " << d << "       |" << std::endl;
		}break;
		}
	}
	std::cout << "|                                                |" << std::endl;
	std::cout << "|------------------------------------------------|" << std::endl;
}
void cSiatka::sprawdz_czy_nie_ustawiono_statkow_recznie_w_razie_co_wyczysc() {
	if (czy_ustawiono_statki_gracza_losowo_ == false)
		for (auto& el : flota)
		{
			el.set_wartoscx_oraz_y(1000, 1000);
		}
}
void cSiatka::wyczysc_dane_ustawionej_floty() {

	flota_ustawiona.clear();
}
void cSiatka::ustaw_statki_gracza_losowo() {
	int licznik = 1, liczba_obroconych = 0;
	srand(time(NULL));
	int max_liczba_obronych_elementow = (std::rand() % 10);
	for (auto& el : flota) {
		licznik++;
		sprawdz_i_wstaw_gracz(el, licznik, liczba_obroconych, max_liczba_obronych_elementow);
	}
	if (czy_ustawiono_statki_gracza_losowo_ == true)
	{
		for (auto& el : flota)//nasze ellementy wektora rysujemy dalej, aby nie wyswietlaly sie poniewaz ustawiamy statki w innym vektorze
		{
			el.set_wartoscx_oraz_y(1000, 1000);
		}
	}
	std::cout << "DANE DLA FLOTY GRACZA:" << std::endl << std::endl;
	for (auto& el : flota_ustawiona) {
		el.dane_rozlozenia_losowego(); //dostajemy informacje gdzie statki zostal umieszonczy 
	}
}
void cSiatka::ustaw_statki_przeciwnika_losowo() {
	int licznik = 1, liczba_obroconych = 0;
	srand(time(NULL));
	int max_liczba_obronych_elementow = (std::rand() % 10);
	for (auto& el : flota_przeciwnika) {
		licznik++;
		sprawdz_i_wstaw(el, licznik, liczba_obroconych, max_liczba_obronych_elementow);
	}
	for (auto& el : flota_przeciwnika_ustawiona_losowo) {
		el.dane_rozlozenia_losowego(); //dostajemy informacje gdzie statki zostal umieszonczy 
	}
}
void cSiatka::sprawdz_i_wstaw_gracz(cProstokat element, int licznik, int& liczba_obroconych, int max_liczba_obronych_elementow)
{
	int licznik_do_ewentualnego_wywolania_jeszcze_raz = licznik;
	int liczba_obroconych_elementow = liczba_obroconych;
	double wylosowana_x = (std::rand() % 10);
	double wylosowana_y = (std::rand() % 10);
	int czy_obrocic = (std::rand() % 10);
	bool czy_byla_kolizja = false, czy_byl_problem_z_odwroceniem = false;

	if (czy_obrocic >= 5) //tutaj poprostu odwracamy element
	{
		if (liczba_obroconych_elementow < max_liczba_obronych_elementow)//losowa ilosc max obronych el.
		{
			int obszar_x, obszar_y;
			obszar_x = element.get_b() + wylosowana_x;
			obszar_y = element.get_a() + wylosowana_y;
			if ((obszar_x < 10) && (obszar_y < 10))
			{
				if (licznik == 1) //nie trzeba sprawdzac czy nastapi kolizja
				{
					element.obroc();
					element.set_juz_mnie_obracano(true);
					liczba_obroconych_elementow++;
				}
				if (licznik > 1)
				{
					for (auto& el : flota_ustawiona)
					{
						int obszar_min_x, obszar_max_x, obszar_min_y, obszar_max_y;
						obszar_min_x = el.get_x() - 1;
						obszar_max_x = el.get_x() + el.get_a() + 1;
						obszar_min_y = el.get_y() - 1;
						obszar_max_y = el.get_y() + el.get_b() + 1;
						if (((wylosowana_x >= obszar_min_x) && (wylosowana_x < obszar_max_x)) && ((wylosowana_y >= obszar_min_y) && (wylosowana_y < obszar_max_y)))
						{
							czy_byl_problem_z_odwroceniem = true;
							break;
						}
					}
					if (czy_byl_problem_z_odwroceniem == false)
					{
						element.obroc();
						element.set_juz_mnie_obracano(true);
						liczba_obroconych_elementow++;
					}
					czy_byl_problem_z_odwroceniem = false;
				}
			}
		}
	}
	if (licznik == 1)
	{
		int obszar_x, obszar_y;
		obszar_x = element.get_a() + wylosowana_x;
		obszar_y = element.get_b() + wylosowana_y;
		if ((obszar_x < 10) && (obszar_y < 10)) // ewentualne sprawdzenie czy jest blad i stsatek wsyatje z planszy
		{
			element.set_wartoscx_oraz_y(wylosowana_x, wylosowana_y);
			flota_ustawiona.push_back(element);
		}
		else
		{
			std::cout << "Statek z id=[ " << element.get_id() << " ] wystaje z planszy" << std::endl << std::endl;
			sprawdz_i_wstaw_gracz(element, licznik, liczba_obroconych, max_liczba_obronych_elementow);
		}

	}
	if (licznik > 1)
	{
		for (auto& el : flota_ustawiona)
		{
			int obszar_min_x_juz_zarezerowany, obszar_max_x_juz_zarezerowany, obszar_min_y_juz_zarezerowany, obszar_max_y_juz_zarezerowany;
			obszar_min_x_juz_zarezerowany = el.get_x() - 1;
			obszar_max_x_juz_zarezerowany = el.get_x() + el.get_a() + 1;
			obszar_min_y_juz_zarezerowany = el.get_y() - 1;
			obszar_max_y_juz_zarezerowany = el.get_y() + el.get_b() + 1;
			int lewy_dolny_x, lewy_dolny_y, prawy_dolny_x, prawy_dolny_y, lewy_gorny_x, lewy_gory_y, prawy_gorny_x, prawy_gorny_y;
			lewy_dolny_x = wylosowana_x;
			lewy_dolny_y = wylosowana_y;
			prawy_dolny_x = wylosowana_x + element.get_a();
			prawy_dolny_y = wylosowana_y;
			lewy_gorny_x = wylosowana_x;
			lewy_gory_y = wylosowana_y + element.get_b();
			prawy_gorny_x = wylosowana_x + element.get_a();
			prawy_gorny_y = wylosowana_y + element.get_b();

			if (((lewy_dolny_x > obszar_min_x_juz_zarezerowany) && (lewy_dolny_x < obszar_max_x_juz_zarezerowany)) && ((lewy_dolny_y > obszar_min_y_juz_zarezerowany) && (lewy_dolny_y < obszar_max_y_juz_zarezerowany)))
			{
				sprawdz_i_wstaw_gracz(element, licznik, liczba_obroconych, max_liczba_obronych_elementow);
				czy_byla_kolizja = true;
				break;
			}


			if (((prawy_dolny_x > obszar_min_x_juz_zarezerowany) && (prawy_dolny_x < obszar_max_x_juz_zarezerowany)) && ((prawy_dolny_y > obszar_min_y_juz_zarezerowany) && (prawy_dolny_y < obszar_max_y_juz_zarezerowany)))
			{
				sprawdz_i_wstaw_gracz(element, licznik, liczba_obroconych, max_liczba_obronych_elementow);
				czy_byla_kolizja = true;
				break;
			}

			if (((lewy_gorny_x > obszar_min_x_juz_zarezerowany) && (lewy_gorny_x < obszar_max_x_juz_zarezerowany)) && ((lewy_gory_y > obszar_min_y_juz_zarezerowany) && (lewy_gory_y < obszar_max_y_juz_zarezerowany)))
			{
				sprawdz_i_wstaw_gracz(element, licznik, liczba_obroconych, max_liczba_obronych_elementow);
				czy_byla_kolizja = true;
				break;
			}
			if (((prawy_gorny_x > obszar_min_x_juz_zarezerowany) && (prawy_gorny_x < obszar_max_x_juz_zarezerowany)) && ((prawy_gorny_y > obszar_min_y_juz_zarezerowany) && (prawy_gorny_y < obszar_max_y_juz_zarezerowany)))
			{
				sprawdz_i_wstaw_gracz(element, licznik, liczba_obroconych, max_liczba_obronych_elementow);
				czy_byla_kolizja = true;
				break;
			}


		}

		if (czy_byla_kolizja == false)
		{
			int obszar_x, obszar_y;
			obszar_x = element.get_a() + wylosowana_x;
			obszar_y = element.get_b() + wylosowana_y;
			if ((obszar_x < 10) && (obszar_y < 10)) // ewentualne sprawdzenie czy jest blad i stsatek wsyatje z planszy
			{
				element.set_wartoscx_oraz_y(wylosowana_x, wylosowana_y);
				flota_ustawiona.push_back(element);
			}
			else
			{
				std::cout << "Statek z id=[ " << element.get_id() << " ] wystaje z planszy, wartosc X to: (" << wylosowana_x << "," << obszar_x << ")" << "; wartosc Y to: (" << wylosowana_y << "," << obszar_y << ")" << std::endl << std::endl;
				std::cout << "Losuje nowe dane" << std::endl << std::endl;
				sprawdz_i_wstaw_gracz(element, licznik, liczba_obroconych, max_liczba_obronych_elementow);
			}
		}
		czy_byla_kolizja = false; //reset do wartoscii pcozatkowej w przypadku gdy wykryto kolzije(aby nie dodac do vektora dodatkowo

	}
}
void cSiatka::sprawdz_i_wstaw(cProstokat element, int licznik, int& liczba_obroconych, int max_liczba_obronych_elementow) {
	int licznik_do_ewentualnego_wywolania_jeszcze_raz = licznik;
	int liczba_obroconych_elementow = liczba_obroconych;
	double wylosowana_x = (std::rand() % 10) + 18;
	double wylosowana_y = (std::rand() % 10) + 0;
	int czy_obrocic = (std::rand() % 10);
	bool czy_byla_kolizja = false, czy_byl_problem_z_odwroceniem = false;

	if (wylosowana_x < 19)
		wylosowana_x = 19;
	if (czy_obrocic >= 5) //tutaj poprostu odwracamy element
	{
		if (liczba_obroconych_elementow < max_liczba_obronych_elementow)//losowa ilosc max obronych el.
		{
			int obszar_x, obszar_y;
			obszar_x = element.get_b() + wylosowana_x;
			obszar_y = element.get_a() + wylosowana_y;
			if ((obszar_x < 29) && (obszar_y < 10))
			{
				if (licznik == 1) //nie trzeba sprawdzac czy nastapi kolizja
				{
					element.obroc();
					element.set_juz_mnie_obracano(true);
					liczba_obroconych_elementow++;
				}
				if (licznik > 1)
				{
					for (auto& el : flota_przeciwnika_ustawiona_losowo)
					{
						int obszar_min_x, obszar_max_x, obszar_min_y, obszar_max_y;
						obszar_min_x = el.get_x() - 1;
						obszar_max_x = el.get_x() + el.get_a() + 1;
						obszar_min_y = el.get_y() - 1;
						obszar_max_y = el.get_y() + el.get_b() + 1;
						if (((wylosowana_x >= obszar_min_x) && (wylosowana_x < obszar_max_x)) && ((wylosowana_y >= obszar_min_y) && (wylosowana_y < obszar_max_y)))
						{
							czy_byl_problem_z_odwroceniem = true;
							break;
						}
					}
					if (czy_byl_problem_z_odwroceniem == false)
					{
						element.obroc();
						element.set_juz_mnie_obracano(true);
						liczba_obroconych_elementow++;
					}
					czy_byl_problem_z_odwroceniem = false;
				}
			}
		}
	}
	if (licznik == 1)
	{
		int obszar_x, obszar_y;
		obszar_x = element.get_a() + wylosowana_x;
		obszar_y = element.get_b() + wylosowana_y;
		if ((obszar_x < 29) && (obszar_y < 10)) // ewentualne sprawdzenie czy jest blad i stsatek wsyatje z planszy
		{
			element.set_wartoscx_oraz_y(wylosowana_x, wylosowana_y);
			flota_przeciwnika_ustawiona_losowo.push_back(element);
		}
		else
		{
			std::cout << "Statek z id=[ " << element.get_id() << " ] wystaje z planszy" << std::endl << std::endl;
			sprawdz_i_wstaw(element, licznik, liczba_obroconych, max_liczba_obronych_elementow);
		}

	}
	if (licznik > 1)
	{
		for (auto& el : flota_przeciwnika_ustawiona_losowo)
		{
			int obszar_min_x_juz_zarezerowany, obszar_max_x_juz_zarezerowany, obszar_min_y_juz_zarezerowany, obszar_max_y_juz_zarezerowany;
			obszar_min_x_juz_zarezerowany = el.get_x() - 1;
			obszar_max_x_juz_zarezerowany = el.get_x() + el.get_a() + 1;
			obszar_min_y_juz_zarezerowany = el.get_y() - 1;
			obszar_max_y_juz_zarezerowany = el.get_y() + el.get_b() + 1;
			int lewy_dolny_x, lewy_dolny_y, prawy_dolny_x, prawy_dolny_y, lewy_gorny_x, lewy_gory_y, prawy_gorny_x, prawy_gorny_y;
			lewy_dolny_x = wylosowana_x;
			lewy_dolny_y = wylosowana_y;
			prawy_dolny_x = wylosowana_x + element.get_a();
			prawy_dolny_y = wylosowana_y;
			lewy_gorny_x = wylosowana_x;
			lewy_gory_y = wylosowana_y + element.get_b();
			prawy_gorny_x = wylosowana_x + element.get_a();
			prawy_gorny_y = wylosowana_y + element.get_b();

			if (((lewy_dolny_x > obszar_min_x_juz_zarezerowany) && (lewy_dolny_x < obszar_max_x_juz_zarezerowany)) && ((lewy_dolny_y > obszar_min_y_juz_zarezerowany) && (lewy_dolny_y < obszar_max_y_juz_zarezerowany)))
			{
				sprawdz_i_wstaw(element, licznik, liczba_obroconych, max_liczba_obronych_elementow);
				czy_byla_kolizja = true;
				break;
			}


			if (((prawy_dolny_x > obszar_min_x_juz_zarezerowany) && (prawy_dolny_x < obszar_max_x_juz_zarezerowany)) && ((prawy_dolny_y > obszar_min_y_juz_zarezerowany) && (prawy_dolny_y < obszar_max_y_juz_zarezerowany)))
			{
				sprawdz_i_wstaw(element, licznik, liczba_obroconych, max_liczba_obronych_elementow);
				czy_byla_kolizja = true;
				break;
			}

			if (((lewy_gorny_x > obszar_min_x_juz_zarezerowany) && (lewy_gorny_x < obszar_max_x_juz_zarezerowany)) && ((lewy_gory_y > obszar_min_y_juz_zarezerowany) && (lewy_gory_y < obszar_max_y_juz_zarezerowany)))
			{
				sprawdz_i_wstaw(element, licznik, liczba_obroconych, max_liczba_obronych_elementow);
				czy_byla_kolizja = true;
				break;
			}
			if (((prawy_gorny_x > obszar_min_x_juz_zarezerowany) && (prawy_gorny_x < obszar_max_x_juz_zarezerowany)) && ((prawy_gorny_y > obszar_min_y_juz_zarezerowany) && (prawy_gorny_y < obszar_max_y_juz_zarezerowany)))
			{
				sprawdz_i_wstaw(element, licznik, liczba_obroconych, max_liczba_obronych_elementow);
				czy_byla_kolizja = true;
				break;
			}
			/*if (((wylosowana_x >= obszar_min_x_juz_zarezerowany) && (wylosowana_x < obszar_max_x_juz_zarezerowany)) && ((wylosowana_y >= obszar_min_y_juz_zarezerowany) && (wylosowana_y < obszar_max_y_juz_zarezerowany)))
			{
				int obszar_x, obszar_y, obszar_x_2, obszar_y_2;
				obszar_x = el.get_x() + el.get_a();
				obszar_y = el.get_y() + el.get_b();
				obszar_x_2 = wylosowana_x + element.get_a();
				obszar_y_2 = wylosowana_y + element.get_b();
				/*std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;
				std::cout << "NASTAPILA KOLIZJA!" << std::endl << std::endl;
				std::cout << "Statek z id=[ " << element.get_id() << " ] probowano umiescic na polu zajetym przez statek z id=[ " << el.get_id() << " ]" << std::endl << std::endl;
				std::cout << "Obszar zarezerwoany przez statek z id=[" << el.get_id() << "] wynosi X(" << el.get_x() << "," << obszar_x << ") oraz Y(" << el.get_y() << ", " << obszar_y << ")" << std::endl << std::endl;
				std::cout << "Obszar ktory probowano zarezerowac dla staku z id=[" << element.get_id() << "] wynosi X(" << wylosowana_x << "," << obszar_x_2 << ") oraz Y(" << wylosowana_y << ", " << obszar_y_2 << ")" << std::endl << std::endl;
				std::cout << "Losuje nowe miejsce dla statku z id=[" << element.get_id() << "]" << std::endl;
				std::cout << "---------------------------------------------------------------------------------------------------" << std::endl << std::endl;
				sprawdz_i_wstaw(element, licznik);
				czy_byla_kolizja = true;
				break;
			}*/

		}

		if (czy_byla_kolizja == false)
		{
			int obszar_x, obszar_y;
			obszar_x = element.get_a() + wylosowana_x;
			obszar_y = element.get_b() + wylosowana_y;
			if ((obszar_x < 29) && (obszar_y < 10)) // ewentualne sprawdzenie czy jest blad i stsatek wsyatje z planszy
			{
				element.set_wartoscx_oraz_y(wylosowana_x, wylosowana_y);
				flota_przeciwnika_ustawiona_losowo.push_back(element);
			}
			else
			{
				std::cout << "Statek z id=[ " << element.get_id() << " ] wystaje z planszy, wartosc X to: (" << wylosowana_x << "," << obszar_x << ")" << "; wartosc Y to: (" << wylosowana_y << "," << obszar_y << ")" << std::endl << std::endl;
				std::cout << "Losuje nowe dane" << std::endl << std::endl;
				sprawdz_i_wstaw(element, licznik, liczba_obroconych, max_liczba_obronych_elementow);
			}
		}
		czy_byla_kolizja = false; //reset do wartoscii pcozatkowej w rpzydapku gdy wykryto kolzije(aby nie dodac do vektora dodatkowo

	}
}
void cSiatka::metoda_mouse_move(double openglX, double openglY) {
	for (auto& el : flota)
	{
		if (el.isClicked(openglX, openglY)) //sprawdzic czy dany el jest akywny
		{
			if (el.get_id() == get_aktualnie_przesuwany_statek())
			{
				el.podazaj_za_myszka(openglX, openglY);
			}
		}
	}
	for (auto& el : flota_ustawiona)
	{
		if (el.isClicked(openglX, openglY)) //sprawdzic czy dany el jest akywny
		{
			if (el.get_id() == get_aktualnie_przesuwany_statek())
			{
				el.podazaj_za_myszka(openglX, openglY);
			}
		}
	}
}