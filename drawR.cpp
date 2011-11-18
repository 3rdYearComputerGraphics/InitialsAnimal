//
//  drawK.cpp
//  Computer Graphics Initials
//
//  Created by Jamie Johnstone & Lewis McLean on 04/10/2011.
//  Copyright 2011 Heriot-Watt University. All rights reserved.
//
//

#include <stdlib.h>
#include <GLUT/glut.h>
#include <math.h>
#include <stdio.h>
#include "drawR.h"
#include "cube.h"
#include "3DCurve.h"

void drawR(float breatheRCurve,float breatheRDiag) {
    
    //vertical of R
    glPushMatrix();
    //glTranslatef(0.0,1.2,0.0);
    //glRotatef(90,0.0,0.0,1.0);
    glScalef(0.5,3.2,0.5);
    cube(0,1,2,3,4,5,6,7);
    glPopMatrix();
    
    //straight diagonal of R
    glPushMatrix();
    glTranslatef(0.7,-0.8,0.0);
    glRotatef(breatheRDiag,0.0,0.0,1.0);
    glScalef(0.5,2.0,0.5);
    cube(0,1,2,3,4,5,6,7);
    glPopMatrix();
    
    //curve of R
    glPushMatrix();
    glTranslatef(0.2,0.65,0.0);
    glRotatef(180,0.0,1.0,0.0);
    glScalef(breatheRCurve,1.0,1.0);
    draw3Dcurve  (0.52,          //depth  
				  0.5,          //inner radius
				  0.95,          //outer radius
				  90.0,          //start angle
				  270.0,  //stop angle
				  5.0);
    glPopMatrix();
}   