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
    timer->start(250); //time specified in ms
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}

void MainWindow::timerTick() {
    time++;
    ui->time->setNum(time);
    updateField();
    move(key);



}

void MainWindow::updateField() {



    fieldOutput = "";

    for (int i = 0; i < fieldHeight; ++i) {
        for (int j = 0; j < fieldWidth; ++j) {
            if (pm_y == i && pm_x == j) {
                fieldOutput = fieldOutput + "p ";

            }
            else {
                fieldOutput = fieldOutput + field[i][j] + ' ';
            }
        }
        fieldOutput = fieldOutput + '\n';
    }

    ui->label->setText(fieldOutput);
}

void MainWindow::keyPressEvent(QKeyEvent * event) {
    //event->key();
    key = event->key();

}


void MainWindow::move(int key) {
    switch (key)
      {
     case Qt::Key_Up:
        if (pm_y != 0 && field[pm_x][pm_y-1] != '#') {
            pm_y = pm_y - 1;
        }

       break;

     case  Qt::Key_Down:
        if (pm_y != fieldHeight - 1 && field[pm_x][pm_y+1] != '#') {
            pm_y = pm_y + 1;
        }
       break;

     case  Qt::Key_Left:
        if (pm_x != 0 && field[pm_x - 1][pm_y] != '#') {
            pm_x = pm_x - 1;
        }
       break;

     case Qt::Key_Right:
        if (pm_x != fieldWidth - 1 && field[pm_x + 1][pm_y] != '#') {
            pm_x = pm_x + 1;
        }
       break;
       }
}

























