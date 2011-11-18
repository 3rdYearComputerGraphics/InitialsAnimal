//
//  jellyBodyShape.cpp
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

void jellyBodyShape(float breatheRCurve,float breatheJCurve,float breatheRDiag) {
    
    //draw left J
    glPushMatrix();
    glTranslatef(-0.1,0.25,0.0);
    glRotatef(210,0.0,0.0,1.0);
    glScalef(0.2,0.2,0.2);
    drawJ(breatheJCurve);
    glPopMatrix();
    
    //draw left R
    glPushMatrix();
    glTranslatef(-0.4,-0.01,0.0);
    //glRotatef(180,0.0,1.0,0.0);
    glScalef(-0.2,0.2,0.2);
    drawR(breatheRCurve,breatheRDiag);
    glPopMatrix();
    
    //draw right J
    glPushMatrix();
    glTranslatef(0.1,0.25,0.0);
    glRotatef(180,0.0,1.0,0.0);
    glRotatef(210,0.0,0.0,1.0);
    glScalef(0.2,0.2,0.2);
    drawJ(breatheJCurve);
    glPopMatrix();
    
    //draw right R
    glPushMatrix();
    glTranslatef(0.4,-0.01,0.0);
    glRotatef(180,0.0,1.0,0.0);
    glScalef(-0.2,0.2,0.2);
    drawR(breatheRCurve,breatheRDiag);
    glPopMatrix();
}