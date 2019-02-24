#ifndef FIELD_H
#define FIELD_H

#include <QObject>
#include <QWidget>
#include <QTime>
#include <QTimer>

class Field : public QWidget
{
    Q_OBJECT
public:
    explicit Field(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent * Event) override;


    int coinCount = 0;

signals:


public slots:

    bool moved(int key);
    void ifCoin();

private:
    QColor wall_color;
    QColor coin_color;
    QColor cherry_color;
    QColor blank_color;
    QColor player_color;
    QColor ghost_color;

    char fieldAscii[3][6] = {{'.', '#', '.', 'o', '.', '.'},
                             {'.', '.', '.', '#', '.', '#'},
                             {'#', '.', '#', 'o', '.', '.'}};


    const int fieldHeight = 3;
    const int fieldWidth = 6;

    int pm_x = 0;
    int pm_y = 1;



};

#endif // FIELD_H
