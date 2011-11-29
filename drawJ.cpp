//
//  drawJ.cpp
//  Computer Graphics Initials
//
//  Created by Jamie Johnstone & Lewis McLean on 04/10/2011.
//  Copyright 2011 Heriot-Watt University. All rights reserved.
//
// Arguments:
// float colours1 holds the array with the values for the front face
// float colours2 holds the array with the values for the front face
// float breatheJCurve controls the scale of the letter J

#include <stdlib.h>
#include <GLUT/glut.h>
#include <math.h>
#include <stdio.h>
#include "drawJ.h"
#include "cube.h"
#include "3DCurve.h"

void drawJ(float breatheJCurve,float colours1[], float colours2[]) {
    
    /*
    //horizontal of J
    glPushMatrix();
    glTranslatef(0.0,1.25,0.0);
    glRotatef(90,0.0,0.0,1.0);
    glScalef(0.5,2.0,0.5);
    cube(0,1,2,3,4,5,6,7);
    glPopMatrix();
     */
    
    //vertical of J
    glPushMatrix();
    glTranslatef(0.75,0.35,0.0);
    //glRotatef(90,1.0,0.0,0.0);
    glScalef(0.5,2.2,0.5);
    cube(0,1,2,3,4,5,6,7,colours1,colours2);
    glPopMatrix();
    
    //curve of J
    glPushMatrix();
    glTranslatef(0.0,-0.7,0.0);
    //glRotatef(90,0.0,1.0,0.0);
    glScalef(0.5,breatheJCurve,0.5);
    draw3Dcurve  (1.0,          //depth  
				  0.95,          //inner radius
				  2.05,          //outer radius
				  180.0,          //start angle
				  360.0,  //stop angle
				  5.0,colours1,colours2);
    glPopMatrix();
}   