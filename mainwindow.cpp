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
    timer->start(150); //time specified in ms


    field = new Field;
    ui->verticalLayout->addWidget(field);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}

void MainWindow::timerTick() {
    time+=0.150;
    ui->time->setNum(time);
    this->field->moved(currentKey);
    update();
    this->field->ifCoin();
    ui->label->setNum(this->field->coinCount);

}

void MainWindow::keyPressEvent(QKeyEvent * event) {
    nextKey = event->key();
    if(this->field->moved(nextKey)){
        currentKey = nextKey;
    }
    else {
        this->field->moved(currentKey);
    }

}


























