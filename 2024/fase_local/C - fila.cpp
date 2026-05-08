#include <bits/stdc++.h>

using namespace std;

// InterIF 2024
// Fase Local
// Técnica: Queue

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    queue<string> fila_normal, fila_prioridade;
    string tipo, nome;
    int idade;

    do
    {
        cin >> tipo;

        if (tipo == "CHEGADA")
        {
            cin >> nome >> idade;

            if (idade > 54) fila_prioridade.push(nome);
            else fila_normal.push(nome);
        }
        if (tipo == "ATENDIMENTO")
        {
            if (!fila_prioridade.empty())
            {
                cout << fila_prioridade.front() << '\n';
                fila_prioridade.pop();
            }
            else
            {
                cout << fila_normal.front() << '\n';
                fila_normal.pop();
            }
        }

    } while (!fila_normal.empty() || !fila_prioridade.empty());

    return 0;
}