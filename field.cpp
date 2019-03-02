#include "field.h"
#include <QTime>
#include <QTimer>
#include <QtWidgets>
#include "mainwindow.h"

Field::Field(QWidget *parent) : QWidget(parent)
{

    wall_color = QColor(0, 0, 255, 255);
    coin_color = QColor(223, 201, 56, 255);
    cherry_color = QColor(255, 0, 0, 255);
    blank_color = QColor(0, 0, 0, 255);
    player_color = QColor(255, 255, 0, 255);
    ghost_color = QColor(255, 102, 255, 255);
}
void Field::paintEvent(QPaintEvent * Event) {

    QPainter painter(this);
    painter.fillRect(0, 0, 900, 450, wall_color);

    for (int i = 0; i < fieldWidth; ++i) {
        for (int j = 0; j < fieldHeight; ++j) {
            switch(fieldAscii[j][i]) {
                case '#':

                    painter.fillRect(i*150, j*150, 150, 150, wall_color);
                break;

                case 'o':

                    painter.fillRect(i*150, j*150, 150, 150, coin_color);
                break;

                case '.':

                    painter.fillRect(i*150, j*150, 150, 150, blank_color);
                break;

            }
        }
    }

    painter.fillRect(pm_x*150, pm_y*150, 150, 150, player_color);



}

//if there is a coin, pick it up and add to coin counter.
void Field::ifCoin() {
    if (fieldAscii[pm_y][pm_x] == 'o') {
        fieldAscii[pm_y][pm_x] = '.';
        coinCount++;
    }
}

//returns true if it is possible to move in that direction, starts moving if possible; otherwise false.
void Field::move(int key) {
    switch (key)
      {
     case Qt::Key_Up:
        if (pm_y != 0 && fieldAscii[pm_y-1][pm_x] != '#') {
            pm_y = pm_y - 1;
        }

       break;

     case  Qt::Key_Down:
        if (pm_y != fieldHeight - 1 && fieldAscii[pm_y+1][pm_x] != '#') {
            pm_y = pm_y + 1;
        }
       break;

     case  Qt::Key_Left:
        if (pm_x != 0 && fieldAscii[pm_y][pm_x - 1] != '#') {
            pm_x = pm_x - 1;
        }
       break;

     case Qt::Key_Right:
        if (pm_x != fieldWidth - 1 && fieldAscii[pm_y][pm_x + 1] != '#') {
            pm_x = pm_x + 1;
        }
       break;
       }
}


bool Field::canMove(int key) {
    switch (key)
      {
     case Qt::Key_Up:
        if (pm_y != 0 && fieldAscii[pm_y-1][pm_x] != '#') {
            return true;
        }

       break;

     case  Qt::Key_Down:
        if (pm_y != fieldHeight - 1 && fieldAscii[pm_y+1][pm_x] != '#') {
            return true;
        }
       break;

     case  Qt::Key_Left:
        if (pm_x != 0 && fieldAscii[pm_y][pm_x - 1] != '#') {
            return true;
        }
       break;

     case Qt::Key_Right:
        if (pm_x != fieldWidth - 1 && fieldAscii[pm_y][pm_x + 1] != '#') {
            return true;
        }
       break;
       }

    return false;
}

















