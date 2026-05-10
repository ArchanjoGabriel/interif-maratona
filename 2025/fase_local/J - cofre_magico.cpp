#include <bits/stdc++.h>

using namespace std;

// InterIF 2025
// Fase Local
// Técnica: Estruturas de repetição e decisão

void contar_divisores(const vector<int> &numeros)
{
    int numero_atual;
    int maior_qtde_divisores = 0;
    int contador = 1;
    for (int i = 0; i < (int)numeros.size(); i++)
    {
        for (int j = 2; j < numeros[i]; j++)
        {
            if (numeros[i] % j == 0) contador++;
        }
        if (contador > maior_qtde_divisores)
        {
            maior_qtde_divisores = contador;
            contador = 1;
            numero_atual = numeros[i];
        }
        else if (contador == maior_qtde_divisores)
        {
            if (numeros[i] < numero_atual) numero_atual = numeros[i];
            contador = 1;
        }
    }

    cout << numero_atual << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int qtde_n, n;
    vector<int> numeros;

    cin >> qtde_n;
    while (qtde_n--)
    {
        cin >> n;
        numeros.push_back(n);
    }

    contar_divisores(numeros);
    return 0;
}