#ifndef ONEDIMENSIONALCA_H
#define ONEDIMENSIONALCA_H

#include "cellularautomaton.h"

class OneDimensionalCA : public CellularAutomaton {
    Q_OBJECT
    int rule[8];
public:
    OneDimensionalCA(QObject *parent = 0);
public slots:
    void setRule(int rule);
    virtual void randomize();
    virtual void simulate();
};

#endif // ONEDIMENSIONALCA_H
