#pragma once

class CMonster; // 前方宣言！　クラスと構造体だけで使える。

enum class tAction : int;

void Execution(CMonster* pokemon1, CMonster* pokemon2, tAction command1, tAction command2);
bool IsRoundFinish(CMonster* pokemon1, CMonster* pokemon2);
bool IsGameFinish(CMonster** team1, CMonster** team2);
void battle(CMonster** team1Monster, CMonster** team2Monster, int team1position, int team2position);