#include <bits/stdc++.h>

using namespace std;

// InterIF 2023
// Fase Local
// Técnica: Busca Gulosa

int guloso(const vector<int> &cedulas, int valor)
{
    int i = 0;
    int contador = 0;
    while (valor != 0)
    {
        if (cedulas[i] <= valor)
        {
            contador += valor / cedulas[i];
            valor %= cedulas[i];
        }
        else i++;
    }

    return contador;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int qtde_cedulas, valor;

    cin >> qtde_cedulas;
    vector<int> cedulas;

    for (int i = 0; i < qtde_cedulas; i++)
    {
        int n;
        cin >> n;
        cedulas.push_back(n);
    }

    cin >> valor;

    sort(cedulas.begin(), cedulas.end(), greater<int>());

    cout << guloso(cedulas, valor) << '\n';

    return 0;
}