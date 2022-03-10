#include "mainwindow.h"

MainWindow::MainWindow( QWidget * parent )
    : QWidget( parent )
{
    setMinimumSize( 500, 500 );

    globalTime   = new GlobalTime();
    localTimer1  = new LocalTimerWrapper( globalTime );
    localTimer2  = new LocalTimerWrapper( globalTime );

    QVBoxLayout * gridLayout    = new QVBoxLayout( this );
    QHBoxLayout * timerLayout   = new QHBoxLayout;
    timerLayout->addWidget( localTimer1 );
    timerLayout->addWidget( localTimer2 );

    gridLayout->addWidget( globalTime );
    gridLayout->addLayout( timerLayout );
}

