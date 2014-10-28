#ifndef WOLFRAM_H
#define WOLFRAM_H

#include "cellularautomaton.h"

class Wolfram : public CellularAutomaton {
    Q_OBJECT
    int rule[8];
public:
    Wolfram(QObject *parent = 0);
public slots:
    void setRule(int rule);
    virtual void randomize();
    virtual void simulate();
};

#endif // WOLFRAM_H
