#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    //automaton = new OneDimensionalCA(this);
    automaton = new TwoDimensionalCA(this);
    ui->graphicsView->setScene(automaton);
    connect(ui->pushButton, SIGNAL(clicked()), automaton, SLOT(simulate()));
}

void MainWindow::showEvent(QShowEvent* event) {
    int height, width;

    QWidget::showEvent(event);
    height = ui->graphicsView->geometry().height() / MATRIX_SIZE;
    width = ui->graphicsView->geometry().width() / MATRIX_SIZE;
    automaton->render(height, width);
    automaton->randomize();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), automaton, SLOT(simulate()));
    timer->start(100);
}

MainWindow::~MainWindow() {
    delete ui;
}
