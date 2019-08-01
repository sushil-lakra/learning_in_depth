#pragma once


int ed(int f, int e)
{
    if (f == 0 || f == 1) return f;

    if (e == 1) return f;

    int min = INT_MAX;
    for (int i = 1; i <= f; ++i)
    {
        auto tmp = 1 + std::max(
            ed(i - 1, e - 1),
            ed(f - i, e)
        );

        if (tmp < min) min = tmp;
    }

    return min;
}

int ed(int f, int e, int** aux)
{
    if (f == 0 || f == 1) return f;

    if (e == 1) return f;

    if (aux[f][e] != -1) return aux[f][e];

    aux[f][e] = INT_MAX;
    for (int i = 1; i <= f; ++i)
    {
        auto tmp = 1 + std::max(
            ed(i - 1, e - 1, aux),
            ed(f - i, e, aux)
        );

        if (tmp < aux[f][e]) aux[f][e] = tmp;
    }

    return aux[f][e];
}

int ed_itr(int f, int e, int** aux)
{
    for (int i = 0; i <= e; ++i)
    {
        aux[0][i] = 0;
        aux[1][i] = 1;
    }

    for (int i = 1; i <= f; ++i)
        aux[i][1] = i;

    for (int j = 2; j <= e; ++j)
    {
        for (int i = 1; i <= f; ++i)
        {
            aux[i][j] = INT_MAX;
            for (int x = 1; x <= i; ++x)
            {
                auto tmp = 1 + std::max(
                    aux[x - 1][j - 1],
                    aux[i - x][j]);

                if (tmp < aux[i][j]) aux[i][j] = tmp;
            }
        }
    }

    return aux[f][e];
}

/*
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
*/