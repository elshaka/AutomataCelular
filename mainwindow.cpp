#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    timer = new QTimer(this);
    oneDimensionalCA = new OneDimensionalCA(this);
    twoDimensionalCA = new TwoDimensionalCA(this);
    currentCA = oneDimensionalCA;
    ui->graphicsView->setScene(currentCA);
    ((OneDimensionalCA*) oneDimensionalCA)->setRule(ui->ruleSpinBox->value());

    connect(ui->oneDimensionalButton, SIGNAL(toggled(bool)), this, SLOT(changeAutomaton(bool)));
    connect(ui->ruleSpinBox, SIGNAL(valueChanged(int)), (OneDimensionalCA*) oneDimensionalCA, SLOT(setRule(int)));
    connect(ui->runButton, SIGNAL(clicked()), this, SLOT(simulate()));
    connect(ui->stopButton, SIGNAL(clicked()), this, SLOT(simulate()));
    connectWithCurrentCA();
}

void MainWindow::showEvent(QShowEvent* event) {
    QWidget::showEvent(event);
    currentCA->render(getCellHeight(), getCellWidth());
}

void MainWindow::simulate() {
    bool run = sender() == ui->runButton;
    if (run)
        timer->start(100);
    else
        timer->stop();

    ui->runButton->setEnabled(!run);
    ui->stopButton->setEnabled(run);
}

void MainWindow::connectWithCurrentCA() {
    connect(ui->clearButton, SIGNAL(clicked()), currentCA, SLOT(clearCells()));
    connect(ui->randomizeButton, SIGNAL(clicked()), currentCA, SLOT(randomize()));
    connect(timer, SIGNAL(timeout()), currentCA, SLOT(simulate()));
}

void MainWindow::changeAutomaton(bool oneDimensional) {
    currentCA = oneDimensional ? oneDimensionalCA : twoDimensionalCA;
    ui->graphicsView->setScene(currentCA);
    connectWithCurrentCA();
    currentCA->render(getCellHeight(), getCellWidth());
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
