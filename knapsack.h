#pragma once


/*
60  100 120 200
1   2   3   4
c = 5
*/

int knapsack(int v[], int w[], int n, int c)
{
    if (n == 0 || c == 0) return 0;

    if (w[n - 1] > c)
        return knapsack(v, w, n - 1, c);

    return std::max(
        v[n - 1] + knapsack(v, w, n - 1, c - w[n-1]),
        knapsack(v, w, n - 1, c)
    );
}

/*
                0   1   2   3   4   5
            0   0   0   0   0   0   0
    6   1   1   0   6   6   6   6   6
    10  2   2   0   6   10  16  16  16
    12  3   3   0   6   10  16  18  22
    20  4   4   0   6   10  16  20  26
*/

int knapsack(int v[], int w[], int n, int c, int** aux)
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= c; ++j)
        {
            if (w[i - 1] <= j)
                aux[i][j] = std::max(
                    v[i - 1] + aux[i - 1][j - w[i - 1]],
                    aux[i - 1][j]);
            else
                aux[i][j] = aux[i - 1][j];
        }

    return aux[n][c];
}

/*
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
*/