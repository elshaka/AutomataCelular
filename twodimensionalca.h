#ifndef TWODIMENSIONALCA_H
#define TWODIMENSIONALCA_H

#include "cellularautomaton.h"

class TwoDimensionalCA: public CellularAutomaton
{
    Q_OBJECT
public:
    TwoDimensionalCA(QObject *parent = 0);
public slots:
    virtual void randomize();
    virtual void simulate();
};
#endif // TWODIMENSIONALCA_H
