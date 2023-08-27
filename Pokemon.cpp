#include <iostream>
#include <cassert>
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

enum class tMonsterNo : int
{
    nNone,
    nPikachu,
    nMewtwo,
    nSquirtle,
    nNidoking,
};

tAction input_action()
{
    // trueになった時(条件に合致したとき)にブロックの中を処理する
    while (true)
    {
        std::cout << "数字を入力してください nAttack：Attack　nGuard：Guard\n";
        std::string command;
        std::cin >> command;

        // ふるいにかけてる
        if (command.length() != 1)
        {
            std::cout << "入力可能な文字数は1文字です\n";
        }
        else if (isdigit(command.at(0)) == false )
        {
        }
        else
        {
            int number = std::stoi(command);
            return static_cast<tAction>(number);
        }
    }
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

CMonster* createMonster()
{
    std::cout << "モンスターの番号を選択してください\n";

    int number = 0;
    std::cin >> number;
    tMonsterNo monsterNo = static_cast<tMonsterNo>(number);

    switch (monsterNo)
    {
    case tMonsterNo::nPikachu:
        return new CPikachu;

    case tMonsterNo::nMewtwo:
        return new CMewtwo;

    case tMonsterNo::nSquirtle:
        return new CSquirtle;
   
    case tMonsterNo::nNidoking:
        return new CNidoking;

    default:
        assert(false);
        return nullptr;
    }
}

//int selectMonster()
//{
//
//}

int selectMonster(CMonster ** team)
{
    std::cout << "モンスターを選択してください\n";
    int number = 0;

    while (true)
    {
        std::cin >> number;

        if (team[number]->FaintFlag() == false)
        {
            return number;
        }
        std::cout << "そのモンスターは倒れています。再度選択してください。\n";
    }
}

int main()
{
    // todo:チームメンバーを選択する関数の作成
    // switch-case 
    // まずは。。。0が選ばれていればピカチュウ、1が選ばれていればミュウツーを表示する

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

    int team1position = selectMonster(team1monster);
    int team2position = selectMonster(team2monster);

    // ループ始まり
    while (IsGameFinish(team1monster, team2monster) == false)
    {
        std::cout << team1position << "\n";
        std::cout << team2position << "\n";

        const tAction command1 = selectaction1();
        const tAction command2 = selectaction2();

        execution(team1monster[team1position], team2monster[team2position], command1, command2);

        // 気絶していれば次のポケモンを繰り出す
        if (IsRoundFinish(team1monster[team1position], team2monster[team2position]))
        {
            if (team1monster[team1position]->FaintFlag())
            {
                team1position = selectMonster(team1monster);
            }

            if (team2monster[team2position]->FaintFlag())
            {
                team2position = selectMonster(team2monster);
            }
        }
    }
    // ループ終わり

    std::cout << "ゲーム終了\n";
}
