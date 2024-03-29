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
#include "time.h"
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
#include "Timer.cpp"

//======================================================
// GLOBAL VARIABLES 
//======================================================

//For rotation MJC code
//======================================================
float pitch = 0.0f;
float yaw = 0.0f;
float pitch0, yaw0;

//for mouse call back MJC code
//======================================================
bool MousePressed;
int mouseX0, mouseY0;


//for view control MJC code
//======================================================
static float G_theta[3]; // View X,Y,Z
static float G_zoom=0.6;


// GLOBAL VARIABLES WRITTEN TO BY motionCallBack( ) MJC code
//====================================================================
double square_x, square_y, square_z; // position of square
float square_dx = .0007; // incremental change insquare_x
float square_dy= .0008; // incremental change insquare_x
float square_dz= .0008;
Timer* G_rStopwatch ;
double slowRotationTimer;
bool rotate = false;
int randomMovement = 0;



// Jelly Legs sine wave
//======================================================
double angles1[] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
double angles2[] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
double angles3[] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
double angles4[] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};

//these are values to make each leg and each joint act differently when using the sine function
double angleRandomSeeds1 [] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
double angleRandomSeeds2 [] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
double angleRandomSeeds3 [] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
double angleRandomSeeds4 [] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
const double MAX_ANGLE= 10.0 ;

//Timer for Sine waveing
Timer* sineTimer ;
//flag for random functioning
bool finishedRandomising = false;
double randomDouble = 0;



// Jelly Movement (bounaries) 
//======================================================
int w_height=3;
int w_width=3;
int w_depth =3;
//to keep track of where nelly is
int lastX;
int lastY;
int lastZ;

// to keep control of the movement on different H/W
Timer* movementTimer ;
bool move = false;
double slowStartTimer;




//****************************************************
//Jamies variables
float breatheRCurve = 0.8;
float breatheJCurve = 0.3;
float breatheRDiag = 20;
bool swimming=false;
bool rotating=false;
bool out=true;
bool lines=false;
float rotation=0.0f;
//*****************************************************

//****************************************
// These change the color of the jellyfish
//****************************************
//Colours
float bodyColour1[]={0.0,0.8,1.0};
float bodyColour2[]={0.0,0.7,1.0};
float legsColour1[]={1.0,0.8,1.0};
float legsColour2[]={1.0,0.7,1.0};




//======================================================
//Prototypes
//======================================================
void mouseClickCallBack(int button, int state, int x, int y);
void mouseMotionCallBack(int x, int y);
void displayCallBack(void);
void executeViewControl(float y, float p);
void viewControl();
void drawInitials();
void drawJelly();
void keyboardCallBack(unsigned char key, int x, int y) ;
void rotateView(bool r);
void rotatingFunc(int extra);
//void idleCallBack ();
void resetView();
void drawAxesAndGridLines(bool x_y_display, bool y_z_display,  bool x_z_display);
void jellyLeg(double array []);
void reshapeCallBack(int w, int h);
void animate() ;
void randomiseSeeds(double array[]);
void background();

//*********************************************
void swimmingFunc(int extra);
void jellySwim(bool r);

//just add the 4th variable to the already existing drawAxesAndGridLines prototype
void drawAxesAndGridLines(bool x_y_display, bool y_z_display,  bool x_z_display,  bool x_y_z_display);
//*********************************************



//======================================================
// DRAW AXES and GRIDS
//======================================================
void drawAxesAndGridLines(bool x_y_display, bool y_z_display,  bool x_z_display,  bool x_y_z_display)
{
	float offset;
    
    glBegin(GL_LINES);
    
    if(x_y_z_display)
    {
        glColor3f(1, 0, 0);
        glVertex3f(-20, 0, 0);					
        glVertex3f(+20, 0, 0);					
        glVertex3f( 0 ,-20, 0);				    	
        glVertex3f(	0, +20, 0);
        glVertex3f( 0, 0,-20);				    	
        glVertex3f(	0, 0, +20);
	}
    
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
// KEYBOARD CALLBACK ROUTINE - MJC code & edited to allow for out controls 
//======================================================


void keyboardCallBack(unsigned char key, int x, int y) {
	printf("Keyboard call back: key=%c, x=%d, y=%d\n", key, x, y);
	switch(key)
	{
        //fills in the front colouring
        case 'f': case 'F':
            glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
            break;
        //switches to line mode
        case 'l': case 'L':
            glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
            break;
        //toggles the grid
        case 'g': case 'G':
            lines=!lines;
            break;
        //toggles rotation
        case 'r': case 'R':
            rotating= !rotating;
            rotateView(rotating);
            break;
        //toggle jelly legs independently
        case 'j': case 'J': 
            if ( sineTimer->isStopped() )
            {
                sineTimer->start() ;
                glutIdleFunc( animate ) ;
            }
            else
            {
                sineTimer->stop() ;
                glutIdleFunc( NULL ) ;
            }
            break;
        //toggle movement independently
        case 'm': case 'M': 
            if ( movementTimer->isStopped() )
            {
                move = true;
                movementTimer->start() ;
                glutIdleFunc( animate ) ;
            }
            else
            {
                movementTimer->stop() ;
                glutIdleFunc( NULL ) ;
            }
            break;
        //toggle boddy swimming effect independently
        case 's': case 'S': 
            swimming= !swimming;
            jellySwim(swimming);
            break;
        //toggle body, legs, and movement at once
        case 'a': case 'A': 
            if ( sineTimer->isStopped() )
            {
                sineTimer->start() ;
                glutIdleFunc( animate ) ;
            }
            else
            {
                sineTimer->stop() ;
                glutIdleFunc( NULL ) ;
            }
            
            if ( movementTimer->isStopped() )
            {
                move = true;
                movementTimer->start() ;
                glutIdleFunc( animate ) ;
            }
            else
            {
                movementTimer->stop() ;
                glutIdleFunc( NULL ) ;
            }
            
            swimming= !swimming;
            jellySwim(swimming);
            break;

        //default:
            
	}
	glutPostRedisplay();
}




//======================================================
// ROTATION
//======================================================
void rotatingFunc(int extra){
    if(extra==1)
    {
        rotation=rotation+1.0;
        glutPostRedisplay();
        rotateView(rotating);
    }
    else if(extra==0)
    {
        glutPostRedisplay();
    }
}

void rotateView(bool r)
{
	rotating = r;
    if(r)
    {
        glutTimerFunc(50,rotatingFunc,1);
    }
    else
    {
        glutTimerFunc(50,rotatingFunc,0);
    }
}


//====================================================
// to create the swimming effect
//====================================================

void swimmingFunc(int extra){
    if(extra==1&&out==true)
    {
        if(breatheRCurve<1.05)
        {
            breatheRCurve=(breatheRCurve+0.05);
            breatheJCurve=(breatheJCurve-0.03);
            breatheRDiag=(breatheRDiag+3);
        }
        else
        {
            out=false;
        }
        glutPostRedisplay();
        jellySwim(swimming);
    }
    else if(extra==1&&out==false)
    {
        if(breatheRCurve>0.8)
        {
            breatheRCurve=(breatheRCurve-0.05);
            breatheJCurve=(breatheJCurve+0.03);
            breatheRDiag=(breatheRDiag-3);
        }
        else
        {
            out=true;
        }
        glutPostRedisplay();
        jellySwim(swimming);
    }
    else if(extra==0)
    {
        breatheRCurve=0.8;
        breatheJCurve=0.3;
        breatheRDiag=20;
        out=true;
        glutPostRedisplay();
    }
}

//=====================================================
//Timer Code to control the body movement
//=====================================================

void jellySwim(bool s)
{
	swimming = s;
    if (s) glutTimerFunc(150,swimmingFunc,1);
    else glutTimerFunc(150,swimmingFunc,0);
}


//=====================================================
//View Contorls MJC CODE
//=====================================================

void executeViewControl (float y, float p){
	glRotatef(y, 0.0f, 1.0f, 0.0f); //yaw about y-axis
    glRotatef(p, 1.0f, 0.0f, 0.0f); //pitch about x-axis 
}



//======================================================
// MOUSE CALLBACK ROUTINES MJC CODE
//======================================================
void mouseClickCallBack(int button, int state, int x, int y) 
{
	// Called on button press or release
    switch (state)
    {
		case GLUT_DOWN:
			pitch0 = G_theta[0]; 
			yaw0 = G_theta[1];
			mouseX0 = x; mouseY0 = y;
            rotate = true;
			break;
		default:
		case GLUT_UP:
            rotate = false;
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
// VIEW CONTROL ROUTINE  - MJC CODE
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
	//draw J now needs parameters
    drawJ(breatheJCurve,bodyColour1,bodyColour2);
    glPopMatrix();
    
    //draw intial K
    glPushMatrix();
    glTranslatef(-0.4,0.0,0.0);
    glScalef(0.1,0.1,0.1);
    drawK(bodyColour1,bodyColour2);
    glPopMatrix();
    
    //draw initial R
    glPushMatrix();
    glTranslatef(-0.2,-0.01,0.0);
    glScalef(0.1,0.1,0.1);
    //draw R now needs parameters
    drawR(breatheRCurve,breatheRDiag,bodyColour1,bodyColour2);
    glPopMatrix();
    
    //draw initial L
    glPushMatrix();
    glTranslatef(0.2,0.0,0.0);
    glScalef(0.1,0.1,0.1);
    drawL(bodyColour1,bodyColour2);
    glPopMatrix();
    
    //draw initial I
    glPushMatrix();
    glTranslatef(0.0,0.0,0.0);
    glScalef(0.1,0.1,0.1);
    drawI(bodyColour1,bodyColour2);
    glPopMatrix();
    
    //draw initial M
    glPushMatrix();
    glTranslatef(0.5,-0.25,0.0);
    glRotatef(90,0.0,0.0,1.0);
    glScalef(0.1,0.1,0.1);
    drawM(bodyColour1,bodyColour2);
    glPopMatrix();
     
}

void drawJelly()
{
    glPushMatrix();
    
    //loop to create the body
    for (int i=0; i<=180; (i=i+10)) {


        //draw instance of jellyBodyShape()
        glPushMatrix();
        glRotatef(i,0.0,1.0,0.0);
        jellyBodyShape(breatheRCurve,breatheJCurve,breatheRDiag,bodyColour1,bodyColour2);        
        glPopMatrix();
        

    }
        //used the arrays with angles
        glPushMatrix();
        glRotatef(90,0.0,1.0,0.0);
        jellyLeg(angles1);
        glRotatef(90,0.0,1.0,0.0);
        jellyLeg(angles2);
        glRotatef(90,0.0,1.0,0.0);
        jellyLeg(angles3);
        glRotatef(90,0.0,1.0,0.0);
        jellyLeg(angles4);
        glPopMatrix();
    
    glPopMatrix();
  
}

//======================================================
// DrawJellyLeg
//======================================================

void jellyLeg(double array [])
{
    //draw instance of jellyLegShape()
    jellyLegShape(array, legsColour1, legsColour2);
    
}


void animate()  
// One frame of animation.
{
    glutPostRedisplay() ;
}


//======================================================
// DISPLAY CALLBACK ROUTINE 
//======================================================
void displayCallBack(void)
{
	// display callback,
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(rotate)executeViewControl (yaw, pitch);

    //draw jellyfish body
    glPushMatrix();
    glTranslatef(square_x, square_y, 0.0);
    glRotatef(rotation, 0.0, 1.0, 0.0);
    drawJelly();
    glPopMatrix();
    
    // Get elapsed animation time (in seconds) from stopwatch.
    //t is effectively the y-axis of the sine graph for each
    double t= sineTimer->getValue() * 0.001 ;  

    //set up the arrays for passing to the legs
    angles1[0]= MAX_ANGLE * sin( angleRandomSeeds1[0] * t ) ;
    angles1[1]= MAX_ANGLE * sin( angleRandomSeeds1[1] * t ) ;
    angles1[2]= MAX_ANGLE * sin( angleRandomSeeds1[2] * t ) ;
    angles1[3]= MAX_ANGLE * sin( angleRandomSeeds1[3] * t ) ;
    angles1[4]= MAX_ANGLE * sin( angleRandomSeeds1[4] * t ) ;
    angles1[5]= MAX_ANGLE * sin( angleRandomSeeds1[5] * t ) ;
    angles1[6]= MAX_ANGLE * sin( angleRandomSeeds1[6] * t ) ;
    angles1[7]= MAX_ANGLE * sin( angleRandomSeeds1[7] * t ) ;

    angles2[0]= MAX_ANGLE * sin( angleRandomSeeds2[0] * t ) ;
    angles2[1]= MAX_ANGLE * sin( angleRandomSeeds2[1] * t ) ;
    angles2[2]= MAX_ANGLE * sin( angleRandomSeeds2[2] * t ) ;
    angles2[3]= MAX_ANGLE * sin( angleRandomSeeds2[3] * t ) ;
    angles2[4]= MAX_ANGLE * sin( angleRandomSeeds2[4] * t ) ;
    angles2[5]= MAX_ANGLE * sin( angleRandomSeeds2[5] * t ) ;
    angles2[6]= MAX_ANGLE * sin( angleRandomSeeds2[6] * t ) ;
    angles2[7]= MAX_ANGLE * sin( angleRandomSeeds2[7] * t ) ;
    
    angles3[0]= MAX_ANGLE * sin( angleRandomSeeds3[0] * t ) ;
    angles3[1]= MAX_ANGLE * sin( angleRandomSeeds3[1] * t ) ;
    angles3[2]= MAX_ANGLE * sin( angleRandomSeeds3[2] * t ) ;
    angles3[3]= MAX_ANGLE * sin( angleRandomSeeds3[3] * t ) ;
    angles3[4]= MAX_ANGLE * sin( angleRandomSeeds3[4] * t ) ;
    angles3[5]= MAX_ANGLE * sin( angleRandomSeeds3[5] * t ) ;
    angles3[6]= MAX_ANGLE * sin( angleRandomSeeds3[6] * t ) ;
    angles3[7]= MAX_ANGLE * sin( angleRandomSeeds3[7] * t ) ;

    angles4[0]= MAX_ANGLE * sin( angleRandomSeeds4[0] * t ) ;
    angles4[1]= MAX_ANGLE * sin( angleRandomSeeds4[1] * t ) ;
    angles4[2]= MAX_ANGLE * sin( angleRandomSeeds4[2] * t ) ;
    angles4[3]= MAX_ANGLE * sin( angleRandomSeeds4[3] * t ) ;
    angles4[4]= MAX_ANGLE * sin( angleRandomSeeds4[4] * t ) ;
    angles4[5]= MAX_ANGLE * sin( angleRandomSeeds4[5] * t ) ;
    angles4[6]= MAX_ANGLE * sin( angleRandomSeeds4[6] * t ) ;
    angles4[7]= MAX_ANGLE * sin( angleRandomSeeds4[7] * t ) ;

   

    if(move){
        if((movementTimer->getValue() * 0.001)-slowStartTimer > .01){
            slowStartTimer = movementTimer->getValue() * 0.001;
            randomMovement++;
            if(randomMovement >= 1500){
                double temp1 = (rand()%10);
                double temp2 = (rand()%10);
                double temp3 = (rand()%10);
                
                
                square_dx = temp1/1000;
                square_dy = temp2/1000;
                square_dz = temp3/1000;
                randomMovement = 0;
                
                //debugging
                //printf("%f%f%f\n", temp1/1000, temp2/1000, temp3/1000);
            }
            square_x += square_dx; //Increment x-position of square
            square_y += square_dy; //Increment x-position of square
            square_z += square_dz;
            
            //debugging
            //printf("%d %d %d %d \n", square_x,square_y, square_dx, square_dy);
            if (square_x > w_width || square_x <=0) square_dx *= -1; //Reverse direction if at edges
            if (square_y > w_height || square_y <=0) square_dy *= -1;
            if (square_z > w_depth || square_z <=0) square_dz *= -1;//Reverse direction if at edges

        }
    }
    
    //added grids and lines
    drawAxesAndGridLines(lines, lines, lines, lines);    
    
    //Draw initials 
    //drawInitials();
    
	glFlush();
	glutSwapBuffers();
}


void randomiseSeeds(double array[])
{
    for(int i=0;i<8;i++){
        randomDouble = (rand()%20);
        array[i]=randomDouble/10;

    }
}

//======================================================
// MAIN PROGRAM
//======================================================
int main(int argc, char** argv)
{
    // Allow cmd line arguments to be passed to the glut
	glutInit(&argc, argv);
    
    //seed the random function
    srand ((unsigned)time (0));
    
    randomiseSeeds(angleRandomSeeds1);
    randomiseSeeds(angleRandomSeeds2);
    randomiseSeeds(angleRandomSeeds3);
    randomiseSeeds(angleRandomSeeds4);
    
	// Create and name window
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Need both double buffering and z buffer
    glutInitWindowSize(800, 800);
    glutCreateWindow("Nelly the Jellyfish");
    
    //Prints instructions to screen
    printf("\nPress the following to interact:\n 'f' - fill colour; 'l' - line mode; 'r' - rotate;\n 'm' - movement; 'j' - move jelly legs; 's' - move body; 'a' - move all\n");

    
	// Add Display & Mouse CallBacks
    glutReshapeFunc(reshapeCallBack);
	glutDisplayFunc(displayCallBack);
	glutIdleFunc(NULL); // Starts the Idle Function as having no routine attached to it. This is modified in rotateView()
	glutMouseFunc(mouseClickCallBack);
    glutMotionFunc(mouseMotionCallBack);
	glutKeyboardFunc(keyboardCallBack);
    
    //istantiate the timers
    sineTimer= new Timer ;
    movementTimer= new Timer ;
        
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */
  

	glutMainLoop();
    
	return 0;
}