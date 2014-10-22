#include "cellularautomaton.h"

CellularAutomaton::CellularAutomaton(QObject *parent) : QGraphicsScene(parent) {
    setBackgroundBrush(Qt::white);
}

void CellularAutomaton::render(int height, int width) {
    for (int y = 0; y < MATRIX_SIZE; y++) {
        for (int x = 0; x < MATRIX_SIZE; x++) {
            Cell *cell = new Cell(x * width, y * height, height, width);
            cells[x][y] = cell;
            addItem(cell);
        }
    }
}

void CellularAutomaton::clear() {
    for (int y = 0; y < MATRIX_SIZE; y++)
        for (int x = 0; x < MATRIX_SIZE; x++)
            cells[x][y]->setAlive(false);
}
