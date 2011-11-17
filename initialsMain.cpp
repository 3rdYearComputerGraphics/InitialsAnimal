//
//  initialsMain.cpp
//  Computer Graphics Initials
//
//  Created by Jamie Johnstone & Lewis McLean on 28/09/2011.
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
#include "JellyLegShape.h"

//======================================================
// GLOBAL VARIABLES 
//======================================================
float pitch = 0.0f;
float yaw = 0.0f;
float pitch0, yaw0;
bool MousePressed;
int mouseX0, mouseY0;
bool rotating=false;
//for view control
static float G_theta[3]; // View X,Y,Z
static float G_zoom=0.6;

//stuff for my sine wave 
double angles[] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
long start;
const double ROTATION_FREQ = 0.03 ;
const double MAX_ANGLE= 50.0 ;
long duration;

//======================================================
//Prototypes
//======================================================
void mouseClickCallBack(int button, int state, int x, int y);
void mouseMotionCallBack(int x, int y);
void displayCallBack(void);
void executeViewControl(float y, float p);
void viewControl();
void drawInitials();
void jellyBody();
void keyboardCallBack(unsigned char key, int x, int y) ;
void rotateView(bool r);
void idleCallBack ();
void resetView();
void drawAxesAndGridLines(bool x_y_display, bool y_z_display,  bool x_z_display);
void jellyLeg(double array []);
void reshapeCallBack(int w, int h);
void part1(double array []);
void part2(double array []);
void part3(double array []);
void part4(double array []);
void part5(double array []);
void part6(double array []);
void part7(double array []);
void part8(double array []);

//======================================================
// DRAW AXES and GRIDS
//======================================================
void drawAxesAndGridLines(bool x_y_display, bool y_z_display,  bool x_z_display)
{
	float offset;
	glBegin(GL_LINES);
    glColor3f(1, 0, 0);
    glVertex3f(-20, 0, 0);					
    glVertex3f(+20, 0, 0);					
    glVertex3f( 0 ,-20, 0);				    	
    glVertex3f(	0, +20, 0);
    glVertex3f( 0, 0,-20);				    	
    glVertex3f(	0, 0, +20);
    
	glEnd();
	
	glLineStipple(1, 0xAAAA); //line style = fine dots
	glEnable(GL_LINE_STIPPLE);
    
	glBegin(GL_LINES);
    
    if (x_y_display) {glColor3f(0.0,0.7,0.7);
		for (offset=-10.0;offset<10.1;offset++){
			//draw lines in x-y plane
			glVertex3f(-10.0, offset, 0.0);					// Top Left
			glVertex3f(+10.0, offset, 0.0);					// Top Right
			glVertex3f( offset,-10, 0.0);					// Bottom Right
			glVertex3f(	offset,+10.0, 0.0);					// Bottom Left
		}}
    
    if (y_z_display) {glColor3f(0.7,0.0,0.7);
		for (offset=-10.0;offset<10.1;offset++){
			//draw lines in y-z plane
			glVertex3f( 0, offset, -10);					
			glVertex3f(	0, offset, 10.0);
			glVertex3f( 0, -10, offset);					
			glVertex3f(	0, 10, offset);
		}}
    
    if (x_z_display) {glColor3f(0.7,0.7,0.0);
		for (offset=-10.0;offset<10.1;offset++){
			//draw lines in x-z plane
			glVertex3f( offset, 0, -10);					
			glVertex3f(	offset, 0, 10.0);
			glVertex3f( -10, 0, offset);					
			glVertex3f(	10, 0, offset);
		}}
    
	glEnd();
	glDisable(GL_LINE_STIPPLE);
    
}

//======================================================
// VIEW CONTROL ROUTINES
//======================================================

void idleCallBack (){
	yaw=yaw+.25;
    glutPostRedisplay();
}

void rotateView(bool r){
	rotating = r;
	if (r) glutIdleFunc(idleCallBack); else glutIdleFunc(NULL);
}

void resetView(){
	rotateView(false); //Stop view rotation
	yaw=pitch=0;
}


//======================================================
// KEYBOARD CALLBACK ROUTINE 
//======================================================
void keyboardCallBack(unsigned char key, int x, int y) {
	printf("Keyboard call back: key=%c, x=%d, y=%d\n", key, x, y);
	switch(key)
	{
        case 'b': case 'B':
            glPolygonMode(GL_BACK,GL_FILL);
            break;
        case 'f': case 'F':
            glPolygonMode(GL_FRONT,GL_FILL);
            break;
        case 'l': case 'L':
            glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
            break;
        case 'r': 
            rotating= !rotating;
            rotateView(rotating);
            break;
        case 'j': 
            duration = (glutGet( GLUT_ELAPSED_TIME ) - start)*.0001;
            for(int i=0;i<8;i++){
                angles[i]= MAX_ANGLE * sin( 1 * duration ) ;}

            break;
        case 'R':
            resetView();
            break;
        default:
            printf("Press b - back fill; f - front fill; l - line; i - increment; or d - decrement; r - rotate; R - reset view\n");
	}
    
	glutPostRedisplay();
}



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


void reshapeCallBack(int w, int h) 
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	if (w == 0 || h == 0) return;
    if (w <= h) glOrtho(-3.0, 3.0, -3.0 * (GLfloat) h / (GLfloat) w, 3.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
    else        glOrtho(-3.0 * (GLfloat) w / (GLfloat) h, 3.0 * (GLfloat) w / (GLfloat) h, -3.0, 3.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}


//======================================================
//DRAW INITIALS (Calls external funcs drawJ drawK drawR)
//DRAWING OTHER PARTS OF THE ANIMAL
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

void jellyBody()
{
    
    for (int i=0; i<=180; (i=i+10)) {


        //draw instance of jellyBodyShape()
        glPushMatrix();
        //glTranslatef(0.5,0.0,0.0);
        glRotatef(i,0.0,1.0,0.0);
        //glScalef(1.0,1.0,1.0);
        jellyBodyShape();
        glPopMatrix();
    }
    
}

//======================================================
// DrawJellyLeg
//======================================================

void jellyLeg(double array [])
{
    //draw instance of jellyLegShape()

    part1(array);
    //glPopMatrix();
}


void part1(double array [])
{
    glPushMatrix();
    glTranslatef(0,-0.3,0.0);
    glRotatef(90,0,0,1);
    //glRotated( array[1], 0,0,1 ) ;
    legPart1();
    //glPopMatrix();
    
    part2(array);
   
}

void part2(double array [])
{
    glPushMatrix();
    glRotatef(-90,0,0,1);
    glTranslatef(0.22,-0.15,0.0);
    glRotatef(180,1.0,0.0,0.0);
    //glRotated( array[2], 0,0,1 ) ;
    legPart2();
    //glPopMatrix();
    
    part3(array);
    
}

void part3(double array [])
{
    glPushMatrix();
    glRotatef(-180,1.0,0.0,0.0);
    glTranslatef(-0.32,-0.25,0.0);
    glRotatef(180,0.0,1.0,0.0);
    glRotatef(180,0.0,0.0,1.0);

    //glRotated( array[3], 0,0,1 ) ;
    legPart3();
    //glPopMatrix();
    
    part4(array);
    
}

void part4(double array [])
{
    glPushMatrix();
    glRotatef(-180,0.0,1.0,0.0);
    glRotatef(-180,0.0,0.0,1.0);
    glTranslatef(0.0,-0.28,0.0);
    glRotatef(180,0.0,1.0,0.0);
    glRotated( array[4], 0,0,1 ) ;
    legPart4();
    //glPopMatrix();
    
    part5(array);
    
}

void part5(double array [])
{
    glPushMatrix();
    glRotatef(-180,0.0,1.0,0.0);
    glTranslatef(0,-0.47,0.0);
    glRotatef(90,0,0,1);
    glRotated( array[5], 0,0,1 ) ;
    legPart5();
    //glPopMatrix();
    
    part6(array);
    
}

void part6(double array [])
{    
    glPushMatrix();
    glRotatef(-90,0,0,1);
    glTranslatef(0,-0.15,0.0);
    glRotatef(180,1.0,0.0,0.0);
    glRotated( array[6], 0,0,1 ) ;
    legPart6();
    //glPopMatrix();
    
    part7(array);
    
}

void part7(double array [])
{    
    glPushMatrix();
    glRotatef(-180,1.0,0.0,0.0);
    glTranslatef(0.1,-0.250,0.0);
    glRotatef(180,0.0,1.0,0.0);
    glRotatef(180,0.0,0.0,1.0);
    glRotated( array[7], 0,0,1 ) ;
    legPart7();
    //glPopMatrix();
    
    part8(array);
    
}

void part8(double array [])
{    
    glPushMatrix();
    glRotatef(-180,0.0,1.0,0.0);
    glRotatef(-180,0.0,0.0,1.0);
    glTranslatef(-0.03,-0.23,0.0);
    glRotatef(180,0.0,1.0,0.0);
    glRotated( array[8], 0,0,1 ) ;
    legPart8();
    //glTranslatef(0.5,0.0,0.0);
    //glRotatef(0,0.0,1.0,0.0);
    //glScalef(1.0,1.0,1.0);
    //jellyLegShape();
    glPopMatrix();
    for(int i=0;i<8;i++)glPopMatrix();
}





//======================================================
// DISPLAY CALLBACK ROUTINE 
//======================================================
void displayCallBack(void)
{
	// display callback,
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    executeViewControl (yaw, pitch);
    
    
    
    //double degrees= duration * ROTATION_FREQ * 360 ;
    
    //Angles for leg wabble
  
    
    //draw jellyfish body
    jellyBody();
    
    
    
    //draw jellyfish leg
    jellyLeg(angles);
    
    //added grids and lines
    drawAxesAndGridLines(true, true, true);
    
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
    glutInitWindowSize(800, 800);
    glutCreateWindow("My Initials");
    
	// Add Display & Mouse CallBacks
    glutReshapeFunc(reshapeCallBack);
	glutDisplayFunc(displayCallBack);
	glutIdleFunc(NULL); // Starts the Idle Function as having no routine attached to it. This is modified in rotateView()
	glutMouseFunc(mouseClickCallBack);
    glutMotionFunc(mouseMotionCallBack);
	glutKeyboardFunc(keyboardCallBack);
    
    //need to add scaling ....????
    //Nope, already done in the reshapeCallback on line 508
    //glEnable(GL_NORMALIZE);
    // Enable lighting

    
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */
  

    start = glutGet( GLUT_ELAPSED_TIME );
	glutMainLoop();
    
	return 0;
}