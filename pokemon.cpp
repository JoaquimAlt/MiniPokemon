#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

string nameI;
int defI, ataI;

string nomeInimigo;
int ataqueInimigo, defesaInimigo;

struct Pokemon
{
    Pokemon(string nome, int ataque, int defesa)
    {
        name = nome;
        ata = ataque;
        def = defesa;
    };

    void ShowPokemon()
    {

        cout << "Pokemon: " << name << endl;
        cout << "Ataque: " << ata << endl;
        cout << "HP: " << def << endl
             << endl;
    };

    int Batalha(std::string InimigoName, int InimigoAtaque, int InimigoDefesa)
    {
        while (InimigoDefesa > 0)
        {
            cout << "Voce quer atacar? (s ou n)" << endl;
            cin >> atack;

            if (atack == 's')
            {
                unsigned seed = time(0);
                srand(seed);
                chanceAtaque = 1 + rand() % 3;
                
                if(chanceAtaque == 1 || chanceAtaque == 2){
                InimigoDefesa -= ata;
                cout << "Voce atacou" << InimigoName << " esta com " << InimigoDefesa << " de HP" << endl << endl;
                } else {
                    cout << "Errou o ataque" << endl;
                }
            }
            else
            {
                cout << "vc ficou parado" << endl;
            }

            unsigned seed = time(0);
            srand(seed);
            escolhaInimigo = 1 + rand() % 3;

            if (escolhaInimigo == 1 || escolhaInimigo == 2)
            {
                def -= InimigoAtaque;
                cout << InimigoName << " atacou" << endl;
            } 
            else if (escolhaInimigo == 3) 
            {
            cout << "O " << InimigoName << " nao fez nada" << endl;
            }

            cout << name << " esta com " << def << " de HP" << endl << endl;

            if (def <= 0){
                cout << "Voce foi derrotado";
                break;
            }
        };

        if (InimigoDefesa <= 0)
        {
            cout << "Voce derrotou o " << InimigoName;
        };
    };

    string name;
    char atack;
    int ata, def, escolhaInimigo, chanceAtaque;
};

int PokemonInimigo(std::string nomeI, int ataqueI, int defesaI)
{
    nameI = nomeI;
    ataI = ataqueI;
    defI = defesaI;
};

void InimigoStatus()
{
    cout << "Digite o pokemon que voce quer atacar: ";
    cin >> nomeInimigo;

    cout << "Ataque dele: ";
    cin >> ataqueInimigo;

    cout << "Defesa dele: ";
    cin >> defesaInimigo;
}

void Charmander()
{
    Pokemon main("Charmander", 17, 130);
    cout << "Voce escolheu o " << endl;
    main.ShowPokemon();
    InimigoStatus();
    main.Batalha(nomeInimigo, ataqueInimigo, defesaInimigo);
}

void Bulbasaur()
{
    Pokemon main("Bulbasaur", 11, 190);
    cout << "Voce escolheu o " << endl;
    main.ShowPokemon();
    InimigoStatus();
    main.Batalha(nomeInimigo, ataqueInimigo, defesaInimigo);
}

void Squirtle()
{
    Pokemon main("Squirtle", 15, 150);
    cout << "Voce escolheu o " << endl;
    main.ShowPokemon();
    InimigoStatus();
    main.Batalha(nomeInimigo, ataqueInimigo, defesaInimigo);
}

int main()
{
    char chose;

    Pokemon cha("Charmander", 17, 130);
    Pokemon bulb("Bulbasaur", 11, 190);
    Pokemon squi("Squirtle", 15, 150);

    cha.ShowPokemon();
    bulb.ShowPokemon();
    squi.ShowPokemon();

    cout << "Escolha seu Pokemon para atacar o ( Digite o nome ou: c, b ou s ): "
         << endl;
    cin >> chose;

    if (chose == 'c' || chose == 'C')
    {
        Charmander();
    }
    else if (chose == 'b' || chose == 'B')
    {
        Bulbasaur();
    }
    else if (chose == 's' || chose == 'S')
    {
        Squirtle();
    }
}
