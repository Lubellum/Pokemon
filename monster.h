// �p�����ł��R���X�g���N�^�E�f�X�g���N�^�͖����Ƃ����Ȃ�

#include <iostream>

// ========================================================================= //
//  �y�����X�^�[�z���N���X
// ========================================================================= //
class CMonster
{
public:

    CMonster();
    virtual ~CMonster();

    int Attack();
    void Damage(int aDamagePoint);


protected:

    int mLevel;         // ���x��.
    int mHitPoint;      // HP.
    int mAttackPoint;   // �U��.
    int mDefensePoint;  // �h��.
};