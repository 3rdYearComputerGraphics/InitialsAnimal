//
//  drawJ.cpp
//  Computer Graphics Initials
//
//  Created by Jamie Johnstone on 05/10/2011.
//  Copyright 2011 Heriot-Watt University. All rights reserved.
//

#include <stdlib.h>
#include <GLUT/glut.h>
#include <math.h>
#include <stdio.h>
#include "drawJ.h"
#include "cube.h"
#include "3DCurve.h"

void drawJ() {
    
    //horizontal of J
    glPushMatrix();
    glTranslatef(0.0,1.25,0.0);
    glRotatef(90,0.0,0.0,1.0);
    glScalef(0.5,2.0,0.5);
    cube(0,1,2,3,4,5,6,7);
    glPopMatrix();
    
    //vertical of J
    glPushMatrix();
    glTranslatef(0.75,0.15,0.0);
    //glRotatef(90,1.0,0.0,0.0);
    glScalef(0.5,1.7,0.5);
    cube(0,1,2,3,4,5,6,7);
    glPopMatrix();
    
    //curve of J
    glPushMatrix();
    glTranslatef(0.0,-0.7,0.0);
    //glRotatef(90,0.0,1.0,0.0);
    glScalef(0.5,0.5,0.5);
    draw3Dcurve  (1.0,          //depth  
				  0.95,          //inner radius
				  2.05,          //outer radius
				  180.0,          //start angle
				  360.0,  //stop angle
				  5.0);
    glPopMatrix();
}   