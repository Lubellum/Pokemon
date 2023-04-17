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

//1P用の入力関数
//0 -> attack, 1 -> guard
tAction selectaction1()
{
    std::cout << "1Pの入力" << "\n";
    return input_action();
}

// 
tAction selectaction2()
{
    return random_action();
}


void execution(CMonster* pokemon1, CMonster* pokemon2, tAction command1, tAction command2)
{
    if (command1 == tAction::nAttack && command2 == tAction::nAttack)
    {
        int pokemon1Attack = pokemon1->Attack();
        pokemon2->Damage(pokemon1Attack);
        int pokemon2Attack = pokemon2->Attack();
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


//    // 1Pの攻撃
//    if (command1 == tAction::nAttack)
//    {
//        int attackPoint = pokemon1->Attack();
//
//        // 2Pへダメージ
//        pokemon2->Damage(attackPoint);
//    }
//    else if (command1 == tAction::nGuard)
//    {
//        pokemon1->Guard();
//    }
//    else
//    {
//        std::cout << "エラー：入力に間違いがあります。";
//    }
//
//    // 2Pの攻撃
//    if (command2 == tAction::nAttack)
//    {
//        int attackpoint = pokemon2->Attack();
//
//        // 1Pへダメージ
//        pokemon1->Damage(attackpoint);
//    }
//    else if (command2 == tAction::nGuard)
//    {
//        pokemon2->Guard();
//    }
//    else
//    {
//        std::cout << "エラー：入力に間違いがあります。";
//    }
}

bool should_continue(CMonster* pokemon1, CMonster* pokemon2)
{
    int pokemon1HP = pokemon1->pass_HP();
    int pokemon2HP = pokemon2->pass_HP();

    if (pokemon1HP < 0)
    {
        return false;
    }
    else if (pokemon2HP < 0)
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
    random_action();

    CPikachu pikachu;
    CMewtwo  mewtwo;
    CSquirtle squirtle;

    //// ループ始まり
    while (should_continue(&pikachu, &mewtwo))
    {
        tAction command1 = selectaction1();
        tAction command2 = selectaction2();

        execution(&pikachu, &mewtwo, command1, command2);
    }
    // ループ終わり
    std::cout << "ゲーム終了\n";
}
