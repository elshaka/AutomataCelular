#ifndef ONEDIMENSIONALCA_H
#define ONEDIMENSIONALCA_H

#include "cellularautomaton.h"

class OneDimensionalCA : public CellularAutomaton {
    Q_OBJECT
public:
    OneDimensionalCA(QObject *parent = 0);
    virtual void randomize();
signals:

public slots:
    virtual void simulate();
};

#endif // ONEDIMENSIONALCA_H
