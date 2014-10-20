#include "cell.h"

Cell::Cell(int x, int y, int height, int width) : QGraphicsRectItem(x, y, height, width) {
    setAlive(false);
}

bool Cell::isAlive() {
    return this->alive;
}

void Cell::setAlive(bool alive) {
    this->setBrush(alive ? Qt::black : Qt::white);
    this->alive = alive;
}
