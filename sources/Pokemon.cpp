#include <iostream>
#include "command/command.h"
#include "scene/battle.h"
#include "scene/organization.h"
#include "monster/createMonster.h"
#include "monster/monster.h"


const int gTeam1Number = 4;
const int gTeam2Number = 4;
//CMonster** gTeam1Monster;
//CMonster** gTeam2Monster;

std::vector<CMonster*> gTeam1Monster;
std::vector<CMonster*> gTeam2Monster;


void Initialize()
{
    //gTeam1Monster = new CMonster*[gTeam1Number];
    //gTeam2Monster = new CMonster*[gTeam2Number];
}

void Execute()
{
    Organization(&gTeam1Monster, gTeam1Number, &gTeam2Monster, gTeam2Number);

    int team1position = SelectMonster(gTeam1Monster);
    int team2position = SelectMonster(gTeam2Monster);

    battle(&gTeam1Monster, &gTeam2Monster, team1position, team2position);
}

void Terminate()
{
    //delete[] gTeam1Monster;
    //delete[] gTeam2Monster;
    for (int i = 0; i < gTeam1Monster.size(); i++)
    {
        // 明示的に実行　→　デストラクタを呼び出している
        delete gTeam1Monster[i];
    }

    for (int i = 0; i < gTeam2Monster.size(); i++)
    {
        delete gTeam2Monster[i];
    }
}

int main()
{
    // ゲーム開始
    std::cout << "ゲーム開始\n";

    Initialize();
    Execute();
    Terminate();

    // リザルト
    std::cout << "ゲーム終了\n";
}
