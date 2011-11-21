//
//  Timer.cpp
//  init
//
//  Created by Lewis McLean on 21/11/2011.
//  Copyright (c) 2011 Heriot Watt. All rights reserved.
//


#include <GLUT/glut.h>


class Timer
{
public:
    Timer(): 
    _lastValue( 0 ), _stopped( true ) 
    {}
    

void stop()
{ 
    _lastValue= getValue() ; _stopped= true ; 
}

void start()
{ 
    _tStart= glutGet( GLUT_ELAPSED_TIME ) ; _stopped= false ; 
}

void reset()
{ 
    _lastValue= 0 ; _tStart= glutGet( GLUT_ELAPSED_TIME ) ; 
} 

bool isStopped()
{ 
    return _stopped ; 
}

double getValue()
{ 
    return _stopped ? _lastValue : _lastValue + (glutGet( GLUT_ELAPSED_TIME ) - _tStart) ; 
} 
    
private:
    double       _lastValue ; // counter when clock stopped last
    unsigned int _tStart ;    // when clock (re)started
    bool         _stopped ;   // is clock stopped?
} ;
