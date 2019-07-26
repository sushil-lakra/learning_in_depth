
#include <iostream>
#include <algorithm>
#include "longest_increasing_subsequence.h"
#include "longest_common_subsequence.h"

int main()
{
    char l[] = "AGGTAB";
    char r[] = "GXTXAYB";

    int** aux = new int*[strlen(l)];
    for (int i = 0; i < strlen(l); ++i)
        aux[i] = new int[strlen(r)];

    for (int i = 0; i < strlen(l); ++i)
        for (int j = 0; j < strlen(r); ++j)
            aux[i][j] = -1;

    std::cout << lcs_itr(l, r, strlen(l), strlen(r), aux) << std::endl;

    int stop;
    std::cin >> stop;
}
