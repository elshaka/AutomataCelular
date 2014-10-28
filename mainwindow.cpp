#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    timer = new QTimer(this);
    timer->setInterval(200);
    wolfram = new Wolfram(this);
    conway = new Conway(this);
    currentAutomaton = wolfram;
    ui->graphicsView->setScene(currentAutomaton);
    ((Wolfram*) wolfram)->setRule(ui->ruleSpinBox->value());

    connect(ui->oneDimensionalButton, SIGNAL(toggled(bool)), this, SLOT(changeAutomaton(bool)));
    connect(ui->ruleSpinBox, SIGNAL(valueChanged(int)), (Wolfram*) wolfram, SLOT(setRule(int)));
    connect(ui->runButton, SIGNAL(clicked()), this, SLOT(simulate()));
    connect(ui->stopButton, SIGNAL(clicked()), this, SLOT(simulate()));
    connectWithCurrentAutomaton();
}

void MainWindow::showEvent(QShowEvent* event) {
    QWidget::showEvent(event);
    currentAutomaton->render(getCellHeight(), getCellWidth());
}

void MainWindow::simulate() {
    bool run = sender() == ui->runButton;
    if (run)
        timer->start();
    else
        timer->stop();

    ui->runButton->setEnabled(!run);
    ui->stopButton->setEnabled(run);
}

void MainWindow::connectWithCurrentAutomaton() {
    connect(ui->clearButton, SIGNAL(clicked()), currentAutomaton, SLOT(clear()));
    connect(ui->randomizeButton, SIGNAL(clicked()), currentAutomaton, SLOT(randomize()));
    connect(timer, SIGNAL(timeout()), currentAutomaton, SLOT(simulate()));
}

void MainWindow::changeAutomaton(bool oneDimensional) {
    currentAutomaton = oneDimensional ? wolfram : conway;
    ui->graphicsView->setScene(currentAutomaton);
    connectWithCurrentAutomaton();
    currentAutomaton->render(getCellHeight(), getCellWidth());
    ui->ruleBox->setVisible(oneDimensional);
}

int MainWindow::getCellHeight() {
    return ui->graphicsView->geometry().height() / MATRIX_SIZE;
}

int MainWindow::getCellWidth() {
    return ui->graphicsView->geometry().width() / MATRIX_SIZE;
}

MainWindow::~MainWindow() {
    delete ui;
}
