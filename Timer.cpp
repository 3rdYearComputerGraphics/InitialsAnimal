//
//  Timer.cpp
//  init
//
//  Created by Jamie Johnstone & Lewis McLean on 17/11/2011.
//  Copyright (c) 2011 Heriot Watt. All rights reserved.
//
//


#include <GLUT/glut.h>


class Timer
{

private:
    double       _lastValue ; // counter when clock stopped last
    unsigned int _tStart ;    // when clock (re)started
    bool         _stopped ;   // is clock stopped?
    
public:
    Timer(): 
    _lastValue( 0 ), _stopped( true ) 
    {}
    

void stop()
{ 
    _lastValue= getValue() ;
    _stopped= true ; 
}

void start()
{ 
    _tStart= glutGet( GLUT_ELAPSED_TIME ) ;
    _stopped= false ; 
}

bool isStopped()
{ 
    return _stopped ; 
}

double getValue()
{ 
    if(_stopped) return _lastValue ;
    else{ return _lastValue + (glutGet( GLUT_ELAPSED_TIME ) - _tStart) ; }  

} 
    

} ;
