#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define MATRIX_SIZE 50

#include <QMainWindow>
#include <QtDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QWidget *widgetMatrix[MATRIX_SIZE][MATRIX_SIZE];
    bool boolMatrix[MATRIX_SIZE][MATRIX_SIZE];
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
