#ifndef MONSTER_H_INCLUDED

#define MONSTER_H_INCLUDED

#include <iostream>
#include <string>

// ========================================================================= //
//  �y�����X�^�[�z���N���X
// ========================================================================= //

class CMonster
{
public:

    CMonster();
    CMonster
    (
        std::string aName, // ���O
        int aLevel,        // ���x��.
        int aHitPoint,     // HP.
        int aAttackPoint,  // �U��.
        int aDefencePoint  // �h��.
    );
    virtual ~CMonster();

    int Attack();
    bool Guard();
    void Damage(int aDamagePoint);

private:

    std::string mName; // ���O
    int mLevel;        // ���x��.
    int mHitPoint;     // HP.
    int mAttackPoint;  // �U��.
    int mDefencePoint; // �h��.
    bool mGuardFlag;
};

#endif // !MONSTER_H_INCLUDED