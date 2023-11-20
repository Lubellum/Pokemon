#include <iostream>
#include "battle.h"
#include "../command/command.h"
#include "../monster/monster.h"
#include "../monster/createMonster.h"

enum class tAction : int
{
    nAttack, // 0
    nGuard,  // 1
};

void Execution(CMonster* pokemon1, CMonster* pokemon2, tAction command1, tAction command2)
{
    if (command1 == tAction::nAttack && command2 == tAction::nAttack)
    {
        int pokemon1Attack = pokemon1->Attack();
        int pokemon2Attack = pokemon2->Attack();

        pokemon2->Damage(pokemon1Attack);
        pokemon1->Damage(pokemon2Attack);
    }
    else if (command1 == tAction::nGuard && command2 == tAction::nAttack)
    {
        int pokemon2Attack = pokemon2->Attack();
        pokemon1->Guard();
        pokemon1->Damage(pokemon2Attack);
    }
    else if (command1 == tAction::nAttack && command2 == tAction::nGuard)
    {
        int pokemon1Attack = pokemon1->Attack();
        pokemon2->Guard();
        pokemon2->Damage(pokemon1Attack);
    }
    else
    {
        std::cout << "お互いに防御した！\n";
    }
}

bool TeamAnnihilation(CMonster** team)
{
    int team1FaintCount = 0;

    for (int i = 0; i < 3; i++)
    {
        if (team[i]->FaintFlag())
        {
            team1FaintCount++;
        }
    }

    if (team1FaintCount == 3)
    {
        return true;
    }
    return false;
}

bool IsGameFinish(CMonster** team1, CMonster** team2)
{
    if (TeamAnnihilation(team1))
    {
        return true;
    }
    else if (TeamAnnihilation(team2))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsRoundFinish(CMonster* pokemon1, CMonster* pokemon2)
{
    if (pokemon1->FaintFlag())
    {
        return true;
    }
    else if (pokemon2->FaintFlag())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// ループ始まり　バトル開始
void battle(CMonster** team1Monster, CMonster** team2Monster, int team1position, int team2position)
{
    while (IsGameFinish(team1Monster, team2Monster) == false)
    {
        std::cout << team1position << "\n";
        std::cout << team2position << "\n";

        const tAction command1 = SelectAction1();
        const tAction command2 = SelectAction2();

        Execution(team1Monster[team1position], team2Monster[team2position], command1, command2);

        //// 気絶していれば次のポケモンを繰り出す
        if (IsRoundFinish(team1Monster[team1position], team2Monster[team2position]))
        {
            if (team1Monster[team1position]->FaintFlag())
            {
                team1position = SelectMonster(team1Monster);
            }

            if (team2Monster[team2position]->FaintFlag())
            {
                team2position = SelectMonster(team2Monster);
            }
        }
    }
}
// ループ終わり