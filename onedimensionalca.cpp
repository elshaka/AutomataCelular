#include "onedimensionalca.h"

OneDimensionalCA::OneDimensionalCA(QObject *parent) : CellularAutomaton(parent) {}

void OneDimensionalCA::randomize() {
    qsrand(QTime::currentTime().msec());
    // Primera fila aleatoria
    for (int x = 0; x < MATRIX_SIZE; x++)
        cells[x][0]->setAlive(qrand() % 2 == 1);
    // Resto de filas en blanco
    for (int y = 1; y < MATRIX_SIZE; y++)
        for (int x = 0; x < MATRIX_SIZE; x++)
            cells[x][y]->setAlive(qrand() % 2);
}

void OneDimensionalCA::simulate() {
    cells[MATRIX_SIZE / 2 - 1][0]->setAlive(true);
    // Reglas
    //int rules[] = {0, 0, 1, 1, 1, 1, 0, 0}; // 60
    //int rules[] = {0, 0, 0, 1, 1, 1, 1, 0}; // 30
    int rules[] = {0, 1, 1, 0, 1, 1, 0, 1}; // 182
    //int rules[] = {0, 1, 0, 1, 1, 0, 1, 0}; // 90
    int left, center, right;

    for (int j = 0; j < MATRIX_SIZE - 1; j++) {
        for (int i = 0; i < MATRIX_SIZE; i++) {
            if (i == 0)
                left = 0;
            else
                left = cells[i - 1][j]->isAlive();

            center = cells[i][j]->isAlive();

            if (i == MATRIX_SIZE - 1)
                right = 0;
            else
                right = cells[i + 1][j]->isAlive();

            bool alive = rules[left * 4 + center * 2 + right * 1];
            cells[i][j + 1]->setAlive(alive);
        }
    }
}
