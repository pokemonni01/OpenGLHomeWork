#include <stdlib.h>
#include <math.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif

const int FIRESPACE = 100;
const int WIDTHCHAR = 60;
const int HIEGHTCHAR = 150;
const float DEG2RAD = 3.14159/180.0;
const int WIDTH = 640;
const int HEIGHT = 480;


void myDisplay();
void initializeGL();
void setColor(float R,float G, float B);
void drawEllipse(float xradius, float yradius);
void showTable();
void setRGBColor(int R, int G, int B);



int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(1280,720);
    glutInitWindowPosition(50,50);
    glutCreateWindow("OpenGL Student ID");
    glutDisplayFunc(myDisplay);
    initializeGL();
    glutMainLoop();
}//end main

void initializeGL()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-WIDTH, WIDTH, -HEIGHT, HEIGHT);
    
}

void myDisplay(){
    // Clear Window by black color
    glClear(GL_COLOR_BUFFER_BIT);
    setRGBColor(0, 255, 30);
    showTable();
    glFlush();
}

void showTable(){
    //
    int i,j;
    glLineWidth(2.5);
    setRGBColor(117, 117, 117);
    for(i=-WIDTH;i<WIDTH;i+=20){
        glBegin(GL_LINES);
        glVertex2f(i, -HEIGHT);
        glVertex2f(i, HEIGHT);
        glEnd();
    }
    for(j=-HEIGHT;j<HEIGHT;j+=20){
        glBegin(GL_LINES);
        glVertex2f(-WIDTH, j);
        glVertex2f(WIDTH, j);
        glEnd();
    }
}

void drawZero(){

}

void setColor(float R,float G, float B){
    glColor3f(R,G,B);
}

void setRGBColor(int R, int G, int B){
    float r = (float) R/255;
    float g = (float) G/255;
    float b = (float) B/255;
    glColor3f(r, g, b);
}




