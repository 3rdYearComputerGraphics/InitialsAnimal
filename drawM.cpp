//
//  drawL.cpp
//  GraphicsProject
//
//  Created by Lewis McLean on 02/11/2011.
//  Copyright 2011 Heriot Watt. All rights reserved.
//

#include <stdlib.h>
#include <GLUT/glut.h>
#include <math.h>
#include <stdio.h>
#include "drawM.h"
#include "cube.h"
#include "3DCurve.h"

void drawM() {
    
    //    //horizontal of M
    //    glPushMatrix();
    //    glTranslatef(1.8,-1.46,0.0);
    //    glRotatef(90,0.0,0.0,1.0);
    //    glScalef(0.5,1.0,0.5);
    //    cube(0,1,2,3,4,5,6,7);
    //    glPopMatrix();
    
    //left vertical of M
    glPushMatrix();
    glTranslatef(0.0,0.0,0.0);
    //glRotatef(90,1.0,0.0,0.0);
    glScalef(0.5,2.2,0.5);
    cube(0,1,2,3,4,5,6,7);
    glPopMatrix();
    
    //left vertical of M
    glPushMatrix();
    glTranslatef(1.2,0.0,0.0);
    //glRotatef(90,1.0,0.0,0.0);
    glScalef(0.5,2.2,0.5);
    cube(0,1,2,3,4,5,6,7);
    glPopMatrix();
    
    //left vertical of M
    glPushMatrix();
    glTranslatef(2.4,0.0,0.0);
    //glRotatef(90,1.0,0.0,0.0);
    glScalef(0.5,2.2,0.5);
    cube(0,1,2,3,4,5,6,7);
    glPopMatrix();
    
    //right curve of M
    glPushMatrix();
    glTranslatef(1.8,0.8,0.0);
    //glRotatef(90,0.0,1.0,0.0);
    glScalef(0.5,0.5,0.5);
    draw3Dcurve  (1.0,          //depth  
				  0.7,          //inner radius
				  1.8,
				  0,          //start angle
				  180,  //stop angle
				  5.0);
    glPopMatrix();
    
    //right curve of M
    glPushMatrix();
    glTranslatef(0.6,0.8,0.0);
    //glRotatef(90,0.0,1.0,0.0);
    glScalef(0.5,0.5,0.5);
    draw3Dcurve  (1.0,          //depth  
				  0.7,          //inner radius
				  1.8,          //outer radius
				  0,          //start angle
				  180,  //stop angle
				  5.0);
    glPopMatrix();
}   