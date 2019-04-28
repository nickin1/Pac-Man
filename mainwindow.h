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
    void quitGame();
    void resetGame();
    void onGameWin();


private slots:
    void timerTick();
    //void updateField();
    void keyPressEvent(QKeyEvent * event);

    void on_Pause_clicked();
    void on_Quit_clicked();
    void on_Start_clicked();

private:
    Ui::MainWindow *ui;
    QTimer * timer;
    int time = 0;

    QString fieldOutput;
    int currentKey = 0;
    int nextKey = 0;

    Field * field;
};

#endif // MAINWINDOW_H
