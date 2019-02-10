#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void timerTick();
    void updateField();
    void keyPressEvent(QKeyEvent * event);
    void move(int key);

private:
    Ui::MainWindow *ui;
    char field[2][5] = {{'o', '.', '.', '#', '.'},
                        {'.', '#', '.', 'o', '.'}};
    QTimer * timer;
    int time = 0;

    const int fieldHeight = 2;
    const int fieldWidth = 5;
    QString fieldOutput;
    int key;

    int pm_x = 2;
    int pm_y = 0;
};

#endif // MAINWINDOW_H
