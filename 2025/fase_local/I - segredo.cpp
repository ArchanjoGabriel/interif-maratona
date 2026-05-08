#include <bits/stdc++.h>

using namespace std;

// InterIF 2025
// Fase Local
// Técnica: String + Tabela ASCII

string crip(const string &frase, const string &chave)
{
    bool horario = false, anti_horario = true;
    vector<int> chave_n;
    string final = "";
    for (int i = 0; i < (int)chave.length(); i++)
    {
        chave_n.push_back((int)chave[i] - 96);
    }

    for (int i = 0; i < (int)frase.length(); i++)
    {
        if ((int)frase[i] + chave_n[i] <= 122 && horario) 
        {
            final += frase[i] + chave_n[i];
            horario = false;
            anti_horario = true;
        }
        else if ((int)frase[i] + chave_n[i] > 122 && horario)
        {
            final += 'a' + (chave_n[i] - (123 - (int)frase[i]));
            horario = false;
            anti_horario = true;
        }
        else if ((int)frase[i] - chave_n[i] >= 97 && anti_horario)
        {
            final += frase[i] - chave_n[i];
            horario = true;
            anti_horario = false;
        }
        else if ((int)frase[i] - chave_n[i] < 97 && anti_horario)
        {
            final += 'z' - (chave_n[i] - ((int)frase[i] - 96));
            horario = true;
            anti_horario = false;
        }
    }

    return final;
}

string decrip(string frase, string chave)
{
    bool horario = true, anti_horario = false;
    vector<int> chave_n;
    string final = "";
    for (int i = 0; i < (int)chave.length(); i++)
    {
        chave_n.push_back((int)chave[i] - 96);
    }

    for (int i = 0; i < (int)frase.length(); i++)
    {
        if ((int)frase[i] + chave_n[i] <= 122 && horario) 
        {
            final += frase[i] + chave_n[i];
            horario = false;
            anti_horario = true;
        }
        else if ((int)frase[i] + chave_n[i] > 122 && horario)
        {
            final += 'a' + (chave_n[i] - (123 - (int)frase[i]));
            horario = false;
            anti_horario = true;
        }
        else if ((int)frase[i] - chave_n[i] >= 97 && anti_horario)
        {
            final += frase[i] - chave_n[i];
            horario = true;
            anti_horario = false;
        }
        else if ((int)frase[i] - chave_n[i] < 97 && anti_horario)
        {
            final += 'z' - (chave_n[i] - ((int)frase[i] - 96));
            horario = true;
            anti_horario = false;
        }
    }

    return final;
} 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int caso;
    string frase, chave;
    while(true)
    {
        cin >> caso;
        if (caso == 0) break;

        cin >> frase >> chave;
        if (caso == 1) cout << crip(frase, chave) << '\n';
        else if (caso == 2) cout << decrip(frase, chave) << '\n';
    }

    return 0;
}