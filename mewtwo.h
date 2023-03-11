#ifndef MEWTWO_H_INCLUDED

#define MEWTWO_H_INCLUDED

#include "monster.h"

// =============================================================================== //
//  �y�����X�^�[�z�~���E�c�[.
// =============================================================================== //
class CMewtwo : public CMonster
{
public:

    CMewtwo();
    virtual ~CMewtwo(); // �f�X�g���N�^�ɂ� virtual ��t����.

    int Attack();
    void Damage(int aDamagePoint);

private:

    int mLevel;         // ���x��.
    int mHitPoint;      // HP.
    int mAttackPoint;   // �U��.
    int mDefensePoint;  // �h��.
};

#endif // !MEWTWO_H_INCLUDED