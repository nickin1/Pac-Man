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
    this->ui->Start->setFocusPolicy(Qt::NoFocus);
    this->ui->Pause->setFocusPolicy(Qt::NoFocus);
    this->ui->Quit->setFocusPolicy(Qt::NoFocus);

    //connect(this->ui->Start, SIGNAL(clicked()), this, SLOT(pauseGame()));

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

    if (field->gamePaused) return;

    time+=1;
    ui->time->setNum(time/10.0);
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


    if (time*10 % 3 == 0) {
        field->g_move();
    }

    if (field->pm_x == field->g_x && field->pm_y == field->g_y) {
        endGame();
    }

}

void MainWindow::keyPressEvent(QKeyEvent * event) {
    nextKey = event->key();
}



void MainWindow::endGame() {
    field->gameOver = true;
    timer->stop();

    update();


}

void MainWindow::pauseGame() {
    if (field->gamePaused) {
        field->gamePaused = false;
        qDebug() << "unpausing";
    } else {
        field->gamePaused = true;
        qDebug() << "pausing";
    }
}


/*
void MainWindow::testFunc() {
    qDebug() << "Works!";
}
*/

void MainWindow::on_Pause_clicked()
{
    pauseGame();
}
