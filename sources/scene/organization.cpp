#include <iostream>
class CMonster;

CMonster* CreateMonster();
int SelectMonster(CMonster** team);// ��O�҂�p�ӁB���ʂȏ���

// �`�[�����쐬���A�����o�[�����肷��֐�
void Organization(std::vector<CMonster*> *aTeam1Monster, int aTeam1Number, std::vector<CMonster*> *aTeam2Monster, int aTeam2Number)
{
    // �`�[���Ґ�

    for (int i = 0; i < aTeam1Number; i++)
    {
        aTeam1Monster->push_back( CreateMonster() );
    }
 
    for (int i = 0; i < aTeam2Number; i++)
    {
        aTeam2Monster->push_back( CreateMonster() );
    }
}