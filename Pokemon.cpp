#include <iostream>
#include "pikachu.h"
#include "mewtwo.h"
#include "squirtle.h"

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

    Battle(&mewtwo, &squirtle);
    Battle(&pikachu, &mewtwo);
}
