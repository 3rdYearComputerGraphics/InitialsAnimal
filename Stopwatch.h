// Stopwatch.h
// NKU CSC 480 (1998-2005) - Kirby 
// ---------------------------------------------------------
// A stop/start-able stopwatch that accumulates milliseconds.
// For use in animation programs.
// ---------------------------------------------------------


#include <GLUT/glut.h>


class Stopwatch
{
public:
    Stopwatch() 
    : _lastValue( 0 )
    , _stopped( true ) 
    {}
    
    // Mutators
    void   stop()      { _lastValue= getValue() ; _stopped= true ; }
    void   start()     { _tStart= glutGet( GLUT_ELAPSED_TIME ) ; _stopped= false ; }
    void   reset()     { _lastValue= 0 ; _tStart= glutGet( GLUT_ELAPSED_TIME ) ; } 
    
    // Inspectors
    bool   isStopped() const { return _stopped ; }
    double getValue()  const { return _stopped ? _lastValue : _lastValue + (glutGet( GLUT_ELAPSED_TIME ) - _tStart) ; } 
    
private:
    double       _lastValue ; // counter when clock stopped last
    unsigned int _tStart ;    // when clock (re)started
    bool         _stopped ;   // is clock stopped?
} ;



// ---------------------------------------------------------------------------------------
// Example: if constructed or reset at 477 msec, we might have the following history:
// 
// timeGetTime:    477 478 479 480 481 482 483 484 485 486 487 488 489 490 491 492 493 494
// value:           0   1   2   3   4   -   -   -   -   -   5   6   7   8   9   -   -   -
//             start()              stop()              start()             stop()
// ---------------------------------------------------------------------------------------

