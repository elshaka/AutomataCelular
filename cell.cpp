#include "cell.h"

Cell::Cell(int x, int y, int height, int width) : QGraphicsRectItem(x, y, height, width) {
    setAlive(false);
    this->setPen(QPen( Qt::gray, 1, Qt::SolidLine));


}

bool Cell::isAlive() {
    return this->alive;
}

bool Cell::willLive(){
     return this->thisWillLive;
}

void Cell::setAlive(bool alive) {
    this->setBrush(alive ? Qt::black : Qt::white);
    this->alive = alive;
}

void Cell::setWillLive(bool willLive){
     this->thisWillLive=willLive;
}
