#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(Qt::white);
    ui->graphicsView->setScene(scene);
}

void MainWindow::showEvent(QShowEvent* event) {
    QWidget::showEvent(event);

    int height = ui->graphicsView->geometry().height() / MATRIX_SIZE;
    int width = ui->graphicsView->geometry().width() / MATRIX_SIZE;

    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            QGraphicsRectItem* rect = new QGraphicsRectItem(i * height, j * width, height, width);
            qGraphicsRectMatrix[i][j] = rect;
            boolMatrix[i][j] = false;
            scene->addItem(rect);
        }
    }

    // Inicializacion de celula del centro
    qGraphicsRectMatrix[(MATRIX_SIZE - 1) / 2][0]->setBrush(Qt::black);
    boolMatrix[0][(MATRIX_SIZE - 1) / 2] = true;

    // Reglas
    //int reglas[] = {0, 0, 1, 1, 1, 1, 0, 0}; // 60
    //int reglas[] = {0, 0, 0, 1, 1, 1, 1, 0}; // 30
    //int reglas[] = {1, 0, 1, 1, 0, 1, 1, 0}; // 182
    int reglas[] = {0, 1, 0, 1, 1, 0, 1, 0}; // 90

    // El juego mierdero de la vida
    int izq, cent, der;
    for (int i = 0; i < MATRIX_SIZE - 1; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            // Izquierda
            if (j == 0)
                izq = 0;
            else
                izq = boolMatrix[i][j - 1] ? 1 : 0;
            // Centro
            cent = boolMatrix[i][j] ? 1 : 0;
            // Derecha
            if (j == MATRIX_SIZE - 1)
                der = 0;
            else
                der = boolMatrix[i][j + 1]? 1 : 0;

            // Evaluar regla
            bool visible = reglas[izq * 4 + cent * 2 + der * 1] == 1;
            if (visible) {
                qGraphicsRectMatrix[j][i + 1]->setBrush(Qt::black);
                boolMatrix[i + 1][j] = visible;
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
