#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "field.h"
#include <QTimer>
#include <QKeyEvent>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerTick()));
    timer->start(150); //time specified in ms
    this->ui->pushButton->setFocusPolicy(Qt::NoFocus);

    //connect(field, SIGNAL(testSignal()), this, SLOT(testFunc()));

    field = new Field;
    ui->verticalLayout->addWidget(field);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}

void MainWindow::timerTick() {
    time+=0.100;
    ui->time->setNum(time);
    update();
    this->field->ifCoin();
    ui->label->setNum(this->field->coinCount);

    if (this->field->bufferOn == true) {
        this->field->powerUpTimer+=0.1;
        if (this->field->powerUpTimer >= 10.0) {
            this->field->bufferOn = false;
        }
        else {
            update();
        }
    }

    if(this->field->pm_move(nextKey)) {
        currentKey = nextKey;
    }
    else {
        this->field->pm_move(currentKey);
    }

        field->g_move();

}

void MainWindow::keyPressEvent(QKeyEvent * event) {
    nextKey = event->key();
}

/*
void MainWindow::testFunc() {
    qDebug() << "Works!";
}
*/























