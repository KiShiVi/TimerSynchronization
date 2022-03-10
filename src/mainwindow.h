#pragma once

#include "globaltime.h"
#include "localtimer.h"
#include "localtimerwrapper.h"

#include <QWidget>
#include <QTime>
#include <QTimer>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLCDNumber>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow( QWidget * parent = nullptr );

private:
    GlobalTime  * globalTime;

    LocalTimerWrapper  * localTimer1;
    LocalTimerWrapper  * localTimer2;
};
