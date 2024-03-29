//
//  drawL.cpp
//  GraphicsProject
//
//  Created by Jamie Johnstone & Lewis McLean on 02/11/2011.
//  Copyright 2011 Heriot-Watt University. All rights reserved.
//
// Arguments:
// float colours1 holds the array with the values for the front face
// float colours2 holds the array with the values for the front face

#include <stdlib.h>
#include <GLUT/glut.h>
#include <math.h>
#include <stdio.h>
#include "drawM.h"
#include "cube.h"
#include "3DCurve.h"

void drawM(float colours1[], float colours2[]) {
    
    //    //horizontal of M
    glPushMatrix();
    glTranslatef(1.5,-0.2,0.0);
    glRotatef(270,0.0,0.0,1.0);
    
    //left vertical of M
    glPushMatrix();
    glTranslatef(0.0,-0.6,0.0);
    //glRotatef(90,1.0,0.0,0.0);
    glScalef(0.5,2.1,0.5);
    cube(0,1,2,3,4,5,6,7,colours1,colours2);
    glPopMatrix();
    
    //left vertical of M
    glPushMatrix();
    glTranslatef(1.5,-0.6,0.0);
    //glRotatef(90,1.0,0.0,0.0);
    glScalef(0.5,2.1,0.5);
    cube(0,1,2,3,4,5,6,7,colours1,colours2);
    glPopMatrix();
    
    //left vertical of M
    glPushMatrix();
    glTranslatef(3.0,-0.6,0.0);
    //glRotatef(90,1.0,0.0,0.0);
    glScalef(0.5,2.1,0.5);
    cube(0,1,2,3,4,5,6,7,colours1,colours2);
    glPopMatrix();
    
    //right curve of M
    glPushMatrix();
    glTranslatef(2.3,0.3,0.0);
    //glRotatef(90,0.0,1.0,0.0);
    glScalef(0.5,0.5,0.5);
    draw3Dcurve  (1.0,          //depth  
				  1.0,          //inner radius
				  2.0,
				  0,          //start angle
				  180,  //stop angle
				  5.0,colours1,colours2);
    glPopMatrix();
    
    //right curve of M
    glPushMatrix();
    glTranslatef(0.7,0.3,0.0);
    //glRotatef(90,0.0,1.0,0.0);
    glScalef(0.5,0.5,0.5);
    draw3Dcurve  (1.0,          //depth  
				  1.0,          //inner radius
				  2.0,          //outer radius
				  0,          //start angle
				  180,  //stop angle
				  5.0,colours1,colours2);
    glPopMatrix();
    glPopMatrix();
}   