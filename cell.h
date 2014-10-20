#ifndef CELL_H
#define CELL_H

#include <QGraphicsRectItem>
#include <QBrush>

class Cell : public QGraphicsRectItem {
    bool alive;
public:
    Cell(int x, int y, int height, int width);
    void setAlive(bool alive);
    bool isAlive();
};

#endif // CELL_H
