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


void jellyLegShape();
void legPart();
void legBigPart();
void legPart1();
void legPart2();
void legPart3();
void legPart4();
void legPart5();
void legPart6();
void legPart7();
void legPart8();

void jellyLegShape()
{

    glPushMatrix();
    legPart1();
    legPart2();
    legPart3();
    legPart4();
    legPart5();
    legPart6();
    legPart7();
    legPart8();
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

