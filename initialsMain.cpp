//
//  initialsMain.cpp
//  Computer Graphics Initials
//
//  Created by Jamie Johnstone on 28/09/2011.
//  Copyright 2011 Heriot-Watt University. All rights reserved.
//
//  Assignment to create our initials out cubes and 3dcurves.
//  Uses files 3dCurve.cpp cube.cpp to create shapes
//  initials built in seperate files j.c k.c m.c

#include <stdlib.h>
#include <GLUT/glut.h>
#include <math.h>
#include <stdio.h>
#include "3Dcurve.h"
#include "cube.h"
#include "drawJ.h"
#include "drawK.h"
#include "drawR.h"
#include "drawL.h"
#include "drawI.h"
#include "drawM.h"
#include "jellyBodyShape.h"


//======================================================
//Prototypes
//======================================================
void mouseClickCallBack(int button, int state, int x, int y);
void mouseMotionCallBack(int x, int y);
void displayCallBack(void);
void executeViewControl(float y, float p);
void viewControl();
void drawInitials();

//======================================================
//  GLOBAL VARIABLES
//======================================================

//for view control
static float G_theta[3]; // View X,Y,Z
static float G_zoom=0.6;

bool MousePressed; // Used in Mouse Drag to change the Viewpoint
float pitch = 0.0f;
float yaw = 0.0f;
float pitch0, yaw0;
int mouseX0, mouseY0;


//=====================================================
//View Contorls
//=====================================================

void executeViewControl (float y, float p){
	glRotatef(y, 0.0f, 1.0f, 0.0f); //yaw about y-axis
    glRotatef(p, 1.0f, 0.0f, 0.0f); //pitch about x-axis 
}



//======================================================
// MOUSE CALLBACK ROUTINES
//======================================================
void mouseClickCallBack(int button, int state, int x, int y) 
{
	// Called on button press or release
    switch (state)
    {
		case GLUT_DOWN:
			MousePressed = true;
			pitch0 = G_theta[0]; 
			yaw0 = G_theta[1];
			mouseX0 = x; mouseY0 = y;
			break;
		default:
		case GLUT_UP:
			MousePressed = false;
			break;
    }
} 

void mouseMotionCallBack(int x, int y) 
{
	// Called when the Mouse is moved with left button down
	pitch = pitch0 + (y - mouseY0)/10;
    yaw = yaw0 + (x - mouseX0)/10;
	glutPostRedisplay();
} 


//======================================================
// VIEW CONTROL ROUTINE 
//======================================================
void viewControl()
{
	// Reset matrix
	glLoadIdentity();
    
	//Rotate everything 
	glRotatef(G_theta[0], 1.0, 0.0, 0.0);
	glRotatef(G_theta[1], 0.0, 1.0, 0.0);
	glRotatef(G_theta[2], 0.0, 0.0, 1.0);
    
	//zoom (NB glOrtho projection)
	glScalef(G_zoom,G_zoom,G_zoom);
}

//hiya
//hiya back...
//======================================================
//DRAW INITIALS (Calls external funcs drawJ drawK drawR)
//======================================================
void drawInitials()
{
    
    
    //draw initial J
    glPushMatrix();
    glTranslatef(-0.6,0.0,0.0);
    glScalef(0.1,0.1,0.1);
    //glRotatef(90,0.0,1.0,0.0);
    drawJ();
    glPopMatrix();
    
    //draw intial K
    glPushMatrix();
    glTranslatef(-0.4,0.0,0.0);
    glScalef(0.1,0.1,0.1);
    //glRotatef(90,0.0,1.0,0.0);
    drawK();
    glPopMatrix();
    
    //draw initial R
    glPushMatrix();
    glTranslatef(-0.2,-0.01,0.0);
    glScalef(0.1,0.1,0.1);
    //glRotatef(90,0.0,1.0,0.0);
    drawR();
    glPopMatrix();
    
    //draw initial L
    glPushMatrix();
    glTranslatef(0.2,0.0,0.0);
    glScalef(0.1,0.1,0.1);
    //glRotatef(90,0.0,1.0,0.0);
    drawL();
    glPopMatrix();
    
    //draw initial I
    glPushMatrix();
    glTranslatef(0.0,0.0,0.0);
    glScalef(0.1,0.1,0.1);
    //glRotatef(90,0.0,1.0,0.0);
    drawI();
    glPopMatrix();
    
    //draw initial M
    glPushMatrix();
    glTranslatef(0.5,0.0,0.0);
    glScalef(0.1,0.1,0.1);
    //glRotatef(90,0.0,1.0,0.0);
    drawM();
    glPopMatrix();
}


//======================================================
// DISPLAY CALLBACK ROUTINE 
//======================================================
void displayCallBack(void)
{
	// display callback,
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    executeViewControl (yaw, pitch);
    
    //draw initials
    //drawInitials();
    
    //jellyfish body shape
    jellyBodyShape();

	glFlush();
	glutSwapBuffers();
}

//======================================================
// MAIN PROGRAM
//======================================================
int main(int argc, char** argv)
{
    // Allow cmd line arguments to be passed to the glut
	glutInit(&argc, argv);
    
	// Create and name window
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Need both double buffering and z buffer
    glutInitWindowSize(500, 500);
    glutCreateWindow("My Initials");
    
	// Add Display & Mouse CallBacks
	glutDisplayFunc(displayCallBack);
	glutIdleFunc(NULL); // Starts the Idle Function as having no routine attached to it. This is modified in rotateView()
	glutMouseFunc(mouseClickCallBack);
    glutMotionFunc(mouseMotionCallBack);
	//glutKeyboardFunc(keyboardCallBack);
    
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */

     
	glutMainLoop();
    
	return 0;
}