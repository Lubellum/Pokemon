#include <iostream>
#include "pikachu.h"
#include "mewtwo.h"
#include "squirtle.h"

//void Battle(Pikachu * pikachu, CMewtwo * mewtwo)
//{
//    int pikachuDamagePoint = pikachu->Attack();
//    mewtwo->Damage(pikachuDamagePoint);
//
//    int mewtwoDamagePoint = mewtwo->Attack();
//    pikachu->Damage(mewtwoDamagePoint);
//}

void Battle(CSquirtle* squirtle)
{
    int squirtleDamagePoint = squirtle->Attack();
    squirtleDamagePoint = squirtle->Guard();
    squirtle->Damage(squirtleDamagePoint);
}

int main()
{
    //CPikachu pikachu;
    //CMonster* monster = new CMonster;
    //CMonster* pikachu = new CPikachu;
    //pikachu.Attack();
    //CMewtwo  mewtwo;
    CSquirtle squirtle;

    Battle(&squirtle);
    //Battle(&pikachu, &mewtwo);
}
