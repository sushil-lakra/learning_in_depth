
#include <iostream>
#include <algorithm>
#include "matrix_chain_multiplication.h"

int main()
{
    int arr[] = {3, 2, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int** aux = new int*[n];
    for (int i = 0; i < n; ++i)
        aux[i] = new int[n];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            aux[i][j] = 0;

    std::cout << mcm(arr, n - 1, aux) << std::endl;

    int stop;
    std::cin >> stop;
}


