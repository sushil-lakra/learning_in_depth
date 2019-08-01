
#include <iostream>
#include <algorithm>
#include "egg_dropping_problem.h"

int main()
{
    int f = 36;
    int e = 2;

    int** aux = new int*[f + 1];
    for (int i = 0; i < f + 1; ++i)
        aux[i] = new int[e + 1];

    for (int i = 0; i < f + 1; ++i)
        for (int j = 0; j < e + 1; ++j)
            aux[i][j] = 0;

    std::cout << ed_itr(f, e, aux) << std::endl;

    int stop;
    std::cin >> stop;
}

