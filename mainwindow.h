#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QGraphicsScene>
#include "cell.h"
#include "environment.h"
#include <QDebug>


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    Environment* environment;
    Cell* cells[MATRIX_SIZE][MATRIX_SIZE];
    explicit MainWindow(QWidget *parent = 0);
    void showEvent(QShowEvent *event);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
