#include <iostream>
#include "monster.h"

CMonster* SelectMonster();
int SelectMonster(CMonster** team);// ��O�҂�p�ӁB���ʂȏ���

// �`�[�����쐬���A�����o�[�����肷��֐�
void Organization(CMonster** aTeam1Monster, int aTeam1Number, CMonster** aTeam2Monster ,int aTeam2Number)
{
    // �`�[���Ґ�

    for (int i = 0; i < aTeam1Number; i++)
    {
        aTeam1Monster[i] = SelectMonster();
    }

    for (int i = 0; i < aTeam2Number; i++)
    {
        aTeam2Monster[i] = SelectMonster();
    }
}
