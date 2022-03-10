#pragma once

#include "globaltime.h"
#include "localtimer.h"
#include "localtimerwrapper.h"

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>

//!
//! \brief The MainWindow class Класс основного окна приложения
//!
class MainWindow : public QWidget
{
    Q_OBJECT

public:
    //!
    //! \brief MainWindow Конструктор
    //! \param parent Указатель на родительский виджет
    //!
    MainWindow( QWidget * parent = nullptr );

private:
    //!
    //! \brief globalTime Указатель на объект локального времени
    //!
    GlobalTime  * globalTime;

    //!
    //! \brief localTimer1 Указатель на первый таймер
    //!
    LocalTimerWrapper  * localTimer1;
    //!
    //! \brief localTimer2 Укащатель на второй таймер
    //!
    LocalTimerWrapper  * localTimer2;
};
