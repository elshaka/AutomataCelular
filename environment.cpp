#include "environment.h"

Environment::Environment(QObject *parent):QGraphicsScene(parent){
    setBackgroundBrush(Qt::white);
}

void Environment::render(int height, int width){

  for (int i = 0; i < MATRIX_SIZE; i++) {
      for (int j = 0; j < MATRIX_SIZE; j++) {
          Cell* cell = new Cell(i * width, j * height, height, width);
          cells[i][j] = cell;
          addItem(cell);
      }
  }
}

void Environment::wolframCellular(){

// Inicializacion de celula del centro
cells[MATRIX_SIZE / 2 - 1][0]->setAlive(true);

// Reglas
//int rules[] = {0, 0, 1, 1, 1, 1, 0, 0}; // 60
//int rules[] = {0, 0, 0, 1, 1, 1, 1, 0}; // 30
int rules[] = {0, 1, 1, 0, 1, 1, 0, 1}; // 182
//int rules[] = {0, 1, 0, 1, 1, 0, 1, 0}; // 90

// El juego mierdero de la vida
int izq, cent, der;
for (int j = 0; j < MATRIX_SIZE - 1; j++) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        // Izquierda
        if (i == 0)
            izq = 0;
        else
            izq = cells[i - 1][j]->isAlive() ? 1 : 0;
        // Centro
            cent = cells[i][j]->isAlive() ? 1 : 0;
        // Derecha
        if (i == MATRIX_SIZE - 1)
            der = 0;
        else
            der = cells[i + 1][j]->isAlive() ? 1 : 0;

        // Evaluar regla
        bool alive = rules[izq * 4 + cent * 2 + der * 1] == 1;
        cells[i][j + 1]->setAlive(alive);
    }
}
}
