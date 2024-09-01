#pragma once

class CMonster; // �O���錾�I�@�N���X�ƍ\���̂����Ŏg����B

enum class tAction : int;

void Execution(CMonster* pokemon1, CMonster* pokemon2, tAction command1, tAction command2);
bool IsRoundFinish(CMonster* pokemon1, CMonster* pokemon2);
bool IsGameFinish(std::vector<CMonster*> *team1, std::vector<CMonster*> *team2);
void battle(std::vector<CMonster*> *team1Monster, std::vector<CMonster*> *team2Monster, int team1position, int team2position);