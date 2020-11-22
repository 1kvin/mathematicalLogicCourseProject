#include "bddUtils.h"
#include "settings.h"
#include <iostream>

void init(bdd p[M][N][N])
{
	int I = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int z = 0; z < M; z++)
			{
				p[z][i][j] = bddtrue;
				for (int k = 0; k < LOG_N; k++)
					p[z][i][j] &= ((j >> k) & 1) ? bdd_ithvar(I + LOG_N * z + k) : bdd_nithvar(I + LOG_N * z + k);
			}
		}
		I += LOG_N * M;
	}
}


void print()
{
	for (int i = 0; i < N; i++)
	{
		std::cout << i << ": ";
		for (int j = 0; j < M; j++)
		{
			int J = i * M * LOG_N + j * LOG_N;
			int num = 0;
			for (int k = 0; k < LOG_N; k++) num += var[J + k] << k;
			std::cout << num << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void build(char* varset, unsigned n, unsigned I)
{
	if (I == n - 1) {
		if (varset[I] >= 0) {
			var[I] = varset[I];
			print();
			return;
		}

		var[I] = 0;
		print();
		var[I] = 1;
		print();
		return;
	}

	if (varset[I] >= 0)
	{
		var[I] = varset[I];
		build(varset, n, I + 1);
		return;
	}

	var[I] = 0;
	build(varset, n, I + 1);
	var[I] = 1;
	build(varset, n, I + 1);
}

void outFun(char* varset, int size)
{
	build(varset, size, 0);
}
