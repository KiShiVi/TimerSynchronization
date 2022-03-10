#pragma once

#include <QWidget>
#include <QLCDNumber>
#include <QTime>
#include <QTimer>

class GlobalTime: public QLCDNumber
{
    Q_OBJECT
public:
    GlobalTime();

signals:
    void secondHasPassed();

private slots:
    void onTimeoutTimingTimer();

private:
};
