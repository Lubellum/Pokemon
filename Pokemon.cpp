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

bool should_continue(CMonster* pokemon1, CMonster* pokemon2)
{
    for (int i = 0; i < 2; i++)
    {
        printf_s("pokemon1[%d]", pokemon1[i].c_str(), i);
    }

    if (pokemon1->faint_flag())
    {
        return false;
    }
    else if (pokemon2->faint_flag())
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    CPikachu pikachu[3];
    //CMewtwo  mewtwo;
    CSquirtle squirtle[3];

    // ループ始まり
    while (should_continue(&pikachu[0], &squirtle[0]))
    {
        tAction command1 = selectaction1();
        tAction command2 = selectaction2();

        execution(&pikachu[0], &squirtle[0], command1, command2);
    }
    // ループ終わり

    //[0] 先鋒
    //[1] 中堅
    //[2] 大将
    // 気絶していれば次のポケモンを繰り出す

    std::cout << "ゲーム終了\n";
}
