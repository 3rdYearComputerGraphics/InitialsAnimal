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

void jellyLegShape() {
    
    glPushMatrix();
    glTranslatef(0,-0.3,0.0);
    glRotatef(90,0,0,1);
    glScalef(0.1,0.1,0.1);
    drawM();
    glPopMatrix();
    
   
    glPushMatrix();
    glTranslatef(0.22,-0.45,0.0);
    glRotatef(180,1.0,0.0,0.0);
    glScalef(-0.1,0.1,0.1);
    drawI();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.1,-0.7,0.0);
    glRotatef(180,0.0,1.0,0.0);
    glRotatef(180,0.0,0.0,1.0);
    glScalef(0.1,0.1,0.1);
    drawL();
    glPopMatrix();
    

    glPushMatrix();
    glTranslatef(-0.03,-0.98,0.0);
    glRotatef(180,0.0,1.0,0.0);
    glScalef(-0.1,0.1,0.1);
    drawK();
    glPopMatrix();
}