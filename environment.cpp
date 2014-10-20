#include "environment.h"
#include <QTime>

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

void Environment::randomGame(){
  int high=1;
  int low=0;
  qsrand(QTime::currentTime().msec());
  for (int y = 0; y < MATRIX_SIZE; y++) {
      for (int x = 0; x < MATRIX_SIZE; x++){
          bool alive = qrand() % ((high + 1) - low) + low;
          cells[x][y]->setAlive(alive);
        }
    }

}

void Environment::gameOfLife(){
//calcula la vida para la siguiente generacion
  //problema con definicion de -1
  for (int y = 1; y < MATRIX_SIZE - 1; y++) {
        for (int x = 1; x < MATRIX_SIZE - 1; x++){
            int neighbors=0;
            for (int j = -1; j <= 1; j++) {
                for (int i = -1; i <= 1; i++) {
                    neighbors += cells[x+i][y+j]->isAlive() ? 1 : 0;
               }
           }
           neighbors -= cells[x][y]->isAlive() ? 1 : 0;
           if( cells[x][y]->isAlive() && (neighbors <  2)) cells[x][y]->setWillLive(0);
           else if (cells[x][y]->isAlive() && (neighbors >  3)) cells[x][y]->setWillLive(0);
           else if (cells[x][y]->isAlive() && (neighbors == 3)) cells[x][y]->setWillLive(1);
           else cells[x][y]->setWillLive(cells[x][y]->isAlive()? 1 : 0);
          }
    }
    //cargamos el futuro valor al tablero
    nextGame();
}

void Environment::nextGame(){
  for (int y = 0; y < MATRIX_SIZE - 1; y++) {
      for (int x = 0; x < MATRIX_SIZE; x++){
          cells[x][y]->setAlive(cells[x][y]->willLive());
        }
    }
}
