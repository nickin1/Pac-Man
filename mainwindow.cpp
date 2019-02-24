#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "field.h"
#include <QTimer>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerTick()));
    timer->start(100); //time specified in ms


    field = new Field;
    ui->verticalLayout->addWidget(field);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}

void MainWindow::timerTick() {
    time+=0.1;
    ui->time->setNum(time);
    this->field->move(key);
    update();

}

void MainWindow::keyPressEvent(QKeyEvent * event) {
    key = event->key();

}


























