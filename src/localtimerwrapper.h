#pragma once

#include "globaltime.h"
#include "localtimer.h"

#include <QWidget>
#include <QPushButton>
#include <QTimeEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>

//!
//! \brief The LocalTimerWrapper class Класс обёртка для таймера
//!
class LocalTimerWrapper: public QWidget
{
    Q_OBJECT
public:
    //!
    //! \brief LocalTimerWrapper Конструктор
    //! \param globalTime Указатель на объект локального времени (для синхронизации)
    //!
    LocalTimerWrapper( GlobalTime * globalTime );
    //!
    //! \brief localTimer Указатель на таймер
    //!
    LocalTimer * localTimer;

signals:
    //!
    //! \brief setTime Сигнал, испускаемый в таймер для задачи времени
    //! \param time
    //!
    void setTime( QTime time );

private slots:
    //!
    //! \brief onSetTimeClicked Слот, связанный с кнопкой задачи времени на таймере
    //!
    void onSetTimeClicked();

private:
    //!
    //! \brief timeTimeEdit Указатель на редактируемое поле QTimeEdit (для задачи времени)
    //!
    QTimeEdit * timeTimeEdit;
};

