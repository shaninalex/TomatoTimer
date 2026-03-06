//
// Created by alex on 3/6/26.
//

#include "MainWindow.h"
#include <QVBoxLayout>

namespace ui {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Tomato Timer");
    resize(400, 200);

    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    timeLabel = new QLabel("25:00", this);

    QFont font;
    font.setPointSize(32);
    font.setBold(true);

    timeLabel->setFont(font);
    timeLabel->setAlignment(Qt::AlignCenter);

    toggleButton = new QPushButton("Start", this);
    resetButton = new QPushButton("Reset", this);

    QVBoxLayout* mainLayout = new QVBoxLayout();
    QHBoxLayout* buttonLayout = new QHBoxLayout();

    buttonLayout->addWidget(toggleButton);
    buttonLayout->addWidget(resetButton);

    mainLayout->addWidget(timeLabel);
    mainLayout->addLayout(buttonLayout);

    centralWidget->setLayout(mainLayout);

    connect(toggleButton, &QPushButton::clicked, this, &MainWindow::onToggleClicked);
    connect(resetButton, &QPushButton::clicked, this, &MainWindow::onResetClicked);
    connect(&tickTimer, &QTimer::timeout, this, &MainWindow::onTick);
    tickTimer.start(1000);

    setWindowIcon(QIcon("../assets/icon.png"));
}

MainWindow::~MainWindow() = default;

void MainWindow::onToggleClicked() {
    if (session.timerState() == core::TimerState::IDLE) {
        session.start();
        toggleButton->setText("Pause");
        setWindowTitle("Tomato Timer (running)");
    } else if (session.timerState() == core::TimerState::RUNNING) {
        session.pause();
        toggleButton->setText("Resume");
        setWindowTitle("Tomato Timer (paused)");
    } else if (session.timerState() == core::TimerState::PAUSED) {
        session.resume();
        toggleButton->setText("Pause");
        setWindowTitle("Tomato Timer (running)");
    }
}

void MainWindow::onResetClicked() {
    session.reset();
    setWindowTitle("Tomato Timer");
}

void MainWindow::onTick() {
    session.update(std::chrono::seconds(1));
    auto remaining = session.remaining().count();

    int minutes = remaining / 60;
    int seconds = remaining % 60;

    QString text = QString("%1:%2")
        .arg(minutes, 2, 10, QChar('0'))
        .arg(seconds, 2, 10, QChar('0'));

    timeLabel->setText(text);
}

}
