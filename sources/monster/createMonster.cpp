#include <iostream>
#include "monster.h"
#include "pikachu.h"
#include "mewtwo.h"
#include "squirtle.h"
#include "nidoking.h"

enum class tMonsterNo : int
{
    nNone,
    nPikachu,
    nMewtwo,
    nSquirtle,
    nNidoking,
};

CMonster* CreateMonster(tMonsterNo aMonsterNo)
{
    switch (aMonsterNo)
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

tMonsterNo InputMonsterNumber()
{
    std::cout << "モンスターの番号を選択してください\n";

    int number = 0;
    std::cin >> number;
    tMonsterNo monsterNo = static_cast<tMonsterNo>(number);

    return monsterNo;
}

CMonster* SelectMonster()
{
    tMonsterNo monsterNo = InputMonsterNumber();

    return CreateMonster(monsterNo);
}

int SelectMonster(CMonster** team)
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