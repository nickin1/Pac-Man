#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include <QKeyEvent>
#include <field.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    //void testFunc();

    void endGame();
    void pauseGame();

private slots:
    void timerTick();
    //void updateField();
    void keyPressEvent(QKeyEvent * event);



    void on_Pause_clicked();

private:
    Ui::MainWindow *ui;
    QTimer * timer;
    int time = 0;

    QString fieldOutput;
    int currentKey;
    int nextKey;

    Field * field;
};

#endif // MAINWINDOW_H
