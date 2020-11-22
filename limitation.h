#ifndef LIMITATION_H
#define LIMITATION_H

#include "bdd.h"
#include "settings.h"
#include "basicTypes.h"

void limitation_1(bdd& tree, bdd p[M][N][N], int propertyNumber, int objectNumber, int propertyValue);
void limitation_2(bdd& tree, bdd p[M][N][N], int propertyNumber1, int propertyValue1, int propertyNumber2, int propertyValue2);
void limitation_3(bdd& tree, bdd p[M][N][N], NeighbourRelations neighbour, int propertyNumber1, int propertyValue1, int propertyNumber2, int propertyValue2);
bdd lim3(bdd p[M][N][N], NeighbourRelations neighbour, int propertyNumber1, int propertyValue1, int propertyNumber2, int propertyValue2);
void limitation_4(bdd& tree, bdd p[M][N][N], int propertyNumber1, int propertyValue1, int propertyNumber2, int propertyValue2);
void limitation_different_property(bdd& tree, bdd p[M][N][N]);
void limitation_value_less_N(bdd& tree, bdd p[M][N][N]);
void limitation_7(bdd& tree, bdd p[M][N][N]);

#endif
