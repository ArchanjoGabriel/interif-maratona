#include <bits/stdc++.h>

using namespace std;

struct Competidor
{
    string nome;
    double melhor_salto;
};

bool comparador(Competidor &a, Competidor &b)
{
    return a.melhor_salto > b.melhor_salto;
}

int main()
{
    int qtde_competidores, qtde_saltos;

    cin >> qtde_competidores >> qtde_saltos;

    vector<Competidor> competidores;
    while (qtde_competidores--)
    {
        Competidor comp;
        string nome;
        string val_salto;
        vector<double> saltos;

        cin >> nome;
        cin.ignore();

        for (int i = 0; i < qtde_saltos; i++)
        {
            getline(cin, val_salto);

            if (val_salto.length() <= 5) saltos.push_back(stold(val_salto));
        }

        comp.nome = nome;
        comp.melhor_salto = *max_element(saltos.begin(), saltos.end());

        competidores.push_back(comp);
    }

    sort(competidores.begin(), competidores.end(), comparador);

    cout << competidores[0].nome << '\n'
        << competidores[0].melhor_salto << '\n';

    return 0;
}
