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
   // timer->start(150); //time specified in ms
    this->ui->Start->setFocusPolicy(Qt::NoFocus);
    this->ui->Pause->setFocusPolicy(Qt::NoFocus);
    this->ui->Quit->setFocusPolicy(Qt::NoFocus);

    //connect(this->ui->Start, SIGNAL(clicked()), this, SLOT(pauseGame()));


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

    ui->label->setNum(this->field->scoreCount);

    if (this->field->weaknessOn == true) {
        this->field->powerUpTimer+=0.1;
        if (this->field->powerUpTimer >= 10.0) {
            this->field->weaknessOn = false;
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
        if (field->weaknessOn) {

            field->g_x = 10;
            field->g_y = 9;

            field->scoreCount += 200;

            field->weaknessOn = false;
        }
        else {
            endGame();
        }
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

void MainWindow::quitGame() {
    this->~MainWindow();
}

void MainWindow::pauseGame() {
    if (field->gamePaused) {
        ui->Pause->setText("Pause");
        field->gamePaused = false;
    }
    else {
        ui->Pause->setText("Unpause");
        field->gamePaused = true;
    }
}


void MainWindow::resetGame() {
    field->restart();
    timer->stop();
    currentKey = 0;
    nextKey = 0;
}

void MainWindow::on_Pause_clicked()
{
    pauseGame();
}

void MainWindow::on_Quit_clicked()
{
    quitGame();
}

void MainWindow::on_Start_clicked()
{
    if (field->gameStarted){
        field->gameStarted = false;
        resetGame();
        ui->Start->setText("Start");

    }
    else {
        field->gameStarted = true;
        ui->Start->setText("Reset");
        timer->start(150); //time specified in ms

    }
}
