#include <bits/stdc++.h>

using namespace std;

vector<char> criterios;

struct Selecao
{
    string nome;
    int pontos;
    int vitorias;
    int saldo;
    int gols;
};

bool comparador(const Selecao& a, const Selecao& b)
{
    for (char c : criterios)
    {
        if (c == 'P')
        {
            if (a.pontos != b.pontos) return a.pontos > b.pontos;
        }

        if (c == 'V')
        {
            if (a.vitorias != b.vitorias) return a.vitorias > b.vitorias;
        }

        if (c == 'S')
        {
            if (a.saldo != b.saldo) return a.saldo > b.saldo;
        }

        if (c == 'G')
        {
            if (a.gols != b.gols) return a.gols > b.gols;
        }
    }
    return a.nome < b.nome;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Selecao> selecoes;
    int qtde_sel, qtde_crit;

    cin >> qtde_sel;
    cin >> qtde_crit;

    while(qtde_crit--)
    {
        char c;
        cin >> c;
        criterios.push_back(c);
    }

    for (int i = 0; i < qtde_sel; i++)
    {
        Selecao selecao;

        string nome;
        int pontos;
        int vitorias;
        int saldo;
        int gols;

        cin >> nome >> pontos >> vitorias >> saldo >> gols;

        selecao.nome = nome;
        selecao.pontos = pontos;
        selecao.vitorias = vitorias;
        selecao.saldo = saldo;
        selecao.gols = gols;

        selecoes.push_back(selecao);
    }

    sort(selecoes.begin(), selecoes.end(), comparador);

    for (int i = 0; i < qtde_sel; i++)
    {
        cout << i + 1 << ' '
        << selecoes[i].nome << ' '
        << selecoes[i].pontos << ' '
        << selecoes[i].vitorias << ' '
        << selecoes[i].saldo << ' '
        << selecoes[i].gols << '\n';
    }

    return 0;
}