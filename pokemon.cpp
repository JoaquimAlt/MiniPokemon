#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

struct Pokemon
{
    Pokemon(string nome, int ataque, int defesa, int ataqueI, int defesaI)
    {
        name = nome;
        ata = ataque;
        def = defesa;

        ataI = ataqueI;
        defI = defesaI;
    };

    void ShowPokemon()
    {

        cout << "Pokemon: " << name << endl;
        cout << "Ataque: " << ata << endl;
        cout << "HP: " << def << endl
             << endl;
    };

    void Batalha()
    {
        while (defI > 0)
        {
            cout << "Voce quer atacar? (s ou n)";
            cin >> atack;

            if (atack == 's')
            {
                Ataque();
            }
            else
            {
                cout << "vc ficou parado" << endl;
            }
        }
    }

    void Ataque()
    {
        defI -= ata;
        cout << "Pikachu esta com " << defI << " de HP" << endl;
    };

    string name;
    char atack;
    int ata, def, defI, ataI;
};

void Charmander()
{
    Pokemon main("Charmander", 17, 130, 18, 120);
    cout << "Voce escolheu o " << endl;
    main.ShowPokemon();

    main.Batalha();
}

void Bulbasaur()
{
    Pokemon main("Bulbasaur", 11, 190, 18, 120);
    cout << "Voce escolheu o " << endl;
    main.ShowPokemon();

    main.Batalha();
}

void Squirtle()
{
    Pokemon main("Squirtle", 15, 150, 18, 120);
    cout << "Voce escolheu o " << endl;
    main.ShowPokemon();

    main.Batalha();
}

int main()
{
    char chose;

    Pokemon cha("Charmander", 17, 130, 18, 120);
    Pokemon bulb("Bulbasaur", 11, 190, 18, 120);
    Pokemon squi("Squirtle", 15, 150, 18, 120);

    cha.ShowPokemon();
    bulb.ShowPokemon();
    squi.ShowPokemon();

    cout << "Escolha seu Pokemon para atacar o Pikachu(Ataque: 18 e Defesa: 120 ( Digite: c, b ou s ): "
         << endl;
    cin >> chose;

    if (chose == 'c')
    {
        Charmander();
    }
    else if (chose == 'b')
    {
        Bulbasaur();
    }
    else if (chose == 's')
    {
        Squirtle();
    }
}
