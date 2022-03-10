#pragma once

#include <QLCDNumber>
#include <QTime>
#include <QTimer>

//!
//! \brief The GlobalTime class Класс для отображения локального времени
//!
class GlobalTime: public QLCDNumber
{
    Q_OBJECT
public:
    //!
    //! \brief GlobalTime Конструктор
    //!
    GlobalTime();

signals:
    //!
    //! \brief secondHasPassed Сигнал, который испускается каждый раз, когда локальное
    //! время увеличивается на одну секунду. Важно для синхронизации
    //!
    void secondHasPassed();

private slots:
    //!
    //! \brief onTimeoutTimingTimer Слот, который обрабатывает сигнал внутреннего таймера,
    //! чтобы фиксировать факт прохождения одной секунды
    //!
    void onTimeoutTimingTimer();
};
