#ifndef CELL_H
#define CELL_H

#include <QGraphicsRectItem>
#include <QBrush>

class Cell : public QGraphicsRectItem {
    bool alive;
    bool nextAlive;
public:
    Cell(int x, int y, int height, int width);
    void setAlive(bool alive);
    void setNextAlive(bool nextAlive);
    bool isAlive();
    bool willLive();
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
};

#endif // CELL_H
