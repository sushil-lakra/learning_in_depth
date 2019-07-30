
#include <iostream>
#include <algorithm>
#include "edit_distance.h"


int main()
{
    char l[] = "ACDCX";
    char r[] = "BADCF";
    int m = strlen(l);
    int n = strlen(r);

    int** aux = new int*[m + 1];
    for (int i = 0; i < m + 1; ++i)
        aux[i] = new int[n + 1];

    for (int i = 0; i < m + 1; ++i)
        for (int j = 0; j < n + 1; ++j)
            aux[i][j] = 0;

    std::cout << ed_itr(l, r, m, n, aux) << std::endl;

    int stop;
    std::cin >> stop;
}

