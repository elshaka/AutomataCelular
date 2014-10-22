#include "cell.h"

Cell::Cell(int x, int y, int height, int width) : QGraphicsRectItem(x, y, height, width) {
    setAlive(false);
    setNextAlive(false);
}

bool Cell::isAlive() {
    return alive;
}

bool Cell::willLive() {
     return nextAlive;
}

void Cell::setAlive(bool alive) {
    this->alive = alive;
    setBrush(alive ? Qt::black : Qt::white);
}

void Cell::setNextAlive(bool nextAlive){
     this->nextAlive = nextAlive;
}

void Cell::mousePressEvent(QGraphicsSceneMouseEvent * event) {
    setAlive(!isAlive());
}
