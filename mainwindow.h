#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include "cell.h"
#include "onedimensionalca.h"
#include "twodimensionalca.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    CellularAutomaton *automaton;
    Cell* cells[MATRIX_SIZE][MATRIX_SIZE];
    explicit MainWindow(QWidget *parent = 0);
    void showEvent(QShowEvent *event);
    void enabledRule(bool enabledRule);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
