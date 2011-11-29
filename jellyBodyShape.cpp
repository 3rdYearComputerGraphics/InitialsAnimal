//
//  jellyBodyShape.cpp
//  GraphicsProject
//
//  Created by Jamie Johnstone & Lewis McLean on 16/11/2011.
//  Copyright 2011 Heriot-Watt University. All rights reserved.
//
// Arguments:
// float colours1 holds the array with the values for the front face
// float colours2 holds the array with the values for the front face
// float breatheRCurve controls the scale of the letter R
// float breatheJCurve controls the scale of the letter J
// float breatheRDiag controls the angle of the R within the body

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

void jellyBodyShape(float breatheRCurve,float breatheJCurve,float breatheRDiag,float colours1[], float colours2[]) {
    
    //draw left J
    glPushMatrix();
    glTranslatef(-0.1,0.25,0.0);
    glRotatef(210,0.0,0.0,1.0);
    glScalef(0.2,0.2,0.2);
    drawJ(breatheJCurve,colours1,colours2);
    glPopMatrix();
    
    //draw left R
    glPushMatrix();
    glTranslatef(-0.4,-0.01,0.0);
    //glRotatef(180,0.0,1.0,0.0);
    glScalef(-0.2,0.2,0.2);
    drawR(breatheRCurve,breatheRDiag,colours1,colours2);
    glPopMatrix();
    
    //draw right J
    glPushMatrix();
    glTranslatef(0.1,0.25,0.0);
    glRotatef(180,0.0,1.0,0.0);
    glRotatef(210,0.0,0.0,1.0);
    glScalef(0.2,0.2,0.2);
    drawJ(breatheJCurve,colours1,colours2);
    glPopMatrix();
    
    //draw right R
    glPushMatrix();
    glTranslatef(0.4,-0.01,0.0);
    glRotatef(180,0.0,1.0,0.0);
    glScalef(-0.2,0.2,0.2);
    drawR(breatheRCurve,breatheRDiag,colours1,colours2);
    glPopMatrix();
}