#include <iostream>
#include "monster.h"

CMonster* SelectMonster();
int SelectMonster(CMonster** team);// 第三者を用意。共通な処理

// チームを作成し、メンバーを決定する関数
void Organization(CMonster** aTeam1Monster, int aTeam1Number, CMonster** aTeam2Monster ,int aTeam2Number)
{
    // チーム編成

    for (int i = 0; i < aTeam1Number; i++)
    {
        aTeam1Monster[i] = SelectMonster();
    }

    for (int i = 0; i < aTeam2Number; i++)
    {
        aTeam2Monster[i] = SelectMonster();
    }
}
