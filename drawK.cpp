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
#include "drawK.h"
#include "cube.h"
#include "3DCurve.h"

void drawK(float colours1[], float colours2[]) {
    
    glPushMatrix();    
    glTranslatef(0.0,-1.5,0.0);
    //vertical of K
    glPushMatrix();
    glTranslatef(0.0,-0.1,0.0);
    //glRotatef(90,1.0,0.0,0.0);
    glScalef(0.5,3.2,0.5);
    cube(0,1,2,3,4,5,6,7,colours1,colours2);
    glPopMatrix();
    
    //curve of K
    glPushMatrix();
    glTranslatef(1.4,-0.1,0.0);
    //glRotatef(270,0.0,0.0,1.0);
    //glScalef(0.0,0.0,0.0);
    draw3Dcurve  (0.5,          //depth  
				  1.05,          //inner radius
				  1.6,          //outer radius
				  90.0,          //start angle
				  270.0,  //stop angle
				  5.0,colours1,colours2);
    glPopMatrix();
    glPopMatrix();
}   