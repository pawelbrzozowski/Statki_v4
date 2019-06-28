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
cSiatka siatka_1,siatka_2;
cScena::cScena(int ostuzid, bool mozna_obr, int aktualnieprzesuwstatek): ostanio_uzyte_id_(ostuzid) , mozna_obrocic_(mozna_obr), aktualnie_przersuwany_statek_(aktualnieprzesuwstatek){
	cProstokat cztermasztowiec(15, 9, 4, 1, 4, 1,1);
	flota.push_back(cztermasztowiec);

	cProstokat trojmasztowiec_1(12, 7, 3,2, 3,1,2);
	flota.push_back(trojmasztowiec_1);

	cProstokat trojmasztowiec_2(16, 7, 3,3, 3, 1,3);
	flota.push_back(trojmasztowiec_2);

	cProstokat dwumasztowiec_1(11, 5, 2,4, 2, 1,4);
	flota.push_back(dwumasztowiec_1);

	cProstokat dwumasztowiec_2(14, 5, 2,5, 2, 1,5);
	flota.push_back(dwumasztowiec_2);

	cProstokat dwumasztowiec_3(17, 5, 2,6, 2, 1,6);
	flota.push_back(dwumasztowiec_3);

	cProstokat jednomasztowiec_1(12, 3, 1,7 ,1,1,7);
	flota.push_back(jednomasztowiec_1);

	cProstokat jednomasztowiec_2(14, 3, 1,8,1, 1,8);
	flota.push_back(jednomasztowiec_2);

	cProstokat jednomasztowiec_3(16, 3, 1,9, 1, 1,9);
	flota.push_back(jednomasztowiec_3);

	cProstokat jednomasztowiec_4(18, 3, 1,10, 1, 1, 10);
	flota.push_back(jednomasztowiec_4);

	 ////// GENEROWANIE FLOTY PRZECIWNIKA ////////

	cProstokat cztermasztowiec_przeciwnika(25, 9, 4,1, 4, 1, 1);
	flota_przeciwnika.push_back(cztermasztowiec_przeciwnika);

	cProstokat trojmasztowiec_1_przeciwnika(21, 7, 3,2, 3, 1, 2);
	flota_przeciwnika.push_back(trojmasztowiec_1_przeciwnika);

	cProstokat trojmasztowiec_2_przeciwnika(26, 7, 3,3, 3, 1, 3);
	flota_przeciwnika.push_back(trojmasztowiec_2_przeciwnika);

	cProstokat dwumasztowiec_1_przeciwnika(21, 5, 2,4, 2, 1, 4);
	flota_przeciwnika.push_back(dwumasztowiec_1_przeciwnika);

	cProstokat dwumasztowiec_2_przeciwnika(24, 5, 2,5, 2, 1, 5);
	flota_przeciwnika.push_back(dwumasztowiec_2_przeciwnika);

	cProstokat dwumasztowiec_3_przeciwnika(27, 5, 2,6, 2, 1, 6);
	flota_przeciwnika.push_back(dwumasztowiec_3_przeciwnika);

	cProstokat jednomasztowiec_1_przeciwnika(22, 3, 1,7, 1, 1, 7);
	flota_przeciwnika.push_back(jednomasztowiec_1_przeciwnika);

	cProstokat jednomasztowiec_2_przeciwnika(24, 3, 1,8, 1, 1, 8);
	flota_przeciwnika.push_back(jednomasztowiec_2_przeciwnika);

	cProstokat jednomasztowiec_3_przeciwnika(26, 3, 1,9, 1, 1, 9);
	flota_przeciwnika.push_back(jednomasztowiec_3_przeciwnika);

	cProstokat jednomasztowiec_4_przeciwnika(28, 3, 1,10, 1, 1, 10);
	flota_przeciwnika.push_back(jednomasztowiec_4_przeciwnika);

	//ustaw_statki_przeciwnika_losowo();

	
	cPrzycisk przyczik_obroc(10.5, 0.5, 1, 1, 1, 0.7, 0.7,0);
	przyciski.push_back(przyczik_obroc);

	cPrzycisk przycisk_dalej(14, 0.5, 2, 2,1,0.7,0.7,0);
	przyciski.push_back(przycisk_dalej);
}
void cScena::ustaw_statki_przeciwnika_losowo() {
	/*srand(time(NULL));
	for (auto& el : flota_przeciwnika) {
		if (licznik_ustawiania_losowego == 0)
		{
			do{
			double wylosowana_x = (std::rand() % 10) + 19;
			double wylosowana_y = (std::rand() % 10) + 0;
			while (sprawdz_i_wstaw(el, x, y));
			//el.set_nowa_pozycja_po_losowym_ustaweniu(tmp1, tmp2);
			
		}
		else
		{
			int abc = 0;
			double wylosowana_x = (std::rand() % 10) + 19;
			double wylosowana_y = (std::rand() % 10) + 0;
			double tmp1, tmp2;
			tmp1 = round(wylosowana_x);
			tmp2 = round(wylosowana_y);
			for (int i = 0; i < licznik_ustawiania_losowego; i++)
			{
				if (tmp1 <(flota_przeciwnika[i].get_x() + flota_przeciwnika[i].get_a()) && tmp1 >flota_przeciwnika[i].get_x() && tmp2< (flota_przeciwnika[i].get_y() + flota_przeciwnika[i].get_b()) && tmp2 >flota_przeciwnika[i].get_y())
					abc++;
			}
			if(abc== licznik_ustawiania_losowego)
				el.set_nowa_pozycja_po_losowym_ustaweniu(tmp1, tmp2);
		}
	}*/
}
void cScena::resize(int width, int height) {
   
    glViewport(0, 0, (GLsizei)width, (GLsizei)height); //ustawai vievport,lewy grony punkt i olegly o wysokosc i szerokosc prawy dolny

    glMatrixMode(GL_PROJECTION); //mozemy dzieki temu usatwic glortho
    glLoadIdentity(); //upewnia sie ze nie ma zmian w matrxie i ze wsyztsko jets ustaloneod pcoztaku tak
	glOrtho(0.0, DLUGOSC_GL,0.0, WYSOKOSC_GL,-1.0,1.0);

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
		for (auto& el : flota_przeciwnika)
			el.rysuj();
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

void cScena::init(int argc, char **argv, const char *window_name) {

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
	siatka_1.zainicjuj_siatke(0, 0, 10, 10,0); //inicjujemy dane lewy dolny rog i prawy gorny dla danej siatki
	siatka_2.zainicjuj_siatke(19, 0, 29, 10,100);//inicjujemy dane lewy dolny rog i prawy gorny dla danej siatki
    glutMainLoop();
}
void cScena::key(int key){
	
}
void cScena::mouse(int button, int state, int x, int y) {
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		double openglX = (((double)DLUGOSC_GL)/ ((double)WIELKOSC_OKNA_X)) * ((double)x);
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
				}
			}
			
		}

		for (auto& el : przyciski)
		{
			if (el.isClicked(openglX, openglY))
			{
				el.dane();
				if (el.get_typ() == 2) // sprawdzanie czy klinketo na przycisk dalej, gdy tak ustwaimy jego stan na true
				{
					std::cout << "stan przycisku: " << el.get_stan_klikniety() << std::endl;
				}
				if (el.get_typ() == 1)
				{
					set_mozna_obrocic_statek(true); //ustwaimy parametr sceny mozna_orocic na true
				}
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
	std::cout << "wd. sceny ostanio klinketo na prosotkat z id [" << get_ostanio_uzyte_id_statku() << "]" <<std::endl;
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