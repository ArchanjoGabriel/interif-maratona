#include <bits/stdc++.h>

using namespace std;

// InterIF 2023
// Fase Local
// Técnica: Switch-Case

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int vogais = 0;
    string nome;

    getline(cin, nome);

    for (int i = 0; i < (int)nome.length(); i++)
    {
        switch (nome[i])
        {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                vogais++;
        }
    }

    cout <<  "frasco " << vogais%3 << '\n';
}