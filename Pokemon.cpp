#include <iostream>
#include "pikachu.h"
#include "mewtwo.h"
#include "squirtle.h"

void Battle(CMonster * pokemon1, CMonster * pokemon2)
{
    int pokemon1DamagePoint = pokemon1->Attack();
    pokemon2->Damage(pokemon1DamagePoint);

    int pokemon2DamagePoint = pokemon2->Attack();
    pokemon1->Damage(pokemon2DamagePoint);
}

int main()
{
    CPikachu pikachu;
    CMewtwo  mewtwo;
    CSquirtle squirtle;

    Battle(&mewtwo, &squirtle);
    Battle(&pikachu, &mewtwo);
}
