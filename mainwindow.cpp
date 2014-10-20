#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    environment = new Environment(this);
    ui->graphicsView->setScene(environment);
}

void MainWindow::showEvent(QShowEvent* event) {
    QWidget::showEvent(event);

    int height = ui->graphicsView->geometry().height() / MATRIX_SIZE;
    int width = ui->graphicsView->geometry().width() / MATRIX_SIZE;
    environment->render(height,width);

    //modelo basico de Wolfram
    //environment->wolframCellular();

    //Juego de la vida
    environment->randomGame();
    environment->gameOfLife();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
      environment->gameOfLife();
}
