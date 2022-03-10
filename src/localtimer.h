#pragma once

#include "globaltime.h"

#include <QLCDNumber>
#include <QTime>

//!
//! \brief The LocalTimer class Класс таймера
//!
class LocalTimer: public QLCDNumber
{
    Q_OBJECT
public:
    //!
    //! \brief LocalTimer Конструктор
    //! \param _globalTime Указатель на локальное время (у всех таймеров он должен быть одинаковым)
    //! Требуется для синхронизации
    //!
    LocalTimer( GlobalTime * _globalTime );

public slots:
    //!
    //! \brief onStartTimer Слот запуска таймера
    //!
    void onStartTimer();
    //!
    //! \brief onSetTime Слот установки времени на таймере
    //! \param time Время
    //!
    void onSetTime( QTime time );
    //!
    //! \brief onStopTimer Слот остановки таймера
    //!
    void onStopTimer();

private slots:
    //!
    //! \brief onSecondHasPassed Слот, который связан с объектом локального времени (GlobalTime).
    //! Срабатывает каждую секунду и делает декремент на таймере.
    //!
    void onSecondHasPassed();

private:
    //!
    //! \brief isEnable Флаг, показывающий запущен таймер или нет
    //!
    bool isEnable;
    //!
    //! \brief globalTime Указатель на объект GlobalTime локального времени
    //!
    GlobalTime  * globalTime;
    //!
    //! \brief localTime Время таймера
    //!
    QTime       * localTime;
};
