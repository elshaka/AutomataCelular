#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define MATRIX_SIZE 50

#include <QMainWindow>
#include <QtDebug>
#include <QGraphicsItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QGraphicsScene* scene;
    QGraphicsRectItem* qGraphicsRectMatrix[MATRIX_SIZE][MATRIX_SIZE];
    bool boolMatrix[MATRIX_SIZE][MATRIX_SIZE];
    explicit MainWindow(QWidget *parent = 0);
    void showEvent(QShowEvent *event);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
