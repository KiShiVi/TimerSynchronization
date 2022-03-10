#include "localtimerwrapper.h"

LocalTimerWrapper::LocalTimerWrapper( GlobalTime * globalTime )
{
    localTimer      = new LocalTimer( globalTime );
    timeTimeEdit    = new QTimeEdit();
    timeTimeEdit->setDisplayFormat( "mm:ss" );

    QPushButton * setTimeButton    = new QPushButton( "Set Time" );
    QPushButton * startTimerButton = new QPushButton( "Start Timer" );
    QPushButton * stopTimerButton  = new QPushButton( "Stop Timer" );

    QHBoxLayout * buttonLayout = new QHBoxLayout( );

    buttonLayout->addWidget( setTimeButton );
    buttonLayout->addWidget( startTimerButton );
    buttonLayout->addWidget( stopTimerButton );

    QVBoxLayout * gridLayout = new QVBoxLayout( this );
    gridLayout->addWidget( localTimer );
    gridLayout->addWidget( timeTimeEdit );
    gridLayout->addLayout( buttonLayout );

    connect( setTimeButton, SIGNAL( clicked() ), this, SLOT( onSetTimeClicked() ) );

    connect( this,              SIGNAL( setTime( QTime ) ),
             localTimer,        SLOT( onSetTime( QTime ) ) );
    connect( startTimerButton,  SIGNAL( clicked() ), localTimer, SLOT( onStartTimer() ) );
    connect( stopTimerButton,   SIGNAL( clicked() ), localTimer, SLOT( onStopTimer() ) );

}

void LocalTimerWrapper::onSetTimeClicked()
{
    emit setTime( timeTimeEdit->time() );
}
