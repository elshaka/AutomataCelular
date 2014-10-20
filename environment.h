#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include "cell.h"
#define MATRIX_SIZE 51
#include <QGraphicsScene>

class Environment : public QGraphicsScene
{
public:
    Environment(QObject *parent);
    void wolframCellular();
    void gameOfLife();
    void randomGame();
    void nextGame();
    void board();
    void render(int height, int width);
    Cell* cells[MATRIX_SIZE][MATRIX_SIZE];

};

#endif // ENVIRONMENT_H
