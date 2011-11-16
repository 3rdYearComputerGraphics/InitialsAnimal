// cube.cpp
// By Jamie Johnstone
// 4/10/11
// Adapted from Example_8_3.cpp : Mechanical Arm Example
//
// Author  : Mike Chantler
// Date    : 18/03/2007
// Version : 1.0
//

#include <stdlib.h>
#include <GLUT/glut.h>
#include <math.h>
#include <stdio.h>
#include "cube.h"

//======================================================
//Prototypes
//======================================================

void polygon(int a, int b, int c , int d);


//======================================================
// CUBE ROUTINES
//======================================================
//Cube points and colours

float vertices[][3] = 
{
    {-0.5,-0.5,-0.5},{0.5,-0.5,-0.5},
    {0.5,0.5,-0.5}, {-0.5,0.5,-0.5}, {-0.5,-0.5,0.5}, 
    {0.5,-0.5,0.5}, {0.5,0.5,0.5}, {-0.5,0.5,0.5}
};

float colors[][3] = {{0.9,0.9,0.9},{0.9,0.9,0.9},
	{0.9,0.9,0.9}, {0.9,0.9,0.9}, {0.9,0.9,0.9}, 
	{0.9,0.9,0.9}, {0.9,0.9,0.9}, {0.9,0.9,0.9}};


void polygon(int a, int b, int c , int d)
{
	// draw a polygon using colour of first vertex
    
 	glBegin(GL_POLYGON);
    glColor3fv(colors[a]);
    glVertex3fv(vertices[a]);
    glVertex3fv(vertices[b]);
    glVertex3fv(vertices[c]);
    glVertex3fv(vertices[d]);
	glEnd();
	
	glEnable(GL_LINE_SMOOTH);
	glBegin(GL_LINE_LOOP);
    glColor3f(0.8,0.8,0.8);
    glVertex3fv(vertices[a]);
    glVertex3fv(vertices[b]);
    glVertex3fv(vertices[c]);
    glVertex3fv(vertices[d]);
	glEnd();
	glDisable(GL_LINE_SMOOTH);
}

//default values - a-0 b-1 c-2 d-3 e-4 f-5 g-6 h-7
void cube(int a, int b, int c, int d, int e, int f, int g, int h) {
	//Draw unit cube centred on the origin
	polygon(a,d,c,b);
	polygon(c,d,h,g);
	polygon(e,h,d,a);
	polygon(b,c,g,f);
	polygon(h,e,f,g);
	polygon(f,e,a,b);
}