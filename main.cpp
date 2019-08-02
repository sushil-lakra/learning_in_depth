
#include <iostream>
#include <algorithm>
#include "rod_cutting.h"

int main()
{
    int p[] = {60, 100, 120, 200};
    int l[] = {1, 2, 3, 4};

    int m = sizeof(p) / sizeof(p[0]);
    int n = 5;

    int** aux = new int*[m + 1];
    for (int i = 0; i < m + 1; ++i)
        aux[i] = new int[n + 1];

    for (int i = 0; i < m + 1; ++i)
        for (int j = 0; j < n + 1; ++j)
            aux[i][j] = 0;

    std::cout << rcp_itr(p, l, m, n, aux) << std::endl;

    int stop;
    std::cin >> stop;
}
