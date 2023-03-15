#include <iostream>
#include "pikachu.h"
#include "mewtwo.h"
#include "squirtle.h"

// 1P用の入力関数
// 0 -> attack, 1 -> guard
//int inputaction1(CMonster * pokemon)
//{
//    std::cout << "数字を入力してください 0：Attack　1：Guard\n";
//    int command;
//    std::cin >> command;
//
//    switch (command)
//    {
//    case 0:
//        pokemon->Attack();
//        break;
//
//    case 1:
//        pokemon->Guard(pokemon->Attack());
//        break;
//
//    default:
//
//        break;
//    }
//}

// 2P用の入力関数
// 0 -> attack, 1 -> guard
//int inputaction2();

void Battle(CMonster * pokemon1, CMonster * pokemon2)
{
    int pokemon1AttackPoint = pokemon1->Attack();
    int pokemon1result = pokemon2->Guard(pokemon1AttackPoint);
    pokemon2->Damage(pokemon1result);

    int pokemon2AttackPoint = pokemon2->Attack();
    int pokemon2result = pokemon1->Guard(pokemon2AttackPoint);
    pokemon1->Damage(pokemon2result);
}

int main()
{
    CPikachu pikachu;
    CMewtwo  mewtwo;
    CSquirtle squirtle;

    //int inputaction1();
    //int inputaction2();

    Battle(&mewtwo, &squirtle);
    Battle(&pikachu, &mewtwo);
}
