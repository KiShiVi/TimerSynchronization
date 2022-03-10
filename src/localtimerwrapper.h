#pragma once

#include "globaltime.h"
#include "localtimer.h"

#include <QWidget>
#include <QPushButton>
#include <QTimeEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>

class LocalTimerWrapper: public QWidget
{
    Q_OBJECT
public:
    LocalTimerWrapper( GlobalTime * globalTime );
    LocalTimer * localTimer;

signals:
    void setTime( QTime time );

private slots:
    void onSetTimeClicked();

private:
    QTimeEdit * timeTimeEdit;
};

