#include <iostream>
#include "pikachu.h"
#include "mewtwo.h"
#include "squirtle.h"

enum class tAction : int
{
    nAttack, // 0
    nGuard,  // 1
};

//1P用の入力関数
//0 -> attack, 1 -> guard
tAction inputaction1()
{
    std::cout << "数字を入力してください(1P) nAttack：Attack　nGuard：Guard\n";
    int command;
    std::cin >> command;

    return static_cast< tAction >( command );
}

// 2P用の入力関数
tAction inputaction2()
{
    std::cout << "数字を入力してください(2P) nAttack：Attack　nGuard：Guard\n";
    int command;
    std::cin >> command;

    return static_cast< tAction >( command );
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
        int pokemon1Guard = pokemon1->Guard(pokemon2Attack);
        pokemon1->Damage(pokemon1Guard);
    }
    else if (command1 == tAction::nAttack && command2 == tAction::nGuard)
    {
        int pokemon1Attack = pokemon1->Attack();
        int pokemon2Guard = pokemon2->Guard(pokemon1Attack);
        pokemon2->Damage(pokemon2Guard);
    }
    else
    {
        std::cout << "お互いに防御した！\n";
    }
}

int main()
{
    CPikachu pikachu;
    CMewtwo  mewtwo;
    CSquirtle squirtle;

    tAction command1 = inputaction1();
    tAction command2 = inputaction2();

    execution(&pikachu, &mewtwo, command1, command2);
}
