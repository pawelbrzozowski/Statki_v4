//
// Created by piotr on 27.03.19.
//
#include "cSiatka.h"
#include "cScena.h"
#include "cPrzycisk.h"
#include <iostream>
#define DLUGOSC_GL 29
#define WYSOKOSC_GL 10
#define WIELKOSC_OKNA_X 1102
#define WIELKOSC_OKNA_Y 380
cSiatka siatka_1, siatka_2;
cScena::cScena(int ostuzid, bool mozna_obr, int aktualnieprzesuwstatek, bool czywyswtlmenu, bool czy_statki_gracza_losowo, bool czy_wyswietlac_juz_statki_gracza) : ostanio_uzyte_id_(ostuzid), mozna_obrocic_(mozna_obr), aktualnie_przersuwany_statek_(aktualnieprzesuwstatek), czy_wyswietlac_menu_strzalow_(czywyswtlmenu),czy_statki_gracza_sa_ustawione_(czy_statki_gracza_losowo),czy_wyswietlac_juz_statki_gracza_(czy_wyswietlac_juz_statki_gracza){
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
	pociski.push_back(nalot_samolotu);

	cStrzal bombardowanie(11, 6, 2, 1, false);
	pociski.push_back(bombardowanie);

	cStrzal torpeda(11, 4.5, 3, 2, false);
	pociski.push_back(torpeda);

	cStrzal zwykly_strzal(11, 3, 4, 1000, true);
	pociski.push_back(zwykly_strzal);
}
void cScena::ustaw_statki_przeciwnika_losowo() {
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
void cScena::ustaw_statki_gracza_losowo() {
	int licznik = 1, liczba_obroconych = 0;
	srand(time(NULL));
	int max_liczba_obronych_elementow = (std::rand() % 10);
	for (auto& el : flota) {
		licznik++;
		sprawdz_i_wstaw_gracz(el, licznik, liczba_obroconych, max_liczba_obronych_elementow);
	}
	for (auto& el : flota)//nasze ellementy wektora rysujemy dalej, aby nie wyswietlaly sie poniewaz ustawiamy statki w innym vektorze
	{
		el.set_wartoscx_oraz_y(1000, 1000);
	}
	std::cout << "DANE DLA FLOTY GRACZA:" << std::endl << std::endl;
	for (auto& el : flota_ustawiona) {
		el.dane_rozlozenia_losowego(); //dostajemy informacje gdzie statki zostal umieszonczy 
	}
}
void cScena::wyczysc_dane_ustawionej_floty() {
	
	flota_ustawiona.clear();
}
void cScena::sprawdz_i_wstaw_gracz(cProstokat element, int licznik, int& liczba_obroconych, int max_liczba_obronych_elementow)
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
void cScena::sprawdz_i_wstaw(cProstokat element, int licznik, int& liczba_obroconych,int max_liczba_obronych_elementow) {
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
				int lewy_dolny_x, lewy_dolny_y , prawy_dolny_x, prawy_dolny_y , lewy_gorny_x, lewy_gory_y,  prawy_gorny_x, prawy_gorny_y;
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
				

				if (((prawy_dolny_x > obszar_min_x_juz_zarezerowany) && (prawy_dolny_x < obszar_max_x_juz_zarezerowany))&& ((prawy_dolny_y > obszar_min_y_juz_zarezerowany) && (prawy_dolny_y < obszar_max_y_juz_zarezerowany)))
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
				std::cout << "Statek z id=[ " << element.get_id() << " ] wystaje z planszy, wartosc X to: ("<<wylosowana_x<<","<<obszar_x<<")" <<"; wartosc Y to: (" << wylosowana_y << "," << obszar_y << ")" << std::endl << std::endl;
				std::cout << "Losuje nowe dane" << std::endl << std::endl;
				sprawdz_i_wstaw(element, licznik, liczba_obroconych, max_liczba_obronych_elementow);
			}
		}
		czy_byla_kolizja = false; //reset do wartoscii pcozatkowej w rpzydapku gdy wykryto kolzije(aby nie dodac do vektora dodatkowo

	}


}
void cScena::resize(int width, int height) {

	glViewport(0, 0, (GLsizei)width, (GLsizei)height); //ustawai vievport,lewy grony punkt i olegly o wysokosc i szerokosc prawy dolny

	glMatrixMode(GL_PROJECTION); //mozemy dzieki temu usatwic glortho
	glLoadIdentity(); //upewnia sie ze nie ma zmian w matrxie i ze wsyztsko jets ustaloneod pcoztaku tak
	glOrtho(0.0, DLUGOSC_GL, 0.0, WYSOKOSC_GL, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void cScena::idle() {
	for (auto& el : flota)
		el.rysuj();
	glutPostRedisplay();

}

void cScena::display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//czysci buffer i ustawia kolor z glClearColor
	siatka_1.rysuj_siatke();
	siatka_2.rysuj_siatke();
	glPushMatrix();
	{
		for (auto& el : flota_przeciwnika_ustawiona_losowo)
		{
			el.rysuj();
		}

	}
	glPushMatrix();
	{
		for (auto& el : flota)
			el.rysuj();
	}
	glPopMatrix();
	glPushMatrix();
	{
		for (auto& el : przyciski)
			el.rysuj();
	}
	glPopMatrix();

	if (get_czy_mozna_wyswietlic_menu_strzalow() == true)
	{
		glPushMatrix();
		{
			for (auto& el : pociski)
				el.rysuj();
		}
		glPopMatrix();

	}
	if (czy_wyswietlac_juz_statki_gracza_ == true)
	{
		glPushMatrix();
		{
			for (auto& el : flota_ustawiona)
				el.rysuj();
		}
		glPopMatrix();
	}
	glutSwapBuffers();//wyswietla nowa kaltke gdy display jesy wczytywany
}



void cScena::set_callbacks() {
	glutReshapeFunc(resize_binding);
	glutDisplayFunc(display_binding);
	glutIdleFunc(idle_binding);
	glutMouseFunc(mouse_binding);
	glutMotionFunc(mouse_move_binding);
	glutSpecialFunc(keyboard_bingidng);
}

void cScena::init(int argc, char** argv, const char* window_name) {

	glutInit(&argc, argv);
	glutInitWindowSize(WIELKOSC_OKNA_X, WIELKOSC_OKNA_Y);
	glutInitWindowPosition(40, 40);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutCreateWindow(window_name);

	// set white as the clear colour
	glClearColor(0.8, 0.8, 0.8, 1);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	set_callbacks();
	siatka_1.zainicjuj_siatke(0, 0, 10, 10, 0); //inicjujemy dane lewy dolny rog i prawy gorny dla danej siatki
	siatka_2.zainicjuj_siatke(19, 0, 29, 10, 100);//inicjujemy dane lewy dolny rog i prawy gorny dla danej siatki
	glutMainLoop();
}
void cScena::key(int key) {

}
void cScena::mouse(int button, int state, int x, int y) {
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		double openglX = (((double)DLUGOSC_GL) / ((double)WIELKOSC_OKNA_X)) * ((double)x);
		double openglY = ((double)WYSOKOSC_GL) - ((((double)WYSOKOSC_GL) / ((double)WIELKOSC_OKNA_Y)) * ((double)y));
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

		for (auto& el : flota_przeciwnika_ustawiona_losowo)
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



		for (auto& el : przyciski)
		{
			if (el.isClicked(openglX, openglY))
			{
				if (el.get_typ() == 3) // sprawdzanie czy klinketo na przycisk dalej, gdy tak ustwaimy jego stan na true
				{
					std::cout << "KLIKNIETO DALEJ " << std::endl;
					set_czy_mozna_wyswietlic_menu_strzalow(true);
					stan_arsenalu();
				}
				if (el.get_typ() == 2) // sprawdzanie czy klinketo na przycisk dalej, gdy tak ustwaimy jego stan na true
				{
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
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
		double openglX = (((double)DLUGOSC_GL) / ((double)WIELKOSC_OKNA_X)) * ((double)x);
		double openglY = ((double)WYSOKOSC_GL) - ((((double)WYSOKOSC_GL) / ((double)WIELKOSC_OKNA_Y)) * ((double)y));
		for (auto& el : flota)
		{
			el.isUnclicked(openglX, openglY);
			el.dopasuj_element_na_planszy();

		}

	}
}
void cScena::mouse_move(int x, int y) {
	double openglX = (((double)DLUGOSC_GL) / ((double)WIELKOSC_OKNA_X)) * ((double)x);
	double openglY = ((double)WYSOKOSC_GL) - ((((double)WYSOKOSC_GL) / ((double)WIELKOSC_OKNA_Y)) * ((double)y));
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

}
void cScena::set_ostanio_uzyte_id_statku(int wartosc) {
	ostanio_uzyte_id_ = wartosc;
	std::cout << "wd. sceny ostanio klinketo na prosotkat z id [" << get_ostanio_uzyte_id_statku() << "]" << std::endl;
}
int cScena::get_ostanio_uzyte_id_statku() {
	return ostanio_uzyte_id_;
}
void cScena::set_mozna_obrocic_statek(int wartosc) {
	mozna_obrocic_ = wartosc;
}
bool cScena::get_mozna_obrocic_statek() {
	return mozna_obrocic_;
}
void cScena::set_aktualnie_przesuwany_statek(int wartosc) {
	aktualnie_przersuwany_statek_ = wartosc;
}
int cScena::get_aktualnie_przesuwany_statek() {
	return aktualnie_przersuwany_statek_;
}
void cScena::set_czy_mozna_wyswietlic_menu_strzalow(int wartosc) {
	czy_wyswietlac_menu_strzalow_ = wartosc;
}
bool cScena::get_czy_mozna_wyswietlic_menu_strzalow() {
	return czy_wyswietlac_menu_strzalow_;
}
void cScena::stan_arsenalu() {
	std::string a = "nalotu", b = "bombardowania", c = "torped", d = "zwyklego ostrzalu";
	int tmp;
	std::cout << "|------------------------------------------------|" << std::endl;
	std::cout << "|Pozostalo Ci:                                   |" << std::endl;
	std::cout << "|                                                |" << std::endl;
	for (auto& el : pociski)
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