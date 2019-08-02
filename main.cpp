
#include <iostream>
#include <algorithm>
#include "longest_palindromic_subsequence.h"

int main()
{
    int v[] = {60, 100, 120, 200};
    int w[] = {1, 2, 3, 4};

    int m = sizeof(v) / sizeof(v[0]);
    int n = 5;

    int** aux = new int*[m + 1];
    for (int i = 0; i < m + 1; ++i)
        aux[i] = new int[n + 1];

    for (int i = 0; i < m + 1; ++i)
        for (int j = 0; j < n + 1; ++j)
            aux[i][j] = 0;

    std::cout << knapsack(v, w, m, n, aux) << std::endl;

    int stop;
    std::cin >> stop;
}
