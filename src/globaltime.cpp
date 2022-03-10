#include "globaltime.h"

GlobalTime::GlobalTime() : QLCDNumber( 8 )
{
    QTimer * timingTimer = new QTimer;
    connect( timingTimer, SIGNAL( timeout() ), SLOT( onTimeoutTimingTimer() ) );
    timingTimer->start( 1000 );

    display( QTime::currentTime().toString( "hh:mm:ss" ) );
}

void GlobalTime::onTimeoutTimingTimer()
{
    display( QTime::currentTime().toString( "hh:mm:ss" ) );
    emit secondHasPassed();
}
