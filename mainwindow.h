#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define MATRIX_SIZE 41

#include <QMainWindow>
#include <QGraphicsScene>
#include "cell.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    QGraphicsScene* scene;
    Cell* cells[MATRIX_SIZE][MATRIX_SIZE];
    explicit MainWindow(QWidget *parent = 0);
    void showEvent(QShowEvent *event);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
