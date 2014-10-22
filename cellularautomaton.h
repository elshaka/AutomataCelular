#ifndef CELLULARAUTOMATON_H
#define CELLULARAUTOMATON_H

#define MATRIX_SIZE 51

#include <QGraphicsScene>
#include <QTime>
#include "cell.h"

class CellularAutomaton : public QGraphicsScene {
    Q_OBJECT
protected:
    Cell *cells[MATRIX_SIZE][MATRIX_SIZE];
public:
    CellularAutomaton(QObject *parent = 0);
    void render(int height, int width);
public slots:
    void clear();
    virtual void randomize() = 0;
    virtual void simulate() = 0;
};

#endif // CELLULARAUTOMATON_H
