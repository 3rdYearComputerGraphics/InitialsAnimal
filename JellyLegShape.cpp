//
//  jellyLegShape.cpp
//  GraphicsProject
//
//  Created by Jamie Johnstone & Lewis McLean on 04/10/2011.
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


void jellyLegShape(double array[]);
void legPart();
void legPart1();
void legPart2();
void legPart3();
void legPart4();
void legPart5();
void legPart6();
void legPart7();
void legPart8();

void jellyLegShape(double array[])
{
    
    glPushMatrix();

    glRotated( array[1], 0,0,1 ) ;
    legPart1();
    
    glPushMatrix();
    glTranslatef(-0.02,-0.3,0.0);
    glRotated( array[2], 0,0,1 ) ;
    legPart2();
  
    glPushMatrix();
    glTranslatef(-0.0,-0.22,0.0);
    glRotated( array[3], 0,0,1 ) ;
    legPart3();

    glPushMatrix();
    glTranslatef(0.0,-0.28,0.0);
    glRotated( array[4], 0,0,1 ) ;
    legPart4();

    glPushMatrix();
    glTranslatef(0,-0.27,0.0);
    glRotated( array[5], 0,0,1 ) ;
    legPart5();

    glPushMatrix();
    glTranslatef(0,-0.35,0.0);
    glRotated( array[6], 0,0,1 ) ;
    legPart6();

    glPushMatrix();
    glTranslatef(0,-0.23,0.0);
    glRotated( array[7], 0,0,1 ) ;
    legPart7();

    glPushMatrix();
    glTranslatef(-0.0,-0.26,0.0);
    glRotated( array[8], 0,0,1 ) ;
    legPart8();
    

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    

  

}

void legPart1() {
    
    glPushMatrix();

    glScalef(0.1,0.1,0.1);
    drawM();
    glPopMatrix();
}
   
void legPart2() {
    glPushMatrix();

    glScalef(-0.1,0.1,0.1);
    drawI();
    glPopMatrix();
}
    
void legPart3() {
    glPushMatrix();
    glScalef(0.1,0.1,0.1);
    drawL();
    glPopMatrix();
}
    
void legPart4() {
    glPushMatrix();

    glScalef(-0.1,0.1,0.1);
    drawK();
    glPopMatrix();
}

void legPart5() {
    
    glPushMatrix();
    glScalef(0.1,0.1,0.1);
    drawM();
    glPopMatrix();
}

void legPart6() {
    glPushMatrix();

    glScalef(-0.1,0.1,0.1);
    drawI();
    glPopMatrix();
}

void legPart7() {
    glPushMatrix();

    glScalef(0.1,0.1,0.1);
    drawL();
    glPopMatrix();
}

void legPart8() {
    glPushMatrix();

    glScalef(-0.1,0.1,0.1);
    drawK();
    glPopMatrix();
}

