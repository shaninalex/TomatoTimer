//
// Created by alex on 3/6/26.
//

#ifndef TOMATOTIMER_MAINWINDOW_H
#define TOMATOTIMER_MAINWINDOW_H

#include <QMainWindow>

namespace ui {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};


};


#endif //TOMATOTIMER_MAINWINDOW_H