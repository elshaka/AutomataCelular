#include "twodimensionalca.h"

TwoDimensionalCA::TwoDimensionalCA(QObject *parent) : CellularAutomaton(parent) {}

void TwoDimensionalCA::randomize(){
    qsrand(QTime::currentTime().msec());
    for (int y = 1; y < MATRIX_SIZE - 1; y++)
        for (int x = 1; x < MATRIX_SIZE - 1; x++)
            cells[x][y]->setAlive(qrand() % 2 == 1);
}

void TwoDimensionalCA::simulate() {
    for (int y = 1; y < MATRIX_SIZE - 1; y++) {
        for (int x = 1; x < MATRIX_SIZE - 1; x++) {
            int neighbors = 0;
            for (int j = -1; j <= 1; j++)
                for (int i = -1; i <= 1; i++)
                    neighbors += cells[x+i][y+j]->isAlive();
            neighbors -= cells[x][y]->isAlive();

            if (cells[x][y]->isAlive() && (neighbors < 2)) cells[x][y]->setNextAlive(false);
            else if (cells[x][y]->isAlive() && (neighbors > 3)) cells[x][y]->setNextAlive(false);
            else if (!cells[x][y]->isAlive() && (neighbors == 3)) cells[x][y]->setNextAlive(true);
            else cells[x][y]->setNextAlive(cells[x][y]->isAlive());
        }
    }

    for (int y = 1; y < MATRIX_SIZE - 1; y++)
        for (int x = 1; x < MATRIX_SIZE - 1; x++)
            cells[x][y]->setAlive(cells[x][y]->willLive());
}
