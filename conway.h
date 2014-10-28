#ifndef CONWAY_H
#define CONWAY_H

#include "cellularautomaton.h"

class Conway : public CellularAutomaton {
    Q_OBJECT
public:
    Conway(QObject *parent = 0);
public slots:
    virtual void randomize();
    virtual void simulate();
};
#endif // CONWAY_H
