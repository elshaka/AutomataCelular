#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

void MainWindow::showEvent(QShowEvent* event) {
    QWidget::showEvent(event);

    scene->setBackgroundBrush(Qt::white);

    int height = ui->graphicsView->geometry().height() / MATRIX_SIZE;
    int width = ui->graphicsView->geometry().width() / MATRIX_SIZE;

    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            Cell* cell = new Cell(i * width, j * height, height, width);
            cells[i][j] = cell;
            scene->addItem(cell);
        }
    }

    // Inicializacion de celula del centro
    cells[MATRIX_SIZE / 2 - 1][0]->setAlive(true);

    // Reglas
    //int rules[] = {0, 0, 1, 1, 1, 1, 0, 0}; // 60
    //int rules[] = {0, 0, 0, 1, 1, 1, 1, 0}; // 30
    int rules[] = {1, 0, 1, 1, 0, 1, 1, 0}; // 182
    //int rules[] = {0, 1, 0, 1, 1, 0, 1, 0}; // 90

    // El juego mierdero de la vida
    int izq, cent, der;
    for (int j = 0; j < MATRIX_SIZE - 1; j++) {
        for (int i = 0; i < MATRIX_SIZE; i++) {
            // Izquierda
            if (i == 0)
                izq = 0;
            else
                izq = cells[i - 1][j]->isAlive() ? 1 : 0;
            // Centro
            cent = cells[i][j]->isAlive() ? 1 : 0;
            // Derecha
            if (i == MATRIX_SIZE - 1)
                der = 0;
            else
                der = cells[i + 1][j]->isAlive() ? 1 : 0;

            // Evaluar regla
            bool alive = rules[izq * 4 + cent * 2 + der * 1] == 1;

            cells[i][j + 1]->setAlive(alive);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
