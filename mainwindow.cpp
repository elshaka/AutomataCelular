#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget *w, *ww;
    QVBoxLayout *l;

    // Creación
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            w = new QWidget(this);
            ww = new QWidget(this);
            l = new QVBoxLayout(ww);
            l->setMargin(0);
            w->setStyleSheet("background: #333;");
            l->addWidget(w);
            ww->setLayout(l);
            widgetMatrix[i][j] = w;
            w->hide();
            boolMatrix[i][j] = false;
            ui->gridLayout->addWidget(ww, i, j);
        }
    }

    // Inicializacion primera fila de forma aleatoria
    qsrand(time(NULL));
    for(int j = 0; j < MATRIX_SIZE; j++) {
        bool visible = qrand() % 2 == 1;
        widgetMatrix[0][j]->setVisible(visible);
        boolMatrix[0][j] = visible;
    }

    // Reglas
    //int reglas[] = {0, 0, 1, 1, 1, 1, 0, 0}; // 60
    int reglas[] = {0, 0, 0, 1, 1, 1, 1, 0}; // 30
    //int reglas[] = {1, 0, 1, 1, 0, 1, 1, 0}; // 182

    // El juego mierdero de la vida
    int izq, cent, der;
    for (int i = 0; i < MATRIX_SIZE - 1; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            // Izquierda
            if (j == 0)
                izq = 0;
            else
                izq = boolMatrix[i][j - 1] ? 1 : 0;
            //qDebug() << "Izquierda " << izq;
            // Centro
            cent = boolMatrix[i][j] ? 1 : 0;
            // Derecha
            if (j == MATRIX_SIZE - 1)
                der = 0;
            else
                der = boolMatrix[i][j + 1]? 1 : 0;
            // Evaluar regla
            bool visible = reglas[izq * 4 + cent * 2 + der * 1] == 1;
            widgetMatrix[i + 1][j]->setVisible(visible);
            boolMatrix[i + 1][j] = visible;
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
