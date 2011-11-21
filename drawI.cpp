//
//  drawI.cpp
//  GraphicsProject
//
//  Created by Jamie Johnstone & Lewis McLean on 02/11/2011.
//  Copyright 2011 Heriot-Watt University. All rights reserved.
//
//

#include <stdlib.h>
#include <GLUT/glut.h>
#include <math.h>
#include <stdio.h>
#include "drawI.h"
#include "cube.h"
#include "3DCurve.h"

void drawI(float colours1[], float colours2[]) {
    
    
    //vertical of I
    glPushMatrix();
    glTranslatef(-0.75,-0.6,0.0);
    
    glPushMatrix();
    glTranslatef(0.75,-0.6,0.0);
    //glRotatef(90,1.0,0.0,0.0);
    glScalef(0.5,2.1,0.5);
    cube(0,1,2,3,4,5,6,7,colours1,colours2);
    glPopMatrix();
    
    //curve of I
    glPushMatrix();
    glTranslatef(0.75,1.1,0.0);
    //glRotatef(90,0.0,1.0,0.0);
    glScalef(0.2,0.2,0.2);
    draw3Dcurve  (1.0,          //depth  
				  0.95,          //inner radius
				  2.05,          //outer radius
				  0,          //start angle
				  360,  //stop angle
				  5.0,
                  colours1, colours2);
    glPopMatrix();
    glPopMatrix();
}   