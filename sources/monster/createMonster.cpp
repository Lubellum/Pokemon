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
    std::cout << "�����X�^�[�̔ԍ���I�����Ă�������\n";

    int number = 0;
    std::cin >> number;
    tMonsterNo monsterNo = static_cast<tMonsterNo>(number);

    return monsterNo;
}

CMonster* CreateMonster()
{
    tMonsterNo monsterNo = InputMonsterNumber();

    return CreateMonster(monsterNo);
}

int SelectMonster(const std::vector<CMonster*> &team)
{
    std::cout << "�����X�^�[��I�����Ă�������\n";
    int number = 0;

    while (true)
    {
        std::cin >> number;

        if (number < team.size())
        {
            if (team[number]->FaintFlag() == false)
            {
                return number;
            }
            std::cout << "���̃����X�^�[�͓|��Ă��܂��B�ēx�I�����Ă��������B\n";
        }
        else
        {
            std::cout << "0�`3�̐�������͂��Ă�������\n";
        }
    }
}