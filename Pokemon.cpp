#include <iostream>
#include "pikachu.h"
#include "mewtwo.h"

int main()
{
    CPicachu picachu;
    CMewtwo  mewtwo;

    int picachuDamagePoint = picachu.Attack();
    mewtwo.Damage(picachuDamagePoint);

    int mewtwoDamagePoint = mewtwo.Attack();
    picachu.Damage(mewtwoDamagePoint);
}
