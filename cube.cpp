// cube.cpp
// By Jamie Johnstone
// 4/10/11
// Adapted from Example_8_3.cpp : Mechanical Arm Example
//
// Author  : Mike Chantler
// Date    : 18/03/2007
// Version : 1.0
//
// Arguments:
// float colours1 holds the array with the values for the front face
// float colours2 holds the array with the values for the front face
// int a - h specify the points/corners of used to build the cube

#include <stdlib.h>
#include <GLUT/glut.h>
#include <math.h>
#include <stdio.h>
#include "cube.h"

//======================================================
//Prototypes
//======================================================

void polygon(int a, int b, int c , int d, float colours1[], float colours2[]);
void cube(int a, int b, int c, int d, int e, int f, int g, int h, float colours1[], float colours2[]);


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




void polygon(int a, int b, int c , int d, float colours1[], float colours2[])
{
    float colors[][3] = {{colours1[0],colours1[1],colours1[2]},{colours1[0],colours1[1],colours1[2]},
        {colours1[0],colours1[1],colours1[2]}, {colours1[0],colours1[1],colours1[2]}, {colours2[0],colours2[1],colours2[2]}, 
        {colours2[0],colours2[1],colours2[2]}, {colours2[0],colours2[1],colours2[2]}, {colours2[0],colours2[1],colours2[2]}};
    
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
    glColor3f(colours2[0],colours2[1],colours2[2]);
    glVertex3fv(vertices[a]);
    glVertex3fv(vertices[b]);
    glVertex3fv(vertices[c]);
    glVertex3fv(vertices[d]);
	glEnd();
	glDisable(GL_LINE_SMOOTH);
}

//default values - a-0 b-1 c-2 d-3 e-4 f-5 g-6 h-7
void cube(int a, int b, int c, int d, int e, int f, int g, int h, float colours1[], float colours2[]) {
	//Draw unit cube centred on the origin
	polygon(a,d,c,b,colours1,colours2);
	polygon(c,d,h,g,colours1,colours2);
	polygon(e,h,d,a,colours1,colours2);
	polygon(b,c,g,f,colours1,colours2);
	polygon(h,e,f,g,colours1,colours2);
	polygon(f,e,a,b,colours1,colours2);
}