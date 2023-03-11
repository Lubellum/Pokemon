#ifndef MONSTER_H_INCLUDED

#define MONSTER_H_INCLUDED

#include <iostream>

// ========================================================================= //
//  �y�����X�^�[�z���N���X
// ========================================================================= //

class CMonster
{
public:

    CMonster();
    CMonster
    (
        int aLevel,       // ���x��.
        int aHitPoint,    // HP.
        int aAttackPoint, // �U��.
        int aDefencePoint // �h��.
    );
    virtual ~CMonster();

    int Attack();
    int Guard(int aAttackPoint);
    void Damage(int aDamagePoint);

private:

    int mLevel;        // ���x��.
    int mHitPoint;     // HP.
    int mAttackPoint;  // �U��.
    int mDefencePoint; // �h��.
};

#endif // !MONSTER_H_INCLUDED