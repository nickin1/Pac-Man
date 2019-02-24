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


private slots:
    void timerTick();
    //void updateField();
    void keyPressEvent(QKeyEvent * event);

private:
    Ui::MainWindow *ui;
    QTimer * timer;
    double time = 0;

    QString fieldOutput;
    int key;

    Field * field;
};

#endif // MAINWINDOW_H
