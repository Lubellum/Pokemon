#include <iostream>
#include "pikachu.h"
#include "mewtwo.h"
#include "squirtle.h"
#include <random>

enum class tAction : int
{
    nAttack, // 0
    nGuard,  // 1
};

tAction input_action()
{
    std::cout << "数字を入力してください nAttack：Attack　nGuard：Guard\n";
    int command;
    std::cin >> command;

    return static_cast<tAction>(command);
}

// コマンドをランダムに決定
tAction random_action()
{
    std::random_device seed;
    std::mt19937 mt(seed());
    return static_cast<tAction>(mt() % 2);
}

// 1P用の入力関数
//0 -> attack, 1 -> guard
tAction selectaction1()
{
    std::cout << "1Pの入力" << "\n";
    return input_action();
}

// 2P用の入力関数
tAction selectaction2()
{
    return random_action();
}


void execution(CMonster* pokemon1, CMonster* pokemon2, tAction command1, tAction command2)
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

bool IsGameFinish(CMonster* team1, CMonster* team2)
{
    if (team1[0].faint_flag() && team1[1].faint_flag() && team1[2].faint_flag())
    {
        return true;
    }
    else if (team2[0].faint_flag() && team2[1].faint_flag() && team2[2].faint_flag())
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
    if (pokemon1->faint_flag())
    {
        return true;
    }
    else if (pokemon2->faint_flag())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    CPikachu pikachu[3];
    //CMewtwo  mewtwo;
    CSquirtle squirtle[3];

    int team1position = 0;
    int team2position = 0;

    // ループ始まり
    while (IsGameFinish(pikachu, squirtle) == false)
    {
        std::cout << team1position << "\n";
        std::cout << team2position << "\n";

        tAction command1 = selectaction1();
        tAction command2 = selectaction2();

        execution(&pikachu[team1position], &squirtle[team2position], command1, command2);

        if (IsRoundFinish(&pikachu[team1position], &squirtle[team2position]))
        {
            team1position++;
            team2position++;
        }
    }
    // ループ終わり

    //[0] 先鋒
    //[1] 中堅
    //[2] 大将
    // 気絶していれば次のポケモンを繰り出す

    std::cout << "ゲーム終了\n";
}
