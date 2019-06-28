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
cScena::cScena(  ){
	
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
	/*for (auto& el : flota)
		el.rysuj();*/
	glutPostRedisplay();

}

void cScena::display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//czysci buffer i ustawia kolor z glClearColor
	
	siatka_1.rysuj_siatke(czy_juz_wyswietlac_kwadraty); //argument true jest to siatka gracza
	siatka_2.rysuj_siatke(czy_juz_wyswietlac_kwadraty);

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
	siatka_1.zainicjuj_siatke(0, 0, 10, 10, 0, true); //inicjujemy dane lewy dolny rog i prawy gorny dla danej siatki
	siatka_2.zainicjuj_siatke(19, 0, 29, 10, 100, false);//inicjujemy dane lewy dolny rog i prawy gorny dla danej siatki
	
	glutMainLoop();
}
void cScena::key(int key) {

}
void cScena::mouse(int button, int state, int x, int y) {
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		double openglX = (((double)DLUGOSC_GL) / ((double)WIELKOSC_OKNA_X)) * ((double)x);
		double openglY = ((double)WYSOKOSC_GL) - ((((double)WYSOKOSC_GL) / ((double)WIELKOSC_OKNA_Y)) * ((double)y));
		siatka_1.metoda_mouse_right_button_down(openglX, openglY, czy_juz_wyswietlac_kwadraty);
		std::cout << "wartosc bool: " << czy_juz_wyswietlac_kwadraty << std::endl;
		siatka_1.liczba_zyc(liczba_zyc_gracza,liczba_zyc_przeciwnika);
		//siatka_1.zaktualizuj_liczbe_zyc();
	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) 
	{
		double openglX = (((double)DLUGOSC_GL) / ((double)WIELKOSC_OKNA_X)) * ((double)x);
		double openglY = ((double)WYSOKOSC_GL) - ((((double)WYSOKOSC_GL) / ((double)WIELKOSC_OKNA_Y)) * ((double)y));
		siatka_1.metoda_mouse_right_button_up(openglX, openglY);
	}
}
void cScena::mouse_move(int x, int y) {
	double openglX = (((double)DLUGOSC_GL) / ((double)WIELKOSC_OKNA_X)) * ((double)x);
	double openglY = ((double)WYSOKOSC_GL) - ((((double)WYSOKOSC_GL) / ((double)WIELKOSC_OKNA_Y)) * ((double)y));
	siatka_1.metoda_mouse_move(openglX, openglY);
}
