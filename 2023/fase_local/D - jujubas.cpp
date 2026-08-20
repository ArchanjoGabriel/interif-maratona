#include <bits/stdc++.h>

using namespace std;

// InterIF 2023
// Fase Local
// Técnica: Matrizes

auto ehIgual = [](const int &a, const int &b){return a==b;};

int main()
{
    vector<int> tubo_padrao;
    int qtde_tubos, qtde_analises;

    for (int i = 0; i < 8; i++)
    {
        int n;
        cin >> n;
        tubo_padrao.push_back(n);
    }

    cin >> qtde_tubos;

    vector<vector<int>> tubos_analise(qtde_tubos, vector<int>(8));

    for (int i = 0; i < qtde_tubos; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int n;
            cin >> n;
            tubos_analise[i][j] = n;
        }
    }

    cin >> qtde_analises;

    for (int i = 0; i < qtde_analises; i++)
    {
        double valor_analise_atual;
        cin >> valor_analise_atual;

        int tubos_validos = 0;
        for (int lin = 0; lin < qtde_tubos; lin++)
        {
            int qtde_gomas_validas = 0;
            for (int col = 0; col < 8; col++)
            {
                if (ehIgual(tubos_analise[lin][col], tubo_padrao[col]))
                    qtde_gomas_validas++;
            }

            double percentual_tubo_atual = qtde_gomas_validas / 8.0 * 100;

            if (percentual_tubo_atual >= valor_analise_atual)
                tubos_validos++;
        }

        double percentual_tubos_validos = 100.0 * tubos_validos / qtde_tubos;
        printf("%.2lf\n", percentual_tubos_validos);
    }
    return 0;
}