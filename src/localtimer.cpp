#include "localtimer.h"

LocalTimer::LocalTimer( GlobalTime * _globalTime ): QLCDNumber( 5 ), globalTime( _globalTime )
{
    isEnable = false;
    display( QTime::currentTime().toString( "mm:ss" ) );

    localTime = new QTime;
    * localTime = QTime::currentTime();
    connect( globalTime, SIGNAL( secondHasPassed() ), SLOT( onSecondHasPassed() ) );
}

void LocalTimer::onStartTimer()
{
    isEnable = true;
}

void LocalTimer::onSetTime( const QTime time )
{
    * localTime = time;
    display( localTime->toString( "mm:ss" ) );
}

void LocalTimer::onStopTimer()
{
    isEnable = false;
}

void LocalTimer::onSecondHasPassed()
{
    if ( !isEnable )
        return;
    * localTime = localTime->addSecs( -1 );
    display( localTime->toString( "mm:ss" ) );
}
