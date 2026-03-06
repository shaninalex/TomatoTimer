//
// Created by alex on 3/6/26.
//

#include "MainWindow.h"

namespace ui {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Tomato Timer");
    resize(400, 200);
}

MainWindow::~MainWindow() = default;

}
