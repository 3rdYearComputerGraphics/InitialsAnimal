//
//  jellyBodyShape.cpp
//  GraphicsProject
//
//  Created by Jamie Johnstone on 16/11/2011.
//  Copyright 2011 Heriot Watt. All rights reserved.
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

void jellyBodyShape() {
    
    //draw left J
    glPushMatrix();
    glTranslatef(-0.1,0.15,0.0);
    glRotatef(210,0.0,0.0,1.0);
    glScalef(0.2,0.2,0.2);
    drawJ();
    glPopMatrix();
    
    //draw left R
    glPushMatrix();
    glTranslatef(-0.4,-0.01,0.0);
    //glRotatef(180,0.0,1.0,0.0);
    glScalef(-0.2,0.2,0.2);
    drawR();
    glPopMatrix();
    
    //draw right J
    glPushMatrix();
    glTranslatef(0.1,0.15,0.0);
    glRotatef(180,0.0,1.0,0.0);
    glRotatef(210,0.0,0.0,1.0);
    glScalef(0.2,0.2,0.2);
    drawJ();
    glPopMatrix();
    
    //draw right R
    glPushMatrix();
    glTranslatef(0.4,-0.01,0.0);
    glRotatef(180,0.0,1.0,0.0);
    glScalef(-0.2,0.2,0.2);
    drawR();
    glPopMatrix();
}