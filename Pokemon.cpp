#include <iostream>
#include "pikachu.h"
#include "mewtwo.h"
#include "squirtle.h"


//1P用の入力関数
//0 -> attack, 1 -> guard

int inputaction1()
{
    std::cout << "数字を入力してください(1P) 0：Attack　1：Guard\n";
    int command;
    std::cin >> command;

    return command;
}

// 2P用の入力関数
int inputaction2()
{
    std::cout << "数字を入力してください(2P) 0：Attack　1：Guard\n";
    int command;
    std::cin >> command;

    return command;
}

void attack()
{

}

void guard()
{

}

void damage()
{

}

//void execution(CMonster * pokemon1 , CMonster * pokemon2 ,int command1, int command2)
//{
//    if (command1 == 0 && command2 == 0)
//    {
//        //1P Attack 2P Attack
//        int command_1P = pokemon1->Attack();
//        int command_2P = pokemon2->Attack();
//    } else if (command1 == 0 && command2 == 1)
//    {
//        //1P Attack 2P Guard
//        int command_1P = pokemon1->Attack();
//        int command_2P = pokemon2->Guard(command_1P);
//    } else if (command1 == 1 && command2 == 0)
//    {
//        //1P Guard 2P Attack
//        int command_2P = pokemon2->Attack();
//        int command_1P = pokemon1->Guard(command_2P);
//    }
//    else
//    {
//        //1P Guard 2P Guard
//        std::cout << "お互いに防御\n";
//    }
//}


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

    int command1 = inputaction1();
    int command2 = inputaction2();

    //execution(&pikachu, &mewtwo, command1, command2);

    //Battle(&mewtwo, &squirtle);
    //Battle(&pikachu, &mewtwo);
}
