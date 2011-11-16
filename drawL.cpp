//
//  drawL.cpp
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
#include "drawL.h"
#include "cube.h"
#include "3DCurve.h"

void drawL() {
    
    //horizontal of L
    glPushMatrix();
    glTranslatef(1.8,-1.46,0.0);
    glRotatef(90,0.0,0.0,1.0);
    glScalef(0.5,0.7,0.5);
    cube(0,1,2,3,4,5,6,7);
    glPopMatrix();
    
    //vertical of L
    glPushMatrix();
    glTranslatef(0.75,0.15,0.0);
    //glRotatef(90,1.0,0.0,0.0);
    glScalef(0.5,2.2,0.5);
    cube(0,1,2,3,4,5,6,7);
    glPopMatrix();
    
    //curve of L
    glPushMatrix();
    glTranslatef(1.5,-0.7,0.0);
    //glRotatef(90,0.0,1.0,0.0);
    glScalef(0.5,0.5,0.5);
    draw3Dcurve  (1.0,          //depth  
				  0.95,          //inner radius
				  2.05,          //outer radius
				  180,          //start angle
				  270.0,  //stop angle
				  5.0);
    glPopMatrix();
}   