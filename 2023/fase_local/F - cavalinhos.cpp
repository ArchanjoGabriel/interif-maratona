#include <bits/stdc++.h>

using namespace std;

// InterIF 2023
// Fase Local
// Técnica: Struct, Sort, Hash Table, Ponteiros

struct Time
{
    string nome;
    int pontos;
    int vitorias;
    int saldo;

    Time(string nome)
    {
        this->nome = nome;
        pontos = 0;
        vitorias = 0;
        saldo = 0;
    }
};

bool comparador(const Time &a, const Time &b)
{
    if (a.pontos != b.pontos) return a.pontos > b.pontos;
    else if (a.vitorias != b.vitorias) return a.vitorias > b.vitorias;

    return a.saldo > b.saldo;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, Time> times;
    vector<Time> tabela;
    vector<string> nome_times;

    int qtde_times, qtde_partidas;

    cin >> qtde_times >> qtde_partidas;

    while (qtde_partidas--)
    {
        string nome_time_1, nome_time_2;
        int gol_time_1, gol_time_2;
        char x;

        cin >> nome_time_1 >> gol_time_1 >> x >> gol_time_2 >> nome_time_2;

        if (times.find(nome_time_1) == times.end())
        {
            Time time(nome_time_1);
            times.insert({nome_time_1, time});
            nome_times.push_back(nome_time_1);
        }
        if (times.find(nome_time_2) == times.end())
        {
            Time time(nome_time_2);
            times.insert({nome_time_2, time});
            nome_times.push_back(nome_time_2);
        }

        Time *time_atual_1 = &times.at(nome_time_1);
        Time *time_atual_2 = &times.at(nome_time_2);
        if (gol_time_1 == gol_time_2)
        {
            time_atual_1->pontos += 1;
            time_atual_2->pontos += 1;
        }
        else if (gol_time_1 > gol_time_2)
        {
            time_atual_1->pontos += 3;
            time_atual_1->vitorias += 1;
            time_atual_1->saldo += gol_time_1 - gol_time_2;
            time_atual_2->saldo += gol_time_2 - gol_time_1;
        }
        else
        {
            time_atual_2->pontos += 3;
            time_atual_2->vitorias += 1;
            time_atual_2->saldo += gol_time_2 - gol_time_1;
            time_atual_1->saldo += gol_time_1-gol_time_2;
        }
    }

    for (string s : nome_times)
    {
        tabela.push_back(times.at(s));
    }

    sort(tabela.begin(), tabela.end(), comparador);

    for (Time t : tabela)
    {
        cout << t.nome << ' '
             << t.pontos << ' '
             << t.vitorias << ' '
             << t.saldo << '\n';
    }

    return 0;
}
