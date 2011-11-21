//
//  jellyLegShape.cpp
//  GraphicsProject
//
//  Created by Jamie Johnstone & Lewis McLean on 16/11/2011.
//  Copyright 2011 Heriot-Watt University. All rights reserved.
//
//

#include <stdlib.h>
#include <GLUT/glut.h>
#include <math.h>
#include <stdio.h>
#include "jellyBodyShape.h"
#include "cube.h"
#include "drawJ.h"
#include "drawK.h"
#include "drawR.h"
#include "drawL.h"
#include "drawI.h"
#include "drawM.h"
#include "3DCurve.h"


void jellyLegShape(double array[],float colours1[], float colours2[]);
void legPart(float colours1[], float colours2[]);
void legPart1(float colours1[], float colours2[]);
void legPart2(float colours1[], float colours2[]);
void legPart3(float colours1[], float colours2[]);
void legPart4(float colours1[], float colours2[]);
void legPart5(float colours1[], float colours2[]);
void legPart6(float colours1[], float colours2[]);
void legPart7(float colours1[], float colours2[]);
void legPart8(float colours1[], float colours2[]);

void jellyLegShape(double array[],float colours1[], float colours2[])
{
    
    glPushMatrix();

    glRotated( array[1], 0,0,1 ) ;
    legPart1(colours1,colours2);
    
    glPushMatrix();
    glTranslatef(-0.02,-0.3,0.0);
    glRotated( array[2], 0,0,1 ) ;
    legPart2(colours1,colours2);
  
    glPushMatrix();
    glTranslatef(-0.0,-0.22,0.0);
    glRotated( array[3], 0,0,1 ) ;
    legPart3(colours1,colours2);

    glPushMatrix();
    glTranslatef(0.0,-0.28,0.0);
    glRotated( array[4], 0,0,1 ) ;
    legPart4(colours1,colours2);

    glPushMatrix();
    glTranslatef(0,-0.27,0.0);
    glRotated( array[5], 0,0,1 ) ;
    legPart5(colours1,colours2);

    glPushMatrix();
    glTranslatef(0,-0.35,0.0);
    glRotated( array[6], 0,0,1 ) ;
    legPart6(colours1,colours2);

    glPushMatrix();
    glTranslatef(0,-0.23,0.0);
    glRotated( array[7], 0,0,1 ) ;
    legPart7(colours1,colours2);

    glPushMatrix();
    glTranslatef(-0.0,-0.26,0.0);
    glRotated( array[8], 0,0,1 ) ;
    legPart8(colours1,colours2);
    

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    

  

}

void legPart1(float colours1[], float colours2[]) {
    
    glPushMatrix();

    glScalef(0.1,0.1,0.1);
    drawM(colours1,colours2);
    glPopMatrix();
}
   
void legPart2(float colours1[], float colours2[]) {
    glPushMatrix();

    glScalef(-0.1,0.1,0.1);
    drawI(colours1,colours2);
    glPopMatrix();
}
    
void legPart3(float colours1[], float colours2[]) {
    glPushMatrix();
    glScalef(0.1,0.1,0.1);
    drawL(colours1,colours2);
    glPopMatrix();
}
    
void legPart4(float colours1[], float colours2[]) {
    glPushMatrix();

    glScalef(-0.1,0.1,0.1);
    drawK(colours1,colours2);
    glPopMatrix();
}

void legPart5(float colours1[], float colours2[]) {
    
    glPushMatrix();
    glScalef(0.1,0.1,0.1);
    drawM(colours1,colours2);
    glPopMatrix();
}

void legPart6(float colours1[], float colours2[]) {
    glPushMatrix();

    glScalef(-0.1,0.1,0.1);
    drawI(colours1,colours2);
    glPopMatrix();
}

void legPart7(float colours1[], float colours2[]) {
    glPushMatrix();

    glScalef(0.1,0.1,0.1);
    drawL(colours1,colours2);
    glPopMatrix();
}

void legPart8(float colours1[], float colours2[]) {
    glPushMatrix();

    glScalef(-0.1,0.1,0.1);
    drawK(colours1,colours2);
    glPopMatrix();
}

