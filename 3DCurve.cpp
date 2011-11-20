////////////////////////////////////////////////////////////////
//
// 3Dcurve.c - code for 3Dcurve model
// 
// Author: Mike Chantler
// Date:   29/04/2008
//
////////////////////////////////////////////////////////////////

//#include "stdafx.h" //Only required for windows
#include <stdlib.h>
#include <GLUT/glut.h>
#include <math.h>
#include <stdio.h>
#include "3Dcurve.h"


void draw3Dcurve(double depth, double r1, double r2, double theta_start, double theta_stop, double theta_inc, float colours1[], float colours2[]) {
	// Function to draw 3D curve 
	// depth = depth centred round z=0
	// r1 = inner radius
	// r2 = outer radius
	// theta_start = start angle in degrees measured from x-axis
	// theta_stop = similar 

	double x, y, x1, x2, y1, y2, z, thet, z_front, z_back;
	//int i=0;
	//double radius=1.5, 
    double c=3.14159/180.0;
	z_front=depth/2; z_back=-depth/2;
	
	// draw rear face (away from viewer)
	glColor3f(colours2[0],colours2[1],colours2[2]);
	z=z_back;
	glBegin(GL_QUAD_STRIP);
	for(thet=theta_start; thet<=theta_stop;thet+=theta_inc) {
		x=cos(c*thet)*r2; y=sin(c*thet)*r2; glVertex3d(x,y,z);
		x=cos(c*thet)*r1; y=sin(c*thet)*r1; glVertex3d(x,y,z);
	}
	glEnd();

	// draw front face (closer to viewer)
	glColor3f(colours2[0],colours2[1],colours2[2]);
	z=z_front;
	glBegin(GL_QUAD_STRIP);
	for(thet=theta_start; thet<=theta_stop;thet+=theta_inc)	{
		x=cos(c*thet)*r1; y=sin(c*thet)*r1; glVertex3d(x,y,z);
		x=cos(c*thet)*r2; y=sin(c*thet)*r2; glVertex3d(x,y,z);
	}
	glEnd();

	// draw upper face
	glColor3f(colours1[0],colours1[1],colours1[2]);
	glBegin(GL_QUAD_STRIP);
	for(thet=theta_start; thet<=theta_stop;thet+=theta_inc) {
		x=cos(c*thet)*r2; y=sin(c*thet)*r2;
		z=z_front; glVertex3d(x,y,z);
		z=z_back;  glVertex3d(x,y,z);
	}
	glEnd();

	// draw lower face
	glBegin(GL_QUAD_STRIP);
	for(thet=theta_start; thet<=theta_stop;thet+=theta_inc)	{
		x=cos(c*thet)*r1; y=sin(c*thet)*r1;
		z=z_back; glVertex3d(x,y,z);
		z=z_front; glVertex3d(x,y,z);
	}
	glEnd();

	// draw bottom end
	glColor3f(colours2[0],colours2[1],colours2[2]);
	glBegin(GL_POLYGON);
    x1=cos(c*theta_start)*r1; y1=sin(c*theta_start)*r1;
    x2=cos(c*theta_start)*r2; y2=sin(c*theta_start)*r2;
    
    glVertex3d(x1,y1,z_front);
    glVertex3d(x2,y2,z_front);
    glVertex3d(x2,y2,z_back);
    glVertex3d(x1,y1,z_back);
	glEnd();

	// draw top end
	glBegin(GL_POLYGON);
		x1=cos(c*theta_stop)*r1; y1=sin(c*theta_stop)*r1;
		x2=cos(c*theta_stop)*r2; y2=sin(c*theta_stop)*r2;

		glVertex3d(x1,y1,z_front);
		glVertex3d(x2,y2,z_front);
		glVertex3d(x2,y2,z_back);
		glVertex3d(x1,y1,z_back);
	glEnd();
}