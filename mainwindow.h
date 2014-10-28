#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include "wolfram.h"
#include "conway.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
    Ui::MainWindow *ui;
    QTimer *timer;
    int getCellHeight();
    int getCellWidth();
    void connectWithCurrentAutomaton();
public:
    CellularAutomaton *wolfram, *conway, *currentAutomaton;
    explicit MainWindow(QWidget *parent = 0);
    void showEvent(QShowEvent *event);
    ~MainWindow();
public slots:
    void changeAutomaton(bool);
    void simulate();
};

#endif // MAINWINDOW_H
