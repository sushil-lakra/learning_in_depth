#pragma once

/*
60  100 120 200
1   2   3   4
len = 5

5   41  32  311 221 2111    11111
*/


int rcp(int p[], int l[], int n, int rl)
{
    if (n <= 0 || rl == 0) return 0;

    if (l[n - 1] > rl)
        return rcp(p, l, n - 1, rl);

    return std::max(
        p[n - 1] + rcp(p, l, n, rl - l[n - 1]),
        rcp(p, l, n - 1, rl));
}

int rcp(int p[], int l[], int n, int rl, int** aux)
{
    if (n <= 0 || rl == 0) return 0;

    if (aux[n][rl] != -1) return aux[n][rl];

    if (l[n - 1] > rl)
        aux[n][rl] = rcp(p, l, n - 1, rl, aux);
    else
        aux[n][rl] = std::max(
            p[n - 1] + rcp(p, l, n, rl - l[n - 1], aux),
            rcp(p, l, n - 1, rl, aux));

    return aux[n][rl];
}

/*
            0   1   2   3   4   5
        0   0   0   0   0   0   0
    6   1   0   6   12  18  24  30
    10  2   0   6   12  18  24  30
    12  3   0   6   12  18  24  30
    20  4   0   6   12  18  24  30
*/

int rcp_itr(int p[], int l[], int n, int rl, int** aux)
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= rl; ++j)
        {
            if (l[i - 1] > j)
                aux[i][j] = aux[i - 1][j];
            else
                aux[i][j] = std::max(
                    p[i - 1] + aux[i][j - l[i - 1]],
                    aux[i - 1][j]);
        }

    return aux[n][rl];
}

/*
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
*/
