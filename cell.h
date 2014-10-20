#ifndef CELL_H
#define CELL_H

#include <QGraphicsRectItem>
#include <QBrush>
#include <QPen>
class Cell : public QGraphicsRectItem {
    bool alive;
    bool thisWillLive;
public:
    Cell(int x, int y, int height, int width);
    void setAlive(bool alive);
    void setWillLive(bool willLive);
    bool isAlive();
    bool willLive();
};

#endif // CELL_H
