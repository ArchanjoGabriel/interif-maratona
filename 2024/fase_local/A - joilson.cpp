#include <bits/stdc++.h>

using namespace std;

// InterIF 2024
// Fase Local
// Técnica: Pesquisa em matrizes + verificação de limites

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int fileiras, cadeiras;

    cin >> fileiras >> cadeiras;
    bool cinema[fileiras][cadeiras];

    for (int i = 0; i < fileiras; i++)
    {
        for (int j = 0; j < cadeiras; j++)
        {
            cin >> cinema[i][j];
        }
    }

    vector<int> n_cadeiras;
    int min_vizinhos = 9;
    for (int i = 0; i < fileiras; i++)
    {
        for (int j = 0; j < cadeiras; j++)
        {
            if (!cinema[i][j])
            {
                int vizinhos = 0;

                // verifica as cadeiras na fileira de cima de cinema[i][j] se houver
                if (i-1 >= 0 && j-1 >= 0 && cinema[i-1][j-1]) vizinhos += 1;
                if (i-1 >= 0 && cinema[i-1][j]) vizinhos += 1;
                if (i-1 >= 0 && j+1 < cadeiras && cinema[i-1][j+1]) vizinhos += 1;

                // verifica as laterais de cinema[i][j] se houver
                if (j-1 >= 0 && cinema[i][j-1]) vizinhos += 1;
                if (j+1 < cadeiras && cinema[i][j+1]) vizinhos += 1;

                // verifica as cadeiras na fileira de baixo de cinema [i][j] se houver
                if (i+1 < fileiras && j-1 >= 0 && cinema[i+1][j-1]) vizinhos += 1;
                if (i+1 < fileiras && cinema[i+1][j]) vizinhos += 1;
                if (i+1 < fileiras && j+1 < cadeiras && cinema[i+1][j+1]) vizinhos += 1;

                if (vizinhos < min_vizinhos)
                {
                    min_vizinhos = vizinhos;
                    n_cadeiras.clear();
                    n_cadeiras.push_back((i * cadeiras) + j + 1);
                }
                else if (vizinhos == min_vizinhos)
                {
                    n_cadeiras.push_back((i * cadeiras) + j + 1);
                }
            }
        }
    }

    cout << min_vizinhos << '\n';
    for (int i = 0; i < (int)n_cadeiras.size(); i++)
    {
        cout << n_cadeiras[i] << '\n';
    }
    return 0;
}