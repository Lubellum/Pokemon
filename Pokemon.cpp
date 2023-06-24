#include <iostream>
#include "pikachu.h"
#include "mewtwo.h"
#include "squirtle.h"
#include "nidoking.h"
#include <random>

enum class tAction : int
{
    nAttack, // 0
    nGuard,  // 1
};

tAction input_action()
{
    // todo:数値以外を入力すると無限ループしてしまう
    //char number[2];
    //scanf_s("%s", &number, 1);

    //if ((number[0] >= 48) && (number[0] <= 57))
    //{
    //    int command = atoi(number);
    //}

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

bool TeamAnnihilation(CMonster** team)
{
    int Team1FaintCount = 0;

    for (int i = 0; i < 3; i++)
    {
        if (team[i]->FaintFlag())
        {
            Team1FaintCount++;
        }
    }

    if (Team1FaintCount == 3)
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

int main()
{
    CMonster* team1monster[4];

    team1monster[0] = new CPikachu;
    team1monster[1] = new CMewtwo;
    team1monster[2] = new CSquirtle;
    team1monster[3] = new CNidoking;

    CMonster* team2monster[4];

    team2monster[0] = new CPikachu;
    team2monster[1] = new CMewtwo;
    team2monster[2] = new CSquirtle;
    team2monster[3] = new CNidoking;
    
    // 抽象クラスなのでインスタンスを作れない
    //CMonster* cmonster = new CMonster;

    //CPikachu pikachu[3];
    //CMewtwo  mewtwo;
    //CSquirtle squirtle[3];

    int team1position = 0;
    int team2position = 0;

    // ループ始まり
    while (IsGameFinish(team1monster, team2monster) == false)
    {
        std::cout << team1position << "\n";
        std::cout << team2position << "\n";

        tAction command1 = selectaction1();
        tAction command2 = selectaction2();

        execution(team1monster[team1position], team2monster[team2position], command1, command2);

        // 気絶していれば次のポケモンを繰り出す
        if (IsRoundFinish(team1monster[team1position], team2monster[team2position]))
        {
            if (team1monster[team1position]->FaintFlag())
            {
                int number = 0;
                
                // モンスター番号の入力を受け付けて、もし死亡フラグが立っていたら再選択
                while (true)
                {
                    std::cin >> number;

                    if (team1monster[number]->FaintFlag() == false)
                    {
                        team1position = number;
                        break;
                    }

                    std::cout << "そのモンスターは倒れています。再度選択してください。\n";
                }
            }
            
            if (team2monster[team2position]->FaintFlag())
            {
                std::cout << "次のモンスターを選択してください\n";

                int number = 0;
                std::cin >> number;

                team2position = number;
            }
        }
    }
    // ループ終わり

    std::cout << "ゲーム終了\n";
}
