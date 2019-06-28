#include <iostream>

#define NDEBUG
#include <GL/freeglut.h>
#include <GL/glut.h>
#include "cScena.h"
#include "cSiatka.h"
cScena scena;

void resize_binding(int width, int height){
    scena.resize(width,height);
}
void keyboard_bingidng(int key,int,int){
	scena.key(key);
}
void idle_binding(){
    scena.idle();
}
void mouse_binding(int button, int state, int x, int y) {
	scena.mouse(button, state, x, y);
}
void mouse_move_binding(int x, int y) {
	scena.mouse_move(x, y);
}
void display_binding(){
    scena.display();
}

int main(int argc, char *argv[])
{
    // it's still possible to use console to print messages
    scena.init(argc,argv,"STATKI PRO");

    return 0;
}