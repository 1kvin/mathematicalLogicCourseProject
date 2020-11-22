#pragma (lib, "bdd.h")
#include "bdd.h"
#include "settings.h"
#include "limitation.h"
#include "basicTypes.h"
#include "bddUtils.h"

char var[N_VAR];

int main()
{
	bdd_init(1000000, 100000);
	bdd_setcacheratio(1000);
	bdd_setvarnum(N_VAR);
	bdd p[M][N][N];
	init(p);

	bdd tree = bddtrue;

	limitation_1(tree, p, 0, 0, 0);
	limitation_1(tree, p, 0, 1, 1);
	limitation_1(tree, p, 3, 2, 1);
	limitation_1(tree, p, 2, 6, 7);

	limitation_1(tree, p, 2, 4, 5);
	limitation_1(tree, p, 1, 8, 6);
	limitation_1(tree, p, 3, 5, 3);
	limitation_1(tree, p, 0, 5, 8);
	limitation_1(tree, p, 1, 0, 4);
	limitation_1(tree, p, 0, 3, 6);
	limitation_1(tree, p, 1, 6, 2);
	limitation_1(tree, p, 2, 2, 0);
	limitation_1(tree, p, 2, 5, 2);
	limitation_1(tree, p, 3, 6, 5);
	limitation_1(tree, p, 1, 1, 1);
	limitation_1(tree, p, 3, 7, 4);
	limitation_1(tree, p, 1, 5, 3);

	limitation_2(tree, p, 2, 6, 1, 5);
	limitation_2(tree, p, 0, 3, 2, 6);
	limitation_2(tree, p, 1, 8, 2, 4);
	limitation_2(tree, p, 2, 7, 0, 7);
	limitation_2(tree, p, 2, 8, 0, 2);

	limitation_2(tree, p, 2, 1, 3, 6);
	limitation_2(tree, p, 0, 6, 3, 8);
	limitation_2(tree, p, 0, 4, 1, 7);

	limitation_3(tree, p, NeighbourRelations::UP, 0, 5, 2, 1);
	limitation_3(tree, p, NeighbourRelations::UP, 2, 7, 3, 2);
	limitation_3(tree, p, NeighbourRelations::DOWN, 1, 5, 1, 0);
	limitation_3(tree, p, NeighbourRelations::DOWN, 2, 4, 0, 8);

	limitation_3(tree, p, NeighbourRelations::UP, 0, 2, 1, 6);

	limitation_4(tree, p, 1, 5, 3, 7);
	limitation_4(tree, p, 1, 2, 0, 5);

	limitation_4(tree, p, 3, 7, 1, 1);
	limitation_4(tree, p, 2, 8, 3, 3);
	limitation_4(tree, p, 3, 8, 0, 5);
	limitation_4(tree, p, 2, 4, 2, 2);

	limitation_different_property(tree, p);

	limitation_value_less_N(tree, p);

	limitation_7(tree, p);

	int satcount = bdd_satcount(tree);
	std::cout << satcount << " solutions:" << std::endl;
	if (satcount)
		bdd_allsat(tree, outFun);

	bdd_done();
	system("pause");
}
