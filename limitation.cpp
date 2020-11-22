#include "limitation.h"

void limitation_1(bdd& tree, bdd p[M][N][N], int propertyNumber, int objectNumber, int propertyValue)
{
	tree &= p[propertyNumber][objectNumber][propertyValue];
}

void limitation_2(bdd& tree, bdd p[M][N][N], int propertyNumber1, int propertyValue1, int propertyNumber2, int propertyValue2)
{
	bdd treeTemp = bddtrue;

	for (int i = 0; i < N; i++)
		treeTemp &= !(p[propertyNumber1][i][propertyValue1] ^ p[propertyNumber2][i][propertyValue2]);
	tree &= treeTemp;
}

void limitation_3(bdd& tree, bdd p[M][N][N], NeighbourRelations neighbour, int propertyNumber1, int propertyValue1, int propertyNumber2, int propertyValue2)
{
	tree &= lim3(p, neighbour, propertyNumber1, propertyValue1, propertyNumber2, propertyValue2);
}

bdd lim3(bdd p[M][N][N], NeighbourRelations neighbour, int propertyNumber1, int propertyValue1, int propertyNumber2, int propertyValue2)
{
	bdd treeTemp = bddtrue;

	if (neighbour == UP)
	{
		for (int i = N_SQRT; i < N; i++)
		{
			if ((i + 1) % N_SQRT != 0)
				treeTemp &= !(p[propertyNumber1][i][propertyValue1] ^ p[propertyNumber2][i - N_SQRT + 1][propertyValue2]);
		}
	}
	else //DOWN
	{
		for (int i = 1; i < N - N_SQRT; i++)
		{
			if ((N_SQRT - i) % N_SQRT != 0)
				treeTemp &= (!p[propertyNumber1][i][propertyValue1] ^ p[propertyNumber2][i + N_SQRT - 1][propertyValue2]);
		}
	}
	return treeTemp;
}

void limitation_4(bdd& tree, bdd p[M][N][N], int propertyNumber1, int propertyValue1, int propertyNumber2, int propertyValue2)
{
	bdd treeTmp = bddfalse;

	treeTmp |= lim3(p, NeighbourRelations::UP, propertyNumber1, propertyValue1, propertyNumber2, propertyValue2);
	treeTmp |= lim3(p, NeighbourRelations::DOWN, propertyNumber1, propertyValue1, propertyNumber2, propertyValue2);

	tree &= treeTmp;
}

void limitation_different_property(bdd& tree, bdd p[M][N][N])
{
	for (int m = 0; m < M; m++)
		for (int i = 0; i < N - 1; i++)
			for (int j = i + 1; j < N; j++)
				for (int k = 0; k < N; k++)
					tree &= p[m][i][k] >> !p[m][j][k];
}

void limitation_value_less_N(bdd& tree, bdd p[M][N][N])
{
	bdd treeTemp = bddtrue;

	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < M; k++)
		{
			bdd temp = bddfalse;
			for (int j = 0; j < N; j++)
			{
				temp |= p[k][i][j];
			}

			treeTemp &= temp;
		}
	}

	tree &= treeTemp;
}

void limitation_7(bdd& tree, bdd p[M][N][N])
{
	for (int i = 1; i < N - 1; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				for (int x = 0; x < N; x++)
					for (int y = 0; y < N; y++)
						if (j + k + x + y > K)
							tree &= !(p[0][i][j] & p[1][i][k] & p[2][i][x] & p[3][i][y]);
}
