#pragma once

/*
BBABCBCAB
BABCBCA
ABCBCA BABCBC
*/

int lpd(char arr[], int i, int j)
{
    if (i == j) return 1;
    else if (i > j) return 0;

    if (arr[i] == arr[j])
        return 2 + lpd(arr, i + 1, j - 1);
    else
        return std::max(
            lpd(arr, i + 1, j),
            lpd(arr, i, j - 1));
}

int lpd(char arr[], int i, int j, int** aux)
{
    if (i == j) return 1;
    else if (i > j) return 0;

    if (aux[i][j] != -1) return aux[i][j];

    if (arr[i] == arr[j])
        aux[i][j] = 2 + lpd(arr, i + 1, j - 1, aux);
    else
        aux[i][j] = std::max(
            lpd(arr, i + 1, j, aux),
            lpd(arr, i, j - 1, aux));

    return aux[i][j];
}

/*

        0   1   2   3   4
    0   1               res
    1   0   1
    2   0       1
    3   0           1
    4   0               1

    a b c
*/

int lpd(char arr[], int n, int** aux)
{
    for (int i = 0; i < n; ++i)
        aux[i][i] = 1;

    for (int len = 2; len <= n; ++len)
        for (int i = 0; i <= n - len; ++i)
        {
            int j = i + len - 1;

            if (arr[i] == arr[j])
                aux[i][j] = 2 + aux[i + 1][j - 1];
            else
                aux[i][j] = std::max(
                    aux[i + 1][j],
                    aux[i][j - 1]);
        }

    return aux[0][n - 1];
}
