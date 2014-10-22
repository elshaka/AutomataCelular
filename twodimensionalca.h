#ifndef TWODIMENSIONALCA_H
#define TWODIMENSIONALCA_H

#include "cellularautomaton.h"

class TwoDimensionalCA: public CellularAutomaton
{
    Q_OBJECT
public:
    TwoDimensionalCA(QObject *parent = 0);
    virtual void randomize();

signals:

public slots:
    virtual void simulate();
};
#endif // TWODIMENSIONALCA_H
