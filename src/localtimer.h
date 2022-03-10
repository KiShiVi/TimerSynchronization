#pragma once

#include "globaltime.h"

#include <QWidget>
#include <QLCDNumber>
#include <QTime>
#include <QTimer>

class LocalTimer: public QLCDNumber
{
    Q_OBJECT
public:
    LocalTimer( GlobalTime * _globalTime );

public slots:
    void onStartTimer();
    void onSetTime( QTime time );
    void onStopTimer();

private slots:
    void onSecondHasPassed();

private:
    bool isEnable;
    GlobalTime  * globalTime;
    QTime       * localTime;
};
