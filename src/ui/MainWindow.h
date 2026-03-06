//
// Created by alex on 3/6/26.
//

#ifndef TOMATOTIMER_MAINWINDOW_H
#define TOMATOTIMER_MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include "PomodoroSession.h"

namespace ui {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onToggleClicked();
    void onResetClicked();

    void onTick();

private:
    QLabel *timeLabel;
    QPushButton *toggleButton;
    QPushButton *resetButton;

    QTimer tickTimer;
    core::PomodoroSession session;
};


};


#endif //TOMATOTIMER_MAINWINDOW_H