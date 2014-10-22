#include "onedimensionalca.h"

OneDimensionalCA::OneDimensionalCA(QObject *parent) : CellularAutomaton(parent) {}

void OneDimensionalCA::setRule(int rule) {
    for (int i = 0; i < 8; i++)
        this->rule[i] = rule & (1 << i);
}

void OneDimensionalCA::randomize() {
    qsrand(QTime::currentTime().msec());
    for (int x = 0; x < MATRIX_SIZE; x++)
        cells[x][0]->setAlive(qrand() % 2);
    for (int y = 1; y < MATRIX_SIZE; y++)
        for (int x = 0; x < MATRIX_SIZE; x++)
            cells[x][y]->setAlive(false);
}

void OneDimensionalCA::simulate() {
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

            cells[i][j + 1]->setAlive(rule[left * 4 + center * 2 + right * 1]);
        }
    }
}
