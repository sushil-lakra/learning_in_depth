#pragma once


/*
ACDCX   BADCF
ACDCXF  ACDC    ACDCF
*/

int ed(char l[], char r[], int m, int n)
{
    if (m == 0) return n;
    else if (n == 0) return m;

    if (l[m-1] == r[n-1])
        return ed(l, r, m - 1, n - 1);
    else
        return 1 + std::min(
            ed(l, r, m, n - 1), // insert
            std::min( ed(l, r, m - 1, n), //delete
                ed(l, r, m - 1, n - 1)) //replace
            );
}

int ed_itr(char l[], char r[], int m, int n, int** aux)
{
    for (int i = m - 1; i >= 0; --i)
        for (int j = n - 1; j >= 0; --j)
        {
            if (l[i] == r[j])
                aux[i][j] = aux[i + 1][j + 1];
            else
                aux[i][j] = 1 + std::min(
                    aux[i][j + 1], // insert
                    std::min( aux[i + 1][j], //delete
                        aux[i + 1][j + 1]) //replace
                    );
        }

    return aux[0][0];
}

int ed(char l[], char r[], int m, int n, int** aux)
{
    if (m == 0) return n;
    else if (n == 0) return m;

    if (l[m - 1] == r[n - 1])
    {
        if (aux[m-1][n-1] == -1)
            aux[m-1][n-1] = ed(l, r, m - 1, n - 1);

        return aux[m-1][n-1];
    }
    else
    {
        if (aux[m][n-1] == -1)
            aux[m][n-1] = ed(l, r, m, n - 1);
        if (aux[m-1][n] == -1)
            aux[m-1][n] = ed(l, r, m - 1, n);
        if (aux[m-1][n-1] == -1)
            aux[m-1][n-1] = ed(l, r, m - 1, n - 1);

        return 1 + std::min(
            aux[m][n-1], // insert
            std::min(aux[m-1][n], //delete
                aux[m-1][n-1]) //replace
        );
    }
}

/*
int main()
{
    char l[] = "ACDCX";
    char r[] = "BADCF";

    int** aux = new int*[strlen(l) + 1];
    for (int i = 0; i < strlen(l) + 1; ++i)
        aux[i] = new int[strlen(r) + 1];

    for (int i = 0; i < strlen(l) + 1; ++i)
        for (int j = 0; j < strlen(r) + 1; ++j)
            aux[i][j] = 0;

    std::cout << ed_itr(l, r, strlen(l), strlen(r), aux) << std::endl;

    int stop;
    std::cin >> stop;
}
*/