#include <bits/stdc++.h>

using namespace std;

// InterIF 2024
// Fase Local
// Técnica: DP + memoização

void mostrar_tabuleiro(const string &notacao)
{
    for (int i = 0; i < (int)notacao.length(); i++)
    {
        if (isalpha(notacao[i])) cout << "|" << notacao[i]; 
        else if (isalnum(notacao[i]))
        {
            int repet = notacao[i] - '0';
            for (int j = 0; j < repet; j++) cout << "| ";
        }
        else if (notacao[i] == '/') cout <<  "|\n";
    }

    cout << "|\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string notacao;
    cin >> notacao;
    mostrar_tabuleiro(notacao);
}